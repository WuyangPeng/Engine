// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/05 22:05)

#ifndef BOOK_GAME_PROGRAMMING_INPUT_HANDLER3_H 
#define BOOK_GAME_PROGRAMMING_INPUT_HANDLER3_H 

#include "Example/BookGameDesign/BookGameProgramming/GameProgrammingPatterns/Chapter2/2.1/ButtonType.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class Command2;

		class InputHandler3
		{
		public:
			Command2* handleInput();

		private:
			bool isPressed(ButtonType buttonType);
			
		private:
			Command2* buttonX_;
			Command2* buttonY_;
			Command2* buttonA_;
			Command2* buttonB_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_INPUT_HANDLER3_H