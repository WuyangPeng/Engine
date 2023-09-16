///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:05)

#include "FreeLibraryTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <thread>

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
    std::thread thread{ &ClassType::FreeLibraryThread, this };
    thread.join();
}

void System::FreeLibraryTesting::FreeLibraryThread()
{
    const auto resourcesLibraryDll = DYNAMIC_LINK_TEXT("Resource/ResourcesLibrary"s) + CoreTools::StringConversion::StandardConversionDynamicLinkString(GetEngineeringSuffix());

    const auto module = LoadDynamicLibrary(resourcesLibraryDll.c_str(), LoadLibraryType::DontResolveDllReferences);

    ASSERT_NOT_THROW_EXCEPTION_1(DoFreeLibraryTest, module);

    ASSERT_TRUE(FreeDynamicLibrary(module));
}

void System::FreeLibraryTesting::DoFreeLibraryTest(const DynamicLinkModule& module)
{
    ASSERT_UNEQUAL_NULL_PTR(module);

    ASSERT_TRUE(DisableThreadDynamicLibraryCalls(module));
}
