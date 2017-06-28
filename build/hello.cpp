#include <stdio.h>
#include <string>

extern "C" void reg(int moduleId);

int registerModule() {
	reg(1);
	return 1;
}

static int x = registerModule();
