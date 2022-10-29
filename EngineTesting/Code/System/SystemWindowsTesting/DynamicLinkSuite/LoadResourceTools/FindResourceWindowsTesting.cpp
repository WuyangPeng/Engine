///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/09 23:21)

#include "FindResourceWindowsTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "System/SystemWindowsTesting/resource.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FindResourceWindowsTesting::FindResourceWindowsTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream },
      instance{ instance },
      container{ { static_cast<WindowsWord>(IDI_TEST_ICON), predefinedResourceTypesGroupIcon },
                 { static_cast<WindowsWord>(IDC_TEST_CURSOR), predefinedResourceTypesGroupCursor },
                 { static_cast<WindowsWord>(IDB_BITMAP1), predefinedResourceTypesBitmap },
                 { static_cast<WindowsWord>(IDR_MENU1), predefinedResourceTypesMenu } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FindResourceWindowsTesting)

void System::FindResourceWindowsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FindResourceWindowsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FindResourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FindResourceUseLanguageTest);
}

void System::FindResourceWindowsTesting::FindResourceTest()
{
    for (const auto& value : container)
    {
        const auto resource = FindResourceInLibrary(instance, value.second, MakeIntreSource(value.first));

        ASSERT_UNEQUAL_NULL_PTR(resource);
    }
}

void System::FindResourceWindowsTesting::FindResourceUseLanguageTest()
{
    constexpr LanguageIDData languageIDData{};

    for (const auto& value : container)
    {
        const auto resource = FindResourceInLibrary(instance, value.second, MakeIntreSource(value.first), languageIDData);

        ASSERT_UNEQUAL_NULL_PTR(resource);
    }
}
