// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/21 23:12)

#include "Ghost2.h"  

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{		 
		Ghost2::Ghost2(int health, int speed)
			:health_(health),speed_(speed)
		{

		}

		Ghost2::Ghost2()
			: health_(0), speed_(0)
		{

		}

		Monster2* Ghost2::clone()
		{
			return new Ghost2(health_, speed_);
		}
	}
}


