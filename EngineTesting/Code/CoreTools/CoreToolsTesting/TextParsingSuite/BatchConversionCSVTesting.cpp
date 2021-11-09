///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/15 14:23)

#include "BatchConversionCSVTesting.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/BatchConversionCSV.h"
#include "CoreTools/TextParsing/ExcelConversionCSV.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <filesystem>

using namespace std::literals;

CoreTools::BatchConversionCSVTesting::BatchConversionCSVTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BatchConversionCSVTesting)

void CoreTools::BatchConversionCSVTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::BatchConversionCSVTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BatchConversionCSVTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VerifyTest);
}

void CoreTools::BatchConversionCSVTesting::BatchConversionCSVTest()
{
    const BatchConversionCSV batchConversionCSV{ SYSTEM_TEXT("Resource/InputCSVTesting"s), SYSTEM_TEXT("Resource/OutputCSVTesting") };
}

void CoreTools::BatchConversionCSVTesting::VerifyTest()
{
    std::filesystem::path path{ SYSTEM_TEXT("Resource/OutputCSVTesting"s) };

    auto haveFile = false;

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        auto fileName = inputPath.path().native();

        IFStreamManager ifStreamManager{ fileName };

        ASSERT_FALSE(ifStreamManager.GetFileContent().empty());

        haveFile = true;
    }

    ASSERT_TRUE(haveFile);
}
