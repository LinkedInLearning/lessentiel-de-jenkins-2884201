#ifndef _POSTFIXE_H
#define _POSTFIXE_H

#include <memory>
#include "Pile.hpp"

template<typename T, int MAX>
class Postfixe;

template<typename T, int MAX>
class Terme {
public:
    virtual T val(Postfixe<T, MAX>& expression) const = 0;
};

template<typename T, int MAX>
class Postfixe : public Pile<std::shared_ptr<Terme<T, MAX>>, MAX> {
public:
    inline int Calculer() {
        std::shared_ptr<Terme<T, MAX>> terme = this->Depiler();

        return terme->val(*this);
    }
};

#endif


