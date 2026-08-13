#include "iostream"
#include "stack"
#include "string"
#include "vector"

enum class NodeType
{
    Operator,
    MathematicalValue
};

struct Node
{
    std::string value;
    NodeType type;
};

int main()
{
    std::vector<std::string> operatorPrecedenceOrder = {"/", "*", "+", "-"};

    std::vector<Node> nodes;

    std::string expression;

    std::cout<<"Enter any mathematical expression:";
    std::cin>>expression;

    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {

            Node node;
            node.type = NodeType::MathematicalValue;

            int num = 0;
            while (i < expression.length())
            {
                char ch = expression[i];
                if (!isdigit(ch))
                {
                    i--;
                    break;
                }
                else
                {
                    num = num * 10 + (ch - '0');
                    i++;
                }
            }

            node.value = std::to_string(num);

            nodes.push_back(node);
        }
        else if (isspace(expression[i]))
            continue;
        else if (expression[i] == '+')
        {
            Node node;
            node.type = NodeType::Operator;
            node.value = expression[i];

            nodes.push_back(node);
        }
        else if (expression[i] == '-')
        {   
            Node node;
            node.type = NodeType::Operator;
            node.value = expression[i];

            nodes.push_back(node);
        }
        else if (expression[i] == '*')
        {
            Node node;
            node.type = NodeType::Operator;
            node.value = expression[i];

            nodes.push_back(node);
        }
        else if (expression[i] == '/')
        {
            Node node;
            node.type = NodeType::Operator;
            node.value = expression[i];

            nodes.push_back(node);
        }
        else if (expression[i] == '(')
        {
            Node node;
            node.type = NodeType::Operator;
            node.value = expression[i];

            nodes.push_back(node);
        }
        else if (expression[i] == ')')
        {
            Node node;
            node.type = NodeType::Operator;
            node.value = expression[i];

            nodes.push_back(node);
        }
        else
        {
            throw std::runtime_error("Unknown syntax found" + expression[i]);
        }
    }

    // for (const Node &node : nodes)
    // {
    //     std::cout << node.value << std::endl;
    // }

    // parsing the expression is complete upto here

    // now we will create the postfix evaluation
    std::stack<Node> stackNodes;

    std::vector<Node> expressionNodes;
    for (const Node &node : nodes)
    {
        if (node.type == NodeType::MathematicalValue)
        {
            expressionNodes.push_back(node);
        }
        else if (node.type == NodeType::Operator)
        {
            if (stackNodes.empty())
            {
                stackNodes.push(node);
            }
            else
            {

                Node topNode = stackNodes.top();
                const Node &currentNode = node;
                if (topNode.value == "+")
                {
                    if (currentNode.value == "+")
                    {
                        expressionNodes.push_back(currentNode);
                    }
                    else if (currentNode.value == "-")
                    {   
                        expressionNodes.push_back(topNode);
                        stackNodes.pop();
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "*")
                    {
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "/")
                    {
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "(")
                    {
                        if (currentNode.value == ")")
                        {
                            bool isFound = false;
                            while (!stackNodes.empty())
                            {
                                Node top = stackNodes.top();
                                stackNodes.pop();
                                if (top.value == "(")
                                {
                                    isFound = true;
                                    break;
                                }
                                else
                                {
                                    expressionNodes.push_back(top);
                                }
                            }

                            if (!isFound)
                            {
                                throw std::runtime_error("Syntax Error in bracketing");
                            }
                        }
                        else
                        {
                            stackNodes.push(currentNode);
                        }
                    }
                    else if (currentNode.value == ")")
                    {
                        bool isFound = false;
                        while (!stackNodes.empty())
                        {
                            Node top = stackNodes.top();
                            stackNodes.pop();
                            if (top.value == "(")
                            {
                                isFound = true;
                                break;
                            }
                            else
                            {
                                expressionNodes.push_back(top);
                            }
                        }

                        if (!isFound)
                        {
                            throw std::runtime_error("Syntax Error in bracketing");
                        }
                    }
                }
                else if (topNode.value == "-")
                {
                    if (currentNode.value == "+")
                    {   
                        expressionNodes.push_back(topNode);
                        stackNodes.pop();
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "-")
                    {
                        expressionNodes.push_back(currentNode);
                    }
                    else if (currentNode.value == "*")
                    {
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "/")
                    {
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "(")
                    {
                        if (currentNode.value == ")")
                        {
                            bool isFound = false;
                            while (!stackNodes.empty())
                            {
                                Node top = stackNodes.top();
                                stackNodes.pop();
                                if (top.value == "(")
                                {
                                    isFound = true;
                                    break;
                                }
                                else
                                {
                                    expressionNodes.push_back(top);
                                }
                            }

                            if (!isFound)
                            {
                                throw std::runtime_error("Syntax Error in bracketing");
                            }
                        }
                        else
                        {
                            stackNodes.push(currentNode);
                        }
                    }
                    else if (currentNode.value == ")")
                    {
                        bool isFound = false;
                        while (!stackNodes.empty())
                        {
                            Node top = stackNodes.top();
                            stackNodes.pop();
                            if (top.value == "(")
                            {
                                isFound = true;
                                break;
                            }
                            else
                            {
                                expressionNodes.push_back(top);
                            }
                        }

                        if (!isFound)
                        {
                            throw std::runtime_error("Syntax Error in bracketing");
                        }
                    }
                }
                else if (topNode.value == "*")
                {
                    if (currentNode.value == "+")
                    {
                        stackNodes.pop();
                        expressionNodes.push_back(topNode);
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "-")
                    {
                        stackNodes.pop();
                        expressionNodes.push_back(topNode);
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "*")
                    {
                        expressionNodes.push_back(currentNode);
                    }
                    else if (currentNode.value == "/")
                    {
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "(")
                    {
                        if (currentNode.value == ")")
                        {
                            bool isFound = false;
                            while (!stackNodes.empty())
                            {
                                Node top = stackNodes.top();
                                stackNodes.pop();
                                if (top.value == "(")
                                {
                                    isFound = true;
                                    break;
                                }
                                else
                                {
                                    expressionNodes.push_back(top);
                                }
                            }

                            if (!isFound)
                            {
                                throw std::runtime_error("Syntax Error in bracketing");
                            }
                        }
                        else
                        {
                            stackNodes.push(currentNode);
                        }
                    }
                    else if (currentNode.value == ")")
                    {
                        bool isFound = false;
                        while (!stackNodes.empty())
                        {
                            Node top = stackNodes.top();
                            stackNodes.pop();
                            if (top.value == "(")
                            {
                                isFound = true;
                                break;
                            }
                            else
                            {
                                expressionNodes.push_back(top);
                            }
                        }

                        if (!isFound)
                        {
                            throw std::runtime_error("Syntax Error in bracketing");
                        }
                    }
                }
                else if (topNode.value == "/")
                {
                    if (currentNode.value == "+")
                    {
                        stackNodes.pop();
                        expressionNodes.push_back(topNode);
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "-")
                    {
                        stackNodes.pop();
                        expressionNodes.push_back(topNode);
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "*")
                    {

                        stackNodes.pop();
                        expressionNodes.push_back(topNode);
                        stackNodes.push(currentNode);
                    }
                    else if (currentNode.value == "/")
                    {
                        expressionNodes.push_back(currentNode);
                    }
                    else if (currentNode.value == "(")
                    {
                        if (currentNode.value == ")")
                        {
                            bool isFound = false;
                            while (!stackNodes.empty())
                            {
                                Node top = stackNodes.top();
                                stackNodes.pop();
                                if (top.value == "(")
                                {
                                    isFound = true;
                                    break;
                                }
                                else
                                {
                                    expressionNodes.push_back(top);
                                }
                            }

                            if (!isFound)
                            {
                                throw std::runtime_error("Syntax Error in bracketing");
                            }
                        }
                        else
                        {
                            stackNodes.push(currentNode);
                        }
                    }
                    else if (currentNode.value == ")")
                    {
                        bool isFound = false;
                        while (!stackNodes.empty())
                        {
                            Node top = stackNodes.top();
                            stackNodes.pop();
                            if (top.value == "(")
                            {
                                isFound = true;
                                break;
                            }
                            else
                            {
                                expressionNodes.push_back(top);
                            }
                        }

                        if (!isFound)
                        {
                            throw std::runtime_error("Syntax Error in bracketing");
                        }
                    }
                }
                else if (topNode.value == "(")
                {
                    if (currentNode.value == ")")
                    {
                        bool isFound = false;
                        while (!stackNodes.empty())
                        {
                            Node top = stackNodes.top();
                            stackNodes.pop();
                            if (top.value == "(")
                            {
                                isFound = true;
                                break;
                            }
                            else
                            {
                                expressionNodes.push_back(top);
                            }
                        }

                        if (!isFound)
                        {
                            throw std::runtime_error("Syntax Error in bracketing");
                        }
                    }
                    else
                    {
                        stackNodes.push(currentNode);
                    }
                }
                else if (topNode.value == ")")
                {
                    bool isFound = false;
                    while (!stackNodes.empty())
                    {
                        Node top = stackNodes.top();
                        stackNodes.pop();
                        if (top.value == "(")
                        {
                            isFound = true;
                            break;
                        }
                        else
                        {
                            expressionNodes.push_back(top);
                        }
                    }

                    if (!isFound)
                    {
                        throw std::runtime_error("Syntax Error in bracketing");
                    }
                }
                else
                {
                    throw std::runtime_error("Unidentified syntax" + currentNode.value);
                }
            }
        }
    }

    while (!stackNodes.empty())
    {
        Node top = stackNodes.top();
        stackNodes.pop();
        expressionNodes.push_back(top);
    }

    // for (const auto &node : expressionNodes)
    // {
    //     std::cout << node.value << std::endl;
    // }

    //execute the expression node

    std::stack<double> executionStack;

    for(int i=0;i<expressionNodes.size();i++){
        
        const Node& currentNode = expressionNodes[i];

        if(currentNode.type==NodeType::MathematicalValue){
            executionStack.push(std::stod(currentNode.value));
        }else if(currentNode.type==NodeType::Operator){
            double second;
            if(executionStack.empty()){
                throw std::runtime_error("Error execution context. Execution Stack is empty");
            }else{
                second=executionStack.top();
                executionStack.pop();
            }
            
            double first;
            if(executionStack.empty()){
                throw std::runtime_error("Error execution context. Execution Stack is empty");
            }else{
                first = executionStack.top();
                executionStack.pop();
            }

            double result;
            if(currentNode.value=="+"){
                result=first+second;
            }else if(currentNode.value=="-"){
                result=first-second;
            }else if(currentNode.value=="*"){
                result = first*second;
            }else if(currentNode.value=="/"){
                result = first/second;
            }else{
                throw std::runtime_error("Error evaluating unknown expression:"+currentNode.value+"\n");
            }

            executionStack.push(result);
        }
    }

    if(executionStack.size()!=1){
        throw std::runtime_error("Execution stack error. Have more than 1 results");
    }

    double result = executionStack.top();
    executionStack.pop();

    std::cout<<"Result is:"<<result<<std::endl;

    return 0;
}