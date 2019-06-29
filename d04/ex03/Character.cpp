#include "Character.hpp"

Character::Character(std::string const &name) : name_(name) {
    int i = -1;
    while (MAX_SLOTS > ++i) {
        this->items_[i] = NULL;
    }
}
Character::Character(const Character &copy) { *this = copy; }
Character::~Character() { }

Character &Character::operator=(const Character &copy) {
    if (this != &copy) {
        int i = -1;
        while (MAX_SLOTS > ++i) {
            AMateria *m_copy = NULL;

            if (copy.items_[i]) {
                m_copy = copy.items_[i]->clone();
            }
            if (this->items_[i]) {
                delete this->items_[i];
            }
            this->items_[i] = m_copy;
        }
        this->name_ = copy.name_;
    }
    return *this;
}

std::string const &Character::getName(void) const { return this->name_; }

void Character::equip(AMateria *m) {
    int i = -1;
    while (MAX_SLOTS > ++i) {
        if (!this->items_[i]) {
            this->items_[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx) {
    if (MAX_SLOTS > idx && 0 <= idx) {
        if (this->items_[idx]) {
            this->items_[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter &target) {
    if (MAX_SLOTS > idx && 0 <= idx) {
        if (this->items_[idx]) {
            this->items_[idx]->use(target);
        }
    }
}
