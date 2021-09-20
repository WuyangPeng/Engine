// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/21 23:25)

#include "Spawner3.h"  
#include "Monster2.h"
#include "SpawnerGhost.h"

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{			 
		Spawner3::Spawner3(SpawnCallback spawn)
			:spawn_(spawn)
		{

		}

		Monster2* Spawner3::spawnMonster()
		{
			return spawn_();
		}

		void Spawner3Test()
		{		 
			Spawner3* ghostSpawner = new Spawner3(spawnGhost);

			delete ghostSpawner;
		}
	}
}


