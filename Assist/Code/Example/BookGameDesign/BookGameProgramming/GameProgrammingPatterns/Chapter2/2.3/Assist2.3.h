// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/09 0:05)

#ifndef BOOK_GAME_PROGRAMMING_ASSIST_23_H 
#define BOOK_GAME_PROGRAMMING_ASSIST_23_H 

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{			
		class Unit
		{
		public:
			void moveTo(int x, int y);

			int x() const;
			int y() const;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_ASSIST_23_H