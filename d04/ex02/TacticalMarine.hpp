#pragma once

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
public:
    TacticalMarine();
    TacticalMarine(TacticalMarine const &copy);
    ~TacticalMarine();

    TacticalMarine &operator=(const TacticalMarine &copy);

    ISpaceMarine *clone(void) const;

    void battleCry(void) const;
    void rangedAttack(void) const;
    void meleeAttack(void) const;
};
