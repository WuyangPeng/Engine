// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/21 23:34)

#include "Spawner4.h"   
#include "SpawnerFor.h"
#include "Ghost2.h"

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{		
		Spawner4::~Spawner4()
		{

		}

		void Spawner4Test()
		{
			Spawner4* ghostSpawner = new SpawnerFor<Ghost2>();

			delete ghostSpawner;
		}
	}
}


