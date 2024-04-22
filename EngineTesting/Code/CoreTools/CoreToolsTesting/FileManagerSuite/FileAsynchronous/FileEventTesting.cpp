/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:50)

#include "FileEventTesting.h"
#include "CoreTools/CoreToolsTesting/FileManagerSuite/Detail/FileEvent.h"
#include "CoreTools/FileManager/FileAsynchronousParameter.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

CoreTools::FileEventTesting::FileEventTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileEventTesting)

void CoreTools::FileEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FileEventTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileEventTest);
}

System::String CoreTools::FileEventTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/FileAsynchronousTesting/FileEventText.txt");
}

void CoreTools::FileEventTesting::FileEventTest()
{
    const std::shared_ptr fileEvent{ FileEvent::Create() };
    const FileBuffer fileBuffer{ 100 };
    const FileAsynchronousParameter fileAsynchronousParameter{ GetFileName(), true, fileEvent };

    fileEvent->EventFunction(fileAsynchronousParameter, fileBuffer);
}
