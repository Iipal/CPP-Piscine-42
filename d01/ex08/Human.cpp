#include "Human.hpp"

Human::Human() {}
Human::~Human() {}

typedef void (Human::*fnptrActions)(std::string const&);
void    Human::meleeAttack(std::string const &target) {
    std::cout << "Human slap your pretty " << target << std::endl;
}
void    Human::rangedAttack(std::string const &target) {
    std::cout << "Human spat in your dirty " << target << std::endl;
}
void    Human::intimidatingShout(std::string const &tagret) {
    std::cout << "Human scared as fuck when saw your " << tagret << std::endl;
}

void    Human::action(std::string const &action_name, std::string const &target) {
    static const fnptrActions   fnActions[] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
    static const std::string    actionNames[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

    size_t  i = ~0ULL;
    while (3 > ++i)
        if (actionNames[i] == action_name) {
            (this->*fnActions[i])(target);
            return ;
        }
}
