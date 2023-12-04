#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base *Base::generate(void)
{
	srand(time(NULL));
	switch (rand() % 3)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

void Base::identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void Base::identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void) a;
	}
	catch (const std::exception e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void) b;
	}
	catch (const std::exception e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void) c;
	}
	catch (const std::exception e)
	{
	}
}