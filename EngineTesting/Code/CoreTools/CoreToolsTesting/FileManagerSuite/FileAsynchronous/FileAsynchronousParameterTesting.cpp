///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:59)

#include "FileAsynchronousParameterTesting.h"
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

CoreTools::FileAsynchronousParameterTesting::FileAsynchronousParameterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileAsynchronousParameterTesting)

void CoreTools::FileAsynchronousParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FileAsynchronousParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_THROW_EXCEPTION_0(FileBufferFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EventTest);
}

System::String CoreTools::FileAsynchronousParameterTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/FileAsynchronousTesting/FileAsynchronousParameterText.txt"s);
}

void CoreTools::FileAsynchronousParameterTesting::BaseTest()
{
    const std::shared_ptr<FileEventInterface> fileEvent{ FileEvent::Create() };
    FileAsynchronousParameter fileAsynchronousParameter{ GetFileName(), true, fileEvent };

    ASSERT_EQUAL(fileAsynchronousParameter.GetFileName(), GetFileName());
    ASSERT_TRUE(fileAsynchronousParameter.IsBinaryFile());
    ASSERT_EQUAL(fileAsynchronousParameter.GetEvent().lock(), fileEvent);
    ASSERT_FALSE(fileAsynchronousParameter.IsAppend());
}

void CoreTools::FileAsynchronousParameterTesting::FileBufferFailTest()
{
    const std::shared_ptr<FileEventInterface> fileEvent{ FileEvent::Create() };
    FileAsynchronousParameter fileAsynchronousParameter{ GetFileName(), true, fileEvent };
    MAYBE_UNUSED auto fileBuffer = fileAsynchronousParameter.GetFileBuffer();
}

void CoreTools::FileAsynchronousParameterTesting::FileBufferTest()
{
    const auto fileBuffer = make_shared<FileBuffer>(100);
    FileAsynchronousParameter fileAsynchronousParameter{ GetFileName(), false, fileBuffer, true };

    ASSERT_EQUAL(fileAsynchronousParameter.GetFileName(), GetFileName());
    ASSERT_FALSE(fileAsynchronousParameter.IsBinaryFile());
    ASSERT_TRUE(fileAsynchronousParameter.IsAppend());
    ASSERT_EQUAL(fileAsynchronousParameter.GetFileBuffer(), fileBuffer);
    ASSERT_EQUAL_NULL_PTR(fileAsynchronousParameter.GetEvent().lock());
}

void CoreTools::FileAsynchronousParameterTesting::EventTest()
{
    const std::shared_ptr<FileEventInterface> fileEvent{ FileEvent::Create() };
    const auto fileBuffer = make_shared<FileBuffer>(100);
    FileAsynchronousParameter fileAsynchronousParameter{ GetFileName(), false, fileEvent, fileBuffer, true };

    ASSERT_EQUAL(fileAsynchronousParameter.GetFileName(), GetFileName());
    ASSERT_FALSE(fileAsynchronousParameter.IsBinaryFile());
    ASSERT_TRUE(fileAsynchronousParameter.IsAppend());
    ASSERT_EQUAL(fileAsynchronousParameter.GetFileBuffer(), fileBuffer);
    ASSERT_EQUAL(fileAsynchronousParameter.GetEvent().lock(), fileEvent);
}
