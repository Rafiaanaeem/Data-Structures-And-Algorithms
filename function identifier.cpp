#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Enum to categorize variables
enum VarCategory { NONE, POINTER, REFERENCE };

// Class to represent a variable
class Variable {
public:
    string name;
    string datatype;
    VarCategory var_category;

    Variable(string n, string dt, VarCategory vc) {
        name = n;
        datatype = dt;
        var_category = vc;
    }
    void display() const {
        cout << "Name: " << name << ", Datatype: " << datatype
            << ", Category: " << (var_category == NONE ? "None" :
                var_category == POINTER ? "Pointer" : "Reference")
            << endl;
    }
};

// Class to represent a function
class Function {
public:
    string return_type;
    string name;
    vector<Variable> parameters;

    Function(string rt, string fn) : return_type(rt), name(fn) {}

    void addParameter(const Variable& param) {
        parameters.push_back(param);
    }

    void display() const {
        cout << "Function Name: " << name << endl;
        cout << "Return Type: " << return_type << endl;
        cout << "Parameters: " << endl;
        for (const auto& param : parameters) {
            param.display();
        }
    }
    // Static method to parse a function declaration
    static Function parse(const string& str) {
        int pos = str.find('(');
        string before_bracket = str.substr(0, pos);

        // Extract return type and function name
        int last_space = before_bracket.find_last_of(' ');
        string return_type = before_bracket.substr(0, last_space);
        string func_name = before_bracket.substr(last_space + 1);

        Function func(return_type, func_name);

        // Extract parameters
        int end_pos = str.find(')');
        string param_str = str.substr(pos + 1, end_pos - pos - 1);  // start, length(the number of characters to extract)

        if (!param_str.empty()) {
            int start = 0;
            while (start < param_str.length()) {
                int comma_pos = param_str.find(',', start);  // start means to start from the specific index
                if (comma_pos == string::npos) comma_pos = param_str.length();

                string param = param_str.substr(start, comma_pos - start);  // int x

                // Parse type and name for each parameter
                int space_pos = param.find_last_of(' ');
                string type = param.substr(0, space_pos);
                string name = param.substr(space_pos + 1);

                // Handle leading '*' or '&' in the name
                VarCategory category = NONE;
                if (!name.empty() && name[0] == '*') {
                    category = POINTER;
                    name = name.substr(1); // Remove '*' from the name
                }
                else if (!name.empty() && name[0] == '&') {
                    category = REFERENCE;
                    name = name.substr(1); // Remove '&' from the name
                }

                // Add the parsed parameter
                
                func.addParameter(Variable(name, type, category));

                start = comma_pos + 1;
            }
        }

        return func;
    }
};

int main() {
    // Example function declaration
    string str = "double product(int x, int &y,double z)";

    // Parse the function using the static method
    Function func = Function::parse(str);

    // Display the function details
    func.display();

    return 0;
}
