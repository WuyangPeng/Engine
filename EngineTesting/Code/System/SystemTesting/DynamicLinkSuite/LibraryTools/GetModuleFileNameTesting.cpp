///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/26 11:09)

#include "GetModuleFileNameTesting.h"
#include "System/DynamicLink/Flags/GetModuleHandleFlags.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LibraryTools.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "System/Windows/Engineering.h"

#include <array>

using std::array;
using namespace std::literals;

System::GetModuleFileNameTesting::GetModuleFileNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetModuleFileNameTesting)

void System::GetModuleFileNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetModuleFileNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetModuleFileNameSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetModuleFileNameFailureTest);
}

void System::GetModuleFileNameTesting::GetModuleFileNameSucceedTest()
{
    auto libraryModule = GetDynamicLibrary();

    array<DynamicLinkCharType, g_MaxPath> moduleFileName{};
    const auto maxFileNameLength = GetDynamicLinkFileName(libraryModule, moduleFileName.data(), g_MaxPath);

    DynamicLinkString dllModuleFileName{ moduleFileName.data() };

    ASSERT_TRUE(0 < maxFileNameLength && maxFileNameLength < g_MaxPath);
    ASSERT_EQUAL(dllModuleFileName.size(), maxFileNameLength);

    ASSERT_UNEQUAL(dllModuleFileName.find(GetResource()), DynamicLinkString::npos);
    ASSERT_UNEQUAL(dllModuleFileName.find(GetResourcesLibrary()), DynamicLinkString::npos);

    Destroy(libraryModule);
}

void System::GetModuleFileNameTesting::GetModuleFileNameFailureTest()
{
    auto libraryModule = GetDynamicLibrary();
    Destroy(libraryModule);

    array<DynamicLinkCharType, g_MaxPath> moduleFileName{};
    const auto maxFileNameLength = GetDynamicLinkFileName(libraryModule, moduleFileName.data(), g_MaxPath);

    ASSERT_EQUAL(0u, maxFileNameLength);

    for (auto value : moduleFileName)
    {
        ASSERT_EQUAL(value, nullDynamicLinkChar);
    }
}

System::DynamicLinkString System::GetModuleFileNameTesting::GetResourcesLibraryName()
{
    return GetResource() + DYNAMIC_LINK_TEXT("/"s) + GetResourcesLibrary() + GetEngineeringSuffix();
}

System::DynamicLinkModule System::GetModuleFileNameTesting::GetDynamicLibrary()
{
    const auto resourcesLibraryDll = GetResourcesLibraryName();

    return LoadDynamicLibrary(resourcesLibraryDll.c_str(), LoadLibraryType::DontResolveDllReferences);
}

void System::GetModuleFileNameTesting::Destroy(DynamicLinkModule dynamicLinkModule)
{
    ASSERT_TRUE(FreeDynamicLibrary(dynamicLinkModule));
}

System::DynamicLinkString System::GetModuleFileNameTesting::GetResource()
{
    return DYNAMIC_LINK_TEXT("Resource"s);
}

System::DynamicLinkString System::GetModuleFileNameTesting::GetResourcesLibrary()
{
    return DYNAMIC_LINK_TEXT("ResourcesLibrary"s);
}
