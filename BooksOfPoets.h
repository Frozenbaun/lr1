#pragma once
#include <fstream>
#include "BooksOfPoets.h"
#include "keeper.h"
using namespace std;
class BooksOfPoets
{
public:
	BooksOfPoets();
	virtual ~BooksOfPoets();
	virtual void setVal() = 0;
};
