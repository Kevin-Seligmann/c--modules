#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{

public:
	Zombie(std::string const & name);
	Zombie(void);
	~Zombie(void);

	void announce(void) const;
	void setName(std::string const &name);
	std::string const & getName(void) const;

private:
	std::string _name;

};

#endif
