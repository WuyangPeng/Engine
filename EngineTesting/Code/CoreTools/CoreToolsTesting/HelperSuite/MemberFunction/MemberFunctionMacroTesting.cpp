///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/17 13:21)

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