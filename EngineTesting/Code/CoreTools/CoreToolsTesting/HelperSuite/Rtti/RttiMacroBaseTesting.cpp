/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 20:39)

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
    ASSERT_NOT_THROW_EXCEPTION_0(GetRttiTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetCurrentRttiTypeTest);
}

void CoreTools::RttiMacroBaseTesting::GetRttiTypeTest()
{
    ASSERT_EQUAL(GetBaseRttiName(), GetRttiType().GetName());
    ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_TRUE(GetRttiType().IsDerived(ClassType::GetRttiType()));
}

void CoreTools::RttiMacroBaseTesting::GetCurrentRttiTypeTest()
{
    ASSERT_EQUAL(GetBaseRttiName(), GetCurrentRttiType().GetName());
    ASSERT_TRUE(GetCurrentRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_TRUE(GetCurrentRttiType().IsDerived(ClassType::GetRttiType()));
}

const char* CoreTools::RttiMacroBaseTesting::GetBaseRttiName() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return "CoreTools.RttiMacroBaseTesting";
}