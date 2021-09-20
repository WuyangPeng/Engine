// Copyright (c) 2011-2019
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.1.0 (2019/11/05 22:05)

#ifndef BOOK_GAME_PROGRAMMING_JUMP_COMMAND2_H 
#define BOOK_GAME_PROGRAMMING_JUMP_COMMAND2_H 

#include "Command2.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class JumpCommand2 : public Command2
		{
		public: 
			virtual void execute(GameActor& actor);
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_JUMP_COMMAND2_H