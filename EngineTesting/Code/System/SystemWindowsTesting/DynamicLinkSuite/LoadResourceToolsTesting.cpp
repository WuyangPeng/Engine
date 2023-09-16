///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:09)

/// 原始文件在SystemTesting下，SystemWindowsTesting下的为自动复制文件，请勿修改。
#include "LoadResourceToolsTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LoadResourceToolsTesting::LoadResourceToolsTesting(const OStreamShared& stream)
    : ParentType{ stream }, dllModule{ nullptr }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadResourceToolsTesting)

void System::LoadResourceToolsTesting::LoadTestingLibrary()
{
    const auto resourcesLibrary = GetResourcesLibrary();

    const auto fullPath = DYNAMIC_LINK_TEXT("Resource/") + resourcesLibrary;

    dllModule = LoadDynamicLibrary(fullPath.c_str(), LoadLibraryType::DontResolveDllReferences);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(dllModule, "加载ResourcesLibrary失败");
}

System::String System::LoadResourceToolsTesting::GetResourcesLibrary() const
{
    return DYNAMIC_LINK_TEXT("ResourcesLibrary") + GetEngineeringSuffix();
}

void System::LoadResourceToolsTesting::FreeTestingLibrary()
{
    ASSERT_TRUE(FreeDynamicLibrary(dllModule));
}

System::DynamicLinkModule System::LoadResourceToolsTesting::GetDllModule() noexcept
{
    return dllModule;
}
