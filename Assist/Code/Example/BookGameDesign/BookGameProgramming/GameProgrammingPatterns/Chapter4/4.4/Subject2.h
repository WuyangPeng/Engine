// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/19 21:09)

#ifndef BOOK_GAME_PROGRAMMING_SUBJECT2_H 
#define BOOK_GAME_PROGRAMMING_SUBJECT2_H  

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{
		class Observer2;
		class Entity2;
		enum class Event;

		class Subject2
		{
		public:
			Subject2();

			// Methods...

			void addObserver(Observer2* observer);
			void removeObserver(Observer2* observer);

			// Other stuff...

		protected:
			void notify(const Entity2& entity, Event event);

		private:
			Observer2* head_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_SUBJECT2_H