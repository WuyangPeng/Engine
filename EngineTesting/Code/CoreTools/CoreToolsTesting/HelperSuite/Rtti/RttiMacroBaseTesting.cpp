///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 14:46)

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
    ASSERT_EQUAL("CoreTools.RttiMacroBaseTesting", GetRttiType().GetName());
    ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_TRUE(GetRttiType().IsDerived(ClassType::GetRttiType()));

    ASSERT_EQUAL("CoreTools.RttiMacroBaseTesting", GetCurrentRttiType().GetName());
    ASSERT_TRUE(GetCurrentRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_TRUE(GetCurrentRttiType().IsDerived(ClassType::GetRttiType()));
}
