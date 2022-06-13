///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:35)

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
