#include <iostream>
#include <cmath>

class Expression
{
public:
    virtual double evaluate() const = 0;
};

class Constant : public Expression
{
private:
    double value;
public:
    Constant(double value) : value(value) {}
    virtual double evaluate() const
    {
        return value;
    }
};

class Negated : public Expression
{
private:
    const Expression* expression;
public:
    Negated(Expression* expression) : expression(expression) {}
    virtual double evaluate() const
    {
        return -(expression->evaluate());
    }
};

class Exponent : public Expression
{
private:
    const Expression* expression;
    const int exponent;
public:
    Exponent(Expression* expression, int exponent) : expression(expression), exponent(exponent)
        {}
    virtual double evaluate() const
    {
        return std::pow(expression->evaluate(), exponent);
    }
};

class Addition : public Expression
{
private:
    const Expression* left;
    const Expression* right;
public:
    Addition(Expression* left, Expression* right) : left(left), right(right) {}
    virtual double evaluate() const
    {
        return left->evaluate() + right->evaluate();
    }
};

class Multiplication : public Expression
{
private:
    const Expression* left;
    const Expression* right;
public:
    Multiplication(Expression* left, Expression* right) : left(left), right(right) {}
    virtual double evaluate() const
    {
        return left->evaluate() * right->evaluate();
    }
};

int main()
{
    Expression* two = new Constant(2);
    Expression* four = new Constant(4);
    Expression* negOne = new Negated(new Constant(1));
    Expression* sumTwoFour = new Addition(two, four);
    Expression* mult = new Multiplication(sumTwoFour, negOne);
    Expression* exp = new Exponent(mult, 2);
    Expression* res = new Addition(exp, new Constant(1));

    std::cout << res->evaluate() << "\n";

    delete[] two;
    delete[] four;
    delete[] negOne;
    delete[] sumTwoFour;
    delete[] mult;
    delete[] exp;
    delete[] res;

    return 0;
}
