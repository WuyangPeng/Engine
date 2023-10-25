///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 10:30)

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

using namespace std::literals;

CoreTools::CSVGenerateTesting::CSVGenerateTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    const BatchConversionCSV batchConversionCSV{ SYSTEM_TEXT("Resource/CSVConfigure"s), SYSTEM_TEXT("Resource/CSVConfigure") };
}

void CoreTools::CSVGenerateTesting::CSVGenerateBaseHeadTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::BaseHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateChildHeadTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ChildHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateContainerHeadTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ContainerHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateContainerDetailHeadTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ContainerDetailHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateBaseSourceTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::BaseSource };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateChildSourceTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ChildSource };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateContainerSourceTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::ContainerSource };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalVectorTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Equip.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalTreeMapTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Hero.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalHashMapTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Scene.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalKeyTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Skill.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalEnumHeadTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/VectorType.csv"s) };

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvContent, codeMappingAnalysis, CSVGenerateType::EnumHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalEnumSourceTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/VectorType.csv"s) };

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvContent, codeMappingAnalysis, CSVGenerateType::EnumSource };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalEnumTotalTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/LineType.csv"s) };

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvContent, codeMappingAnalysis, CSVGenerateType::EnumTotal };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalUniqueTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/SystemConstant.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

    const CodeMappingAnalysis codeMappingAnalysis{ SYSTEM_TEXT("Resource/CSVEngineering/CSVEngineering.json"s) };

    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVEngineering"s), SYSTEM_TEXT("Resource/CSVGenerate"s));
}
