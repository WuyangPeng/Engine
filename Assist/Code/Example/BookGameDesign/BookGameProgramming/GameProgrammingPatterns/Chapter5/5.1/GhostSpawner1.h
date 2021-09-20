// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/20 22:15)

#ifndef BOOK_GAME_PROGRAMMING_GHOST_SPAWNER1_H 
#define BOOK_GAME_PROGRAMMING_GHOST_SPAWNER1_H

#include "Spawner1.h"

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{	
		class Monster1;

		class GhostSpawner1 : public Spawner1
		{
		public:	
			virtual Monster1* spawnMonster();
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_GHOST_SPAWNER1_H