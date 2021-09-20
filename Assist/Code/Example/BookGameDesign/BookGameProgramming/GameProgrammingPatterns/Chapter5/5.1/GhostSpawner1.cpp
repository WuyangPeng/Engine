// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/20 22:18)

#include "GhostSpawner1.h"  
#include "Ghost1.h"

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{			 
		Monster1* GhostSpawner1::spawnMonster()
		{
			return new Ghost1();
		}
	}
}


