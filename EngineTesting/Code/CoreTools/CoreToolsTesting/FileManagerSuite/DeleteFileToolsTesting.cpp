///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/03 09:14)

#include "DeleteFileToolsTesting.h"
#include "CoreTools/FileManager/CWriteFileManager.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::DeleteFileToolsTesting::DeleteFileToolsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DeleteFileToolsTesting)

void CoreTools::DeleteFileToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DeleteFileToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileSucceedTest);
}

void CoreTools::DeleteFileToolsTesting::DeleteFileSucceedTest()
{
    const auto deleteFileName = SYSTEM_TEXT("Resource/DeleteTestingText.txt"s);

    {
        CWriteFileManager manager{ deleteFileName };
    }

    DeleteFileTools deleteFileTools{ deleteFileName };
}
