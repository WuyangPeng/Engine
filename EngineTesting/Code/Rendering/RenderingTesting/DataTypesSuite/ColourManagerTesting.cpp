///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 16:38)

#include "ColourManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ColourManagerTesting)

void Rendering::ColourManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ColourTest);
}

void Rendering::ColourManagerTesting::ColourTest()
{
    constexpr unsigned char red = 20;
    constexpr unsigned char green = 50;
    constexpr unsigned char blue = 40;
    constexpr unsigned char alpha = 100;

    unsigned int colour = ColourManager::MakeR8G8B8(red, green, blue);

#ifdef SYSTEM_BIG_ENDIAN

    ASSERT_EQUAL(colour, 255u | (blue << 8) | (green << 16) | (red << 24));

#else  // !SYSTEM_BIG_ENDIAN

    ASSERT_EQUAL(colour, red | (green << 8) | (blue << 16) | (255u << 24));

#endif  // SYSTEM_BIG_ENDIAN

    colour = ColourManager::MakeR8G8B8A8(red, green, blue, alpha);

#ifdef SYSTEM_BIG_ENDIAN

    ASSERT_EQUAL(colour, static_cast<unsigned>(alpha | (blue << 8) | (green << 16) | (red << 24)));

#else  // !SYSTEM_BIG_ENDIAN

    ASSERT_EQUAL(colour, static_cast<unsigned>(red | (green << 8) | (blue << 16) | (alpha << 24)));

#endif  // SYSTEM_BIG_ENDIAN
}
