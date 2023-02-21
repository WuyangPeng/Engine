///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/12 21:32)

#include "CallConstMemberFunctionMacroTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/CallConstMemberFunctionMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CallConstMemberFunctionMacroTesting::CallConstMemberFunctionMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CallConstMemberFunctionMacroTesting)

void CoreTools::CallConstMemberFunctionMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CallConstMemberFunctionMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstMemberFunctionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NonConstMemberFunctionTest);
}

void CoreTools::CallConstMemberFunctionMacroTesting::ConstMemberFunctionTest()
{
    const CallConstMemberFunctionMacro memberFunctionMacro{ "" };

    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(), "");
    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(""), "");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    ASSERT_EQUAL(memberFunctionMacro[0], "");

#include STSTEM_WARNING_POP

    ASSERT_EQUAL(*memberFunctionMacro[""], "");
}

void CoreTools::CallConstMemberFunctionMacroTesting::NonConstMemberFunctionTest()
{
    CallConstMemberFunctionMacro memberFunctionMacro{ "" };

    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(), memberFunctionMacro.NonConstCopyMemberFunction());
    ASSERT_EQUAL(memberFunctionMacro.ConstMemberFunction(""), memberFunctionMacro.NonConstCopyMemberFunction(""));

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    ASSERT_EQUAL(memberFunctionMacro[0], "");

#include STSTEM_WARNING_POP

    ASSERT_EQUAL(*memberFunctionMacro[""], "");
}