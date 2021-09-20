// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/21 23:25)

#ifndef BOOK_GAME_PROGRAMMING_SPAWNER3_H 
#define BOOK_GAME_PROGRAMMING_SPAWNER3_H 

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{	
		class Monster2;

		typedef Monster2* (*SpawnCallback)();

		class Spawner3
		{
		public:
			Spawner3(SpawnCallback spawn);
			Monster2* spawnMonster();

		private:
			SpawnCallback spawn_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_SPAWNER3_H