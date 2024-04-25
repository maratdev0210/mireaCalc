#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <cmath>
#include <algorithm>
#include <windows.h>

bool russian = false;

using namespace std;

class Instructions
{
private:
    vector<string> instructions = {
        "Welcome to the Quadratic Equation Calculator. Type in any of the quadratic equations and the program will give you the detailed solutions"
        "to any of those equations.",
        "Here is the full list of 8 types of Quadratic equations:",
        "The first type: a = 0, b = 0, c = 0.",
        "0 * x^2 + 0 * x + 0 = 0",
        "In this case the solution is all the x that belong to the range of (-inf, +inf).",
        "The second type: a != 0, b = 0, c = 0.",
        "a * x^2 + 0 * x + 0 = 0",
        "In this case the equation is a * x^2 = 0, the only solution to this equation is x = 0.",
        "The third type: c = 0, a is undefnied, b is undefined",
        "In this case the equation is not being fully defined. There are no solutions.",
        "The fourth type: a != 0, b = 0, c != 0",
        "a * x^2 + c = 0",
        "In this case the solution depends on the result of (-c/a).",
        "if (-c/a) < 0, then there are no solutions. if (-c/a) > 0 then the solution is sqrt(-c/a) and -sqrt(-c/a)",
        "The fifth type: a = 0, b != 0, c != 0",
        "bx + c = 0",
        "In this case the solution is (-c/b)",
        "The sixth type: a != 0, b != 0, c != 0",
        "ax^2 + bx + c = 0",
        "In this case there are many solutions. One of which is finding the Discriminant: x = (-b + sqrt(D)) / 2a, where D = b^2 - 4ac",
        "The seventh type: a = 0, b != 0, c = 0",
        "bx = 0",
        "In this case the solution is x = 0.",
        "The eigth type: a != 0, b != 0, c = 0",
        "ax^2 + bx = 0",
        "In this case the solution is x = 0 and x = -b/a",
        "Enter an equation in the following format: a b c"
        "where a b c are the parameters of the equation"
        "\n",
        "\n",
    };

    // 0.234

    vector<string> onStartInstructions = {"\tShow help:\n\t\tHELP\n",
                                          "\tQuit the program:\n\t\tQUIT\n",
                                          "\tType an equation and find the solution:\n\t\tEQUATION\n"};

    vector<string>
        systemInstructions = {
            "Enter a: ",
            "Enter b: ",
            "Enter c: "};

public:
    void show()
    {
        for (int i = 0; i < instructions.size(); i += 1)
        {
            cout << instructions[i] << endl;
        }
    }

