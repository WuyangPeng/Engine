/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/07 21:38)

#include "NameMacroTesting.h"
#include "Detail/NameFinalMacro.h"
#include "Detail/NameMacro.h"
#include "Detail/NameMacroBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::NameMacroTesting::NameMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }, name{ "name" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NameMacroTesting)

void CoreTools::NameMacroTesting::DoRunUnitTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ObjectManager::Destroy();
}

void CoreTools::NameMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImplTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FinalTest);
}

void CoreTools::NameMacroTesting::BaseTest()
{
    NameMacroBase nameMacroBase{};

    ASSERT_NOT_THROW_EXCEPTION_1(BaseGetObjectByNameTest, nameMacroBase);
    ASSERT_NOT_THROW_EXCEPTION_1(BaseGetConstObjectByNameTest, nameMacroBase);
    ASSERT_NOT_THROW_EXCEPTION_1(BaseGetAllObjectsByNameTest, nameMacroBase);
    ASSERT_NOT_THROW_EXCEPTION_1(BaseGetAllConstObjectsByNameTest, nameMacroBase);
}

void CoreTools::NameMacroTesting::BaseGetObjectByNameTest(NameMacroBase& nameMacroBase)
{
    const auto result = nameMacroBase.GetObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(result, "查找对象失败。");
    ASSERT_FALSE(result->IsNullObject());
    ASSERT_EQUAL(result->GetName(), name);
}

void CoreTools::NameMacroTesting::BaseGetConstObjectByNameTest(const NameMacroBase& nameMacroBase)
{
    const auto constResult = nameMacroBase.GetConstObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(constResult, "查找对象失败。");
    ASSERT_FALSE(constResult->IsNullObject());
    ASSERT_EQUAL(constResult->GetName(), name);
}

void CoreTools::NameMacroTesting::BaseGetAllObjectsByNameTest(NameMacroBase& nameMacroBase)
{
    const auto container = nameMacroBase.GetAllObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(container.empty(), "查找对象失败。");
    for (const auto& object : container)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }
}

void CoreTools::NameMacroTesting::BaseGetAllConstObjectsByNameTest(const NameMacroBase& nameMacroBase)
{
    const auto constContainer = nameMacroBase.GetAllConstObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(constContainer.empty(), "查找对象失败。");
    for (const auto& object : constContainer)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }
}

void CoreTools::NameMacroTesting::ImplTest()
{
    const auto nameMacro = NameMacro::Create(name);

    ASSERT_NOT_THROW_EXCEPTION_1(ImplGetObjectByNameTest, *nameMacro);
    ASSERT_NOT_THROW_EXCEPTION_1(ImplGetConstObjectByNameTest, *nameMacro);
    ASSERT_NOT_THROW_EXCEPTION_1(ImplGetAllObjectsByNameTest, *nameMacro);
    ASSERT_NOT_THROW_EXCEPTION_1(ImplGetAllConstObjectsByNameTest, *nameMacro);
}

void CoreTools::NameMacroTesting::ImplGetObjectByNameTest(NameMacro& nameMacro)
{
    const auto result = nameMacro.GetObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(result, "查找对象失败。");
    ASSERT_FALSE(result->IsNullObject());
    ASSERT_EQUAL(result->GetName(), name);
}

void CoreTools::NameMacroTesting::ImplGetConstObjectByNameTest(const NameMacro& nameMacro)
{
    const auto constResult = nameMacro.GetConstObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(constResult, "查找对象失败。");
    ASSERT_FALSE(constResult->IsNullObject());
    ASSERT_EQUAL(constResult->GetName(), name);
}

void CoreTools::NameMacroTesting::ImplGetAllObjectsByNameTest(NameMacro& nameMacro)
{
    const auto container = nameMacro.GetAllObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(container.empty(), "查找对象失败。");
    for (const auto& object : container)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }
}

void CoreTools::NameMacroTesting::ImplGetAllConstObjectsByNameTest(const NameMacro& nameMacro)
{
    const auto constContainer = nameMacro.GetAllConstObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(constContainer.empty(), "查找对象失败。");
    for (const auto& object : constContainer)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }
}

void CoreTools::NameMacroTesting::FinalTest()
{
    const auto nameFinalMacro = NameFinalMacro::Create(name);

    ASSERT_NOT_THROW_EXCEPTION_1(FinalGetObjectByNameTest, *nameFinalMacro);
    ASSERT_NOT_THROW_EXCEPTION_1(FinalGetConstObjectByNameTest, *nameFinalMacro);
    ASSERT_NOT_THROW_EXCEPTION_1(FinalGetAllObjectsByNameTest, *nameFinalMacro);
    ASSERT_NOT_THROW_EXCEPTION_1(FinalGetAllConstObjectsByNameTest, *nameFinalMacro);
}

void CoreTools::NameMacroTesting::FinalGetObjectByNameTest(NameMacro& nameFinalMacro)
{
    const auto result = nameFinalMacro.GetObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(result, "查找对象失败。");
    ASSERT_FALSE(result->IsNullObject());
    ASSERT_EQUAL(result->GetName(), name);
}

void CoreTools::NameMacroTesting::FinalGetConstObjectByNameTest(const NameMacro& nameFinalMacro)
{
    const auto constResult = nameFinalMacro.GetConstObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(constResult, "查找对象失败。");
    ASSERT_FALSE(constResult->IsNullObject());
    ASSERT_EQUAL(constResult->GetName(), name);
}

void CoreTools::NameMacroTesting::FinalGetAllObjectsByNameTest(NameMacro& nameFinalMacro)
{
    const auto container = nameFinalMacro.GetAllObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(container.empty(), "查找对象失败。");
    for (const auto& object : container)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }
}

void CoreTools::NameMacroTesting::FinalGetAllConstObjectsByNameTest(const NameMacro& nameFinalMacro)
{
    const auto constContainer = nameFinalMacro.GetAllConstObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(constContainer.empty(), "查找对象失败。");
    for (const auto& object : constContainer)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }
}