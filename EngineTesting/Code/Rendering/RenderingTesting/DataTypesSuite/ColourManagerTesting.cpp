// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 15:20)

#include "ColourManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ColourManagerTesting)
#include SYSTEM_WARNING_DISABLE(26496)
void Rendering::ColourManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ColourTest);
}

void Rendering::ColourManagerTesting::ColourTest()
{
    unsigned char red = 20;
    unsigned char green = 50;
    unsigned char blue = 40;
    unsigned char alpha = 100;

    unsigned int colour = ColourManager::MakeR8G8B8(red, green, blue);

#ifdef SYSTEM_BIG_ENDIAN
    ASSERT_EQUAL(colour, 255u | (blue << 8) | (green << 16) | (red << 24));
#else  // !SYSTEM_BIG_ENDIAN
    ASSERT_EQUAL(colour, red | (green << 8) | (blue << 16) | (255u << 24));
#endif  // SYSTEM_BIG_ENDIAN

    colour = ColourManager::MakeR8G8B8A8(red, green, blue, alpha);

#ifdef SYSTEM_BIG_ENDIAN
    ASSERT_EQUAL(colour,
                 static_cast<unsigned>(alpha | (blue << 8) | (green << 16) | (red << 24)));
#else  // !SYSTEM_BIG_ENDIAN
    ASSERT_EQUAL(colour,
                 static_cast<unsigned>(red | (green << 8) | (blue << 16) | (alpha << 24)));
#endif  // SYSTEM_BIG_ENDIAN

    // 	 unsigned char newRed = 0;
    // 	 unsigned char newGreen = 0;
    // 	 unsigned char newBlue = 0;
    // 	 unsigned char newAlpha = 0;

    // 	 ColourManager::ExtractR8G8B8(colour,newRed,newGreen,newBlue);
    //
    // 	 ASSERT_EQUAL(red,newRed);
    // 	 ASSERT_EQUAL(green,newGreen);
    // 	 ASSERT_EQUAL(blue,newBlue);
    //
    // 	 ColourManager::ExtractR8G8B8A8(colour,newRed,newGreen,newBlue,newAlpha);
    //
    // 	 ASSERT_EQUAL(red,newRed);
    // 	 ASSERT_EQUAL(green,newGreen);
    // 	 ASSERT_EQUAL(blue,newBlue);
    // 	 ASSERT_EQUAL(alpha,newAlpha);
}