    void formatOutputTable(string operation, string command)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << "\t\t\t\t";
            if (i == 3)
            {
                int j = 0;
                while (j < 60)
                {
                    if (j == 0 || j == 35 || j == 59)
                    {
                        cout << "|";
                        j++;
                        continue;
                    }
                    if (j == 8)
                    {
                        cout << operation;
                        j += operation.size();
                        continue;
                    }

                    if (j == 44)
                    {
                        cout << command;
                        j += command.size();
                        continue;
                    }

                    if (j < 5 || j < 35 || j < 44 || j < 59)
                    {
                        cout << " ";
                        j++;
                        continue;
                    }
                }
                cout << endl;
            }
            else
            {
                int j = 0;
                while (j < 60)
                {
                    if (j == 0 || j == 59 || j == 35)
                    {
                        cout << "|";
                        j++;
                        continue;
                    }
                    cout << " ";
                    j++;
                }
                cout << endl;
            }
        }
        cout << "\t\t\t\t";
        for (int i = 0; i < 60; i++)
        {
            cout << "~";
        }
        cout << endl;
    }

    void showOnStart()
    {
        cout << "\t\t";
        for (int i = 0; i < 90; i++)
        {
            cout << '-';
        }
        cout << endl;
        if (russian)
        {
            cout << "\t\t|    Добро пожаловать в калькулятор по решению квадратных уравнений. Список доступных комманд:     |" << endl;
        }
        else
        {
            cout << "\t\t|    Welcome to the Quadratic Equation Solver. Here is the list of available commands     |" << endl;
        }
        cout << "\t\t";
        for (int i = 0; i < 90; i++)
        {
            cout << '-';
        }
        cout << endl;
        cout << "\t\t\t\t";
        for (int i = 0; i < 60; i++)
        {
            cout << "~";
        }
        cout << endl;
        if (russian)
        {
            formatOutputTable("Операция", "Комманда");
            formatOutputTable("показать помощь", "HELP");
            formatOutputTable("Выйти из программы", "QUIT");
            formatOutputTable("Решить уравнение", "EQUATION");
            formatOutputTable("Информация об уравнениях", "INFO");
            formatOutputTable("Смена языка", "SWITCH");
            return;
        }
        formatOutputTable("OPERATION", "COMMAND");
        formatOutputTable("Show help", "HELP");
        formatOutputTable("Exit the program", "QUIT");
        formatOutputTable("Solve equation", "EQUATION");
        formatOutputTable("Equation info", "INFO");
        formatOutputTable("Switch language", "SWITCH");
        /*
        for (int i = 0; i < onStartInstructions.size(); i += 1)
        {
            cout << onStartInstructions[i] << endl;
        } */
    }

    void setEquationRowsValues();

    void formatEquationTable(string type, string parameters, string form, string solution)
    {
        int cur = 0;
        bool solutionDisplayed = false;
        for (int i = 0; i < 6; i++)
        {
            if (cur >= solution.size())
            {
                solutionDisplayed = true;
            }
            if (i == 3)
            {
                int j = 0;
                while (j <= 140)
                {
                    if (j == 0 || j == 15 || j == 42 || j == 71 || j == 140)
                    {
                        cout << "|";
                        j++;
                        continue;
                    }
                    if (j == 6)
                    {
                        cout << type;
                        j += 1;
                        continue;
                    }
                    if (j == 18)
                    {
                        cout << parameters;
                        j += parameters.size();
                        continue;
                    }
                    if (j == 47)
                    {
                        cout << form;
                        j += form.size();
                        continue;
                    }
                    if (j == 75 && !solutionDisplayed)
                    {
                        /*string line = solution.substr(cur, cur + min(50ull, solution.size() - cur));
                        cout << line;
                        j += min(50ull, solution.size() - cur);
                        cur += 50; */
                        string line = "";
                        bool seen = false;
                        for (unsigned long long k = cur; k < cur + min(50ull, solution.size() - cur); k++)
                        {
                            if (solution[k] == 'b' && solution[k + 1] == 'r')
                            {
                                cur += (k - cur + 2);
                                j += (k - cur + 2);
                                seen = true;
                                break;
                            }
                            line += solution[k];
                        }
                        if (!seen)
                        {
                            j += min(50ull, solution.size() - cur);
                            cur += 50;
                        }
                        cout << line;
                        continue;
                    }
                    if (j < 6 || j < 15 || j < 18 || j < 42 || j < 47 || j < 70 || j < 75 || j < 140)
                    {
                        cout << " ";
                        j++;
                        continue;
                    }
                }
                cout << endl;
            }
            else
            {
                int j = 0;
                while (j <= 140)
                {
                    if (j == 0 || j == 15 || j == 42 || j == 71 || j == 140)
                    {
                        cout << "|";
                        j++;
                        continue;
                    }
                    if (j == 75 && !solutionDisplayed)
                    {
                        string line = "";
                        bool seen = false;
                        for (unsigned long long k = cur; k < cur + min(50ull, solution.size() - cur); k++)
                        {
                            if (solution[k] == 'b' && solution[k + 1] == 'r')
                            {

                                j += (k - cur);
                                cur += (k - cur + 2);
                                seen = true;
                                break;
                            }
                            line += solution[k];
                        }
                        if (!seen)
                        {
                            j += min(50ull, solution.size() - cur);
                            cur += 50;
                        }
                        cout << line;
                        continue;
                    }
                    if (j < 6 || j < 15 || j < 22 || j < 42 || j < 53 || j < 70 || j < 75 || j < 140)
                    {
                        cout << " ";
                        j++;
                        continue;
                    }
                }
                cout << endl;
            }
        }
        for (int i = 0; i <= 140; i++)
        {
            cout << "~";
        }
        cout << endl;
    }

    void formatEquationColumnHeaderRussian()
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == 3)
            {
                int j = 0;
                while (j <= 140)
                {
                    if (j == 0 || j == 15 || j == 42 || j == 71 || j == 140)
                    {
                        cout << "|";
                        j++;
                        continue;
                    }
                    if (j == 6)
                    {
                        if (russian)
                        {
                            cout << "ТИП";
                            j += 3;
                        }
                        else
                        {
                            cout << "TYPE";
                            j += 4;
                        }
                        continue;
                    }
                    if (j == 22)
                    {
                        if (russian)
                        {
                            cout << "ПАРАМЕТРЫ";
                            j += 9;
                        }
                        else
                        {
                            cout << "PARAMETERS";
                            j += 10;
                        }
                        continue;
                    }
                    if (j == 53)
                    {
                        if (russian)
                        {
                            cout << "ФОРМА";
                            j += 5;
                        }
                        else
                        {
                            cout << "FORM";
                            j += 4;
                        }
                        continue;
                    }
                    if (j == 85)
                    {
                        if (russian)
                        {
                            cout << "РЕШЕНИЕ";
                            j += 7;
                        }
                        else
                        {
                            cout << "SOLUTION";
                            j += 8;
                        }
                        continue;
                    }
                    if (j < 6 || j < 15 || j < 22 || j < 42 || j < 53 || j < 70 || j < 85 || j < 140)
                    {
                        cout << " ";
                        j++;
                        continue;
                    }
                }
                cout << endl;
            }
            else
            {
                int j = 0;
                while (j <= 140)
                {
                    if (j == 0 || j == 15 || j == 42 || j == 71 || j == 140)
                    {
                        cout << "|";
                        j++;
                        continue;
                    }
                    if (j < 6 || j < 15 || j < 22 || j < 42 || j < 53 || j < 70 || j < 85 || j < 140)
                    {
                        cout << " ";
                        j++;
                        continue;
                    }
                }
                cout << endl;
            }
        }
        for (int i = 0; i <= 140; i++)
        {
            cout << "~";
        }
        cout << endl;
    }
    void formatEquationColumnHeader()
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == 3)
            {
                int j = 0;
                while (j <= 140)
                {
                    if (j == 0 || j == 15 || j == 42 || j == 71 || j == 140)
                    {
                        cout << "|";
                        j++;
                        continue;
                    }
                    if (j == 6)
                    {
                        cout << "TYPE";
                        j += 4;
                        continue;
                    }
                    if (j == 22)
                    {
                        cout << "PARAMETERS";
                        j += 10;
                        continue;
                    }
                    if (j == 53)
                    {
                        cout << "FORM";
                        j += 4;
                        continue;
                    }
                    if (j == 85)
                    {
                        cout << "SOLUTION";
                        j += 8;
                        continue;
                    }
                    if (j < 6 || j < 15 || j < 22 || j < 42 || j < 53 || j < 70 || j < 85 || j < 140)
                    {
                        cout << " ";
                        j++;
                        continue;
                    }
                }
                cout << endl;
            }
            else
            {
                int j = 0;
                while (j <= 140)
                {
                    if (j == 0 || j == 15 || j == 42 || j == 71 || j == 140)
                    {
                        cout << "|";
                        j++;
                        continue;
                    }
                    if (j < 6 || j < 15 || j < 22 || j < 42 || j < 53 || j < 70 || j < 85 || j < 140)
                    {
                        cout << " ";
                        j++;
                        continue;
                    }
                }
                cout << endl;
            }
        }
        for (int i = 0; i <= 140; i++)
        {
            cout << "~";
        }
        cout << endl;
    }

    void showEquationInfo()
    {
        if (russian)
        {
            cout << "\n\nКвадратное уравнение - это уравнение следующего вида:\n\n ";
            cout << "\t\t\t\t\tax^2 + bx + c = 0\n\n";
            cout << "В таблице представлено 8 типов квадратных уравнений...\n\n\n";
            cout << "Таблица 1. Типы квадратных уравнений\n";
            for (int i = 0; i <= 140; i++)
            {
                cout << "~";
            }
            cout << endl;
            formatEquationColumnHeaderRussian();
            formatEquationTable("1", "a=0,b=0,c=0", "0 * x^2 + 0 * x + 0 = 0", "все x в промежутке (-inf, +inf)");
            formatEquationTable("2", "a != 0, b = 0, c = 0", "a * x^2 = 0", "единственное решение x = 0");
            formatEquationTable("3", "c = 0", "не существует", "решений нет, так как дан только один параметр c");
            formatEquationTable("4", "a != 0, b = 0, c != 0", "a * x^2 + c = 0", "x^2 = -c / a brесли -c / a < 0, то решения не существует brесли -c / a > 0: br    x1 = sqrt(-c/a), x2 = -sqrt(-c/a)");
            formatEquationTable("5", "a = 0, b != 0, c != 0", "bx + c = 0", "x = -c / b");
            formatEquationTable("6", "a != 0, b != 0, c != 0", "a * x^2 + bx + c = 0", "Дискриминант: D = b^2 - 4ac. br1. если D > 0 x = (-b +/- sqrt(b^2 - 4ac) / 2a); br2. если D = 0 x = -b / 2a; если D < 0 то решения brне существует");
            formatEquationTable("7", "a = 0, b != 0, c = 0", "bx = 0", "единственное решение x = 0");
            formatEquationTable("8", "a != 0, b != 0, c = 0", "ax^2 + bx = 0", "перепишем уравнение: br           x(ax + b) = 0. brx1 = 0, x2 = -b/a");
            return;
        }
        cout << "\n\nQuadratic equation is an equation that can be rearranged in standard form as:\n\n ";
        cout << "\t\t\t\t\tax^2 + bx + c = 0\n\n";
        cout << "The table below represents eight types of existing quadratic equations...\n\n\n";
        cout << "Table 1. Types of Quadratic Equations\n";
        for (int i = 0; i <= 140; i++)
        {
            cout << "~";
        }
        cout << endl;
        formatEquationColumnHeader();
        formatEquationTable("1", "a=0,b=0,c=0", "0 * x^2 + 0 * x + 0 = 0", "all x in range(-inf, +inf)");
        formatEquationTable("2", "a != 0, b = 0, c = 0", "a * x^2 = 0", "the only solution is x = 0");
        formatEquationTable("3", "c = 0", "form doesn't exist", "equation is not valid, because only one parameter c is being passed");
        formatEquationTable("4", "a != 0, b = 0, c != 0", "a * x^2 + c = 0", "x^2 = -c / a brif -c / a < 0, the solution does not exist brif -c / a > 0: br    x1 = sqrt(-c/a), x2 = -sqrt(-c/a)");
        formatEquationTable("5", "a = 0, b != 0, c != 0", "bx + c = 0", "x = -c / b");
        formatEquationTable("6", "a != 0, b != 0, c != 0", "a * x^2 + bx + c = 0", "find the Discriminant: D = b^2 - 4ac. br1. if D > 0 x = (-b +/- sqrt(b^2 - 4ac) / 2a); br2. if D = 0 x = -b / 2a; if D < 0 the solution brdoes not exist");
        formatEquationTable("7", "a = 0, b != 0, c = 0", "bx = 0", "the only solution is x = 0");
        formatEquationTable("8", "a != 0, b != 0, c = 0", "ax^2 + bx = 0", "rewrite the equation: br           x(ax + b) = 0. brx1 = 0, x2 = -b/a");
    }

    void showInstructions(int i)
    {
        cout << systemInstructions[i];
    }
};

