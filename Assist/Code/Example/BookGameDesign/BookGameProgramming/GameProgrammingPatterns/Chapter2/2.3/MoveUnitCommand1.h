// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/14 20:55)

#ifndef BOOK_GAME_PROGRAMMING_MOVE_UNIT_COMMAND1_H 
#define BOOK_GAME_PROGRAMMING_MOVE_UNIT_COMMAND1_H 

#include "Example/BookGameDesign/BookGameProgramming/GameProgrammingPatterns/Chapter2/2.1/Command1.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class Unit;

		class MoveUnitCommand1 : public Command1
		{
		public:
			MoveUnitCommand1(Unit* unit, int x, int y);

			virtual void execute();

		private:
			Unit* unit_;
			int x_;
			int y_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_MOVE_UNIT_COMMAND1_H