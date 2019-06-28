#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

# define MAX_UNITS 12

class Squad : public ISquad {
public:
    Squad();
    Squad(Squad const &copy);
    ~Squad();

    Squad &operator=(const Squad &copy);

    int getCount(void) const;
    ISpaceMarine *getUnit(int) const;
    int push(ISpaceMarine*);
private:
    int _count;
    ISpaceMarine *_units[MAX_UNITS];
};