class Input
{
public:
    string command;

    void prompt()
    {
        getline(cin, command);
    }

    string getInput()
    {
        return command;
    }
};

class Equation
{
private:
    vector<int> parameters;

public:
    // \/
    // /\


    /*
                ASCII GRAPHICS CODE SETTERS

//  \     /
//   \   /
//    \ /
//    / \
//   /   \
//  /     \

    */

    vector<vector<string>> numberCodes;
    vector<string> exponent = {"  ___", " /   \\ ", "/--^--\\"};
    vector<string> variable = {"\\     /", " \\   /", "  \\./", "  / \\", " /   \\", "/     \\"};
    // vector<string> multiply = {"    _    ", "  /\\| |/\\", "  \\ ` ' / ", " |_     _|", "  / , . \\", "  \\/|_|\\/"};
    vector<string> multiplyX = {"     _     \\     / ", " /\\| |/\\   \\   / ", "  \\ ` ' /   \\./", " |_     _|  / \\", "  / , . \\  /   \\", "  \\/|_| \\//     \\"};
    vector<string> multiply = {"\\/", "/\\"};
    // display the number graphical code
    void displayStep(int number1, int number2, int number3)
    {
        initNumberCodes();
        for (int i = 0; i < numberCodes[number1].size(); i++)
        {

            // cout << numberCodes[number1][i] << "         " << multiply[i] << "       " << variable[i] << endl;
            // cout << numberCodes[number1][i] << numberCodes[number2][i] << endl;
            /*cout << numberCodes[1][i] << "                 " << variable[i];
            if (i == 2)
            {
                cout << multiply[0] << " " << variable[2] << endl;
                continue;
            }
            else if (i == 3)
            {
                cout << multiply[1] << " " << variable[3] << endl;
                continue;
            }
            cout << endl; */
            cout << numberCodes[2][i] << " " << variable[i] << endl;
        }

        for (int i = 0; i <= 10; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << numberCodes[i][j] << " " << variable[j] << endl;
            }
            cout << endl;
        }

