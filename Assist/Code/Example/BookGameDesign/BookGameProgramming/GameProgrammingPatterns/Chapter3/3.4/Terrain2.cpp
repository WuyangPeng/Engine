// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/17 21:28)

#include "Terrain2.h" 

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{		
		Terrain2::Terrain2(int moveCost, bool isWater, Texture1 texture)
			:moveCost_(moveCost),isWater_(isWater),texture_(texture)
		{

		}

		int Terrain2::getMoveCost()
		{
			return moveCost_;
		}

		bool Terrain2::isWater()
		{
			return isWater_;
		}

		const Texture1& Terrain2::getTexture() const
		{
			return texture_;
		}

	}
}


