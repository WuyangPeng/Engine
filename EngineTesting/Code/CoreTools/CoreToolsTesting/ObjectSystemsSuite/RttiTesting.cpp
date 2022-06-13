///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:44)

#include "RttiTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, RttiTesting)

CORE_TOOLS_RTTI_DEFINE(CoreTools, RttiTesting);

void CoreTools::RttiTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
}

void CoreTools::RttiTesting::RttiTest()
{
    ASSERT_EQUAL("CoreTools.RttiTesting", GetRttiType().GetName());
    ASSERT_EQUAL("CoreTools.RttiTestingBase", ParentType::GetRttiType().GetName());
    ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_FALSE(GetRttiType().IsExactly(ParentType::GetRttiType()));
    ASSERT_TRUE(GetRttiType().IsDerived(ParentType::GetRttiType()));
    ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetRttiType()));
}
