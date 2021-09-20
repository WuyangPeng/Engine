// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/18 23:34)

#ifndef BOOK_GAME_PROGRAMMING_OBSERVER1_H 
#define BOOK_GAME_PROGRAMMING_OBSERVER1_H  

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{
		class Entity2;
		enum class Event;

		class Observer1
		{
		public:
			virtual ~Observer1() {}
			virtual void onNotify(const Entity2& entity, Event event) = 0;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_OBSERVER1_H