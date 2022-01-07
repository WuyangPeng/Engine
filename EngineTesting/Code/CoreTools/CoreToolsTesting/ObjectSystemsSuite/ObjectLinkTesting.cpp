// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:29)

#include "ObjectLinkTesting.h"

#include "Detail/NullObject.h"
#include "CoreTools/Helper/AssertMacro.h"

#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ObjectLinkTesting)

void CoreTools::ObjectLinkTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(InsertObjectPtrTest);
}

void CoreTools::ObjectLinkTesting ::InsertObjectPtrTest() noexcept
{
	 
}

 



