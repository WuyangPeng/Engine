// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/17 21:28)

#include "World1.h" 

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{		 
		int World1::getMovementCost(int x, int y)
		{
			switch (tiles_[x][y])
			{
			case TERRAIN_GRASS:return 1;
			case TERRAIN_HILL:return 3;
			case TERRAIN_RIVER:return 2;
				// Other terrains...
			default:
				break;
			}

			return 0;
		}

		bool World1::isWater(int x, int y)
		{
			switch (tiles_[x][y])
			{
			case TERRAIN_GRASS:return false;
			case TERRAIN_HILL:return false;
			case TERRAIN_RIVER:return true;
				// Other terrains...
			default:
				break;
			}

			return false;
		}

	}
}


