// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/18 23:34)

#ifndef BOOK_GAME_PROGRAMMING_PHYSICS_H 
#define BOOK_GAME_PROGRAMMING_PHYSICS_H 

#include "Assist4.1.h"

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{	
		class Entity1;

		class Physics1
		{
		public:
			void updateEntity(Entity1& entity);

		private:
			void notify(Entity1& entity, int eventStartFall);
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_TREE1_H