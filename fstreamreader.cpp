#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& code) {
    stack<char> s;

    for (size_t i = 0; i < code.length(); ++i) {
        char c = code[i];

        // opening bracket check
        if (c == '(' || c == '{') {
            s.push(c);
        }
        // closing bracket check
        else if (c == ')') {
            if (s.empty() || s.top() != '(') return false;
            s.pop();
        }
        else if (c == '}') {
            if (s.empty() || s.top() != '{') return false;
            s.pop();
        }
    }

    return s.empty();

}
int main() {

    //open file
    ifstream file("C:\\Users\\trese\\CLionProjects\\untitled2\\hello.txt");

    if (!file.is_open()) {
        cerr << "Error ~ file not opening" << endl;
        return 1;
    }

    // puts file contents into string
    string fileContent((istreambuf_iterator<char>(file)),
                             istreambuf_iterator<char>());

    //closes file
    file.close();

    //outputs string to make sure it works
    cout << "Successfully read file contents:\n" << std::endl;
    cout << fileContent;


    isBalanced(fileContent);

    return 0;
}