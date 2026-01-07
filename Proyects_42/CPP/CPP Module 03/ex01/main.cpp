#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "========== CLAPTRAP TESTS ==========" << std::endl;
	ClapTrap clap("Clappy");

	clap.attack("a training dummy");
	clap.takeDamage(4);
	clap.beRepaired(2);
	clap.takeDamage(100);
	clap.attack("nobody");
	clap.beRepaired(5);

	std::cout << "\n========== SCAVTRAP TESTS ==========" << std::endl;
	ScavTrap scav("Serena");

	scav.attack("an intruder");
	scav.guardGate();
	scav.takeDamage(20);
	scav.beRepaired(10);
	for (int i = 0; i < 55; ++i)
		scav.attack("air");

	std::cout << "\n========== END OF PROGRAM ==========\n" << std::endl;
	return 0;
}

