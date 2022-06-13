///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:48)

#include "FreeLibraryTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <thread>

using std::thread;
using namespace std::literals;

System::FreeLibraryTesting::FreeLibraryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FreeLibraryTesting)

void System::FreeLibraryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void System::FreeLibraryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FreeLibraryTest);
}

void System::FreeLibraryTesting::FreeLibraryTest()
{
    thread thread{ &ClassType::FreeLibraryThread, this };
    thread.join();
}

void System::FreeLibraryTesting::FreeLibraryThread()
{
    const auto resourcesLibraryDll = DYNAMIC_LINK_TEXT("Resource/ResourcesLibrary"s) + GetEngineeringSuffix();

    auto module = LoadDynamicLibrary(resourcesLibraryDll.c_str(), LoadLibraryType::DontResolveDllReferences);

    ASSERT_UNEQUAL_NULL_PTR(module);

    ASSERT_TRUE(DisableThreadDynamicLibraryCalls(module));

    ASSERT_TRUE(FreeDynamicLibrary(module));
}
