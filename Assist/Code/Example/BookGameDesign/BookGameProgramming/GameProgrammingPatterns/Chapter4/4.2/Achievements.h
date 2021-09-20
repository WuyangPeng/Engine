// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/18 23:34)

#ifndef BOOK_GAME_PROGRAMMING_ACHIEVEMENTS_H 
#define BOOK_GAME_PROGRAMMING_ACHIEVEMENTS_H 

#include "Assist4.2.h"
#include "Observer1.h"

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{	
		class Achievements : public Observer1
		{
		public:
			virtual void onNotify(const Entity2& entity, Event event);

		private:
			void unlock(Achievement achievement);

			bool heroIsOnBridge_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_ACHIEVEMENTS_H