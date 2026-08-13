#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <bitset>
#include <cstdint>

using namespace std;

// ------------------------------------------------------------
// Read file
// ------------------------------------------------------------

string read_file(const string& filePath)
{
    ifstream file(filePath, ios::binary);

    if (!file.is_open())
    {
        throw runtime_error("Error. File: " + filePath + " not found");
    }

    string data(
        (istreambuf_iterator<char>(file)),
        istreambuf_iterator<char>()
    );

    file.close();

    return data;
}

// ------------------------------------------------------------
// Count character frequencies
// ------------------------------------------------------------

unordered_map<char, int> get_count_mapping(const string& data)
{
    unordered_map<char, int> map;

    for (char ch : data)
    {
        map[ch]++;
    }

    return map;
}


struct Node
{
    char data;
    int count;

    Node* left;
    Node* right;

    Node(char data, int count)
        : data(data),
          count(count),
          left(nullptr),
          right(nullptr)
    {
    }

    Node(Node* left, Node* right)
        : data('\0'),
          count(left->count + right->count),
          left(left),
          right(right)
    {
    }

    bool is_leaf() const
    {
        return left == nullptr && right == nullptr;
    }
};


struct Compare
{
    bool operator()(const Node* first, const Node* second) const
    {
        return first->count > second->count;
    }
};


Node* build_huffman_tree(
    const unordered_map<char, int>& count_mapping)
{
    priority_queue<
        Node*,
        vector<Node*>,
        Compare
    > queue;

    for (const auto& entry : count_mapping)
    {
        queue.push(
            new Node(entry.first, entry.second)
        );
    }

    if (queue.empty())
    {
        return nullptr;
    }

    if (queue.size() == 1)
    {
        Node* only = queue.top();
        queue.pop();

        Node* root = new Node('\0', only->count);
        root->left = only;

        return root;
    }

    while (queue.size() > 1)
    {
        Node* first = queue.top();
        queue.pop();

        Node* second = queue.top();
        queue.pop();

        Node* parent = new Node(first, second);

        queue.push(parent);
    }

    return queue.top();
}


void generate_codes(
    Node* root,
    const string& current_code,
    unordered_map<char, string>& codes)
{
    if (root == nullptr)
        return;

    if (root->is_leaf())
    {
        if (current_code.empty())
            codes[root->data] = "0";
        else
            codes[root->data] = current_code;

        return;
    }

    generate_codes(
        root->left,
        current_code + "0",
        codes
    );

    generate_codes(
        root->right,
        current_code + "1",
        codes
    );
}


void print_codes(
    const unordered_map<char, string>& codes)
{
    cout << "\n================ HUFFMAN CODES ================\n";

    for (const auto& entry : codes)
    {
        if (entry.first == ' ')
            cout << "[SPACE]";
        else if (entry.first == '\n')
            cout << "[NEWLINE]";
        else
            cout << entry.first;

        cout << " -> " << entry.second << '\n';
    }

    cout << "================================================\n";
}


void compress_file(
    const string& inputPath,
    const string& outputPath)
{
    string data = read_file(inputPath);

    if (data.empty())
    {
        cout << "File is empty.\n";
        return;
    }

    unordered_map<char, int> count_mapping =
        get_count_mapping(data);

    Node* root = build_huffman_tree(count_mapping);

    unordered_map<char, string> codes;

    generate_codes(root, "", codes);

    print_codes(codes);


    string encoded;

    for (char ch : data)
    {
        encoded += codes[ch];
    }

    cout << "\nOriginal size : "
         << data.size() * 8
         << " bits\n";

    cout << "Compressed size: "
         << encoded.size()
         << " bits\n";


    ofstream output(outputPath, ios::binary);

    if (!output.is_open())
    {
        throw runtime_error(
            "Could not create output file."
        );
    }


    uint16_t numberOfCharacters =
        static_cast<uint16_t>(count_mapping.size());

    output.write(
        reinterpret_cast<char*>(&numberOfCharacters),
        sizeof(numberOfCharacters)
    );

    for (const auto& entry : count_mapping)
    {
        unsigned char character =
            static_cast<unsigned char>(entry.first);

        uint32_t frequency =
            static_cast<uint32_t>(entry.second);

        output.write(
            reinterpret_cast<char*>(&character),
            sizeof(character)
        );

        output.write(
            reinterpret_cast<char*>(&frequency),
            sizeof(frequency)
        );
    }


    uint8_t validBits =
        static_cast<uint8_t>(encoded.size() % 8);

    if (validBits == 0)
        validBits = 8;

    output.write(
        reinterpret_cast<char*>(&validBits),
        sizeof(validBits)
    );


    for (size_t i = 0; i < encoded.size(); i += 8)
    {
        string byteString = encoded.substr(i, 8);

        while (byteString.size() < 8)
            byteString += '0';

        bitset<8> bits(byteString);

        uint8_t byte =
            static_cast<uint8_t>(bits.to_ulong());

        output.write(
            reinterpret_cast<char*>(&byte),
            sizeof(byte)
        );
    }

    output.close();

    cout << "\nFile compressed successfully!\n";
    cout << "Output: " << outputPath << '\n';
}


void delete_tree(Node* root)
{
    if (root == nullptr)
        return;

    delete_tree(root->left);
    delete_tree(root->right);

    delete root;
}


int main()
{
    try
    {
        string inputPath;
        string outputPath;

        cout << "============================================\n";
        cout << "           HUFFMAN FILE COMPRESSOR\n";
        cout << "============================================\n";

        cout << "\nEnter input file: ";
        cin >> inputPath;

        cout << "Enter output file: ";
        cin >> outputPath;

        compress_file(
            inputPath,
            outputPath
        );
    }
    catch (const exception& error)
    {
        cerr << "\nERROR: "
             << error.what()
             << '\n';

        return 1;
    }

    return 0;
}