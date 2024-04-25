/* cppBASIC
 * A simple BASIC like interpreter in C++
 * Github: https://www.github.com/0x4248/cppBASIC
 * Licence: GNU General Public License v3.0
 * By: 0x4248
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <thread>

#include "util.h"
#include "global.h"

void print(std::string message){
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    for (char c : message){
        std::cout << c;
    }
    std::cout << std::endl;
}

float evaluate_expression(std::string expression){
    std::vector<std::string> tokens = tokenize(expression);

    if(tokens.size() != 3) {
        std::cerr << "Invalid expression format" << std::endl;
        return 0;
    }

    if(tokens[0] == "ADD"){
        try {
            float num1 = std::stof(tokens[1]);
            float num2 = std::stof(tokens[2]);
            return num1 + num2;
        } catch (std::invalid_argument&) {
            int index1 = find_variable(tokens[1], variables);
            int index2 = find_variable(tokens[2], variables);
            if(index1 == -1 || index2 == -1) {
                std::cerr << "Invalid variable in expression" << std::endl;
                return 0;
            }
            return values[index1] + values[index2];
        }
    }

    else if(tokens[0] == "SUB"){
        try {
            float num1 = std::stof(tokens[1]);
            float num2 = std::stof(tokens[2]);
            return num1 - num2;
        } catch (std::invalid_argument&) {
            int index1 = find_variable(tokens[1], variables);
            int index2 = find_variable(tokens[2], variables);
            if(index1 == -1 || index2 == -1) {
                std::cerr << "Invalid variable in expression" << std::endl;
                return 0;
            }
            return values[index1] - values[index2];
        }
    }

    else if(tokens[0] == "MUL"){
        try {
            float num1 = std::stof(tokens[1]);
            float num2 = std::stof(tokens[2]);
            return num1 * num2;
        } catch (std::invalid_argument&) {
            int index1 = find_variable(tokens[1], variables);
            int index2 = find_variable(tokens[2], variables);
            if(index1 == -1 || index2 == -1) {
                std::cerr << "Invalid variable in expression" << std::endl;
                return 0;
            }
            return values[index1] * values[index2];
        }
    }

    else if(tokens[0] == "DIV"){
        try {
            float num1 = std::stof(tokens[1]);
            float num2 = std::stof(tokens[2]);
            return num1 / num2;
        } catch (std::invalid_argument&) {
            int index1 = find_variable(tokens[1], variables);
            int index2 = find_variable(tokens[2], variables);
            if(index1 == -1 || index2 == -1) {
                std::cerr << "Invalid variable in expression" << std::endl;
                return 0;
            }
            return values[index1] / values[index2];
        }
    }

    else {
        std::cerr << "Invalid expression operator" << std::endl;
        return 0;
    }
}

bool is_expression(std::string expression){
    if(expression.find("ADD") != std::string::npos || expression.find("SUB") != std::string::npos || expression.find("MUL") != std::string::npos || expression.find("DIV") != std::string::npos){
        return true;
    }
    return false;
}

void run_program() {
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i] == "") {
            continue;
        }
        std::string line = lines[i];
        std::vector<std::string> tokens;
        std::string delimiter = " ";
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            tokens.push_back(token);
            line.erase(0, pos + delimiter.length());
        }
        tokens.push_back(line);

        std::string command = tokens[1];
        if (command == "LET") {
            std::string variable = tokens[2];
            std::string value = tokens[4];
            int index = find_variable(variable, variables);
            if (index == -1) {
                variables.push_back(variable);
                values.push_back(std::stoi(value));
            } else {
                values[index] = std::stoi(value);
            }
        } else if (command == "PRINT") {
            if(tokens[2][0] == '"'){
                std::string output = "";
                for(int i = 2; i < tokens.size(); i++){
                    output += tokens[i] + " ";
                }
                output = output.substr(1, output.size() - 3);
                print(output);
            } else if(tokens.size() == 3){
                int index = find_variable(tokens[2], variables);
                print(std::to_string(values[index]));
            } else if(is_expression(tokens[2])){
                std::string expression = "";
                for(int i = 2; i < tokens.size(); i++){
                    expression += tokens[i] + " ";
                }
                float result = evaluate_expression(expression);
                print(std::to_string(result));
            }
        } else if (command == "GOTO") {
            int line_number = std::stoi(tokens[2]);
            i = line_number - 1;        
        } else if (command == "WAIT") {
            int time = std::stoi(tokens[2]);
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
        } else if (command == "END") {
            break;
        }
    }
    std::cout << "READY" << std::endl;
}
    
void command_line(){
    for(int i = 0; i < 10000; i++){
        lines.push_back("");
    }
    std::string command;
    std::cout << "cppBASIC v1.0" << std::endl;
    std::cout << "10,000 LINES FREE. TYPE 'QUIT' TO EXIT" << std::endl;
    while(true){
        std::cout << "> ";
        std::getline(std::cin, command);
        if(command == "QUIT"){
            break;
        } else if(command == "NEW"){
            lines.clear();
            variables.clear();
            values.clear();
            for(int i = 0; i < 10000; i++){
                lines.push_back("");
            }
            std::cout << "PROGRAM CLEARED" << std::endl;
        } else if(command == "LIST"){
            for(int i = 0; i < lines.size(); i++){
                if (lines[i] == ""){
                    continue;
                }
                print(std::to_string(i) + " " + lines[i]);
            }
        } else if(command == "CLEAR"){
            std::cout << "\033[2J\033[1;1H";
        } else if(command == "RUN") {
            run_program();
        } else if(isdigit(command[0])){
            int line_number = std::stoi(command);
            lines[line_number] = command;
        }
        
    }
}

int main(){
    command_line();
}

