///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/12 21:24)

#include "CopyMemberFunctionStaticAssertMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CopyMemberFunctionStaticAssertMacroTesting::CopyMemberFunctionStaticAssertMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CopyMemberFunctionStaticAssertMacroTesting)

void CoreTools::CopyMemberFunctionStaticAssertMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CopyMemberFunctionStaticAssertMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NonConstMemberFunctionTest);
}

void CoreTools::CopyMemberFunctionStaticAssertMacroTesting::NonConstMemberFunctionTest() noexcept
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;
}

void CoreTools::CopyMemberFunctionStaticAssertMacroTesting::Copy() noexcept
{
}
