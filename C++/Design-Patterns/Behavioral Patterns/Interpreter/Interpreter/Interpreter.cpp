// Interpreter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>

using namespace std;

class Thousand;
class Hundred;
class Ten;
class One;

class RNInterpreter
{
public:
    RNInterpreter(); // ctor for client
    RNInterpreter(int) {}
    // ctor for subclasses, avoids infinite loop
    int interpret(char*); // interpret() for client
    virtual void interpret(char* input, int& total)
    {
        // for internal use
        int index;
        index = 0;
        if (!strncmp(input, nine(), 2))
        {
            total += 9 * multiplier();
            index += 2;
        }
        else if (!strncmp(input, four(), 2))
        {
            total += 4 * multiplier();
            index += 2;
        }
        else
        {
            if (input[0] == five())
            {
                total += 5 * multiplier();
                index = 1;
            }
            else
                index = 0;
            for (int end = index + 3; index < end; index++)
                if (input[index] == one())
                    total += 1 * multiplier();
                else
                    break;
        }
        strcpy(input, &(input[index]));
    } // remove leading chars processed
protected:
    // cannot be pure virtual because client asks for instance
    virtual char one() { return '0'; }
    virtual const char* four() { return "0"; }
    virtual char five() { return '0'; }
    virtual const char* nine() { return "0"; }
    virtual int multiplier() { return 0; }
private:
    RNInterpreter* thousands;
    RNInterpreter* hundreds;
    RNInterpreter* tens;
    RNInterpreter* ones;
};

class Thousand : public RNInterpreter
{
public:
    // provide 1-arg ctor to avoid infinite loop in base class ctor
    Thousand(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'M';
    }
    const char* four()
    {
        return "";
    }
    char five()
    {
        return '\0';
    }
    const char* nine()
    {
        return "";
    }
    int multiplier()
    {
        return 1000;
    }
};

class Hundred : public RNInterpreter
{
public:
    Hundred(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'C';
    }
    const char* four()
    {
        return "CD";
    }
    char five()
    {
        return 'D';
    }
    const char* nine()
    {
        return "CM";
    }
    int multiplier()
    {
        return 100;
    }
};

class Ten : public RNInterpreter
{
public:
    Ten(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'X';
    }
    const char* four()
    {
        return "XL";
    }
    char five()
    {
        return 'L';
    }
    const char* nine()
    {
        return "XC";
    }
    int multiplier()
    {
        return 10;
    }
};

class One : public RNInterpreter
{
public:
    One(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'I';
    }
    const char* four()
    {
        return "IV";
    }
    char five()
    {
        return 'V';
    }
    const char* nine()
    {
        return "IX";
    }
    int multiplier()
    {
        return 1;
    }
};

RNInterpreter::RNInterpreter()
{
    // use 1-arg ctor to avoid infinite loop
    thousands = new Thousand(1);
    hundreds = new Hundred(1);
    tens = new Ten(1);
    ones = new One(1);
}

int RNInterpreter::interpret(char* input)
{
    int total;
    total = 0;
    thousands->interpret(input, total);
    hundreds->interpret(input, total);
    tens->interpret(input, total);
    ones->interpret(input, total);
    if (strcmp(input, ""))
        // if input was invalid, return 0
        return 0;
    return total;
}

int main()
{
    RNInterpreter interpreter;
    char input[20];
    cout << "Enter Roman Numeral: ";
    while (cin >> input)
    {
        cout << "   interpretation is " << interpreter.interpret(input) << endl;
        cout << "Enter Roman Numeral: ";
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
