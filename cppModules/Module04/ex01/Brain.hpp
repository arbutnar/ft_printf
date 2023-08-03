#pragma once

#include <iostream>
#include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		~Brain( void );
};