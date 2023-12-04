#include "Base.hpp"

int main()
{
	Base *g = Base::generate();
	Base::identify(g);
	Base::identify(*g);
}