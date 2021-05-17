#include <iostream>
#include "Postfixe.hpp"

using namespace std;

const int MAX = 10;

class Entier : public Terme<int, MAX> {
private:
    int valeur;
public:
    Entier(int n) {
        valeur = n;
    }    
    virtual int val(Postfixe<int, MAX>& expression) const {
        return valeur;
    }
};

class Addition : public Terme<int, MAX> {
public:
    virtual int val(Postfixe<int, MAX>& expression) const {
        return expression.Calculer() + expression.Calculer();
    }
};

class Multiplication : public Terme<int, MAX> {
public:
    virtual int val(Postfixe<int, MAX>& expression) const {
        return expression.Calculer() * expression.Calculer();
    }
};

int main()
{
    Postfixe<int, MAX> expression;

    expression.Empiler(make_shared<Entier>(3));
            expression.Empiler(make_shared<Entier>(1));
            expression.Empiler(make_shared<Entier>(3));
        expression.Empiler(make_shared<Addition>());
    expression.Empiler(make_shared<Multiplication>());

    if (12 == expression.Calculer()) {
        cout << "ok";
        return 0;
    }
    else {
        cerr << "KO";
        return -1;
    }
}
