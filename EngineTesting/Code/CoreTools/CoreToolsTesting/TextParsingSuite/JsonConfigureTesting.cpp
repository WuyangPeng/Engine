///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/13 16:56)

#include "JsonConfigureTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Json/JsonGenerate.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/JsonConfigure/JsonConfigure/JsonConfigureContainer.h"
#include "Toolset/CoreTools/JsonConfigure/JsonConfigure/MonstersDetail.h"
#include "Toolset/CoreTools/JsonConfigure/JsonConfigure/PartsDetail.h"
#include "Toolset/CoreTools/JsonConfigure/JsonConfigure/RoadDetail.h"
#include "Toolset/CoreTools/JsonConfigure/JsonConfigure/RunScenesDetail.h"

using namespace std::literals;

CoreTools::JsonConfigureTesting::JsonConfigureTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonConfigureTesting)

void CoreTools::JsonConfigureTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonConfigureTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(JsonConfigureContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MonstersContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PartsContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RoadContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RunScenesContainerTest);
}

void CoreTools::JsonConfigureTesting::JsonConfigureContainerTest()
{
    const JsonConfigure::JsonConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/JsonConfigure"s) };

    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetMonstersContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetPartsContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetRoadContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetRunScenesContainer());
}

void CoreTools::JsonConfigureTesting::MonstersContainerTest()
{
    const JsonConfigure::JsonConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/JsonConfigure"s) };

    const auto monstersContainer = csvConfigureContainer.GetMonstersContainer();

    ASSERT_EQUAL(monstersContainer->GetSystem(), 5);
    ASSERT_EQUAL(monstersContainer->GetCoreTools(), 1);
    ASSERT_EQUAL(monstersContainer->GetNetwork(), SYSTEM_TEXT("Console"s));

    const std::vector test{ 1, 2, 3 };
    ASSERT_EQUAL(monstersContainer->GetTest(), test);

    const std::vector<System::String> consoleTest{ SYSTEM_TEXT("1"), SYSTEM_TEXT("Console"), SYSTEM_TEXT("3") };
    ASSERT_EQUAL(monstersContainer->GetConsoleTest(), consoleTest);

    const auto dataContainer = monstersContainer->GetDataContainer();
    ASSERT_EQUAL_FAILURE_THROW(dataContainer.size(), 1u, "monsters数组为空。");

    const auto data = monstersContainer->GetData(dataContainer.at(0)->GetId());
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(data, "monsters数组为空。");

    ASSERT_EQUAL(data->GetId(), dataContainer.at(0)->GetId());
    ASSERT_EQUAL(data->GetName(), dataContainer.at(0)->GetName());
}

void CoreTools::JsonConfigureTesting::PartsContainerTest()
{
    const JsonConfigure::JsonConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/JsonConfigure"s) };

    const auto partsContainer = csvConfigureContainer.GetPartsContainer();

    const auto dataContainer = partsContainer->GetDataContainer();
    ASSERT_EQUAL_FAILURE_THROW(dataContainer.size(), 1u, "parts数组为空。");

    const auto data = partsContainer->GetData(dataContainer.at(0)->GetId());
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(data, "parts数组为空。");
}

void CoreTools::JsonConfigureTesting::RoadContainerTest()
{
    const JsonConfigure::JsonConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/JsonConfigure"s) };

    const auto roadContainer = csvConfigureContainer.GetRoadContainer();

    const auto dataContainer = roadContainer->GetDataContainer();
    ASSERT_EQUAL_FAILURE_THROW(dataContainer.size(), 2u, "road数组为空。");

    const auto data = roadContainer->GetData(dataContainer.at(0)->GetId());
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(data, "road数组为空。");
}

void CoreTools::JsonConfigureTesting::RunScenesContainerTest()
{
    const JsonConfigure::JsonConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/JsonConfigure"s) };

    const auto runScenesContainer = csvConfigureContainer.GetRunScenesContainer();

    const auto dataContainer = runScenesContainer->GetDataContainer();
    ASSERT_EQUAL_FAILURE_THROW(dataContainer.size(), 1u, "runScenes数组为空。");

    const auto data = runScenesContainer->GetData(dataContainer.at(0)->GetId());
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(data, "runScenes数组为空。");
}
