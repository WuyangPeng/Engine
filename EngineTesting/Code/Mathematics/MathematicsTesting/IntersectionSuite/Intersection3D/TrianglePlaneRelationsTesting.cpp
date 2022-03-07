// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:54)

#include "TrianglePlaneRelationsTesting.h"
 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>

 #include SYSTEM_WARNING_DISABLE(26440)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, TrianglePlaneRelationsTesting)

void Mathematics::TrianglePlaneRelationsTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RelationsTest); 
}

void Mathematics::TrianglePlaneRelationsTesting
	::RelationsTest()
{
	 
}
 