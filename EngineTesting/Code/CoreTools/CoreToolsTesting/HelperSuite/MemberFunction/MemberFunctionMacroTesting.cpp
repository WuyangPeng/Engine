///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:35)

#include "MemberFunctionMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/MemberFunctionMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MemberFunctionMacroTesting::MemberFunctionMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MemberFunctionMacroTesting)

void CoreTools::MemberFunctionMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MemberFunctionMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstMemberFunctionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NonConstMemberFunctionTest);
}

void CoreTools::MemberFunctionMacroTesting::ConstMemberFunctionTest()
{
    MemberFunctionMacro memberFunctionMacro{ DisableNotThrow::Disable };

    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(), "");
    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(""), "");
    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(0), "0");
    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(nullptr), "");
}

void CoreTools::MemberFunctionMacroTesting::NonConstMemberFunctionTest()
{
    MemberFunctionMacro memberFunctionMacro{ DisableNotThrow::Disable };

    memberFunctionMacro.NonConstCopyMemberFunction();
    memberFunctionMacro.NonConstCopyMemberFunction("");
    memberFunctionMacro.NonConstCopyMemberFunction(0);
    memberFunctionMacro.NonConstCopyMemberFunction(nullptr);
}