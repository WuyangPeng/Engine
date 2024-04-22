/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 20:36)

#include "MemberFunctionStaticAssertMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MemberFunctionStaticAssertMacroTesting::MemberFunctionStaticAssertMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MemberFunctionStaticAssertMacroTesting)

void CoreTools::MemberFunctionStaticAssertMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MemberFunctionStaticAssertMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NonConstMemberFunctionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorFunctionTest);
}

void CoreTools::MemberFunctionStaticAssertMacroTesting::NonConstMemberFunctionTest() noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
}

void CoreTools::MemberFunctionStaticAssertMacroTesting::ConstructorFunctionTest() noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
