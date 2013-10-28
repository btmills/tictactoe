#include "Square.h"
#include "IPlayer.h"


Square::Square(void) :
	Player(nullptr)
{
}


Square::~Square(void)
{
}

bool Square::IsEmpty(void) const
{
	return (this->Player == nullptr);
}

char Square::GetSymbol(void) const
{
	if (this->IsEmpty())
		return ' ';
	return this->Player->Symbol;
}
