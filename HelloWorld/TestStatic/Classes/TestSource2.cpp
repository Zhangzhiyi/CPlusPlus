#include <stdio.h>
#include "TestSource2.h"
#include "Person.h"
void TestSource2()
{
	printf("g_int's address in TestSources2.cpp %08x\n", &g_int);
	printf("g_int's value in TestSources2.cpp %d\n", g_int);
}