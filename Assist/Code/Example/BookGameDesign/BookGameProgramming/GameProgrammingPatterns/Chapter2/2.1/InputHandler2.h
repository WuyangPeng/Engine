// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/05 22:05)

#ifndef BOOK_GAME_PROGRAMMING_INPUT_HANDLER2_H 
#define BOOK_GAME_PROGRAMMING_INPUT_HANDLER2_H 

#include "ButtonType.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class Command1;

		class InputHandler2
		{
		public:
			void handleInput();

		private:
			bool isPressed(ButtonType buttonType);

			// Methods to bind commands...
			// ������ķ�����
			
		private:
			Command1* buttonX_;
			Command1* buttonY_;
			Command1* buttonA_;
			Command1* buttonB_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_INPUT_HANDLER2_H