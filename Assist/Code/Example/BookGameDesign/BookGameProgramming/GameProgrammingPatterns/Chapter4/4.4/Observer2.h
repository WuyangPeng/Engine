// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/19 21:20)

#ifndef BOOK_GAME_PROGRAMMING_OBSERVER2_H 
#define BOOK_GAME_PROGRAMMING_OBSERVER2_H  

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{
		class Subject2; 
		class Entity2;
		enum class Event;

		class Observer2
		{
		public:
			friend class Subject2;

		public:
			Observer2();

			virtual void onNotify(const Entity2& entity, Event event) = 0;

		private:
			Observer2* next_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_OBSERVER2_H