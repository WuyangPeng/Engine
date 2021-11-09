///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.5 (2021/10/26 20:26)

#include "CSVTotalGenerateTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSVContent.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/CSVTotalGenerate.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <filesystem>

using namespace std::literals;
using std::vector;

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
    std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

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

    CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"s), container, CSVTotalGenerateType::Head };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateFwdHeadTest()
{
    std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

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

    CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"s), container, CSVTotalGenerateType::FwdHead };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateContainerHeadTest()
{
    std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

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

    CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"s), container, CSVTotalGenerateType::ContainerHead };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}

void CoreTools::CSVTotalGenerateTesting::CSVTotalGenerateContainerSourceTest()
{
    std::filesystem::path path{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

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

    CSVTotalGenerate csvTotalGenerate{ SYSTEM_TEXT("CSVConfigure"s), container, CSVTotalGenerateType::ContainerSource };

    csvTotalGenerate.GenerateFile(SYSTEM_TEXT("Resource/CSVGenerate"s));
}
