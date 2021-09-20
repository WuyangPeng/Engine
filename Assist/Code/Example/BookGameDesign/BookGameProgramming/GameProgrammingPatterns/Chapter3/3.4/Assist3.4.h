// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/17 21:22)

#ifndef BOOK_GAME_PROGRAMMING_ASSIST_34_H 
#define BOOK_GAME_PROGRAMMING_ASSIST_34_H  

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{			
		constexpr int WIDTH = 300;
		constexpr int HEIGHT = 400;

		enum Texture2
		{
			GRASS_TEXTURE,
			HILL_TEXTURE,
			RIVER_TEXTURE
		};

		class Terrain3
		{
		public:
			Terrain3(int movementCost, bool isWater, Texture2 texture);

			int getMoveCost() const;
			bool isWater();
			Texture2 getTexture() const;

		private:
			int moveCost_;
			bool isWater_;
			Texture2 texture_;
		};

		int random(int maxValue);

		void Test();
	}
}

#endif // BOOK_GAME_PROGRAMMING_ASSIST_34_H