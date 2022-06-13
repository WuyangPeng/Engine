///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:48)

#include "LoadResourceTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/System/ResourcesLibrary/resource.h"

System::LoadResourceTesting::LoadResourceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      container{ { static_cast<WindowsWord>(IDI_ICON1), predefinedResourceTypesGroupIcon },
                 { static_cast<WindowsWord>(IDI_ICON2), predefinedResourceTypesGroupIcon },
                 { static_cast<WindowsWord>(IDC_CURSOR1), predefinedResourceTypesGroupCursor },
                 { static_cast<WindowsWord>(IDC_CURSOR2), predefinedResourceTypesGroupCursor },
                 { static_cast<WindowsWord>(IDB_BITMAP1), predefinedResourceTypesBitmap },
                 { static_cast<WindowsWord>(IDR_MENU1), predefinedResourceTypesMenu } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadResourceTesting)

void System::LoadResourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadResourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadTestingLibrary);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadResourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FreeTestingLibrary);

    // SystemWindowsTesting有dllModule为instance的测试。
}

void System::LoadResourceTesting::LoadResourceTest()
{
    for (const auto& value : container)
    {
        const auto resource = FindResourceInLibrary(GetDllModule(), value.second, MakeIntreSource(value.first));

        ASSERT_UNEQUAL_NULL_PTR(resource);

        const auto global = LoadResourceInLibrary(GetDllModule(), resource);

        ASSERT_UNEQUAL_NULL_PTR(global);

        const auto resourceLock = LockResourceInLibrary(global);

        ASSERT_UNEQUAL_NULL_PTR(resourceLock);

        const auto size = SizeofResourceInLibrary(GetDllModule(), resource);

        ASSERT_LESS(0u, size);
    }
}