        /*
        for (int i = 0; i < numberCodes[number1].size(); i++)
        {
            cout << numberCodes[number1][i] << endl;
        }
        for (int i = 0; i < numberCodes[number2].size(); i++)
        {
            cout << numberCodes[number2][i] << endl;
        }
        for (int i = 0; i < numberCodes[number3].size(); i++)
        {
            cout << numberCodes[number3][i] << endl;
        } */
    }

    void initNumberCodes()
    {
        vector<string> zero = {"  ___    ", " / _ \\   ", "| | | |  ", "| | | |  ", "| |_| |  ", " \\___/   "};
        vector<string> one = {" __  ", "/_ | ", " | | ", " | | ", " | | ", " |_| "};
        vector<string> two = {" ___  ", "|__ \\ ", "   ) |", "  / / ", " / /_ ", "|____|"};
        vector<string> three = {" ____  ", "|___ \\ ", "  __) |", " |__ < ", " ___) |", "|____/ "};
        vector<string> four = {" _  _   ", "| || |  ", "| || |_ ", "|__   _|", "   | |  ", "   |_|  "};
        vector<string> five = {" _____ ", "| ____|", "| |__  ", "|___ \\ ", " ___) |", "|____/ "};
        vector<string> six = {"   __   ", "  / /   ", " / /_   ", "| '_ \\  ", "| (_) | ", " \\___/  "};
        vector<string> seven = {" ______ ", "|____  |", "    / / ", "   / /  ", "  / /   ", " /_/    "};
        vector<string> eight = {"  ___   ", " / _ \\  ", "| (_) | ", " > _ <  ", "| (_) | ", " \\___/  "};
        vector<string> nine = {"  ___  ", " / _ \\ ", "| (_) |", " \\__, |", "   / / ", "  /_/  "};

        numberCodes.push_back(zero);
        numberCodes.push_back(one);
        numberCodes.push_back(two);
        numberCodes.push_back(three);
        numberCodes.push_back(four);
        numberCodes.push_back(five);
        numberCodes.push_back(six);
        numberCodes.push_back(seven);
        numberCodes.push_back(eight);
        numberCodes.push_back(nine);
    }

    // vector<vector<int>> vec;

    void showZero()
    {
        //    ___
        //   / _ \  
//  | | | |
        //  | | | |
        //  | |_| |
        //   \___/
        //
        cout << "  ___ " << endl;
        cout << " / _ \\" << endl;
        cout << "| | | |" << endl;
        cout << "| | | |" << endl;
        cout << "| |_| |" << endl;
        cout << " \\___/" << endl;
    }

    void showOne()
    {
        //   __
        //  /_ |
        //   | |
        //   | |
        //   | |
        //   |_|
        //
        cout << " __" << endl;
        cout << "/_ |" << endl;
        cout << " | |" << endl;
        cout << " | |" << endl;
        cout << " | |" << endl;
        cout << " |_|" << endl;
    }

    void showTwo()
    {
        //   ___
        //  |__ \  
        //     ) |
        //    / /
        //   / /_
        //  |____|
        //
        cout << " ___" << endl;
        cout << "|__ \\" << endl;
        cout << "   ) |" << endl;
        cout << "  / /" << endl;
        cout << " / /_ " << endl;
        cout << "|____|" << endl;
    }

    void showThree()
    {
        //   ____
        //  |___ \  
        //    __) |
        //   |__ <
        //   ___) |
        //  |____/
        //
    }

    void setEquation(vector<int> params)
    {
        parameters = params;
    }

    void showEquation()
    {
        for (int i = 0; i < 3; i += 1)
        {
            cout << parameters[i] << endl;
        }
    }

    void solveFirstType()
    {

        cout << "all parameters equal to zero, the equation is:\n0*x^2 + 0*x + 0 = 0\n";
        cout << "the x can be any integer in range (-inf, +inf)\n";
        cout << "Answer: x = (-inf, +inf)\n";
        displayStep(1, 0, 0);
    }

    void solveSecondType()
    {
        cout << "the equation can be rewritten as:\n"
             << parameters[0] << "x^2 = 0\n";
        cout << "divide the right side of the equation by a:\nx^2 = 0/" << parameters[0] << "\n";
        cout << "the only solution is x = 0.\n";
        cout << "Answer: x = 0\n";
    }

    void solveThirdType()
    {
        cout << "The equation can be rewritten as:\n " << parameters[2] << "=0\n";
        cout << "The expression is not correct, because " << parameters[2] << "!=0\n";
        cout << "That means the given parameters are incorrect and the solution does not exist.\n";
        cout << "Answer: the solution does not exist\n";
    }

    void solveFourthType()
    {
        cout << "The equation can be rewritten as:\n"
             << parameters[0] << "x^2 = " << -1 * parameters[2] << "\n";
        if ((-1 * parameters[2]) / parameters[0] < 0)
        {
            cout << "the value of " << -1 * parameters[2] << "/" << parameters[0] << " is less than zero\nthat means there are";
            cout << "no solutions to the equation\n";
            cout << "Answer: the solution does not exist\n";
        }
        else
        {
            cout << "The solution is sqrt(" << -1 * parameters[2] / parameters[0] << ")";
            cout << "and -sqrt(" << -1 * parameters[2] / parameters[0] << ")\n";
            cout << "Answer: " << sqrt(-1 * parameters[2] / parameters[0]) << "; " << -1 * sqrt(-1 * parameters[2] / parameters[0]) << endl;
        }
    }

    void solveFifthType()
    {
        cout << "Rewrite the equation as\n"
             << parameters[1] << "x + " << parameters[2] << " = 0\n";
        cout << "Shift the independent variables to the right side of the equation:\n"
             << parameters[1] << "x = " << -1 * parameters[2] << endl;
        cout << "find the x:\n x = " << -1 * parameters[2] << " / " << parameters[1] << " = " << -1 * parameters[2] / parameters[1] << endl;
        cout << "Answer: x = " << -1 * parameters[2] / parameters[1] << endl;
    }

    void solveSixthType()
    {
        cout << "Rewrite the equation as\n"
             << parameters[0] << "x^2 + " << parameters[1] << "x + " << parameters[2] << " = 0\n";
        cout << "Find the Discriminant: \n";
        int D = parameters[1] * parameters[1] - 4 * parameters[0] * parameters[2];
        cout << "D = " << parameters[1] << "^2 - " << 4 << "*" << parameters[0] << "*" << parameters[2] << endl;
        if (D < 0)
        {
            cout << "D < 0, then the solution does not exist.\n";
            return;
        }
        cout << "General formula for finding the roots of the equaiton:\n x = (-b +/- sqrt(D)) / 2a\n";
        if (D == 0)
        {
            cout << "There is only one solution to the equation\n";
            cout << "according the formula described above: x = (" << -1 * parameters[1] << " + " << sqrt(D) << ") / " << 2 * parameters[0] << " = "
                 << -1 * parameters[1] / (2 * parameters[0]) << endl;
            cout << "Answer: x = " << (-1 * parameters[1] - sqrt(D)) / (2 * parameters[0]) << endl;
        }
        else
        {
            cout << "There are two solutions to the equation\n";
            cout << "according the formula described above: x1 = (" << -1 * parameters[1] << " + " << sqrt(D) << ") / " << 2 * parameters[0] << " = "
                 << (-1 * parameters[1] + sqrt(D)) / (2 * parameters[0]) << endl;
            cout << "according the formula described above: x2 = (" << -1 * parameters[1] << " - " << sqrt(D) << ") / " << 2 * parameters[0] << " = "
                 << (-1 * parameters[1] - sqrt(D)) / (2 * parameters[0]) << endl;
            cout << "Answer: x1 = " << (-1 * parameters[1] + sqrt(D)) / (2 * parameters[0]) << "; x2 = " << (-1 * parameters[1] - sqrt(D)) / (2 * parameters[0]) << endl;
        }
    }

    void solveSeventhType()
    {
        cout << "Rewrite the equation:\n"
             << parameters[1] << "x = 0" << endl;
        cout << "x = " << 0 << " / " << parameters[1] << " = 0" << endl;
        cout << "Answer: x = 0" << endl;
    }

    void solveEigthType()
    {
        cout << "Rewrite theb equation:\n"
             << parameters[0] << "x^2 + " << parameters[1] << "x = 0" << endl;
        cout << "Apply the factorization based on the x:\n x(" << parameters[0] << "x + " << parameters[1] << ") = 0" << endl;
        cout << "The first root of the equation is 0\n";
        cout << "Find the solution to the equation " << parameters[0] << "x + " << parameters[1] << " = 0" << endl;
        cout << "x = " << -1 * parameters[1] << "/" << parameters[0] << " = " << (-1 * parameters[1]) / parameters[0] << endl;
        cout << "Answer: x = 0; x = " << (-1 * parameters[1]) / (parameters[0]) << endl;
    }

    int determineType()
    {
        if (parameters[0] == 0 and parameters[1] == 0 and parameters[2] == 0)
        {
            return 1;
        }
        else if (parameters[0] != 0 and parameters[1] == 0 and parameters[2] == 0)
        {
            return 2;
        }
        else if (parameters[0] == -999 and parameters[1] == -999 and parameters[2] == 0)
        {
            return 3;
        }
        else if (parameters[0] != 0 and parameters[1] == 0 and parameters[2] != 0)
        {
            return 4;
        }
        else if (parameters[0] == 0 and parameters[1] != 0 and parameters[2] != 0)
        {
            return 5;
        }
        else if (parameters[0] != 0 and parameters[1] != 0 and parameters[2] != 0)
        {
            return 6;
        }
        else if (parameters[0] == 0 and parameters[1] != 0 and parameters[2] == 0)
        {
            return 7;
        }
        else if (parameters[0] != 0 and parameters[1] != 0 and parameters[2] == 0)
        {
            return 8;
        }
    }

    void solveEquation()
    {
        int type = determineType();
        if (type == 1)
        {
            solveFirstType();
        }
        else if (type == 2)
        {
            solveSecondType();
        }
        else if (type == 3)
        {
            solveThirdType();
        }
        else if (type == 4)
        {
            solveFourthType();
        }
        else if (type == 5)
        {
            solveFifthType();
        }
        else if (type == 6)
        {
            solveSixthType();
        }
        else if (type == 7)
        {
            solveSeventhType();
        }
        else if (type == 8)
        {
            solveEigthType();
        }
    }
};

