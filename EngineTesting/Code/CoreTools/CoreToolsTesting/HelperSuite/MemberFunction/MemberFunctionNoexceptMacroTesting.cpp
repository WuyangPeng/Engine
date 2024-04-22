/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 20:36)

#include "MemberFunctionNoexceptMacroTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/MemberFunctionNoexceptMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MemberFunctionNoexceptMacroTesting::MemberFunctionNoexceptMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MemberFunctionNoexceptMacroTesting)

void CoreTools::MemberFunctionNoexceptMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MemberFunctionNoexceptMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstMemberFunctionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NonConstMemberFunctionTest);
}

void CoreTools::MemberFunctionNoexceptMacroTesting::ConstMemberFunctionTest()
{
    const auto memberFunctionNoexceptMacro = MemberFunctionNoexceptMacro::Create();

    memberFunctionNoexceptMacro.ConstMemberFunction();
    memberFunctionNoexceptMacro.ConstMemberFunction("");
    memberFunctionNoexceptMacro.ConstMemberFunction(0);
    memberFunctionNoexceptMacro.ConstMemberFunction(nullptr);
}

void CoreTools::MemberFunctionNoexceptMacroTesting::NonConstMemberFunctionTest()
{
    auto memberFunctionNoexceptMacro = MemberFunctionNoexceptMacro::Create();

    memberFunctionNoexceptMacro.NonConstCopyMemberFunction();
    memberFunctionNoexceptMacro.NonConstCopyMemberFunction("");
    memberFunctionNoexceptMacro.NonConstCopyMemberFunction(0);
    memberFunctionNoexceptMacro.NonConstCopyMemberFunction(nullptr);
}
