// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/14 20:55)

#ifndef BOOK_GAME_PROGRAMMING_MOVE_UNIT_COMMAND2_H 
#define BOOK_GAME_PROGRAMMING_MOVE_UNIT_COMMAND2_H 

#include "Command3.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class Unit;

		class MoveUnitCommand2 : public Command3
		{
		public:
			MoveUnitCommand2(Unit* unit, int x, int y);

			virtual void execute();
			virtual void undo();

		private:
			Unit* unit_;
			int x_;
			int y_;
			int xBefore_;
			int yBefore_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_MOVE_UNIT_COMMAND2_H