// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 12:21)

#include "RandomTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MemoryTools/Random.h"

//#include <boost/random/mersenne_twister.hpp>
//#include <boost/random/uniform_int.hpp>
#include <algorithm>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, RandomTesting)

void CoreTools::RandomTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomTest);
}

void CoreTools::RandomTesting ::RandomTest()
{
    Random firstRandom{};

    const auto testLoopCount = GetTestLoopCount();

    for (auto i = 0; i < testLoopCount; ++i)
    {
        [[maybe_unused]] const auto value = firstRandom.Generate();

        const auto secondValue = firstRandom.GeneratePositive();

        ASSERT_TRUE(0 <= secondValue);
    }

    Random secondRandom{ 100 };

    for (auto i = 0; i < testLoopCount; ++i)
    {
        [[maybe_unused]] const auto value = secondRandom.Generate();

        const auto secondValue = secondRandom.GeneratePositive();

        ASSERT_TRUE(0 <= secondValue);
    }
}
