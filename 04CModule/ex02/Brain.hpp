#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain & operator=(Brain const & rhs);

		void setIdea(std::string const & idea, unsigned int n);
		void setIdeas(std::string const ideas[100]);

		std::string const & getIdea(unsigned int n) const;
		std::string const * getIdeas(void) const;

	private:
		std::string _ideas[100];
};

#endif
