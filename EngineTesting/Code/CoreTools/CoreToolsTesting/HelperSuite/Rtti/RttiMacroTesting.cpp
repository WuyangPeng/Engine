/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/06 19:50)

#include "RttiMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::RttiMacroTesting::RttiMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RttiMacroTesting)

void CoreTools::RttiMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

CORE_TOOLS_RTTI_DEFINE(CoreTools, RttiMacroTesting);

void CoreTools::RttiMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
}

void CoreTools::RttiMacroTesting::RttiTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetRttiTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetCurrentRttiTypeTest);
}

void CoreTools::RttiMacroTesting::GetCurrentRttiTypeTest()
{
    ASSERT_EQUAL(GetRttiName(), GetRttiType().GetName());
    ASSERT_EQUAL(GetBaseRttiName(), ParentType::GetRttiType().GetName());
    ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_FALSE(GetRttiType().IsExactly(ParentType::GetRttiType()));
    ASSERT_TRUE(GetRttiType().IsDerived(ParentType::GetRttiType()));
    ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetRttiType()));
}

void CoreTools::RttiMacroTesting::GetRttiTypeTest()
{
    ASSERT_EQUAL(GetRttiName(), GetCurrentRttiType().GetName());
    ASSERT_EQUAL(GetBaseRttiName(), ParentType::GetCurrentRttiType().GetName());
    ASSERT_TRUE(GetCurrentRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_FALSE(GetCurrentRttiType().IsExactly(ParentType::GetRttiType()));
    ASSERT_TRUE(GetCurrentRttiType().IsDerived(ParentType::GetRttiType()));
    ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetCurrentRttiType()));
}

const char* CoreTools::RttiMacroTesting::GetRttiName() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return "CoreTools.RttiMacroTesting";
}