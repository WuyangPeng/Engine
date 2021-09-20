// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:33)

#include "RttiTestingBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, RttiTestingBase)

CORE_TOOLS_RTTI_BASE_DEFINE(CoreTools, RttiTestingBase)

void CoreTools::RttiTestingBase
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
}

void CoreTools::RttiTestingBase
	::RttiTest()
{
	ASSERT_EQUAL("CoreTools.RttiTestingBase", GetRttiType().GetName());
	ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
	ASSERT_TRUE(GetRttiType().IsDerived(ClassType::GetRttiType()));
}
