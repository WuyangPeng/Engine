///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:08)

#include "FindResourceTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/SystemOutput/Data/LanguageIdData.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FindResourceTesting::FindResourceTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    for (const auto& typeName : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoFindResourceTest, typeName.second, typeName.first);
    }
}

void System::FindResourceTesting::FindResourceUseLanguageTest()
{
    for (const auto& typeName : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoFindResourceUseLanguageTest, typeName.second, typeName.first);
    }
}

void System::FindResourceTesting::DoFindResourceTest(const DynamicLinkCharType* type, WindowsWord name)
{
    const auto resource = FindResourceInLibrary(GetDllModule(), type, MakeIntreSource(name));

    ASSERT_UNEQUAL_NULL_PTR(resource);
}

void System::FindResourceTesting::DoFindResourceUseLanguageTest(const DynamicLinkCharType* type, WindowsWord name)
{
    constexpr LanguageIdData languageIdData{};
    const auto resource = FindResourceInLibrary(GetDllModule(), type, MakeIntreSource(name), languageIdData);

    ASSERT_UNEQUAL_NULL_PTR(resource);
}
