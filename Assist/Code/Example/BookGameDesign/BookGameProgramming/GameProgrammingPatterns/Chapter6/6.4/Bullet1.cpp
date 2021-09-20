// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/27 22:31)

#include "Bullet1.h"  

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{				 
		int Bullet1::getX() const
		{
			return x_;
		}

		int Bullet1::getY() const
		{
			return y_;
		}

		void Bullet1::setX(int x)
		{
			x_ = x;
		}

		void Bullet1::setY(int y)
		{
			y_ = y;
		}
	}
}


