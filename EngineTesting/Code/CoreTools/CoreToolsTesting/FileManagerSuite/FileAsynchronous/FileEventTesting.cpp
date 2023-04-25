///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:44)

#include "FileEventTesting.h"
#include "CoreTools/CoreToolsTesting/FileManagerSuite/Detail/FileEvent.h"
#include "CoreTools/FileManager/FileAsynchronousParameter.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

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
    const std::shared_ptr fileEvent{ FileEvent::Create() };
    const FileBuffer fileBuffer{ 100 };
    const FileAsynchronousParameter fileAsynchronousParameter{ GetFileName(), true, fileEvent };

    fileEvent->EventFunction(fileAsynchronousParameter, fileBuffer);
}
