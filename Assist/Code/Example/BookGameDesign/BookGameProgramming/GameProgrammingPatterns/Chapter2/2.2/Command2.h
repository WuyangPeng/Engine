// Copyright (c) 2011-2019
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.1.0 (2019/11/09 0:08)

#ifndef BOOK_GAME_PROGRAMMING_COMMAND2_H 
#define BOOK_GAME_PROGRAMMING_COMMAND2_H 

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class GameActor;

		class Command2
		{
		public:
			virtual ~Command2();
			virtual void execute(GameActor& actor) = 0;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_COMMAND2_H