// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/17 21:28)

#include "World3.h" 

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{		
		World3::World3()
			:grassTerrain_(1,false,GRASS_TEXTURE),
			 hillTerrain_(3, false,HILL_TEXTURE),
			 riverTerrain_(2, true, RIVER_TEXTURE)
		{

		}

		void World3::generateTerrain()
		{
			// Fill the ground with grass.
			// �ò������档
			for (int x = 0; x < WIDTH;x++)
			{
				for (int y = 0; y < HEIGHT; y++)
				{
					// Sprinkle some hills
					// ����һЩɽ
					if (random(10) == 0)
					{
						tiles_[x][y] = &hillTerrain_;
					}
					else
					{
						tiles_[x][y] = &grassTerrain_;
					}
				}
			}

			// Lay a river.
			// ����һ���ӡ�
			int x = random(WIDTH);
			for (int y = 0; y < HEIGHT; y++)
			{
				tiles_[x][y] = &riverTerrain_;
			}

		}

		const GameProgrammingPatterns::Chapter3::Terrain3& World3::getTile(int x, int y) const
		{
			return *tiles_[x][y];
		}

	}
}


