/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 21:08)

#include "SingletonMacroTesting.h"
#include "CoreTools/CoreToolsTesting/BaseSuite/Detail/StaticSingletonSubclass.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(StaticSingletonTest);

    mutex.Delete();
}

void CoreTools::SingletonMacroTesting::SingletonTest()
{
    SingletonMacro::Create();

    SingletonMacro::GetSingleton().DoNothing();

    SingletonMacro::Destroy();
}

void CoreTools::SingletonMacroTesting::StaticSingletonTest()
{
    StaticSingletonSubclass::GetSingleton().DoNothing();
}
