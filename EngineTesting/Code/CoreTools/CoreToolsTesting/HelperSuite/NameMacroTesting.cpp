///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:38)

#include "NameMacroTesting.h"
#include "Detail/NameFinalMacro.h"
#include "Detail/NameMacro.h"
#include "Detail/NameMacroBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::make_shared;
using std::string;

CoreTools::NameMacroTesting::NameMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    string name{ "name" };

    auto result = nameMacroBase.GetObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(result, "查找对象失败。");
    ASSERT_EQUAL(result->GetName(), name);

    auto constResult = nameMacroBase.GetConstObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(constResult, "查找对象失败。");
    ASSERT_EQUAL(constResult->GetName(), name);

    auto container = nameMacroBase.GetAllObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(container.empty(), "查找对象失败。");
    ASSERT_EQUAL(container.at(0)->GetName(), name);

    auto constContainer = nameMacroBase.GetAllConstObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(constContainer.empty(), "查找对象失败。");
    ASSERT_EQUAL(constContainer.at(0)->GetName(), name);
}

void CoreTools::NameMacroTesting::ImplTest()
{
    string name{ "name" };
    auto nameMacro = NameMacro::Create(name);

    auto result = nameMacro->GetObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(result, "查找对象失败。");
    ASSERT_EQUAL(result->GetName(), name);

    auto constResult = nameMacro->GetConstObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(constResult, "查找对象失败。");
    ASSERT_EQUAL(constResult->GetName(), name);

    auto container = nameMacro->GetAllObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(container.empty(), "查找对象失败。");
    ASSERT_EQUAL(container.at(0)->GetName(), name);

    auto constContainer = nameMacro->GetAllConstObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(constContainer.empty(), "查找对象失败。");
    ASSERT_EQUAL(constContainer.at(0)->GetName(), name);
}

void CoreTools::NameMacroTesting::FinalTest()
{
    string name{ "name" };
    auto nameFinalMacro = NameFinalMacro::Create(name);

    auto result = nameFinalMacro->GetObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(result, "查找对象失败。");
    ASSERT_EQUAL(result->GetName(), name);

    auto constResult = nameFinalMacro->GetConstObjectByName(name);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(constResult, "查找对象失败。");
    ASSERT_EQUAL(constResult->GetName(), name);

    auto container = nameFinalMacro->GetAllObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(container.empty(), "查找对象失败。");
    ASSERT_EQUAL(container.at(0)->GetName(), name);

    auto constContainer = nameFinalMacro->GetAllConstObjectsByName(name);
    ASSERT_FALSE_FAILURE_THROW(constContainer.empty(), "查找对象失败。");
    ASSERT_EQUAL(constContainer.at(0)->GetName(), name);
}
