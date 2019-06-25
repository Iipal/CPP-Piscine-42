#pragma once

#include <iostream>

class Zombie {
public:
    Zombie();
    ~Zombie();

    void        announce(void);

    std::string getName (void) const;
    std::string getType (void) const;

    void        setName(std::string name);
    void        setType(std::string type);

private:
    std::string _name, _type;

    static std::string  randomAnnounces[];
    static std::string  __announceGenerator();
};
