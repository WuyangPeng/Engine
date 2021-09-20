// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/21 23:12)

#include "SpawnerGhost.h" 
#include "Ghost2.h"

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{ 
		Monster2* spawnGhost()
		{
			return new Ghost2();
		}
	}
}


