#include "ClapTrap.hpp"

int main()
{
	std::cout << "========== CLAPTRAP TESTS ==========" << std::endl;
	ClapTrap clap("CL4P-TP");

	clap.attack("Bandit");
	clap.takeDamage(3);
	clap.beRepaired(5);
	clap.takeDamage(20);
	clap.attack("Bandit");
	clap.beRepaired(3);

	std::cout << "\n========== END OF PROGRAM ==========\n" << std::endl;
	return 0;
}
