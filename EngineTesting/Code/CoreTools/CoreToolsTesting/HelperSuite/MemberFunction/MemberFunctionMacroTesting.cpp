///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:35)

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