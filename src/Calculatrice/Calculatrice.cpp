#include <iostream>
#include <cmath>
#include "../PostfixeLib/Postfixe.hpp"

using namespace std;

typedef Terme <double, 10> TermeEquation;
typedef Postfixe <double, 10> Equation;

#define OPERATEUR1(nom, fonction ) \
    class nom : public TermeEquation {  \
        public:                                                \
            virtual double val(Equation& expression) const {   \
                return fonction(expression.Calculer());        \
        }                                                      \
    };


#define OPERATEUR2(nom, signe ) \
    class nom : public TermeEquation {                                  \
    public:                                                             \
        virtual double val(Equation& expression) const {                \
            return expression.Calculer() signe expression.Calculer();   \
        }                                                               \
    };


class Nombre : public TermeEquation {
private:
    double valeur;
public:
    Nombre(int n) {
        valeur = n;
    }
    virtual double val(Equation& expression) const {
        return valeur;
    }
};

OPERATEUR2(Addition         , +)
OPERATEUR2(Multiplication   , *)
OPERATEUR2(Division         , /)
OPERATEUR2(Modulo           , %)

OPERATEUR1(Absolue          , abs)
OPERATEUR1(Cosinus          , cos)
OPERATEUR1(Sinus            , sin)
OPERATEUR1(Exponentiel      , exp)
OPERATEUR1(Logarithme       , log)
// ...

int main()
{
    Equation equation;

        equation.Empiler(make_shared<Nombre>(-3.0));
            equation.Empiler(make_shared<Absolue>());
        equation.Empiler(make_shared<Nombre>(4.0));
    equation.Empiler(make_shared<Multiplication>());
    
    if (12.0 == equation.Calculer()) {
        cout << "ok";
        return 0;
    }
    else {
        cerr << "KO";
        return -1;
    }
}
