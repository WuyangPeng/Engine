/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:28)

#include "GetModuleHandleTesting.h"
#include "System/DynamicLink/LibraryTools.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define OPEN_GET_HANDLE_PIN
#undef OPEN_GET_HANDLE_PIN

using namespace std::literals;

System::GetModuleHandleTesting::GetModuleHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

void System::GetModuleHandleTesting::GetHandleUnequalNullPtrTest()
{
    const auto moduleHandle = GetHandle();
    ASSERT_UNEQUAL_NULL_PTR(moduleHandle);
}

System::DynamicLinkModule System::GetModuleHandleTesting::GetHandleUseTypeUnequalNullPtrTest(GetModuleHandleType getModuleHandleType)
{
    const auto moduleHandleEx = GetHandle(getModuleHandleType);
    ASSERT_UNEQUAL_NULL_PTR(moduleHandleEx);

    return moduleHandleEx;
}

void System::GetModuleHandleTesting::GetHandleEqualNullPtrTest()
{
    const auto moduleHandle = GetHandle();
    ASSERT_EQUAL_NULL_PTR(moduleHandle);
}

void System::GetModuleHandleTesting::GetHandleUseTypeEqualNullPtrTest(GetModuleHandleType getModuleHandleType)
{
    const auto moduleHandleEx = GetHandle(getModuleHandleType);
    ASSERT_EQUAL_NULL_PTR(moduleHandleEx);
}

void System::GetModuleHandleTesting::GetModuleHandleSucceed0Test()
{
    const auto libraryModule = GetDynamicLibraryFailureThrow();

    ASSERT_NOT_THROW_EXCEPTION_0(GetHandleUnequalNullPtrTest);

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, libraryModule);

    ASSERT_NOT_THROW_EXCEPTION_0(GetHandleEqualNullPtrTest);
}

void System::GetModuleHandleTesting::GetModuleHandleSucceed1Test()
{
    const auto libraryModule = GetDynamicLibraryFailureThrow();

    const auto moduleHandleEx = GetHandleUseTypeUnequalNullPtrTest(GetModuleHandleType::Default);

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, libraryModule);

    ASSERT_NOT_THROW_EXCEPTION_0(GetHandleUnequalNullPtrTest);

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, moduleHandleEx);

    ASSERT_NOT_THROW_EXCEPTION_0(GetHandleEqualNullPtrTest);
}

void System::GetModuleHandleTesting::GetModuleHandleSucceed2Test()
{
    const auto libraryModule = GetDynamicLibraryFailureThrow();

    ASSERT_NOT_THROW_EXCEPTION_1(GetHandleUseTypeUnequalNullPtrTest, GetModuleHandleType::UnchangedRefCount);

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, libraryModule);

    ASSERT_NOT_THROW_EXCEPTION_0(GetHandleEqualNullPtrTest);
}

void System::GetModuleHandleTesting::GetModuleHandleSucceed3Test()
{
    /// 这个测试会导致ResourcesLibrary不卸载，从而导致其他测试失败。

    const auto libraryModule = GetDynamicLibraryFailureThrow();

    const auto moduleHandleEx = GetHandleUseTypeUnequalNullPtrTest(GetModuleHandleType::Pin);

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, libraryModule);

    ASSERT_NOT_THROW_EXCEPTION_0(GetHandleUnequalNullPtrTest);

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, moduleHandleEx);

    ASSERT_NOT_THROW_EXCEPTION_0(GetHandleUnequalNullPtrTest);
}

void System::GetModuleHandleTesting::GetModuleHandleFailureTest()
{
    const auto libraryModule = GetDynamicLibraryFailureThrow();

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, libraryModule);

    ASSERT_NOT_THROW_EXCEPTION_0(GetHandleEqualNullPtrTest);

    ASSERT_NOT_THROW_EXCEPTION_1(GetHandleUseTypeEqualNullPtrTest, GetModuleHandleType::Default);

    ASSERT_NOT_THROW_EXCEPTION_1(GetHandleUseTypeEqualNullPtrTest, GetModuleHandleType::UnchangedRefCount);

    ASSERT_NOT_THROW_EXCEPTION_1(GetHandleUseTypeEqualNullPtrTest, GetModuleHandleType::Pin);
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

System::DynamicLinkModule System::GetModuleHandleTesting::GetDynamicLibraryFailureThrow()
{
    const auto libraryModule = GetDynamicLibrary();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(libraryModule, "获取ResourcesLibrary失败。"s);

    return libraryModule;
}
