// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/17 21:26)

#ifndef BOOK_GAME_PROGRAMMING_WORLD11_H 
#define BOOK_GAME_PROGRAMMING_WORLD11_H 

#include "Terrain1.h"
#include "Assist3.4.h"

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{
		class World1
		{
		public:
			int getMovementCost(int x, int y);
			bool isWater(int x, int y);

		private:
			Terrain1 tiles_[WIDTH][HEIGHT];
		 };
	}
}

#endif // BOOK_GAME_PROGRAMMING_WORLD11_H