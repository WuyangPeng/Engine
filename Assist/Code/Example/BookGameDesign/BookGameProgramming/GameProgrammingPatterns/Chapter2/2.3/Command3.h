// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/14 21:17)

#ifndef BOOK_GAME_PROGRAMMING_COMMAND3_H 
#define BOOK_GAME_PROGRAMMING_COMMAND3_H 

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class Command3
		{
		public:
			virtual ~Command3();
			virtual void execute() = 0;
			virtual void undo() = 0;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_COMMAND3_H