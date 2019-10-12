#include "EngineTest.h"

namespace engine {
    
	test::test()
	{
		value = 0;
	}

	test::test(int x)
	{
		value = x;
	}

	int test::getvalue()
	{
		return value;
	}
}