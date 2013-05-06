#include "StdAfx.h"
#include "ClxString.h"
#include <iostream>

ClxString::ClxString(int length)
{
	if (length > 0)
	{
		m_pString = new char[length];
	}
}
ClxString::ClxString(const char *pString)
{
	int length = strlen(pString) + 1; //注意：最后要补'\0',所以要+1
	m_pString = new char[length];
	strcpy(m_pString, pString);
	
}

ClxString::~ClxString(void)
{
	if (m_pString != NULL)
	{
		delete[] m_pString;
	}
}
