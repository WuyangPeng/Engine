// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/11/18 23:33)

#ifndef BOOK_GAME_PROGRAMMING_ASSIST_41_H 
#define BOOK_GAME_PROGRAMMING_ASSIST_41_H  

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{			
		constexpr int GRAVITY = 0;
		constexpr int EVENT_START_FALL = 1;
		class Entity1
		{
		public:
			bool isOnSurface() const;

			void accelerate(int gravity);
			void update(); 
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_ASSIST_41_H