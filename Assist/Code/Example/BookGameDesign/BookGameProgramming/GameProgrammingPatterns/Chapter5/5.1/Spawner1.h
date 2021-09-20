// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/20 22:15)

#ifndef BOOK_GAME_PROGRAMMING_SPAWNER1_H 
#define BOOK_GAME_PROGRAMMING_SPAWNER1_H 

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{	
		class Monster1;

		class Spawner1
		{
		public:
			virtual ~Spawner1();
			virtual Monster1* spawnMonster() = 0;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_SPAWNER1_H