/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:52)

#include "ExecuteDllMainTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/MainFunctionHelper/ExecuteDllMain.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ExecuteDllMainTesting::ExecuteDllMainTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ExecuteDllMainTesting)

void CoreTools::ExecuteDllMainTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ExecuteDllMainTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExecuteDllMainTest);
}

void CoreTools::ExecuteDllMainTesting::ExecuteDllMainTest()
{
    DllMutex dllMutex{ MutexCreate::UseBoost };
    ExecuteDllMain(nullptr, EnumCastUnderlying(System::DllMain::ProcessAttach), nullptr, dllMutex);
    ExecuteDllMain(nullptr, EnumCastUnderlying(System::DllMain::ProcessDetach), nullptr, dllMutex);
}