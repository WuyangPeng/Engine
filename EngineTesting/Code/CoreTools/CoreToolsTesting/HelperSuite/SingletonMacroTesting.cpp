///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 15:38)

#include "SingletonMacroTesting.h"
#include "Detail/SingletonMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CORE_TOOLS_MUTEX_EXTERN(CoreTools);

CoreTools::SingletonMacroTesting::SingletonMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SingletonMacroTesting)

void CoreTools::SingletonMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SingletonMacroTesting::MainTest()
{
    auto& mutex = GetCoreToolsMutex();

    mutex.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);

    mutex.Delete();
}

void CoreTools::SingletonMacroTesting::SingletonTest()
{
    SingletonMacro::Create();

    SingletonMacro::GetSingleton().DoNothing();

    SingletonMacro::Destroy();
}