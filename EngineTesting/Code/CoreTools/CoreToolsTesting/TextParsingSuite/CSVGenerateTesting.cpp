///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.5 (2021/10/17 12:49)

#include "CSVGenerateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSVContent.h"
#include "CoreTools/TextParsing/CSVGenerate.h"
#include "CoreTools/TextParsing/CSVHead.h"
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
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::BaseHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateChildHeadTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::ChildHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateContainerHeadTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::ContainerHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateContainerDetailHeadTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::ContainerDetailHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateBaseSourceTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::BaseSource };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateChildSourceTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::ChildSource };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateContainerSourceTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Chapter.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::ContainerSource };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalVectorTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Equip.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalTreeMapTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Hero.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalHashMapTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Scene.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalKeyTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/Skill.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalEnumHeadTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/VectorType.csv"s) };

    CSVGenerate csvGenerate{ csvContent, CSVGenerateType::EnumHead };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalEnumSourceTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/VectorType.csv"s) };

    CSVGenerate csvGenerate{ csvContent, CSVGenerateType::EnumSource };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalEnumTotalTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/LineType.csv"s) };

    CSVGenerate csvGenerate{ csvContent, CSVGenerateType::EnumTotal };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVGenerateTesting::CSVGenerateTotalUniqueTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVConfigure/SystemConstant.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    CSVGenerate csvGenerate{ csvHead, CSVGenerateType::Total };

    csvGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}
