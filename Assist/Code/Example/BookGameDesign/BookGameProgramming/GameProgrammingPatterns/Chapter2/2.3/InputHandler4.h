// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/14 21:03)

#ifndef BOOK_GAME_PROGRAMMING_INPUT_HANDLER4_H 
#define BOOK_GAME_PROGRAMMING_INPUT_HANDLER4_H 

#include "Example/BookGameDesign/BookGameProgramming/GameProgrammingPatterns/Chapter2/2.1/ButtonType.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class Unit;
		class Command1;

		class InputHandler4
		{
		public:
			Command1* handleInput();

		private:
			bool isPressed(ButtonType2 buttonType);
			
		private:
			Unit* getSelectedUnit();			 
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_INPUT_HANDLER4_H