/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:24)

#include "BatchConversionCSVTesting.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <filesystem>

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
    const BatchConversionCSV batchConversionCSV{ SYSTEM_TEXT("Resource/InputCSVTesting"), SYSTEM_TEXT("Resource/OutputCSVTesting") };
}

void CoreTools::BatchConversionCSVTesting::VerifyTest()
{
    const std::filesystem::path path{ SYSTEM_TEXT("Resource/OutputCSVTesting") };

    auto haveFile = false;

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto fileName = inputPath.path().native();

        IFileStreamManager ifStreamManager{ StringConversion::FileSystemConversionStandard(fileName) };

        ASSERT_FALSE(ifStreamManager.GetFileContent().empty());

        haveFile = true;
    }

    ASSERT_TRUE(haveFile);
}
