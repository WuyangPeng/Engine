// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 19:05)

#include "EdgeKeyTesting.h"
#include "Mathematics/Meshes/EdgeKey.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EdgeKeyTesting) 

void Mathematics::EdgeKeyTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(KeyTest);
}

void Mathematics::EdgeKeyTesting
	::KeyTest()
{
	EdgeKey firstEdgeKey(5, 4);

	ASSERT_EQUAL(firstEdgeKey.GetKey(0), 4);
	ASSERT_EQUAL(firstEdgeKey.GetKey(1), 5);

	EdgeKey secondEdgeKey(5, 14);

	ASSERT_EQUAL(secondEdgeKey.GetKey(0), 5);
	ASSERT_EQUAL(secondEdgeKey.GetKey(1), 14);
}
 