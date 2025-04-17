/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/31 16:57)

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

CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateTesting(const OStreamShared& stream)
    : ParentType{ stream },
      directory{ SYSTEM_TEXT("Resource/CSVConfigure") },
      path{ directory }
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
    ASSERT_NOT_THROW_EXCEPTION_1(CSVTotalGenerateTest, CSVTotalGenerateType::Head);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVTotalGenerateTest, CSVTotalGenerateType::FwdHead);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVTotalGenerateTest, CSVTotalGenerateType::ContainerHead);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVTotalGenerateTest, CSVTotalGenerateType::ContainerSource);
}

void CoreTools::CSVTotalGenerateTesting::CreateCSV()
{
    const BatchConversionCSV batchConversionCSV{ directory, directory };
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateTest(CSVTotalGenerateType csvTotalGenerateType)
{
    const auto container = GetCSVHeadContainer();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json") };

    const CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"), container, codeMappingAnalysis, csvTotalGenerateType };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"), SYSTEM_TEXT("Resource/CSVGenerate"));
}

CoreTools::CSVTotalGenerateTesting::CSVHeadContainer CoreTools::CSVTotalGenerateTesting::GetCSVHeadContainer() const
{
    CSVHeadContainer container{};

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        if (const auto nativeFileName = inputPath.path().native();
            nativeFileName.find(StringConversion::FileSystemConversionStandard(SYSTEM_TEXT("csv"))) == nativeFileName.size() - 3)
        {
            CSVContent csvContent{ StringConversion::WideCharConversionStandard(nativeFileName) };

            container.emplace_back(csvContent.GetCSVHead());
        }
    }

    return container;
}
