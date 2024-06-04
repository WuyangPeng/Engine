/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/31 16:04)

#include "CSVGenerateTesting.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVGenerate.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CSVGenerateTesting::CSVGenerateTesting(const OStreamShared& stream)
    : ParentType{ stream },
      directory{ SYSTEM_TEXT("Resource/CSVConfigure") },
      csvEngineeringDirectory{ SYSTEM_TEXT("Resource/CSVEngineering") },
      csvGenerateDirectory{ SYSTEM_TEXT("Resource/CSVGenerate") },
      csvEngineeringJson{ SYSTEM_TEXT("/CSVEngineering.json") }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateTesting)

void CoreTools::CSVGenerateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CSVGenerateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateCSV);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateBaseHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateChildHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateContainerHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateContainerDetailHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateBaseSourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateChildSourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateContainerSourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateTotalVectorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateTotalTreeMapTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateTotalHashMapTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateTotalKeyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateTotalEnumHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateTotalEnumSourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateTotalEnumTotalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateTotalUniqueTest);
}

void CoreTools::CSVGenerateTesting::CreateCSV()
{
    const BatchConversionCSV batchConversionCSV{ directory, directory };
}

void CoreTools::CSVGenerateTesting::CSVGenerateBaseHeadTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Chapter.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::BaseHead };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateChildHeadTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Chapter.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ChildHead };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateContainerHeadTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Chapter.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ContainerHead };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateContainerDetailHeadTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Chapter.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ContainerDetailHead };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateBaseSourceTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Chapter.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::BaseSource };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateChildSourceTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Chapter.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ChildSource };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateContainerSourceTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Chapter.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ContainerSource };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalVectorTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Equip.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalTreeMapTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Hero.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalHashMapTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Scene.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalKeyTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/Skill.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalEnumHeadTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/VectorType.csv") };

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvContent, codeMappingAnalysis, CSVGenerateType::EnumHead };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalEnumSourceTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/VectorType.csv") };

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvContent, codeMappingAnalysis, CSVGenerateType::EnumSource };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalEnumTotalTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/LineType.csv") };

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvContent, codeMappingAnalysis, CSVGenerateType::EnumTotal };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalUniqueTest()
{
    const CSVContent csvContent{ directory + SYSTEM_TEXT("/SystemConstant.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ csvEngineeringDirectory + csvEngineeringJson };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(csvEngineeringDirectory, csvGenerateDirectory);
}
