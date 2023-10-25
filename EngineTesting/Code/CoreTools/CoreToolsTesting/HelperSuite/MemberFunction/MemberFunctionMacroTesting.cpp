///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 16:06)

#include "MemberFunctionMacroTesting.h"
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
    const auto memberFunctionMacro = MemberFunctionMacro::Create();

    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(), "");
    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(""), "");
    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(0), "0");
    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(nullptr), "");
}

void CoreTools::MemberFunctionMacroTesting::NonConstMemberFunctionTest()
{
    auto memberFunctionMacro = MemberFunctionMacro::Create();

    memberFunctionMacro.NonConstCopyMemberFunction();
    memberFunctionMacro.NonConstCopyMemberFunction("");
    memberFunctionMacro.NonConstCopyMemberFunction(0);
    memberFunctionMacro.NonConstCopyMemberFunction(nullptr);
}