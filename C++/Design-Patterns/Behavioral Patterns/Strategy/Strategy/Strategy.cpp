// Strategy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual string DoAlgorithm(const vector<string>& data) const = 0;
};

class Context
{
private:
    Strategy* strategy_;
public:
    Context(Strategy* strategy = nullptr) : strategy_(strategy)
    {
    }
    ~Context()
    {
        delete this->strategy_;
    }
    void set_strategy(Strategy* strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }
    void DoSomeBusinessLogic() const
    {
        cout << "Context: Sorting data using the strategy (not sure how it'll do it)" << endl;
        string result = this->strategy_->DoAlgorithm(vector<string>{"a", "e", "c", "b", "d"});
        cout << result << endl;
    }
};

class ConcreteStrategyA : public Strategy
{
public:
    string DoAlgorithm(const vector<string>& data) const override
    {
        string result;
        for_each(begin(data), end(data), [&result](const string& letter) {
            result += letter;
            });
        sort(begin(result), end(result));

        return result;
    }
};
class ConcreteStrategyB : public Strategy
{
    string DoAlgorithm(const vector<string>& data) const override
    {
        string result;
        for_each(begin(data), end(data), [&result](const string& letter) {
            result += letter;
            });
        sort(begin(result), end(result));
        for (int i = 0; i < result.size() / 2; i++)
        {
            swap(result[i], result[result.size() - i - 1]);
        }

        return result;
    }
};
void ClientCode()
{
    Context* context = new Context(new ConcreteStrategyA);
    cout << "Client: Strategy is set to normal sorting." << endl;
    context->DoSomeBusinessLogic();
    cout << endl;
    cout << "Client: Strategy is set to reverse sorting." << endl;
    context->set_strategy(new ConcreteStrategyB);
    context->DoSomeBusinessLogic();
    delete context;
}

int main()
{
    ClientCode();
    return 0;
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
