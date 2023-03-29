///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/10 10:21)

#include "CSVTotalGenerateTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTotalGenerate.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <filesystem>

using namespace std::literals;

CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateTesting)

void CoreTools::CSVTotalGenerateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CSVTotalGenerateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateCSV);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVTotalGenerateHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVTotalGenerateFwdHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVTotalGenerateContainerHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVTotalGenerateContainerSourceTest);
}

void CoreTools::CSVTotalGenerateTesting::CreateCSV()
{
    const BatchConversionCSV batchConversionCSV{ SYSTEM_TEXT("Resource/CSVConfigure"s), SYSTEM_TEXT("Resource/CSVConfigure") };
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateHeadTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    CSVTotalGenerate::CSVHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(SYSTEM_TEXT("csv")) != nativeFileName.size() - 3)
        {
            continue;
        }

        CSVContent csvContent{ nativeFileName };

        container.emplace_back(csvContent.GetCSVHead());
    }

    const CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"s), container, CSVTotalGenerateType::Head };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateFwdHeadTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    CSVTotalGenerate::CSVHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(SYSTEM_TEXT("csv")) != nativeFileName.size() - 3)
        {
            continue;
        }

        CSVContent csvContent{ nativeFileName };

        container.emplace_back(csvContent.GetCSVHead());
    }

    const CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"s), container, CSVTotalGenerateType::FwdHead };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateContainerHeadTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    CSVTotalGenerate::CSVHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(SYSTEM_TEXT("csv")) != nativeFileName.size() - 3)
        {
            continue;
        }

        CSVContent csvContent{ nativeFileName };

        container.emplace_back(csvContent.GetCSVHead());
    }

    const CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"s), container, CSVTotalGenerateType::ContainerHead };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateContainerSourceTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    CSVTotalGenerate::CSVHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(SYSTEM_TEXT("csv")) != nativeFileName.size() - 3)
        {
            continue;
        }

        CSVContent csvContent{ nativeFileName };

        container.emplace_back(csvContent.GetCSVHead());
    }

    const CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"s), container, CSVTotalGenerateType::ContainerSource };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}
