// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/21 23:25)

#ifndef BOOK_GAME_PROGRAMMING_SPAWNER4_H 
#define BOOK_GAME_PROGRAMMING_SPAWNER4_H 

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{	
		class Monster2;

		class Spawner4
		{
		public:
			virtual ~Spawner4();		 
			virtual Monster2* spawnMonster() = 0;		 
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_SPAWNER4_H