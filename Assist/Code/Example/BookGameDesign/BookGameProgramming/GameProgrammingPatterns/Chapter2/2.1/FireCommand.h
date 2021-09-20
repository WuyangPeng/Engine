// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/05 22:05)

#ifndef BOOK_GAME_PROGRAMMING_FIRE_COMMAND_H 
#define BOOK_GAME_PROGRAMMING_FIRE_COMMAND_H 

#include "Command1.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{	
		class FireCommand : public Command1
		{
		public: 
			virtual void execute();
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_FIRE_COMMAND_H