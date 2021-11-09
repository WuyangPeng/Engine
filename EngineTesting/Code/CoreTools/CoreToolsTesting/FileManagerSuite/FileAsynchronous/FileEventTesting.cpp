///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/08 14:21)

#include "FileEventTesting.h"
#include "CoreTools/CoreToolsTesting/FileManagerSuite/Detail/FileEvent.h"
#include "CoreTools/FileManager/FileAsynchronousParameter.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

using std::make_shared;
using std::string;
using namespace std::literals;

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
    return SYSTEM_TEXT("Resource/FileAsynchronousTesting/FileEventText.txt"s);
}

void CoreTools::FileEventTesting::FileEventTest()
{
    const std::shared_ptr<FileEventInterface> fileEvent{ FileEvent::Create() };
    const FileBuffer fileBuffer{ 100 };
    FileAsynchronousParameter fileAsynchronousParameter{ GetFileName(), true, fileEvent };

    fileEvent->EventFunction(fileAsynchronousParameter, fileBuffer);
}
