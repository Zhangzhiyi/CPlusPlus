#include <stdio.h>
#include "TestSource1.h"
#include "Person.h"

void TestSource1()
{
	printf("g_int's address in TestSources1.cpp %08x\n", &g_int);
	g_int = 500;
	printf("g_int's value in TestSources1.cpp %d\n", g_int);
}