// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/05 22:07)

#include "JumpCommand2.h"   
#include "Assist2.2.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{		 
		void JumpCommand2::execute(GameActor& actor)
		{
			actor.jump();
		}

	}
}


