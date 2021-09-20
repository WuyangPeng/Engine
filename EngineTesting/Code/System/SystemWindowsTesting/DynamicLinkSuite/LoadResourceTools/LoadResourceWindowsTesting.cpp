///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/03/29 22:55)

#include "LoadResourceWindowsTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/SystemWindowsTesting/resource.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LoadResourceWindowsTesting::LoadResourceWindowsTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream },
      instance{ instance },
      container{ { static_cast<WindowsWord>(IDI_TEST_ICON), predefinedResourceTypesGroupIcon },
                 { static_cast<WindowsWord>(IDC_TEST_CURSOR), predefinedResourceTypesGroupCursor },
                 { static_cast<WindowsWord>(IDB_BITMAP1), predefinedResourceTypesBitmap },
                 { static_cast<WindowsWord>(IDR_MENU1), predefinedResourceTypesMenu } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadResourceWindowsTesting)

void System::LoadResourceWindowsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadResourceWindowsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadResourceTest);
}

void System::LoadResourceWindowsTesting::LoadResourceTest()
{
    for (const auto& value : container)
    {
        const auto resource = FindResourceInLibrary(instance, value.second, MakeIntreSource(value.first));

        ASSERT_UNEQUAL_NULL_PTR(resource);

        const auto global = LoadResourceInLibrary(instance, resource);

        ASSERT_UNEQUAL_NULL_PTR(global);

        const auto resourceLock = LockResourceInLibrary(global);

        ASSERT_UNEQUAL_NULL_PTR(resourceLock);

        const auto size = SizeofResourceInLibrary(instance, resource);

        ASSERT_LESS(0u, size);
    }
}
