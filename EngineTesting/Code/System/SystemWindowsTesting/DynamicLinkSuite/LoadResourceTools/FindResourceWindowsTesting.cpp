///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/10 22:25)

#include "FindResourceWindowsTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FindResourceWindowsTesting::FindResourceWindowsTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream, instance }
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
    for (const auto& typeName : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoFindResourceTest, typeName.second, typeName.first);
    }
}

void System::FindResourceWindowsTesting::FindResourceUseLanguageTest()
{
    for (const auto& typeName : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoFindResourceUseLanguageTest, typeName.second, typeName.first);
    }
}

void System::FindResourceWindowsTesting::DoFindResourceTest(const DynamicLinkCharType* type, WindowsWord name)
{
    const auto resource = FindResourceInLibrary(GetInstance(), type, MakeIntreSource(name));

    ASSERT_UNEQUAL_NULL_PTR(resource);
}

void System::FindResourceWindowsTesting::DoFindResourceUseLanguageTest(const DynamicLinkCharType* type, WindowsWord name)
{
    constexpr LanguageIDData languageIDData{};

    const auto resource = FindResourceInLibrary(GetInstance(), type, MakeIntreSource(name), languageIDData);

    ASSERT_UNEQUAL_NULL_PTR(resource);
}
