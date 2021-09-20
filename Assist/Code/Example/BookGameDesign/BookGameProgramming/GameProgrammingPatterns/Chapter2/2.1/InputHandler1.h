// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/05 22:05)

#ifndef BOOK_GAME_PROGRAMMING_INPUT_HANDLER1_H 
#define BOOK_GAME_PROGRAMMING_INPUT_HANDLER1_H 

#include "ButtonType.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class InputHandler1
		{
		public:
			void handleInput();

		private:
			bool isPressed(ButtonType buttonType);			
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_INPUT_HANDLER1_H