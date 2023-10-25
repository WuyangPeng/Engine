///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 16:07)

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
    const auto finalRtti = "CoreTools.RttiMacroFinalTesting";

    ASSERT_EQUAL(finalRtti, GetRttiType().GetName());
    ASSERT_EQUAL(GetRttiName(), ParentType::GetRttiType().GetName());
    ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_FALSE(GetRttiType().IsExactly(ParentType::GetRttiType()));
    ASSERT_TRUE(GetRttiType().IsDerived(ParentType::GetRttiType()));
    ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetRttiType()));

    ASSERT_EQUAL(finalRtti, GetCurrentRttiType().GetName());
    ASSERT_EQUAL(GetRttiName(), ParentType::GetCurrentRttiType().GetName());
    ASSERT_TRUE(GetCurrentRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_FALSE(GetCurrentRttiType().IsExactly(ParentType::GetRttiType()));
    ASSERT_TRUE(GetCurrentRttiType().IsDerived(ParentType::GetRttiType()));
    ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetCurrentRttiType()));
}
