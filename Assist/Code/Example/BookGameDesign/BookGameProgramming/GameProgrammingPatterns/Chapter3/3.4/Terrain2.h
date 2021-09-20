
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/17 21:24)

#ifndef BOOK_GAME_PROGRAMMING_TERRAIN2_H 
#define BOOK_GAME_PROGRAMMING_TERRAIN2_H 

#include "Example/BookGameDesign/BookGameProgramming/GameProgrammingPatterns/Chapter3/3.1/Assist3.1.h"

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{
		class Terrain2
		{
		public:
			Terrain2(int movementCost, bool isWater, Texture1 texture);

			int getMoveCost();
			bool isWater();
			const Texture1& getTexture() const;

		private:
			int moveCost_;
			bool isWater_;
			Texture1 texture_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_TERRAIN2_H