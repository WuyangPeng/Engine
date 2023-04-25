///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:09)

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
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::NameMacroTesting::MainTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImplTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FinalTest);

    ObjectManager::Destroy();
}

void CoreTools::NameMacroTesting::BaseTest()
{
    NameMacroBase nameMacroBase{};

    const auto result = nameMacroBase.GetObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(result, "查找对象失败。");
    ASSERT_FALSE(result->IsNullObject());
    ASSERT_EQUAL(result->GetName(), name);

    const auto constResult = nameMacroBase.GetConstObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(constResult, "查找对象失败。");
    ASSERT_FALSE(constResult->IsNullObject());
    ASSERT_EQUAL(constResult->GetName(), name);

    const auto container = nameMacroBase.GetAllObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(container.empty(), "查找对象失败。");
    for (const auto object : container)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }

    const auto constContainer = nameMacroBase.GetAllConstObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(constContainer.empty(), "查找对象失败。");
    for (const auto object : constContainer)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }
}

void CoreTools::NameMacroTesting::ImplTest()
{
    const auto nameMacro = NameMacro::Create(name);

    const auto result = nameMacro->GetObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(result, "查找对象失败。");
    ASSERT_FALSE(result->IsNullObject());
    ASSERT_EQUAL(result->GetName(), name);

    const auto constResult = nameMacro->GetConstObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(constResult, "查找对象失败。");
    ASSERT_FALSE(constResult->IsNullObject());
    ASSERT_EQUAL(constResult->GetName(), name);

    const auto container = nameMacro->GetAllObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(container.empty(), "查找对象失败。");
    for (const auto object : container)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }

    const auto constContainer = nameMacro->GetAllConstObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(constContainer.empty(), "查找对象失败。");
    for (const auto object : constContainer)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }
}

void CoreTools::NameMacroTesting::FinalTest()
{
    const auto nameFinalMacro = NameFinalMacro::Create(name);

    const auto result = nameFinalMacro->GetObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(result, "查找对象失败。");
    ASSERT_FALSE(result->IsNullObject());
    ASSERT_EQUAL(result->GetName(), name);

    const auto constResult = nameFinalMacro->GetConstObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(constResult, "查找对象失败。");
    ASSERT_FALSE(constResult->IsNullObject());
    ASSERT_EQUAL(constResult->GetName(), name);

    const auto container = nameFinalMacro->GetAllObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(container.empty(), "查找对象失败。");
    for (const auto object : container)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }

    const auto constContainer = nameFinalMacro->GetAllConstObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(constContainer.empty(), "查找对象失败。");
    for (const auto object : constContainer)
    {
        ASSERT_EQUAL(object->GetName(), name);
    }
}
