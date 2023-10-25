///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:27)

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
