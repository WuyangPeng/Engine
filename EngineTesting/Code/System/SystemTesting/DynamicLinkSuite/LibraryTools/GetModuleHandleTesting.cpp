///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:48)

#include "GetModuleHandleTesting.h"
#include "System/DynamicLink/Flags/GetModuleHandleFlags.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LibraryTools.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define OPEN_GET_HANDLE_PIN
#undef OPEN_GET_HANDLE_PIN

using namespace std::literals;

System::GetModuleHandleTesting::GetModuleHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetModuleHandleTesting)

void System::GetModuleHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetModuleHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetModuleHandleSucceed0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetModuleHandleSucceed1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetModuleHandleSucceed2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetModuleHandleFailureTest);

#ifdef OPEN_GET_HANDLE_PIN

    ASSERT_NOT_THROW_EXCEPTION_0(GetModuleHandleSucceed3Test);

#endif  // OPEN_GET_HANDLE_PIN
}

void System::GetModuleHandleTesting::GetModuleHandleSucceed0Test()
{
    auto libraryModule = GetDynamicLibrary();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(libraryModule, "获取ResourcesLibrary失败。"s);

    auto moduleHandle = GetHandle();
    ASSERT_UNEQUAL_NULL_PTR(moduleHandle);

    ASSERT_TRUE(FreeDynamicLibrary(libraryModule));

    moduleHandle = GetHandle();
    ASSERT_EQUAL_NULL_PTR(moduleHandle);
}

void System::GetModuleHandleTesting::GetModuleHandleSucceed1Test()
{
    auto libraryModule = GetDynamicLibrary();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(libraryModule, "获取ResourcesLibrary失败。"s);

    auto moduleHandleEx = GetHandle(GetModuleHandleType::Default);
    ASSERT_UNEQUAL_NULL_PTR(moduleHandleEx);

    ASSERT_TRUE(FreeDynamicLibrary(libraryModule));

    auto moduleHandle = GetHandle();
    ASSERT_UNEQUAL_NULL_PTR(moduleHandle);

    ASSERT_TRUE(FreeDynamicLibrary(moduleHandleEx));

    moduleHandle = GetHandle();
    ASSERT_EQUAL_NULL_PTR(moduleHandle);
}

void System::GetModuleHandleTesting::GetModuleHandleSucceed2Test()
{
    auto libraryModule = GetDynamicLibrary();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(libraryModule, "获取ResourcesLibrary失败。"s);

    auto moduleHandleEx = GetHandle(GetModuleHandleType::UnchangedRefcount);
    ASSERT_UNEQUAL_NULL_PTR(moduleHandleEx);

    ASSERT_TRUE(FreeDynamicLibrary(libraryModule));

    auto moduleHandle = GetHandle();
    ASSERT_EQUAL_NULL_PTR(moduleHandle);
}

void System::GetModuleHandleTesting::GetModuleHandleSucceed3Test()
{
    // 这个测试会导致ResourcesLibrary不卸载，从而导致其他测试失败。

    auto libraryModule = GetDynamicLibrary();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(libraryModule, "获取ResourcesLibrary失败。"s);

    auto moduleHandleEx = GetHandle(GetModuleHandleType::Pin);
    ASSERT_UNEQUAL_NULL_PTR(moduleHandleEx);

    ASSERT_TRUE(FreeDynamicLibrary(libraryModule));

    auto moduleHandle = GetHandle();
    ASSERT_UNEQUAL_NULL_PTR(moduleHandle);

    ASSERT_TRUE(FreeDynamicLibrary(moduleHandleEx));

    moduleHandle = GetHandle();
    ASSERT_UNEQUAL_NULL_PTR(moduleHandle);
}

void System::GetModuleHandleTesting::GetModuleHandleFailureTest()
{
    const auto resourcesLibraryDll = GetResourcesLibraryName();

    auto libraryModule = GetDynamicLibrary();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(libraryModule, "获取ResourcesLibrary失败。"s);
    ASSERT_TRUE(FreeDynamicLibrary(libraryModule));

    auto moduleHandle = GetHandle();
    ASSERT_EQUAL_NULL_PTR(moduleHandle);

    auto moduleHandleEx = GetHandle(GetModuleHandleType::Default);
    ASSERT_EQUAL_NULL_PTR(moduleHandleEx);

    moduleHandleEx = GetHandle(GetModuleHandleType::UnchangedRefcount);
    ASSERT_EQUAL_NULL_PTR(moduleHandleEx);

    moduleHandleEx = GetHandle(GetModuleHandleType::Pin);
    ASSERT_EQUAL_NULL_PTR(moduleHandleEx);
}

System::DynamicLinkString System::GetModuleHandleTesting::GetResourcesLibraryName()
{
    return DYNAMIC_LINK_TEXT("Resource/ResourcesLibrary"s) + GetEngineeringSuffix();
}

System::DynamicLinkModule System::GetModuleHandleTesting::GetDynamicLibrary()
{
    const auto resourcesLibraryDll = GetResourcesLibraryName();

    return LoadDynamicLibrary(resourcesLibraryDll.c_str(), LoadLibraryType::DontResolveDllReferences);
}

System::DynamicLinkModule System::GetModuleHandleTesting::GetHandle()
{
    const auto resourcesLibraryDll = GetResourcesLibraryName();

    return GetDynamicLinkHandle(resourcesLibraryDll.c_str());
}

System::DynamicLinkModule System::GetModuleHandleTesting::GetHandle(GetModuleHandleType getModuleHandleType)
{
    const auto resourcesLibraryDll = GetResourcesLibraryName();

    DynamicLinkModule moduleHandleEx{ nullptr };
    const auto result = GetDynamicLinkHandle(getModuleHandleType, resourcesLibraryDll.c_str(), &moduleHandleEx);
    ASSERT_TRUE(result ^ (moduleHandleEx == nullptr));

    return moduleHandleEx;
}

void System::GetModuleHandleTesting::Destroy(DynamicLinkModule dynamicLinkModule)
{
    ASSERT_TRUE(FreeDynamicLibrary(dynamicLinkModule));
}
