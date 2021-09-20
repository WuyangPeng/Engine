// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/19 21:17)

#ifndef BOOK_GAME_PROGRAMMING_PHYSICS2_H 
#define BOOK_GAME_PROGRAMMING_PHYSICS2_H 

#include "Subject1.h"

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{	
		class Entity2;

		class Physics2 : public Subject1
		{
		public:
			void updateEntity(Entity2& entity);
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_PHYSICS2_H