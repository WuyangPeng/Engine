// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/05 22:05)

#ifndef BOOK_GAME_PROGRAMMING_COMMAND1_H 
#define BOOK_GAME_PROGRAMMING_COMMAND1_H 

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class Command1
		{
		public:
			virtual ~Command1();
			virtual void execute() = 0;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_COMMAND1_H