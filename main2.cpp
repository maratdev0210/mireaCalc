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
            cout << "\t\t|    ����� ���������� � ����������� �� ������� ���������� ���������. ������ ��������� �������:     |" << endl;
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
            formatOutputTable("��������", "��������");
            formatOutputTable("�������� ������", "HELP");
            formatOutputTable("����� �� ���������", "QUIT");
            formatOutputTable("������ ���������", "EQUATION");
            formatOutputTable("���������� �� ����������", "INFO");
            formatOutputTable("����� �����", "SWITCH");
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
                            cout << "���";
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
                            cout << "���������";
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
                            cout << "�����";
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
                            cout << "�������";
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
            cout << "\n\n���������� ��������� - ��� ��������� ���������� ����:\n\n ";
            cout << "\t\t\t\t\tax^2 + bx + c = 0\n\n";
            cout << "� ������� ������������ 8 ����� ���������� ���������...\n\n\n";
            cout << "������� 1. ���� ���������� ���������\n";
            for (int i = 0; i <= 140; i++)
            {
                cout << "~";
            }
            cout << endl;
            formatEquationColumnHeaderRussian();
            formatEquationTable("1", "a=0,b=0,c=0", "0 * x^2 + 0 * x + 0 = 0", "��� x � ���������� (-inf, +inf)");
            formatEquationTable("2", "a != 0, b = 0, c = 0", "a * x^2 = 0", "������������ ������� x = 0");
            formatEquationTable("3", "c = 0", "�� ����������", "������� ���, ��� ��� ��� ������ ���� �������� c");
            formatEquationTable("4", "a != 0, b = 0, c != 0", "a * x^2 + c = 0", "x^2 = -c / a br���� -c / a < 0, �� ������� �� ���������� br���� -c / a > 0: br    x1 = sqrt(-c/a), x2 = -sqrt(-c/a)");
            formatEquationTable("5", "a = 0, b != 0, c != 0", "bx + c = 0", "x = -c / b");
            formatEquationTable("6", "a != 0, b != 0, c != 0", "a * x^2 + bx + c = 0", "������������: D = b^2 - 4ac. br1. ���� D > 0 x = (-b +/- sqrt(b^2 - 4ac) / 2a); br2. ���� D = 0 x = -b / 2a; ���� D < 0 �� ������� br�� ����������");
            formatEquationTable("7", "a = 0, b != 0, c = 0", "bx = 0", "������������ ������� x = 0");
            formatEquationTable("8", "a != 0, b != 0, c = 0", "ax^2 + bx = 0", "��������� ���������: br           x(ax + b) = 0. brx1 = 0, x2 = -b/a");
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
    vector<double> parameters;
    string number1;
    string number2;
    string number3;

    string removeTrailingZeros(string number, int maxLen)
    {
        // find the dot position
        int dot = 0;
        string current = "";
        for (int i = 0; i < number.size(); i++)
        {
            current += number[i];
            if (number[i] == '.')
            {
                dot = i;
                break;
            }
        }
        int cnt = 0;
        for (int i = dot + 1; i < number.size(); i++)
        {
            cnt += 1;
            current += number[i];
            if (cnt >= maxLen)
            {
                break;
            }
        }
        int toRemove = 0;
        for (int i = current.size() - 1; i >= dot; i--)
        {
            if (current[i] != '0')
            {
                break;
            }
            toRemove += 1;
        }
        if (toRemove == maxLen)
        {
            toRemove++;
        }
        current = current.substr(0, current.size() - toRemove);
        return current;
    }

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
    vector<string> variable = {"\\     /", " \\   / ", "  \\./  ", "  / \\  ", " /   \\ ", "/     \\"};
    // vector<string> multiply = {"    _    ", "  /\\| |/\\", "  \\ ` ' / ", " |_     _|", "  / , . \\", "  \\/|_|\\/"};
    vector<string> multiplyX = {"     _     \\     / ", " /\\| |/\\   \\   / ", "  \\ ` ' /   \\./", " |_     _|  / \\", "  / , . \\  /   \\", "  \\/|_| \\//     \\"};
    vector<string> multiply = {"\\/", "/\\"};
    vector<string> minus = {" ______ ", "|______|"};
    vector<string> plus = {" _| |_ ", "|_   _|", "  |_|  "};
    vector<string> equal = {" ______ ", "|______|", " ______ ", "|______|"};
    // display the number graphical code

    void tabs(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\t";
        }
    }

    void newline(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\n";
        }
    }

    void solutionMessage()
    {
        newline(3);
        tabs(7);
        cout << "  _____  ____  _     _    _ _______ _____ ____  _   _ " << endl;
        tabs(7);
        cout << " / ____|/ __ \\| |   | |  | |__   __|_   _/ __ \\| \\ | |" << endl;
        tabs(7);
        cout << "| (___ | |  | | |   | |  | |  | |    | || |  | |  \\| |" << endl;
        tabs(7);
        cout << " \\___ \\| |  | | |   | |  | |  | |    | || |  | | . ` |" << endl;
        tabs(7);
        cout << " ____) | |__| | |___| |__| |  | |   _| || |__| | |\\  |" << endl;
        tabs(7);
        cout << "|_____/ \\____/|______\\____/   |_|  |_____\\____/|_| \\_|" << endl;
        newline(1);
    }

    void initialEquationMessage()
    {
        tabs(1);
        cout << " _______  _              _         _  _    _         _                              _    _                  " << endl;
        tabs(1);
        cout << "|__   __|| |            (_)       (_)| |  (_)       | |                            | |  (_)               _ " << endl;
        tabs(1);
        cout << "   | |   | |__    ___    _  _ __   _ | |_  _   __ _ | |   ___   __ _  _   _   __ _ | |_  _   ___   _ __  (_)" << endl;
        tabs(1);
        cout << "   | |   | '_ \\  / _ \\  | || '_ \\ | || __|| | / _` || |  / _ \\ / _` || | | | / _` || __|| | / _ \\ | '_ \\    " << endl;
        tabs(1);
        cout << "   | |   | | | ||  __/ |  || | | || || |_ | || (_| || | |  __/| (_| || |_| || (_| || |_ | || (_) || | | | _ " << endl;
        tabs(1);
        cout << "   |_|   |_| |_| \\___|  |_||_| |_||_| \\__||_| \\__,_||_|  \\___| \\__, | \\__,_| \\__,_| \\__||_| \\___/ |_| |_|(_)" << endl;
        tabs(1);
        cout << "                                                                 | |                                       " << endl;
        tabs(1);
        cout << "                                                                 |_|                                       " << endl;
        newline(1);
    }

    void firstStepMessage()
    {
        cout << "  _____ _______ ______ _____    __ " << endl;
        cout << " / ____|__   __|  ____|  __ \\  /_ |" << endl;
        cout << "| (___    | |  | |__  | |__) |  | |" << endl;
        cout << " \\___ \\   | |  |  __| |  ___/   | |" << endl;
        cout << " ____) |  | |  | |____| |       | |" << endl;
        cout << "|_____/   |_|  |______|_|       |_|" << endl;
        newline(2);
    }

    void secondStepMessage()
    {
        cout << "  _____ _______ ______ _____    ___  " << endl;
        cout << " / ____|__   __|  ____|  __ \\  |__ \\ " << endl;
        cout << "| (___    | |  | |__  | |__) |    ) |" << endl;
        cout << " \\___ \\   | |  |  __| |  ___/    / / " << endl;
        cout << " ____) |  | |  | |____| |       / /_ " << endl;
        cout << "|_____/   |_|  |______|_|      |____|" << endl;
        newline(2);
    }

    void thirdStepMessage()
    {
        cout << "  _____ _______ ______ _____    ____  " << endl;
        cout << " / ____|__   __|  ____|  __ \\  |___ \\ " << endl;
        cout << "| (___    | |  | |__  | |__) |   __) |" << endl;
        cout << " \\___ \\   | |  |  __| |  ___/   |__ < " << endl;
        cout << " ____) |  | |  | |____| |       ___) |" << endl;
        cout << "|_____/   |_|  |______|_|      |____/ " << endl;
        newline(2);
    }

    void fourthStepMessage()
    {
        cout << "  _____ _______ ______ _____    _  _   " << endl;
        cout << " / ____|__   __|  ____|  __ \\  | || |  " << endl;
        cout << "| (___    | |  | |__  | |__) | | || |_ " << endl;
        cout << " \\___ \\   | |  |  __| |  ___/  |__   _|" << endl;
        cout << " ____) |  | |  | |____| |         | |  " << endl;
        cout << "|_____/   |_|  |______|_|         |_|  " << endl;
        newline(2);
    }

    void answerMessage() {
        cout << "          _   _  _______          ________ _____  " << endl;
        cout << "    /\\   | \\ | |/ ____\\ \\        / /  ____|  __ \\ " << endl;
        cout << "   /  \\  |  \\| | (___  \\ \\  /\\  / /| |__  | |__) |" << endl;
        cout << "  / /\\ \\ | . ` |\\___ \\  \\ \\/  \\/ / |  __| |  _  / " << endl;
        cout << " / ____ \\| |\\  |____) |  \\  /\\  /  | |____| | \\ \\ " << endl;
        cout << "/_/    \\_\\_| \\_|_____/    \\/  \\/   |______|_|  \\_\"" << endl;
        newline(2);
    }

    void transformEquationMessage()
    {
        tabs(1);
        cout << " _______ _____            _   _  _____ ______ ____  _____  __  __            _   _   ______ ____  _    _      _______ _____ ____  _   _ " << endl;
        tabs(1);
        cout << "|__   __|  __ \\     /\\   | \\ | |/ ____|  ____/ __ \\|  __ \\|  \\/  |     /\\   | \\ | | |  ____/ __ \\| |  | |  /\\|__   __|_   _/ __ \\| \\ | |" << endl;
        tabs(1);
        cout << "   | |  | |__) |   /  \\  |  \\| | (___ | |__ | |  | | |__) | \\  / |    /  \\  |  \\| | | |__ | |  | | |  | | /  \\  | |    | || |  | |  \\| |" << endl;
        tabs(1);
        cout << "   | |  |  _  /   / /\\ \\ | . ` |\\___ \\|  __|| |  | |  _  /| |\\/| |   / /\\ \\ | . ` | |  __|| |  | | |  | |/ /\\ \\ | |    | || |  | | . ` |" << endl;
        tabs(1);
        cout << "   | |  | | \\ \\  / ____ \\| |\\  |____) | |   | |__| | | \\ \\| |  | |  / ____ \\| |\\  | | |___| |__| | |__| / ____ \\| |   _| || |__| | |\\  |" << endl;
        tabs(1);
        cout << "   |_|  |_|  \\_\\/_/    \\_\\_| \\_|_____/|_|    \\____/|_|  \\_\\_|  |_| /_/    \\_\\_| \\_| |______\\___\\_\\____/_/    \\_\\_|  |_____\\____/|_| \\_|" << endl;
        newline(2);
    }

    void displayFullForm(string number1, string sign, string number2, string sign2, string number3)
    {
        initNumberCodes();
        int count = 0;
        for (int i = 0; i < number1.size(); i++)
        {
            if (number1[i] == '-')
            {
                count += 9;
            }
            else if (number1[i] == '.')
            {
                count += 2;
            }
            else
            {
                int cur = number1[i] - '0';
                count += numberCodes[cur][0].size();
            }
        }
        count += 8;  // for x variable
        count += 32; // for tabs
        string s = "";
        for (int i = 0; i < count; i++)
        {
            s = " " + s;
        }
        cout << s << "2" << endl;
        int start = 0;
        bool floatFirst = false, floatSecond = false, floatThird = false;
        for (int j = 0; j < 6; j++)
        {
            tabs(4);
            if (number1[0] == '-')
            {
                if (j >= 2 && j <= 3)
                {
                    int index = j - 2;
                    cout << minus[index];
                }
                else
                {
                    cout << "        ";
                }
                start = 1;
            }
            for (int i = start; i < number1.size(); i++)
            {
                if (number1[i] == '.')
                {
                    if (j == 4)
                    {
                        cout << "__ ";
                    }
                    else if (j == 5)
                    {
                        cout << "|_|";
                    }
                    else
                    {
                        cout << "   ";
                    }
                }
                else
                {
                    int cur = number1[i] - '0';
                    cout << numberCodes[cur][j];
                }
            }
            cout << variable[j];
            cout << "       ";
            if (sign == "plus")
            {
                if (j >= 2 && j <= 4)
                {
                    int index = j - 2;
                    cout << plus[index];
                }
                else
                {
                    cout << "       ";
                }
            }
            else
            {
                if (j >= 2 && j <= 3)
                {
                    int index = j - 2;
                    cout << minus[index];
                }
                else
                {
                    cout << "        ";
                }
            }
            cout << "       ";
            for (int i = 0; i < number2.size(); i++)
            {
                int cur = number2[i] - '0';
                cout << numberCodes[cur][j];
            }
            cout << variable[j];
            cout << "       ";
            if (sign2 == "plus")
            {
                if (j >= 2 && j <= 4)
                {
                    int index = j - 2;
                    cout << plus[index];
                }
                else
                {
                    cout << "       ";
                }
            }
            else
            {
                if (j >= 2 && j <= 3)
                {
                    int index = j - 2;
                    cout << minus[index];
                }
                else
                {
                    cout << "        ";
                }
            }
            cout << "       ";
            for (int i = 0; i < number3.size(); i++)
            {
                int cur = number3[i] - '0';
                cout << numberCodes[cur][j];
            }
            cout << "       ";
            if (j >= 1 && j <= 4)
            {
                int index = j - 1;
                cout << equal[index];
            }
            else
            {
                cout << "        ";
            }
            cout << "       ";
            cout << numberCodes[0][j];
            cout << endl;
        }
        newline(2);
    }

    void displayShortenedForm(string number1, string sign, string number2, string number3) // number3 is the right part of the equation
    {
        initNumberCodes();
        int count = 0;
        for (int i = 0; i < number1.size(); i++)
        {
            if (number1[i] == '-')
            {
                count += 9;
            }
            else if (number1[i] == '.')
            {
                count += 2;
            }
            else
            {
                int cur = number1[i] - '0';
                count += numberCodes[cur][0].size();
            }
        }
        count += 8;  // for x variable
        count += 48; // for tabs
        string s = "";
        for (int i = 0; i < count; i++)
        {
            s = " " + s;
        }
        cout << s << "2" << endl;
        int start = 0, start2 = 0;
        bool floatFirst = false, floatSecond = false, floatThird = false;
        for (int j = 0; j < 6; j++)
        {
            tabs(6);
            if (number1[0] == '-')
            {
                if (j >= 2 && j <= 3)
                {
                    int index = j - 2;
                    cout << minus[index];
                }
                else
                {
                    cout << "        ";
                }
                start = 1;
            }
            for (int i = start; i < number1.size(); i++)
            {
                if (number1[i] == '.')
                {
                    if (j == 4)
                    {
                        cout << "__ ";
                    }
                    else if (j == 5)
                    {
                        cout << "|_|";
                    }
                    else
                    {
                        cout << "   ";
                    }
                }
                else
                {
                    int cur = number1[i] - '0';
                    cout << numberCodes[cur][j];
                }
            }
            cout << variable[j];
            cout << "       ";
            if (sign == "plus")
            {
                if (j >= 2 && j <= 4)
                {
                    int index = j - 2;
                    cout << plus[index];
                }
                else
                {
                    cout << "       ";
                }
            }
            else
            {
                if (j >= 2 && j <= 3)
                {
                    int index = j - 2;
                    cout << minus[index];
                }
                else
                {
                    cout << "        ";
                }
            }
            cout << "       ";
            for (int i = 0; i < number2.size(); i++)
            {
                int cur = number2[i] - '0';
                cout << numberCodes[cur][j];
            }
            cout << variable[j];
            cout << "       ";
            if (j >= 1 && j <= 4)
            {
                int index = j - 1;
                cout << equal[index];
            }
            else
            {
                cout << "        ";
            }
            cout << "      ";
            if (number3[0] == '-')
            {
                if (j >= 2 && j <= 3)
                {
                    int index = j - 2;
                    cout << minus[index];
                }
                else
                {
                    cout << "        ";
                }
                start2 = 1;
            }
            for (int i = start2; i < number3.size(); i++)
            {
                if (number3[i] == '.')
                {
                    if (j == 4)
                    {
                        cout << "__ ";
                    }
                    else if (j == 5)
                    {
                        cout << "|_|";
                    }
                    else
                    {
                        cout << "   ";
                    }
                }
                else
                {
                    int cur = number3[i] - '0';
                    cout << numberCodes[cur][j];
                }
            }
            cout << endl;
        }
        newline(2);
    }

    void displaySquaredVariableOnly(string number1, string number2) // number2 is the right part of the equation
    {
        initNumberCodes();
        int count = 0;
        for (int i = 0; i < number1.size(); i++)
        {
            if (number1[i] == '-')
            {
                count += 9;
            }
            else if (number1[i] == '.')
            {
                count += 2;
            }
            else
            {
                int cur = number1[i] - '0';
                count += numberCodes[cur][0].size();
            }
        }
        count += 8;  // for x variable
        count += 64; // for tabs
        string s = "";
        for (int i = 0; i < count; i++)
        {
            s = " " + s;
        }
        cout << s << "2" << endl;
        int start = 0;
        bool floatFirst = false, floatSecond = false, floatThird = false;
        for (int j = 0; j < 6; j++)
        {
            tabs(8);
            if (number1[0] == '-')
            {
                if (j >= 2 && j <= 3)
                {
                    int index = j - 2;
                    cout << minus[index];
                }
                else
                {
                    cout << "        ";
                }
                start = 1;
            }
            for (int i = start; i < number1.size(); i++)
            {
                if (number1[i] == '.')
                {
                    if (j == 4)
                    {
                        cout << "__ ";
                    }
                    else if (j == 5)
                    {
                        cout << "|_|";
                    }
                    else
                    {
                        cout << "   ";
                    }
                }
                else
                {
                    int cur = number1[i] - '0';
                    cout << numberCodes[cur][j];
                }
            }
            cout << variable[j];
            cout << "       ";
            if (j >= 1 && j <= 4)
            {
                int index = j - 1;
                cout << equal[index];
            }
            else
            {
                cout << "        ";
            }
            cout << "       ";
            for (int i = 0; i < number2.size(); i++)
            {
                int cur = number2[i] - '0';
                cout << numberCodes[cur][j];
            }
            cout << endl;
        }
        newline(2);
    }

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
            cout << numberCodes[2][i] << variable[i] << endl;
        }

        for (int i = 0; i <= 10; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << numberCodes[i][j].size() << endl;
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
        vector<string> zero = {"  ___  ", " / _ \\ ", "| | | |", "| | | |", "| |_| |", " \\___/ "};
        vector<string> one = {" __ ", "/_ |", " | |", " | |", " | |", " |_|"};
        vector<string> two = {" ___  ", "|__ \\ ", "   ) |", "  / / ", " / /_ ", "|____|"};
        vector<string> three = {" ____  ", "|___ \\ ", "  __) |", " |__ < ", " ___) |", "|____/ "};
        vector<string> four = {" _  _   ", "| || |  ", "| || |_ ", "|__   _|", "   | |  ", "   |_|  "};
        vector<string> five = {" _____ ", "| ____|", "| |__  ", "|___ \\ ", " ___) |", "|____/ "};
        vector<string> six = {"   __  ", "  / /  ", " / /_  ", "| '_ \\ ", "| (_) |", " \\___/ "};
        vector<string> seven = {" ______ ", "|____  |", "    / / ", "   / /  ", "  / /   ", " /_/    "};
        vector<string> eight = {"  ___  ", " / _ \\ ", "| (_) |", " > _ < ", "| (_) |", " \\___/ "};
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

    void setEquation(vector<double> params)
    {
        parameters = params;
        number1 = removeTrailingZeros(to_string(parameters[0]), 3);
        number2 = removeTrailingZeros(to_string(parameters[1]), 3);
        number3 = removeTrailingZeros(to_string(parameters[2]), 3);
        cout << number1 << " " << number2 << " " << number3 << endl;
    }

    void showEquation()
    {
        for (int i = 0; i < 3; i += 1)
        {
            cout << parameters[i] << endl;
        }
    }

    void leftSideRectangle(int n) {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cout << "|";
            } else {
                cout << " ";
            }
        }
    }

    void upperSideRectangle(int n) {
        for (int i = 0; i < n; i++) {
            cout << "_";
        }
    }

    void answerFirstType() {
        tabs(3);
        cout << "    _    _ _            _                                           __        _        __            _        __  __  " << endl;
        tabs(3);
        cout << "   / \\  | | |  __  __  (_)_ __     _ __ __ _ _ __   __ _  ___      / /       (_)_ __  / _|     _    (_)_ __  / _| \\ \\ " << endl;
        tabs(3);
        cout << "  / _ \\ | | |  \\ \\/ /  | | '_ \\   | '__/ _` | '_ \\ / _` |/ _ \\    | |   _____| | '_ \\| |_    _| |_  | | '_ \\| |_   | |" << endl;
        tabs(3);
        cout << " / ___ \\| | |   >  <   | | | | |  | | | (_| | | | | (_| |  __/    | |  |_____| | | | |  _|  |_   _| | | | | |  _|  | |" << endl;
        tabs(3);
        cout << "/_/   \\_\\_|_|  /_/\\_\\  |_|_| |_|  |_|  \\__,_|_| |_|\\__, |\\___|    | |        |_|_| |_|_|( )   |_|   |_|_| |_|_|    | |" << endl;
        tabs(3);
        cout << "                                                   |___/           \\_\\                  |/                        /_/ " << endl;
    }

    void solveFirstType()
    {

        /*cout << "all parameters equal to zero, the equation is:\n0*x^2 + 0*x + 0 = 0\n";
        cout << "the x can be any integer in range (-inf, +inf)\n";
        cout << "Answer: x = (-inf, +inf)\n"; */
        displayFullForm(number1, "plus", number2, "plus", number3);
        secondStepMessage();
        transformEquationMessage();
        displayShortenedForm(number1, "plus", number2, "0");
        thirdStepMessage();
        transformEquationMessage();
        displaySquaredVariableOnly(number1, "0");
        answerMessage();
        answerFirstType();
    }

    void solveSecondType()
    {
        cout << "the equation can be rewritten as:\n"
             << parameters[0] << "x^2 = 0\n";
        cout << "divide the right side of the equation by a:\nx^2 = 0/" << parameters[0] << "\n";
        cout << "the only solution is x = 0.\n";
        cout << "Answer: x = 0\n";
        string sign = "plus", sign2 = "plus";
        if (number2[0] == '-')
        {
            number2 = number2.substr(1);
            sign = "minus";
        }
        if (number3[0] == '-')
        {
            number3 = number3.substr(1);
            sign2 = "minus";
        }
        // cout << number1 << endl;
        cout << number1 << endl;
        displayFullForm(number1, sign, number2, sign2, number3);
    }

    void solveThirdType()
    {
        cout << "The equation can be rewritten as:\n " << parameters[2] << "=0\n";
        cout << "The expression is not correct, because " << parameters[2] << "!=0\n";
        cout << "That means the given parameters are incorrect and the solution does not exist.\n";
        cout << "Answer: the solution does not exist\n";
        string sign = "plus", sign2 = "plus";
        if (number2[0] == '-')
        {
            number2 = number2.substr(1);
            sign = "minus";
        }
        if (number3[0] == '-')
        {
            number3 = number3.substr(1);
            sign2 = "minus";
        }
        displayFullForm(number1, sign, number2, sign2, number3);
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
        string sign = "plus", sign2 = "plus";
        if (number2[0] == '-')
        {
            number2 = number2.substr(1);
            sign = "minus";
        }
        if (number3[0] == '-')
        {
            number3 = number3.substr(1);
            sign2 = "minus";
        }
        displayFullForm(number1, sign, number2, sign2, number3);
    }

    void solveFifthType()
    {
        cout << "Rewrite the equation as\n"
             << parameters[1] << "x + " << parameters[2] << " = 0\n";
        cout << "Shift the independent variables to the right side of the equation:\n"
             << parameters[1] << "x = " << -1 * parameters[2] << endl;
        cout << "find the x:\n x = " << -1 * parameters[2] << " / " << parameters[1] << " = " << -1 * parameters[2] / parameters[1] << endl;
        cout << "Answer: x = " << -1 * parameters[2] / parameters[1] << endl;
        string sign = "plus", sign2 = "plus";
        if (number2[0] == '-')
        {
            number2 = number2.substr(1);
            sign = "minus";
        }
        if (number3[0] == '-')
        {
            number3 = number3.substr(1);
            sign2 = "minus";
        }
        displayFullForm(number1, sign, number2, sign2, number3);
    }

    void solveSixthType()
    {
        cout << "Rewrite the equation as\n"
             << parameters[0] << "x^2 + " << parameters[1] << "x + " << parameters[2] << " = 0\n";
        cout << "Find the Discriminant: \n";
        int D = parameters[1] * parameters[1] - 4 * parameters[0] * parameters[2];
        cout << "D = " << parameters[1] << "^2 - " << 4 << "*" << parameters[0] << "*" << parameters[2] << endl;
        string sign = "plus", sign2 = "plus";
        if (number2[0] == '-')
        {
            number2 = number2.substr(1);
            sign = "minus";
        }
        if (number3[0] == '-')
        {
            number3 = number3.substr(1);
            sign2 = "minus";
        }
        displayFullForm(number1, sign, number2, sign2, number3);
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
        string sign = "plus", sign2 = "plus";
        if (number2[0] == '-')
        {
            number2 = number2.substr(1);
            sign = "minus";
        }
        if (number3[0] == '-')
        {
            number3 = number3.substr(1);
            sign2 = "minus";
        }
        displayFullForm(number1, sign, number2, sign2, number3);
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
        string sign = "plus", sign2 = "plus";
        if (number2[0] == '-')
        {
            number2 = number2.substr(1);
            sign = "minus";
        }
        if (number3[0] == '-')
        {
            number3 = number3.substr(1);
            sign2 = "minus";
        }
        displayFullForm(number1, sign, number2, sign2, number3);
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
        solutionMessage();
        firstStepMessage();

        initialEquationMessage();
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
    vector<double> nums = {-999, -999, -999};

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
                double num = 0;
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
