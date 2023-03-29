///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/10 15:15)

#include "JsonTotalGenerateTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonTotalGenerate.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <filesystem>

using namespace std::literals;

CoreTools::JsonTotalGenerateTesting::JsonTotalGenerateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonTotalGenerateTesting)

void CoreTools::JsonTotalGenerateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonTotalGenerateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(JsonTotalGenerateHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(JsonTotalGenerateFwdHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(JsonTotalGenerateContainerHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(JsonTotalGenerateContainerSourceTest);
}

void CoreTools::JsonTotalGenerateTesting::JsonTotalGenerateHeadTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/JsonConfigure"s) };

    JsonTotalGenerate::JsonHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(SYSTEM_TEXT("json")) != nativeFileName.size() - 4)
        {
            continue;
        }

        JsonHead jsonHead{ nativeFileName };

        container.emplace_back(jsonHead);
    }

    const JsonTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("JsonConfigure"s), container, JsonTotalGenerateType::Head };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonTotalGenerateTesting::JsonTotalGenerateFwdHeadTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/JsonConfigure"s) };

    JsonTotalGenerate::JsonHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(SYSTEM_TEXT("json")) != nativeFileName.size() - 4)
        {
            continue;
        }

        JsonHead jsonHead{ nativeFileName };

        container.emplace_back(jsonHead);
    }

    const JsonTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("JsonConfigure"s), container, JsonTotalGenerateType::FwdHead };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonTotalGenerateTesting::JsonTotalGenerateContainerHeadTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/JsonConfigure"s) };

    JsonTotalGenerate::JsonHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(SYSTEM_TEXT("json")) != nativeFileName.size() - 4)
        {
            continue;
        }

        JsonHead jsonHead{ nativeFileName };

        container.emplace_back(jsonHead);
    }

    const JsonTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("JsonConfigure"s), container, JsonTotalGenerateType::ContainerHead };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonTotalGenerateTesting::JsonTotalGenerateContainerSourceTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/JsonConfigure"s) };

    JsonTotalGenerate::JsonHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(SYSTEM_TEXT("json")) != nativeFileName.size() - 4)
        {
            continue;
        }

        JsonHead jsonHead{ nativeFileName };

        container.emplace_back(jsonHead);
    }

    const JsonTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("JsonConfigure"s), container, JsonTotalGenerateType::ContainerSource };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}
