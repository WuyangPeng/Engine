// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 19:06)

#include "TriangleKeyTesting.h"
#include "Mathematics/Meshes/TriangleKey.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include SYSTEM_WARNING_DISABLE(26496)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, TriangleKeyTesting)

void Mathematics::TriangleKeyTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(KeyTest);
}

void Mathematics::TriangleKeyTesting
	::KeyTest()
{	 
	TriangleKey firstTriangleKey(5, 4,6);

	ASSERT_EQUAL(firstTriangleKey.GetKey(0), 4);
	ASSERT_EQUAL(firstTriangleKey.GetKey(1), 6);
	ASSERT_EQUAL(firstTriangleKey.GetKey(2), 5);

	TriangleKey secondTriangleKey(5, 14,18);

	ASSERT_EQUAL(secondTriangleKey.GetKey(0), 5);
	ASSERT_EQUAL(secondTriangleKey.GetKey(1), 14);
	ASSERT_EQUAL(secondTriangleKey.GetKey(2), 18);

	TriangleKey thirdTriangleKey(5, 14, 1);

	ASSERT_EQUAL(thirdTriangleKey.GetKey(0), 1);
	ASSERT_EQUAL(thirdTriangleKey.GetKey(1), 5);
	ASSERT_EQUAL(thirdTriangleKey.GetKey(2), 14);


	TriangleKey fourthTriangleKey(15, 14, 1);

	ASSERT_EQUAL(fourthTriangleKey.GetKey(0), 1);
	ASSERT_EQUAL(fourthTriangleKey.GetKey(1), 15);
	ASSERT_EQUAL(fourthTriangleKey.GetKey(2), 14);

	TriangleKey fifthTriangleKey(15, 2, 13);

	ASSERT_EQUAL(fifthTriangleKey.GetKey(0), 2);
	ASSERT_EQUAL(fifthTriangleKey.GetKey(1), 13);
	ASSERT_EQUAL(fifthTriangleKey.GetKey(2), 15);

	TriangleKey sixthTriangleKey(1, 112, 13);

	ASSERT_EQUAL(sixthTriangleKey.GetKey(0), 1);
	ASSERT_EQUAL(sixthTriangleKey.GetKey(1), 112);
	ASSERT_EQUAL(sixthTriangleKey.GetKey(2), 13);
}
 