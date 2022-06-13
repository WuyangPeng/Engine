///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:35)

#include "RttiMacroFinalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::RttiMacroFinalTesting::RttiMacroFinalTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RttiMacroFinalTesting)

void CoreTools::RttiMacroFinalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

CORE_TOOLS_RTTI_DEFINE(CoreTools, RttiMacroFinalTesting);

void CoreTools::RttiMacroFinalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
}

void CoreTools::RttiMacroFinalTesting::RttiTest()
{
    ASSERT_EQUAL("CoreTools.RttiMacroFinalTesting", GetRttiType().GetName());
    ASSERT_EQUAL("CoreTools.RttiMacroTesting", ParentType::GetRttiType().GetName());
    ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_FALSE(GetRttiType().IsExactly(ParentType::GetRttiType()));
    ASSERT_TRUE(GetRttiType().IsDerived(ParentType::GetRttiType()));
    ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetRttiType()));

    ASSERT_EQUAL("CoreTools.RttiMacroFinalTesting", GetCurrentRttiType().GetName());
    ASSERT_EQUAL("CoreTools.RttiMacroTesting", ParentType::GetCurrentRttiType().GetName());
    ASSERT_TRUE(GetCurrentRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_FALSE(GetCurrentRttiType().IsExactly(ParentType::GetRttiType()));
    ASSERT_TRUE(GetCurrentRttiType().IsDerived(ParentType::GetRttiType()));
    ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetCurrentRttiType()));
}
