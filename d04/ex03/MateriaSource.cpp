#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : currentlyStoredMaterials_(0) {
    int i = -1;
    while (MAX_SLOTS > ++i) {
        this->store_[i] = NULL;
    }
}
MateriaSource::MateriaSource(const MateriaSource &copy) { *this = copy; }
MateriaSource::~MateriaSource() { }

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void MateriaSource::learnMateria(AMateria *am) {
    if (MAX_SLOTS > this->currentlyStoredMaterials_) {
        this->store_[this->currentlyStoredMaterials_++] = am;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    int i = -1;
    while (MAX_SLOTS > ++i) {
        if (this->store_[i]) {
            if (this->store_[i]->getType() == type) {
                return this->store_[i]->clone();
            }
        }
    }
    return NULL;
}
