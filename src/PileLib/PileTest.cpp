#include <iostream>
#include "Pile.hpp"

using namespace std;

typedef int idtest;

void assertion(idtest& cas, bool res);
idtest cas(const char* titre);

int main()
{
    Pile<char, 3> pile;
    int num = 0;
    idtest test;

    test = cas("Nouvelle pile = vide, taille 0"); {
        assertion(test, 0 == pile.Taille());
        assertion(test, pile.EstVide());
        assertion(test, !pile.EstPleine());
    }
    test = cas("Dépiler pile vide = exception"); {
        try {
            pile.Depiler();
            assertion(test, false);
        }
        catch (logic_error&) {
            assertion(test, true);
        }
    }
    test = cas("Sommet pile vide = exception"); {
        try {
            char c = pile.Sommet();
            assertion(test, false);
        }
        catch (logic_error&) {
            assertion(test, true);
        }
    }
    test = cas("Empiler pile vide = non vide 1 élément"); {
        pile.Empiler('x');
        assertion(test, 'x' == pile.Sommet());
        assertion(test, 1 == pile.Taille());
        assertion(test, !pile.EstVide());
        assertion(test, !pile.EstPleine());
    }
    test = cas("Empiler max = pile pleine"); {
        pile.Empiler('y');
        pile.Empiler('z');
        assertion(test, 'z' == pile.Sommet());
        assertion(test, 3 == pile.Taille());
        assertion(test, !pile.EstVide());
        assertion(test, pile.EstPleine());
    }
    test = cas("Empiler trop = exception"); {
        try {
            pile.Empiler('a');
            assertion(test, false);
        }
        catch (logic_error&) {
            assertion(test, true);
        }
    }
    test = cas("Dépiler = taille -1"); {
        assertion(test, 'z' == pile.Depiler());
        assertion(test, 2 == pile.Taille());
        assertion(test, !pile.EstVide());
        assertion(test, !pile.EstPleine());
    }
    test = cas("Dépiler = ordre inverse"); {
        assertion(test, 'y' == pile.Depiler());
        assertion(test, 'x' == pile.Depiler());
        assertion(test, 0 == pile.Taille());
        assertion(test, pile.EstVide());
        assertion(test, !pile.EstPleine());
    }
    cout << endl;
    return 0;
}

void assertion(idtest& cas, bool res) {
    if (res) {
        cout << " #" << ++cas << "-ok";
    }
    else {
        cerr << " #" << ++cas << "KO" << endl;
        exit(-1);
    }
}

idtest cas(const char* titre) {
    static int num = 0;

    cout << endl << "Test " << ++num << " - " << titre << " : ";
    return 0;
}
