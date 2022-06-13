///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:38)

#include "InitializeTerminatorMacroTesting.h"
#include "Detail/InitializeTerminator.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::InitializeTerminatorMacroTesting::InitializeTerminatorMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, InitializeTerminatorMacroTesting)

void CoreTools::InitializeTerminatorMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::InitializeTerminatorMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTermTest);
}

void CoreTools::InitializeTerminatorMacroTesting::InitTermTest()
{
    ASSERT_TRUE(g_InitializeTerminatorStreamRegistered);
    ASSERT_FALSE(InitializeTerminator::IsRegister());

    InitTerm::ExecuteInitializers();
    ASSERT_TRUE(InitializeTerminator::IsRegister());
    ASSERT_TRUE(g_InitializeTerminatorStreamRegistered);

    InitTerm::ExecuteTerminators();
    ASSERT_FALSE(InitializeTerminator::IsRegister());
    ASSERT_TRUE(g_InitializeTerminatorStreamRegistered);
}