class userInterface
{
private:
    string command = "";
    vector<int> nums = {-999, -999, -999};

public:
    Instructions instructions;
    void help()
    {
        instructions.show();
    }

    void helpInstruction(int i)
    {
        instructions.showInstructions(i);
    }

    void showOnStart()
    {
        instructions.showOnStart();
    }

    void showEquationInfo()
    {
        instructions.showEquationInfo();
    }

    void setCommand(Input &input)
    {
        command = input.getInput();
    }

    void quit()
    {
        cout << "THe end!";
        exit(0);
    }
    void processInput()
    {
        showOnStart();
        while (command != "QUIT")
        {
            Input input;
            input.prompt();
            setCommand(input);
            if (command == "HELP")
            {
                showOnStart();
            }
            else if (command == "INFO")
            {
                showEquationInfo();
            }
            else if (command == "SWITCH")
            {
                russian = !russian; // if russian then switch to english, otherwise switch to russian
            }
            else if (command == "EQUATION")
            {
                int num = 0;
                for (int i = 0; i < 3; i++)
                {
                    helpInstruction(i);
                    cin >> num;
                    nums[i] = num;
                }
                Equation equation;
                equation.setEquation(nums);
                equation.solveEquation();
            }
        }
        quit();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    userInterface UI;
    UI.processInput();
}
