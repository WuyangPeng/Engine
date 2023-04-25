///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:07)

#include "RttiMacroBaseTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::RttiMacroBaseTesting::RttiMacroBaseTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RttiMacroBaseTesting)

void CoreTools::RttiMacroBaseTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

CORE_TOOLS_RTTI_BASE_DEFINE(CoreTools, RttiMacroBaseTesting)

void CoreTools::RttiMacroBaseTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
}

void CoreTools::RttiMacroBaseTesting::RttiTest()
{
    ASSERT_EQUAL(GetBaseRttiName(), GetRttiType().GetName());
    ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_TRUE(GetRttiType().IsDerived(ClassType::GetRttiType()));

    ASSERT_EQUAL(GetBaseRttiName(), GetCurrentRttiType().GetName());
    ASSERT_TRUE(GetCurrentRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_TRUE(GetCurrentRttiType().IsDerived(ClassType::GetRttiType()));
}

const char* CoreTools::RttiMacroBaseTesting::GetBaseRttiName() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return "CoreTools.RttiMacroBaseTesting";
}