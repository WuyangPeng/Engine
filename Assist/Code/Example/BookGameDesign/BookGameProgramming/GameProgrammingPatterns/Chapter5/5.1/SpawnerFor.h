// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/21 23:25)

#ifndef BOOK_GAME_PROGRAMMING_SPAWNER_FOR_H 
#define BOOK_GAME_PROGRAMMING_SPAWNER_FOR_H 

#include "Spawner4.h"

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{ 
		template<class T>
		class SpawnerFor : public Spawner4
		{
		public: 		 
			virtual Monster2* spawnMonster()
			{
				return new T();
			}
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_SPAWNER_FOR_H