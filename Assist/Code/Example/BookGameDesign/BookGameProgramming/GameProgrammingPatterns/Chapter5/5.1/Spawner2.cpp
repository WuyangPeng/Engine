// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/21 23:18)

#include "Spawner2.h"  
#include "Monster2.h"
#include "Ghost2.h"

namespace GameProgrammingPatterns
{
	namespace Chapter5
	{				 
		Spawner2::Spawner2(Monster2* prototype)
			:prototype_(prototype)
		{

		}

		Monster2* Spawner2::spawnMonster()
		{
			return prototype_->clone();
		}

		void Test()
		{
			Monster2* ghostPrototype = new Ghost2(15, 3);
			Spawner2* ghostSpawner = new Spawner2(ghostPrototype);

			delete ghostSpawner;
			delete ghostPrototype;
		}
	}
}


