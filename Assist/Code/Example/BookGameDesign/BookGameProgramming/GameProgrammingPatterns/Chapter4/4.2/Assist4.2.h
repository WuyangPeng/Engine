// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/19 20:57)

#ifndef BOOK_GAME_PROGRAMMING_ASSIST_42_H 
#define BOOK_GAME_PROGRAMMING_ASSIST_42_H  

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{			
		enum class Event
		{
			EVENT_ENTITY_FELL
		};

		enum class Achievement
		{
			ACHIEVEMENT_FILL_OFF_BRIDGE
		};	

		class Entity2
		{
		public:
			bool isHero() const;
		};

		constexpr int MAX_OBSERVERS = 5;
	}
}

#endif // BOOK_GAME_PROGRAMMING_ASSIST_42_H