///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:48)

#include "FindResourceTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/System/ResourcesLibrary/resource.h"

System::FindResourceTesting::FindResourceTesting(const OStreamShared& stream)
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FindResourceTesting)

void System::FindResourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FindResourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadTestingLibrary);
    ASSERT_NOT_THROW_EXCEPTION_0(FindResourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FindResourceUseLanguageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FreeTestingLibrary);

    // SystemWindowsTesting有dllModule为instance的测试。
}

void System::FindResourceTesting::FindResourceTest()
{
    for (const auto& value : container)
    {
        const auto resource = FindResourceInLibrary(GetDllModule(), value.second, MakeIntreSource(value.first));

        ASSERT_UNEQUAL_NULL_PTR(resource);
    }
}

void System::FindResourceTesting::FindResourceUseLanguageTest()
{
    constexpr LanguageIDData languageIDData{};

    for (const auto& value : container)
    {
        const auto resource = FindResourceInLibrary(GetDllModule(), value.second, MakeIntreSource(value.first), languageIDData);

        ASSERT_UNEQUAL_NULL_PTR(resource);
    }
}
