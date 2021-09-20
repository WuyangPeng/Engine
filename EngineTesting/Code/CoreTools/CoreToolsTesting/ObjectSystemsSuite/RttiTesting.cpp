// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:33)

#include "RttiTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, RttiTesting)

CORE_TOOLS_RTTI_DEFINE(CoreTools, RttiTesting);

void CoreTools::RttiTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
}

void CoreTools::RttiTesting
	::RttiTest()
{
	ASSERT_EQUAL("CoreTools.RttiTesting", GetRttiType().GetName());
	ASSERT_EQUAL("CoreTools.RttiTestingBase", ParentType::GetRttiType().GetName());
	ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
	ASSERT_FALSE(GetRttiType().IsExactly(ParentType::GetRttiType()));
	ASSERT_TRUE(GetRttiType().IsDerived(ParentType::GetRttiType()));
	ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetRttiType()));
}

