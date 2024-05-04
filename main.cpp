#include <iostream>
#include <vector>
#include <Windows.h>
#include <cmath>
#include <windows.h>

bool russian = false;

using namespace std;

class Instructions
{
private:
    vector<string> systemInstructions = {"Enter a: ", "Enter b: ", "Enter c: "};

public:
    void formatOutputTable(string operation, string command)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << "\t\t\t\t";
            int j = 0;
            while (j < 60)
            {
                if (j == 0 || j == 35 || j == 59)
                {
                    cout << "|";
                    j++;
                    continue;
                }
                if (i == 3)
                {
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
                else
                {
                    cout << " ";
                    j++;
                }
            }
            cout << endl;
        }
        cout << "\t\t\t\t";
        showCharDivider(60, '~');
    }

    void showCharDivider(int n, char ch)
    {
        for (int i = 0; i < n; i++)
        {
            (i == n - 1) ? cout << ch << '\n' : cout << ch;
        }
    }

    void showOnStart()
    {
        cout << "\t\t";
        showCharDivider(90, '-');
        if (russian)
        {
            cout << "\t\t|    пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ. пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ:     |" << endl;
        }
        else
        {
            cout << "\t\t|    Welcome to the Quadratic Equation Solver. Here is the list of available commands     |" << endl;
        }
        cout << "\t\t";
        showCharDivider(90, '-');
        cout << "\t\t\t\t";
        showCharDivider(60, '~');
        if (russian)
        {
            formatOutputTable("пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ", "пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ");
            formatOutputTable("пїЅпїЅпїЅпїЅпїЅпїЅ", "HELP");
            formatOutputTable("пїЅпїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ", "QUIT");
            formatOutputTable("пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ", "EQUATION");
            formatOutputTable("пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ", "INFO");
            formatOutputTable("пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ", "SWITCH");
            return;
        }
        formatOutputTable("OPERATION", "COMMAND");
        formatOutputTable("Show help", "HELP");
        formatOutputTable("Exit the program", "QUIT");
        formatOutputTable("Solve equation", "EQUATION");
        formatOutputTable("Equation info", "INFO");
        formatOutputTable("Switch language", "SWITCH");
    }

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
                if (i == 3)
                {
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
        showCharDivider(140, '~');
    }

    void formatEquationColumnHeader(bool lang)
    {
        for (int i = 0; i < 6; i++)
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
                if (j == 6 && i == 3)
                {
                    lang ? cout << "ТИП" : cout << "TYPE";
                    lang ? j += 3 : j += 4;
                    continue;
                }
                if (j == 22 && i == 3)
                {
                    lang ? cout << "ПАРАМЕТРЫ" : cout << "PARAMETERS";
                    lang ? j += 9 : j += 10;
                    continue;
                }
                if (j == 53 && i == 3)
                {
                    lang ? cout << "ФОРМА" : cout << "FORM";
                    lang ? j += 5 : j += 4;
                    continue;
                }
                if (j == 85 && i == 3)
                {
                    lang ? cout << "РЕШЕНИЕ" : cout << "SOLUTION";
                    lang ? j += 7 : j += 8;
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
        showCharDivider(140, '~');
    }

    void showEquationInfo()
    {
        if (russian)
        {
            cout << "\n\nКвадратное уравнение - это уравнение следующего вида:\n\n";
            cout << "\t\t\t\t\tax^2 + bx + c = 0\n\n";
            cout << "В таблице ниже представлены 8 типов квадратных уравнений...\n\n\n";
            cout << "Таблица 1. Типы квадратных уравнений\n";
        }
        else
        {
            cout << "\n\nQuadratic equation is an equation that can be rearranged in standard form as:\n\n ";
            cout << "\t\t\t\t\tax^2 + bx + c = 0\n\n";
            cout << "The table below represents eight types of existing quadratic equations...\n\n\n";
            cout << "Table 1. Types of Quadratic Equations\n";
        }
        showCharDivider(140, '~');
        formatEquationColumnHeader(russian);
        if (russian)
        {
            formatEquationTable("1", "a=0,b=0,c=0", "0 * x^2 + 0 * x + 0 = 0", "все x в промежутке(-inf, +inf)");
            formatEquationTable("2", "a != 0, b = 0, c = 0", "a * x^2 = 0", "единственное решение x = 0");
            formatEquationTable("3", "c = 0", "form doesn't exist", "уравнение записано неверно, потому что дан только один параметр");
            formatEquationTable("4", "a != 0, b = 0, c != 0", "a * x^2 + c = 0", "x^2 = -c / a brесли -c / a < 0, то решений нет brесли -c / a > 0: br    x1 = sqrt(-c/a), x2 = -sqrt(-c/a)");
            formatEquationTable("5", "a = 0, b != 0, c != 0", "bx + c = 0", "x = -c / b");
            formatEquationTable("6", "a != 0, b != 0, c != 0", "a * x^2 + bx + c = 0", "Найдем дискриминант: D = b^2 - 4ac. br1. если D > 0 x = (-b +/- sqrt(b^2 - 4ac) / 2a); br2. если D = 0 x = -b / 2a; если D < 0 решений brнет");
            formatEquationTable("7", "a = 0, b != 0, c = 0", "bx = 0", "единственное решение x = 0");
            formatEquationTable("8", "a != 0, b != 0, c = 0", "ax^2 + bx = 0", "перепишем уравнение: br           x(ax + b) = 0. brx1 = 0, x2 = -b/a");
            return;
        }
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
    string number1, number2, number3;
    double num1, num2, num3;
    string sign = "plus", sign2 = "plus";

    string removeTrailingZeros(string number, int maxLen)
    {
        string current = number.substr(0, number.find_last_not_of('0') + 1);
        if (number.find('.') == current.size() - 1)
        {
            current = current.substr(0, current.size() - 1);
        }
        return current;
    }

public:
    vector<vector<string>> numberCodes;
    vector<string> variable = {"\\     /", " \\   / ", "  \\./  ", "  / \\  ", " /   \\ ", "/     \\"};
    vector<string> multiply = {"\\/", "/\\"};
    vector<string> minus = {" ______ ", "|______|"};
    vector<string> plus = {" _| |_ ", "|_   _|", "  |_|  "};
    vector<string> equal = {" ______ ", "|______|", " ______ ", "|______|"};
    vector<string> division = {"\\      ", " \\     ", "  \\    ", "   \\   ", "    \\  ", "     \\ ", "      \\"};
    vector<string> radical = {"               __________________________", "              /", "             / ", "            /  ", "           /   ", "______    /    ", "      \\  /     ", "       \\/      "};
    vector<string> lessThan = {"    __", "   / /", "  / / ", " < <  ", "  \\ \\ ", "   \\_\\"};
    vector<string> hence = {"             __   ", " ______ _____\\ \\  ", "|______|______\\ \\ ", " ______ ______ > >", "|______|______/ / ", "             /_/  "};
    vector<string> plusMinus = {"   _    ", " _| |_  ", "|_   _| ", " _|_|__ ", "|______|"};
    vector<string> D = {" _____  ", "|  __ \\ ", "| |  | |", "| |  | |", "| |__| |", "|_____/ "};
    vector<string> b = {" _     ", "| |    ", "| |__  ", "| '_ \\ ", "| |_) |", "|_.__/ "};
    vector<string> a = {"       ", " __ _  ", " / _` |", "| (_| |", " \\__,_|", "       "};
    vector<string> leftParenthesses = {" __ ", " / /", "| | ", "| | ", "| | ", "| | ", "| | ", " \\_\\"};
    vector<string> rightParenthesses = {"__  ", "\\ \\ ", " | |", " | |", " | |", " | |", " | |", "/_/ "};

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
        cout << "\t\t\t\t\t\t\t  _____  ____  _     _    _ _______ _____ ____  _   _ " << endl;
        cout << "\t\t\t\t\t\t\t / ____|/ __ \\| |   | |  | |__   __|_   _/ __ \\| \\ | |" << endl;
        cout << "\t\t\t\t\t\t\t| (___ | |  | | |   | |  | |  | |    | || |  | |  \\| |" << endl;
        cout << "\t\t\t\t\t\t\t \\___ \\| |  | | |   | |  | |  | |    | || |  | | . ` |" << endl;
        cout << "\t\t\t\t\t\t\t ____) | |__| | |___| |__| |  | |   _| || |__| | |\\  |" << endl;
        cout << "\t\t\t\t\t\t\t|_____/ \\____/|______\\____/   |_|  |_____\\____/|_| \\_|" << endl;
        newline(1);
    }

    void initialEquationMessage()
    {
        cout << "\t _______  _              _         _  _    _         _                              _    _                  " << endl;
        cout << "\t|__   __|| |            (_)       (_)| |  (_)       | |                            | |  (_)               _ " << endl;
        cout << "\t   | |   | |__    ___    _  _ __   _ | |_  _   __ _ | |   ___   __ _  _   _   __ _ | |_  _   ___   _ __  (_)" << endl;
        cout << "\t   | |   | '_ \\  / _ \\  | || '_ \\ | || __|| | / _` || |  / _ \\ / _` || | | | / _` || __|| | / _ \\ | '_ \\    " << endl;
        cout << "\t   | |   | | | ||  __/ |  || | | || || |_ | || (_| || | |  __/| (_| || |_| || (_| || |_ | || (_) || | | | _ " << endl;
        cout << "\t   |_|   |_| |_| \\___|  |_||_| |_||_| \\__||_| \\__,_||_|  \\___| \\__, | \\__,_| \\__,_| \\__||_| \\___/ |_| |_|(_)" << endl;
        cout << "\t                                                                 | |                                       " << endl;
        cout << "\t                                                                 |_|                                       " << endl;
        newline(1);
    }

    void showStep(int n)
    {
        initNumberCodes();
        vector<string> stepArray = {"  _____ _______ ______ _____  ", " / ____|__   __|  ____|  __ \\ ", "| (___    | |  | |__  | |__) |", " \\___ \\   | |  |  __| |  ___/ ", " ____) |  | |  | |____| |     ", "|_____/   |_|  |______|_|     "};
        for (int i = 0; i < 6; i++)
        {
            cout << stepArray[i] << "   " << numberCodes[n][i] << endl;
        }
    }

    void answerMessage()
    {
        cout << "          _   _  _______          ________ _____  " << endl;
        cout << "    /\\   | \\ | |/ ____\\ \\        / /  ____|  __ \\ " << endl;
        cout << "   /  \\  |  \\| | (___  \\ \\  /\\  / /| |__  | |__) |" << endl;
        cout << "  / /\\ \\ | . ` |\\___ \\  \\ \\/  \\/ / |  __| |  _  / " << endl;
        cout << " / ____ \\| |\\  |____) |  \\  /\\  /  | |____| | \\ \\ " << endl;
        cout << "/_/    \\_\\_| \\_|_____/    \\/  \\/   |______|_|  \\_\"" << endl;
        newline(2);
    }

    void noSolution(int tabsNumber)
    {
        cout << "\t _   _  ____     _____  ____  _     _    _ _______ _____ ____  _   _ " << endl;
        cout << "\t| \\ | |/ __ \\   / ____|/ __ \\| |   | |  | |__   __|_   _/ __ \\| \\ | |" << endl;
        cout << "\t|  \\| | |  | | | (___ | |  | | |   | |  | |  | |    | || |  | |  \\| |" << endl;
        cout << "\t| . ` | |  | |  \\___ \\| |  | | |   | |  | |  | |    | || |  | | . ` |" << endl;
        cout << "\t| |\\  | |__| |  ____) | |__| | |___| |__| |  | |   _| || |__| | |\\  |" << endl;
        cout << "\t|_| \\_|\\____/  |_____/ \\____/|______\\____/   |_|  |_____\\____/|_| \\_|" << endl;
    }

    void transformEquationMessage()
    {
        cout << "\t _______ _____            _   _  _____ ______ ____  _____  __  __            _   _   ______ ____  _    _      _______ _____ ____  _   _ " << endl;
        cout << "\t|__   __|  __ \\     /\\   | \\ | |/ ____|  ____/ __ \\|  __ \\|  \\/  |     /\\   | \\ | | |  ____/ __ \\| |  | |  /\\|__   __|_   _/ __ \\| \\ | |" << endl;
        cout << "\t   | |  | |__) |   /  \\  |  \\| | (___ | |__ | |  | | |__) | \\  / |    /  \\  |  \\| | | |__ | |  | | |  | | /  \\  | |    | || |  | |  \\| |" << endl;
        cout << "\t   | |  |  _  /   / /\\ \\ | . ` |\\___ \\|  __|| |  | |  _  /| |\\/| |   / /\\ \\ | . ` | |  __|| |  | | |  | |/ /\\ \\ | |    | || |  | | . ` |" << endl;
        cout << "\t   | |  | | \\ \\  / ____ \\| |\\  |____) | |   | |__| | | \\ \\| |  | |  / ____ \\| |\\  | | |___| |__| | |__| / ____ \\| |   _| || |__| | |\\  |" << endl;
        cout << "\t   |_|  |_|  \\_\\/_/    \\_\\_| \\_|_____/|_|    \\____/|_|  \\_\\_|  |_| /_/    \\_\\_| \\_| |______\\___\\_\\____/_/    \\_\\_|  |_____\\____/|_| \\_|" << endl;
        newline(2);
    }

    void displaySimpleDivision(string number1, string number2, bool squared)
    {
        initNumberCodes();
        if (squared)
        {
            int count = 48;
            string s = "";
            for (int i = 0; i < count; i++)
            {
                s = " " + s;
            }
            cout << s << "2" << endl;
        }
        for (int j = 0; j < 6; j++)
        {
            tabs(5);
            cout << variable[j] << "    ";
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
            numberShow(number1, j, true);
            cout << "      " << division[j] << "  ";
            numberShow(number2, j, true);
            cout << endl;
        }
    }

    void numberShow(string number1, int j, bool isMinus)
    {
        initNumberCodes();
        int start = 0;
        if (isMinus)
        {
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
    }

    void equalShow(int j)
    {
        if (j >= 1 && j <= 4)
        {
            int index = j - 1;
            cout << equal[index];
        }
        else
        {
            cout << "        ";
        }
    }

    void minusShow(int j)
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

    void plusShow(int j)
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

    int increaseCount(string number, int param1, int param2, int param3) {
        int count = 0;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == '-') {
                count += param1;
            } else if (number[i] == '.') {
                count += param2;
            } else {
                count += param3;
            }
        }
        return count;
    }

    void stepBlock(int stepNumber) {
        showStep(stepNumber);
        transformEquationMessage();
    }

    void displayPowerOfTwo(int count)
    {
        for (int i = 0; i < count; i++)
        {
            (i == count - 1) ? cout << " 2\n" : cout << " ";
        }
    }

    void displayFullForm(string number1, string sign, string number2, string sign2, string number3, bool full, bool square)
    {
        initNumberCodes();
        int count = 40;
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
        displayPowerOfTwo(count);
        for (int j = 0; j < 6; j++)
        {
            tabs(4);
            numberShow(number1, j, true);
            cout << variable[j] << "       ";
            if (square) {  // form: number1 * x^2 = number2
                equalShow(j);
                (number2[0] == '-') ? numberShow(number2, j, true) : numberShow(number2, j, false);
                cout << endl;
                continue;
            }
            (sign == "plus") ? plusShow(j) : minusShow(j);
            cout << "       ";
            numberShow(number2, j, false);
            cout << variable[j] << "       ";
            if (!full) {
                equalShow(j);
                (number3[0] == '-') ? numberShow(number3, j, true) : numberShow(number3, j, false);
                cout << endl;
                continue;
            }
            (sign2 == "plus") ? plusShow(j) : minusShow(j);
            cout << "       ";
            numberShow(number3, j, false);
            cout << "       ";
            equalShow(j);
            cout << "       " << numberCodes[0][j] << endl;
        }
        newline(2);
    }

    void displayAnswer(string number1, string order)
    { // x1 = answer (order = 1), x2 = answer(order = 2)
        initNumberCodes();
        for (int j = 0; j < 6; j++)
        {
            tabs(5);
            cout << variable[j] << "    ";
            equalShow(j);
            cout << "    ";
            numberShow(number1, j, true);
            cout << endl;
        }
        for (int i = 0; i < 47; i++)
        {
            cout << " ";
        }
        cout << order << endl;
    }

    void discriminantFind(string number1, string number2, string number3)
    { // number1: b; number2: a, number3: c
        newline(1);
        initNumberCodes();
        int count = 64 + increaseCount(number1, 9, 5, 6);
        displayPowerOfTwo(count);
        for (int j = 0; j < 6; j++)
        {
            tabs(5);
            cout << D[j] << "    ";
            equalShow(j);
            cout << "    ";
            numberShow(number1, j, true);
            cout << "   ";
            minusShow(j);
            cout << "    " << numberCodes[4][j] << "   ";
            if (j == 2 || j == 3)
            {
                cout << multiply[j - 2] << "   ";
            }
            else
            {
                cout << "     ";
            }
            numberShow(number2, j, true);
            cout << "    ";
            if (j == 2 || j == 3)
            {
                cout << multiply[j - 2] << "   ";
            }
            else
            {
                cout << "     ";
            }
            numberShow(number3, j, true);
            cout << endl;
        }
    }

    void discriminantEqual(string number1)
    {
        initNumberCodes();
        for (int j = 0; j < 6; j++)
        {
            tabs(5);
            cout << D[j] << "    ";
            equalShow(j);
            cout << "    ";
            numberShow(number1, j, true);
            cout << endl;
        }
    }

    void displaySqrt(string number1)
    {
        initNumberCodes();
        for (int i = 0; i < 71; i++)
        {
            cout << " ";
        }
        cout << radical[0] << endl;
        for (int j = 0; j < 6; j++)
        {
            tabs(5);
            cout << variable[j] << "    ";
            equalShow(j);
            cout << "    ";
            (j < 5) ? cout << plusMinus[j] : cout << "        ";
            cout << " " << radical[j + 1] << " ";
            numberShow(number1, j, true);
            cout << endl;
        }
        for (int i = 0; i < 73; i++)
        {
            (i == 72) ? cout << " " << radical[7] << "\n" : cout << " ";
        }
    }

    void displayDiscriminantSqrt()
    {
        cout << "                          " << leftParenthesses[0];
        for (int i = 0; i < 34; i++)
        {
            (i == 33) ? cout << " " << radical[0] << "       " << rightParenthesses[0] << "\n" : cout << " ";
        }
        for (int j = 0; j < 6; j++)
        {
            cout << variable[j] << "      ";
            equalShow(j);
            cout << "     " << leftParenthesses[j + 1] << "    ";
            minusShow(j);
            cout << " " << b[j] << "    ";
            (j < 5) ? cout << plusMinus[j] : cout << "        ";
            cout << "  " << radical[j + 1] << "  " << D[j] << "                   " << rightParenthesses[j + 1] << "     ";
            cout << division[j] << "     " << numberCodes[2][j] << a[j] << endl;
        }
        cout << "                          " << leftParenthesses[7];
        for (int i = 0; i < 34; i++)
        {
            (i == 33) ? cout << " " << radical[7] : cout << " ";
        }
        for (int i = 0; i < 30; i++)
        {
            (i == 29) ? cout << " " << rightParenthesses[7] << "\n" : cout << " ";
        }
    }

    void displayDiscriminantSqrtNumbers(string number1, string number2, string number3, string type, string sign)
    {
        cout << "                       " << leftParenthesses[0];
        int count = 18 + increaseCount(number1, 7, 5, 6);
        for (int i = 0; i < count + 1; i++)
        {
            (i == count - 1) ? cout << radical[0] << "       " << rightParenthesses[0] << "\n" : cout << " ";
        }
        for (int j = 0; j < 6; j++)
        {
            cout << variable[j] << "      ";
            equalShow(j);
            cout << "     " << leftParenthesses[j + 1] << "    ";
            numberShow(number1, j, true);
            cout << "     ";
            (sign == "plus") ? plusShow(j) : minusShow(j);
            cout << radical[j + 1] << "    ";
            int len = increaseCount(number2, 9, 5, 6);
            numberShow(number2, j, true);
            for (int i = 0; i < 26 - len; i++)
            {
                cout << " ";
            }
            cout << rightParenthesses[j + 1] << "   " << division[j];
            numberShow(number3, j, true);
            cout << endl;
        }
        cout << "       " << type << "                   " << leftParenthesses[7];
        for (int i = 0; i < count - 1; i++)
        {
            (i == count - 2) ? cout << radical[7] : cout << " ";
        }
        for (int i = 0; i <= 30; i++)
        {
            (i == 30) ? cout << rightParenthesses[7] << "\n" : cout << " ";
        }
    }

    void displayVariable(string number1)
    { // used for answer specific types
        initNumberCodes();
        for (int j = 0; j < 6; j++)
        {
            tabs(5);
            cout << variable[j] << "    ";
            equalShow(j);
            cout << "      ";
            numberShow(number1, j, true);
            cout << endl;
        }
    }

    void displayLessThan(string number1)
    {
        for (int j = 0; j < 6; j++)
        {
            tabs(5);
            numberShow(number1, j, true);
            cout << "   " << lessThan[j] << "    " << numberCodes[0][j] << "        " << hence[j] << endl;
        }
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
        numberCodes = {zero, one, two, three, four, five, six, seven, eight, nine};
    }

    void setEquation(vector<double> params)
    {
        parameters = params;
        number1 = removeTrailingZeros(to_string(parameters[0]), 3);
        number2 = removeTrailingZeros(to_string(parameters[1]), 3);
        number3 = removeTrailingZeros(to_string(parameters[2]), 3);
        num1 = params[0], num2 = params[1], num3 = params[2];
    }
    
    void parenthesTransform(string number1, string sign, string number2)
    {
        for (int j = 0; j < 6; j++)
        {
            tabs(4);
            cout << variable[j] << "   " << leftParenthesses[j + 1] << "  ";
            numberShow(number1, j, true);
            cout << " " << variable[j] << "     ";
            (sign == "plus") ? plusShow(j) : minusShow(j);
            cout << "      ";
            numberShow(number2, j, false);
            cout << "  " << rightParenthesses[j + 1] << "     ";
            equalShow(j);
            cout << "  " << numberCodes[0][j] << endl;
        }
        int count = 10;
        tabs(4);
        for (int i = 0; i < count; i++)
        {
            cout << " ";
        }
        cout << leftParenthesses[7];
        count = 3 + increaseCount(number1, 7, 4, 6);
        (sign == "plus") ? count += 29 : count += 30;
        count += increaseCount(number2, 7, 4, 6);
        for (int i = 0; i < count + 3; i++)
        {
            cout << " ";
        }
        cout << rightParenthesses[7] << endl;
    }

    void discriminantZeroFormula()
    {
        for (int j = 0; j < 6; j++)
        {
            tabs(5);
            cout << variable[j] << "    ";
            equalShow(j);
            cout << "    ";
            minusShow(j);
            cout << "     " << b[j] << "     " << division[j] << "    " << numberCodes[2][j] << a[j] << endl;
        }
    }

    void answerFirstType()
    {
        cout << "\t\t\t    _    _ _            _                                           __        _        __            _        __  __  " << endl;
        cout << "\t\t\t   / \\  | | |  __  __  (_)_ __     _ __ __ _ _ __   __ _  ___      / /       (_)_ __  / _|     _    (_)_ __  / _| \\ \\ " << endl;
        cout << "\t\t\t  / _ \\ | | |  \\ \\/ /  | | '_ \\   | '__/ _` | '_ \\ / _` |/ _ \\    | |   _____| | '_ \\| |_    _| |_  | | '_ \\| |_   | |" << endl;
        cout << "\t\t\t / ___ \\| | |   >  <   | | | | |  | | | (_| | | | | (_| |  __/    | |  |_____| | | | |  _|  |_   _| | | | | |  _|  | |" << endl;
        cout << "\t\t\t/_/   \\_\\_|_|  /_/\\_\\  |_|_| |_|  |_|  \\__,_|_| |_|\\__, |\\___|    | |        |_|_| |_|_|( )   |_|   |_|_| |_|_|    | |" << endl;
        cout << "\t\t\t                                                   |___/           \\_\\                  |/                        /_/ " << endl;
    }

    void findDiscriminantMessage()
    {
        cout << " ______ _           _   _   _            _____  _               _           _                   _   " << endl;
        cout << "|  ____(_)         | | | | | |          |  __ \\(_)             (_)         (_)                 | |  " << endl;
        cout << "| |__   _ _ __   __| | | |_| |__   ___  | |  | |_ ___  ___ _ __ _ _ __ ___  _ _ __   __ _ _ __ | |_ " << endl;
        cout << "|  __| | | '_ \\ / _` | | __| '_ \\ / _ \\ | |  | | / __|/ __| '__| | '_ ` _ \\| | '_ \\ / _` | '_ \\| __|" << endl;
        cout << "| |    | | | | | (_| | | |_| | | |  __/ | |__| | \\__ \\ (__| |  | | | | | | | | | | | (_| | | | | |_ " << endl;
        cout << "|_|    |_|_| |_|\\__,_|  \\__|_| |_|\\___| |_____/|_|___/\\___|_|  |_|_| |_| |_|_|_| |_|\\__,_|_| |_|\\__|" << endl;
    }

    void solveFirstType()
    {
        displayFullForm(number1, "plus", number2, "plus", number3, true, false);
        stepBlock(2);
        displayFullForm(number1, "plus", number2, "plus", "0", false, false);
        stepBlock(3);
        displayFullForm(number1, "plus", "0", "plus", "0", false, true);
        answerMessage();
        answerFirstType();
    }

    void solveSecondType()
    {
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
        displayFullForm(number1, sign, number2, sign2, number3, true, false);
        stepBlock(2);
        displayFullForm(number1, sign, number2, sign, "0", false, false);
        stepBlock(3);
        displayFullForm(number1, "plus", "0", "plus", "0", false, true);
        stepBlock(4);
        displaySimpleDivision("0", number1, true);
        newline(1);
        displayFullForm("1", "plus", "0", "plus", "0", false, true);
        showStep(5);
        displaySqrt("0");
        answerMessage();
        displayVariable("0");
    }

    void solveThirdType()
    {
        answerMessage();
        noSolution(1);
    }

    void solveFourthType()
    {
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
        num3 = -1 * num3;
        displayFullForm(number1, sign, number2, sign2, number3, true, false);
        stepBlock(2);
        number3 = removeTrailingZeros(to_string(num3), 3);
        displayFullForm(number1, sign, number2, sign, number3, false, false);
        showStep(3);
        displaySimpleDivision(number3, number1, true);
        double result = num3 / num1;
        string res = removeTrailingZeros(to_string(result), 3);
        newline(1);
        displayFullForm("1", "plus", res, "plus", "0", false, true);
        showStep(4);
        if (result < 0)
        {
            displayLessThan(res);
            noSolution(4);
            newline(2);
            answerMessage();
            noSolution(1);
        }
        else
        {
            displaySqrt(res);
            answerMessage();
            double x1 = sqrt(result), x2 = -x1;
            string x1Str = removeTrailingZeros(to_string(x1), 3), x2Str = removeTrailingZeros(to_string(x2), 3);
            displayAnswer(x1Str, "1");
            newline(1);
            displayAnswer(x2Str, "2");
        }
    }

    void displayVariableNumber(string number1, string number2)
    {
        initNumberCodes();
        for (int j = 0; j < 6; j++)
        {
            tabs(5);
            numberShow(number1, j, true);
            cout << variable[j] << "    ";
            equalShow(j);
            cout << "     ";
            numberShow(number2, j, true);
            cout << endl;
        }
    }

    void solveFifthType()
    {
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
        displayFullForm(number1, sign, number2, sign2, number3, true, false);
        stepBlock(1);
        num3 = -1 * num3, number3 = removeTrailingZeros(to_string(num3), 3);
        displayVariableNumber(number2, number3);
        showStep(2);
        displaySimpleDivision(number3, number2, false);
        newline(1);
        double x1 = num3 / num2;
        string x1Str = removeTrailingZeros(to_string(x1), 3);
        displayAnswer(x1Str, "1");
        answerMessage();
        displayAnswer(x1Str, "1");
    }

    void solveSixthType()
    {
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
        displayFullForm(number1, sign, number2, sign2, number3, true, false);
        showStep(2);
        findDiscriminantMessage();
        number2 = removeTrailingZeros(to_string(num2), 3), number3 = removeTrailingZeros(to_string(num3), 3);
        discriminantFind(number2, number1, number3);
        double dValue = num2 * num2 - 4 * num1 * num3;
        string dStr = removeTrailingZeros(to_string(dValue), 3);
        discriminantEqual(dStr);
        showStep(3);
        num2 = -1 * num2, num2 *= 2;
        number2 = removeTrailingZeros(to_string(num2), 3), number1 = removeTrailingZeros(to_string(num1), 3);
        if (dValue < 0)
        {
            displayLessThan(dStr);
            noSolution(4);
            newline(2);
            answerMessage();
            noSolution(1);
        }
        else if (dValue == 0)
        {
            discriminantZeroFormula();
            newline(1);
            displaySimpleDivision(number2, number1, false);
            double result = num2 / num1;
            string xStr = removeTrailingZeros(to_string(result), 3);
            newline(1);
            displayVariable(xStr);
            answerMessage();
            displayVariable(xStr);
        }
        else
        {
            displayDiscriminantSqrt();
            showStep(4);
            displayDiscriminantSqrtNumbers(number2, dStr, number1, "1", "plus");
            newline(1);
            displayDiscriminantSqrtNumbers(number2, dStr, number1, "2", "minus");
            double x1 = (num2 + sqrt(dValue)) / num1, x2 = (num2 - sqrt(dValue)) / num2;
            string x1Str = removeTrailingZeros(to_string(x1), 3), x2Str = removeTrailingZeros(to_string(x2), 3);
            answerMessage();
            displayAnswer(x1Str, "1");
            newline(1);
            displayAnswer(x2Str, "2");
        }
    }

    void solveSeventhType()
    {
        if (number2[0] == '-')
        {
            sign = "minus";
            number2 = number2.substr(1);
        }
        displayFullForm(number1, sign, number2, "plus", number3, true, false);
        showStep(2);
        displayVariableNumber(number2, "0");
        newline(1);
        displaySimpleDivision("0", number2, false);
        newline(1);
        displayVariable("0");
        answerMessage();
        displayVariable("0");
    }

    void solveEigthType()
    {
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
        displayFullForm(number1, sign, number2, sign2, number3, true, false);
        stepBlock(2);
        parenthesTransform(number1, sign, number2);
        showStep(3);
        displayAnswer("0", "1");
        newline(1);
        num2 *= -1, number2 = removeTrailingZeros(to_string(num2), 3);
        displayVariableNumber(number1, number2);
        showStep(4);
        displaySimpleDivision(number2, number1, false);
        newline(1);
        double x2 = num2 / num1;
        string x1Str = removeTrailingZeros(to_string(x2), 3);
        displayAnswer(x1Str, "2");
        answerMessage();
        displayAnswer("0", "1");
        newline(1);
        displayAnswer(x1Str, "2");
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
        showStep(1);
        if (type != 3)
        {
            initialEquationMessage();
        }
        switch (type)
        {
        case 1:
            solveFirstType();
            break;
        case 2:
            solveSecondType();
            break;
        case 3:
            solveThirdType();
            break;
        case 4:
            solveFourthType();
            break;
        case 5:
            solveFifthType();
            break;
        case 6:
            solveSixthType();
            break;
        case 7:
            solveSeventhType();
            break;
        case 8:
            solveEigthType();
            break;
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
                    while (!(cin >> num))
                    {
                        cout << "ERROR\n";
                        helpInstruction(i);
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
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
