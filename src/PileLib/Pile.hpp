#ifndef _PILE_H
#define _PILE_H

#include <exception>

template <typename T, int MAX>
class Pile {
private:
    T data[MAX];
    int taille;

    void VerifNonVide() const {
        if (EstVide()) {
            throw std::logic_error("Dépilement impossible : pile vide");
        }
    }

public:
    Pile() {
        taille = 0;
    }
    inline int  Taille    () const { return taille; }
    inline bool EstVide   () const { return taille == 0; }
    inline bool EstPleine () const { return taille == MAX; }
    inline T    Sommet    () const { VerifNonVide(); return data[taille - 1]; }

    void Empiler(T element) {
        if (EstPleine()) {
            throw std::logic_error("Empilement impossible : pile pleine");
        }
        data[taille++] = element;
    }
    T Depiler() {
        VerifNonVide();
        return data[--taille];
    }
};

#endif
