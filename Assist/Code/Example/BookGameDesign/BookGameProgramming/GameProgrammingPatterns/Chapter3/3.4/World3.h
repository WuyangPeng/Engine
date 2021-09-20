// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/17 21:26)

#ifndef BOOK_GAME_PROGRAMMING_WORLD13_H 
#define BOOK_GAME_PROGRAMMING_WORLD13_H 

#include "Terrain2.h"
#include "Assist3.4.h"

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{
		class World3
		{
		public:
			World3();

			void generateTerrain();

			const Terrain3& getTile(int x, int y) const;

		private:
			Terrain3 grassTerrain_;
			Terrain3 hillTerrain_;
			Terrain3 riverTerrain_;
			// Other stuff...

			Terrain3* tiles_[WIDTH][HEIGHT];
		 };
	}
}

#endif // BOOK_GAME_PROGRAMMING_WORLD13_H