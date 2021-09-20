// Copyright (c) 2011-2019
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.1.0 (2019/11/21 23:12)

#ifndef BOOK_GAME_PROGRAMMING_MONSTER2_H 
#define BOOK_GAME_PROGRAMMING_MONSTER2_H 

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{	
		class Monster2
		{
		public:
			virtual ~Monster2();
			virtual Monster2* clone() = 0;

			// Other Stuff...
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_MONSTER2_H