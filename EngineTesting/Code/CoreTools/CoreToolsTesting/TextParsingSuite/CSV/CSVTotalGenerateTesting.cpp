/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 18:11)

#include "CSVTotalGenerateTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTotalGenerate.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <filesystem>

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
    const BatchConversionCSV batchConversionCSV{ SYSTEM_TEXT("Resource/CSVConfigure"), SYSTEM_TEXT("Resource/CSVConfigure") };
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateHeadTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure") };

    CSVTotalGenerate::CSVHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(CoreTools::StringConversion::StandardConversionWideChar(SYSTEM_TEXT("csv"))) != nativeFileName.size() - 3)
        {
            continue;
        }

        CSVContent csvContent{ StringConversion::WideCharConversionStandard(nativeFileName) };

        container.emplace_back(csvContent.GetCSVHead());
    }

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json") };

    const CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"), container, codeMappingAnalysis, CSVTotalGenerateType::Head };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"), SYSTEM_TEXT("Resource/CSVGenerate"));
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateFwdHeadTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure") };

    CSVTotalGenerate::CSVHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(CoreTools::StringConversion::StandardConversionWideChar(SYSTEM_TEXT("csv"))) != nativeFileName.size() - 3)
        {
            continue;
        }

        CSVContent csvContent{ StringConversion::WideCharConversionStandard(nativeFileName) };

        container.emplace_back(csvContent.GetCSVHead());
    }

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json") };

    const CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"), container, codeMappingAnalysis, CSVTotalGenerateType::FwdHead };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"), SYSTEM_TEXT("Resource/CSVGenerate"));
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateContainerHeadTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure") };

    CSVTotalGenerate::CSVHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(CoreTools::StringConversion::StandardConversionWideChar(SYSTEM_TEXT("csv"))) != nativeFileName.size() - 3)
        {
            continue;
        }

        CSVContent csvContent{ StringConversion::WideCharConversionStandard(nativeFileName) };

        container.emplace_back(csvContent.GetCSVHead());
    }

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json") };

    const CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"), container, codeMappingAnalysis, CSVTotalGenerateType::ContainerHead };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"), SYSTEM_TEXT("Resource/CSVGenerate"));
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateContainerSourceTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure") };

    CSVTotalGenerate::CSVHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = inputPath.path().native();

        if (nativeFileName.find(CoreTools::StringConversion::StandardConversionWideChar(SYSTEM_TEXT("csv"))) != nativeFileName.size() - 3)
        {
            continue;
        }

        CSVContent csvContent{ StringConversion::WideCharConversionStandard(nativeFileName) };

        container.emplace_back(csvContent.GetCSVHead());
    }

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json") };

    const CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"), container, codeMappingAnalysis, CSVTotalGenerateType::ContainerSource };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"), SYSTEM_TEXT("Resource/CSVGenerate"));
}
