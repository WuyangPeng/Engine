// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/21 23:14)

#ifndef BOOK_GAME_PROGRAMMING_GHOST2_H 
#define BOOK_GAME_PROGRAMMING_GHOST2_H 

#include "Monster2.h"

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{	
		class Ghost2 : public Monster2
		{
		public:
			Ghost2();
			Ghost2(int health, int speed);
			virtual Monster2* clone();

		private:
			int health_;
			int speed_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_GHOST2_H