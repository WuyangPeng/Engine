// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/21 23:17)

#ifndef BOOK_GAME_PROGRAMMING_SPAWNER2_H 
#define BOOK_GAME_PROGRAMMING_SPAWNER2_H 

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{	
		class Monster2;

		class Spawner2
		{
		public:
			Spawner2(Monster2* prototype);
			Monster2* spawnMonster();

		private:
			Monster2* prototype_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_SPAWNER2_H