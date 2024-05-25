/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/06 19:50)

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
    ASSERT_NOT_THROW_EXCEPTION_0(GetRttiTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetCurrentRttiTypeTest);
}

void CoreTools::RttiMacroFinalTesting::GetRttiTypeTest()
{
    ASSERT_EQUAL(GetFinalRttiName(), GetRttiType().GetName());
    ASSERT_EQUAL(GetRttiName(), ParentType::GetRttiType().GetName());
    ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_FALSE(GetRttiType().IsExactly(ParentType::GetRttiType()));
    ASSERT_TRUE(GetRttiType().IsDerived(ParentType::GetRttiType()));
    ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetRttiType()));
}

void CoreTools::RttiMacroFinalTesting::GetCurrentRttiTypeTest()
{
    ASSERT_EQUAL(GetFinalRttiName(), GetCurrentRttiType().GetName());
    ASSERT_EQUAL(GetRttiName(), ParentType::GetCurrentRttiType().GetName());
    ASSERT_TRUE(GetCurrentRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_FALSE(GetCurrentRttiType().IsExactly(ParentType::GetRttiType()));
    ASSERT_TRUE(GetCurrentRttiType().IsDerived(ParentType::GetRttiType()));
    ASSERT_FALSE(ParentType::GetRttiType().IsExactly(GetCurrentRttiType()));
}

const char* CoreTools::RttiMacroFinalTesting::GetFinalRttiName() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return "CoreTools.RttiMacroFinalTesting";
}