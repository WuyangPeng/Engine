// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/17 21:26)

#ifndef BOOK_GAME_PROGRAMMING_WORLD12_H 
#define BOOK_GAME_PROGRAMMING_WORLD12_H 

#include "Terrain2.h"
#include "Assist3.4.h"

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{
		class World2
		{		 
		private:
			Terrain2* tiles_[WIDTH][HEIGHT];
			// Other stuff...
		 };
	}
}

#endif // BOOK_GAME_PROGRAMMING_WORLD12_H