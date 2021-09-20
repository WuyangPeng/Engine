// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:06)

#include "PtrCompareTesting.h"
#include "CoreTools/TemplateTools/PtrCompare.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, PtrCompareTesting)

void CoreTools::PtrCompareTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(PtrCompareTest);
}

void CoreTools::PtrCompareTesting
	::PtrCompareTest()
{
	std::shared_ptr<int> firstPtr{ make_shared<int>(5) };
	std::shared_ptr<int> secondPtr{ make_shared<int>(-5) };

	PtrLess<std::shared_ptr<int> > less;
	PtrGreater<std::shared_ptr<int> > greater;

	ASSERT_TRUE(less(secondPtr, firstPtr));
	ASSERT_TRUE(greater(firstPtr, secondPtr));
}