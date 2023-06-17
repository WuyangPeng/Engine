///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.11 (2023/05/29 22:17)

#include "BatchConversionCodeTesting.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCode.h"
#include "CoreTools/TextParsing/CSV/ExcelConversionCSV.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <filesystem>

using namespace std::literals;

CoreTools::BatchConversionCodeTesting::BatchConversionCodeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BatchConversionCodeTesting)

void CoreTools::BatchConversionCodeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::BatchConversionCodeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BatchConversionCodeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VerifyTest);
}

void CoreTools::BatchConversionCodeTesting::BatchConversionCodeTest()
{
    const BatchConversionCode batchConversionCode{ SYSTEM_TEXT("Resource/OutputCSVTesting"s), SYSTEM_TEXT("Resource/OutputCodeTesting") };
}

void CoreTools::BatchConversionCodeTesting::VerifyTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/OutputCodeTesting"s) };

    auto haveFile = false;

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto fileName = inputPath.path().native();

        IFStreamManager ifStreamManager{ CoreTools::StringConversion::WideCharConversionStandard(fileName) };

        ASSERT_FALSE(ifStreamManager.GetFileContent().empty());

        haveFile = true;
    }

    ASSERT_TRUE(haveFile);
}
