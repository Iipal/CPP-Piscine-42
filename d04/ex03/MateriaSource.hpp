#pragma once

#include "Character.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(MateriaSource const &copy);
    ~MateriaSource();

    MateriaSource &operator=(const MateriaSource &copy);

    void learnMateria(AMateria*);
    AMateria *createMateria(std::string const &type);
private:
    int currentlyStoredMaterials_;
    AMateria *store_[MAX_SLOTS];
};
