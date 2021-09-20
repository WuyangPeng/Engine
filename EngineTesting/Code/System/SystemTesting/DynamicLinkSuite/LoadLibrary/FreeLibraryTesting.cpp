///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/25 13:40)

#include "FreeLibraryTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
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
    const auto resourcesLibraryDll = DYNAMIC_LINK_TEXT("Resource/ResourcesLibrary"s) + GetEngineeringDynamicLinkSuffix();

    auto module = LoadDynamicLibrary(resourcesLibraryDll.c_str(), LoadLibraryType::DontResolveDllReferences);

    ASSERT_UNEQUAL_NULL_PTR(module);

    ASSERT_TRUE(DisableThreadDynamicLibraryCalls(module));

    ASSERT_TRUE(FreeDynamicLibrary(module));
}
