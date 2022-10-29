///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/10 20:00)

#include "LoadResourceToolsTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LibraryTools.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using namespace std::literals;

System::LoadResourceToolsTesting::LoadResourceToolsTesting(const OStreamShared& stream)
    : ParentType{ stream }, dllModule{ nullptr }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadResourceToolsTesting)

void System::LoadResourceToolsTesting::LoadTestingLibrary()
{
    const auto resourcesLibrary = GetResourcesLibrary();

    const auto fullPath = DYNAMIC_LINK_TEXT("Resource/"s) + resourcesLibrary;

    dllModule = LoadDynamicLibrary(fullPath.c_str(), LoadLibraryType::DontResolveDllReferences);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(dllModule, "加载ResourcesLibrary失败"s);
}

System::String System::LoadResourceToolsTesting::GetResourcesLibrary() const
{
    return DYNAMIC_LINK_TEXT("ResourcesLibrary"s) + GetEngineeringSuffix();
}

void System::LoadResourceToolsTesting::FreeTestingLibrary()
{
    ASSERT_TRUE(FreeDynamicLibrary(dllModule));
}

System::DynamicLinkModule System::LoadResourceToolsTesting::GetDllModule() noexcept
{
    return dllModule;
}
