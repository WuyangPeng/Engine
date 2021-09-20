// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/16 18:56)

#include "Assist3.4.h"
#include "World3.h"

namespace GameProgrammingPatterns
{
    namespace Chapter3
    {
        Terrain3::Terrain3(int moveCost, bool isWater, Texture2 texture)
            : moveCost_(moveCost), isWater_(isWater), texture_(texture)
        {
        }

        int Terrain3::getMoveCost() const
        {
            return moveCost_;
        }

        bool Terrain3::isWater()
        {
            return isWater_;
        }

        Texture2 Terrain3::getTexture() const
        {
            return texture_;
        }

        int random(int maxValue)
        {
            return maxValue;
        }

        void Test()
        {
            World3 world;
            [[maybe_unused]] int cost = world.getTile(2, 3).getMoveCost();
        }
    }
}
