/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/02 19:34)

#include "FileAsynchronousTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/SyncTools.h"
#include "CoreTools/FileManager/FileAsynchronous.h"
#include "CoreTools/FileManager/FileAsynchronousParameter.h"
#include "CoreTools/FileManager/ReadBufferIO.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteBufferIO.h"
#include "CoreTools/FileManager/WriteFileHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

CoreTools::FileAsynchronousTesting::FileAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }, callBackCount{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileAsynchronousTesting)

void CoreTools::FileAsynchronousTesting::DoRunUnitTest()
{
    FileAsynchronous::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    FileAsynchronous::Destroy();
}

void CoreTools::FileAsynchronousTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ClearFile);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisteredWriteFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisteredWriteFileByEventTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisteredReadFileTest);
}

System::String CoreTools::FileAsynchronousTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/FileAsynchronousTesting/FileAsynchronousText.txt");
}

std::string CoreTools::FileAsynchronousTesting::GetContent()
{
    return "FileAsynchronous Testing Text";
}

size_t CoreTools::FileAsynchronousTesting::GetContentSize()
{
    const auto content = GetContent();

    return content.size();
}

int CoreTools::FileAsynchronousTesting::GetBufferSize()
{
    const auto size = GetContentSize();

    return boost::numeric_cast<int>(size + sizeof(decltype(size)));
}

void CoreTools::FileAsynchronousTesting::ClearFile()
{
    WriteFileHandle handle{ GetFileName() };
}

void CoreTools::FileAsynchronousTesting::RegisteredWriteFileTest()
{
    FILE_ASYNCHRONOUS_SINGLETON.Run();

    const auto fileBuffer = GetFileBuffer();

    FILE_ASYNCHRONOUS_SINGLETON.RegisteredWriteFile(GetFileName(), true, fileBuffer, false);

    FILE_ASYNCHRONOUS_SINGLETON.Stop();
}

CoreTools::WriteBufferIO CoreTools::FileAsynchronousTesting::GetWriteBuffer(const std::string& content, size_t size, int bufferSize)
{
    WriteBufferIO writeBuffer{ bufferSize };

    writeBuffer.Write(sizeof(decltype(size)), &size);
    writeBuffer.Write(sizeof(char), size, content.c_str());

    return writeBuffer;
}

CoreTools::ConstFileBufferSharedPtr CoreTools::FileAsynchronousTesting::GetFileBuffer()
{
    const auto content = GetContent();
    const auto size = GetContentSize();
    const auto bufferSize = GetBufferSize();

    const auto writeBuffer = GetWriteBuffer(content, size, bufferSize);

    return writeBuffer.GetFileBuffer();
}

void CoreTools::FileAsynchronousTesting::RegisteredWriteFileByEventTest()
{
    FILE_ASYNCHRONOUS_SINGLETON.Run();

    const auto fileBuffer = GetFileBuffer();

    FILE_ASYNCHRONOUS_SINGLETON.RegisteredWriteFile(GetFileName(), false, shared_from_this(), fileBuffer, true);

    FILE_ASYNCHRONOUS_SINGLETON.Stop();

    ASSERT_EQUAL(callBackCount, 1);
}

void CoreTools::FileAsynchronousTesting::RegisteredReadFileTest()
{
    FILE_ASYNCHRONOUS_SINGLETON.Run();

    FILE_ASYNCHRONOUS_SINGLETON.RegisteredReadFile(GetFileName(), true, shared_from_this());

    FILE_ASYNCHRONOUS_SINGLETON.Stop();

    ASSERT_EQUAL(callBackCount, 2);
}

void CoreTools::FileAsynchronousTesting::EventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer)
{
    if (fileAsynchronousParameter.IsAppend())
    {
        WriteEventFunction(fileAsynchronousParameter);
    }
    else
    {
        ReadEventFunction(fileAsynchronousParameter, fileBuffer);
    }

    ++callBackCount;
}

void CoreTools::FileAsynchronousTesting::ReadEventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer)
{
    ASSERT_EQUAL(fileAsynchronousParameter.GetFileName(), GetFileName());
    ASSERT_TRUE(fileAsynchronousParameter.IsBinaryFile());
    ASSERT_EQUAL(fileAsynchronousParameter.GetEvent().lock(), shared_from_this());
    ASSERT_FALSE(fileAsynchronousParameter.IsAppend());

    ASSERT_EQUAL_FAILURE_THROW(fileBuffer.GetSize(), boost::numeric_cast<int>((GetContentSize() + sizeof(size_t)) * 2), "文件读取内容错误。");

    const auto content = GetContent();
    ReadBufferIO readBuffer{ std::make_shared<FileBuffer>(fileBuffer) };

    ASSERT_NOT_THROW_EXCEPTION_1(ResultTest, readBuffer);
    ASSERT_NOT_THROW_EXCEPTION_1(ResultTest, readBuffer);
}

void CoreTools::FileAsynchronousTesting::ResultTest(ReadBufferIO& readBuffer)
{
    auto size = SizeTest(readBuffer);

    ASSERT_NOT_THROW_EXCEPTION_2(ReadBufferSize, readBuffer, size);
}

size_t CoreTools::FileAsynchronousTesting::SizeTest(ReadBufferIO& readBuffer)
{
    size_t size{ 0u };
    readBuffer.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, GetContentSize());

    return size;
}

void CoreTools::FileAsynchronousTesting::ReadBufferSize(ReadBufferIO& readBuffer, size_t size)
{
    BufferType buffer(size);
    readBuffer.Read(sizeof(char), size, buffer.data());

    const std::string content{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(content, GetContent());
}

void CoreTools::FileAsynchronousTesting::WriteEventFunction(const FileAsynchronousParameter& fileAsynchronousParameter)
{
    ASSERT_EQUAL(fileAsynchronousParameter.GetFileName(), GetFileName());
    ASSERT_FALSE(fileAsynchronousParameter.IsBinaryFile());
    ASSERT_EQUAL(fileAsynchronousParameter.GetEvent().lock(), shared_from_this());
    ASSERT_TRUE(fileAsynchronousParameter.IsAppend());

    const auto content = GetContent();
    ReadFileManager readFileManager{ GetFileName() };

    ASSERT_NOT_THROW_EXCEPTION_1(ReadFileResultTest, readFileManager);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadFileResultTest, readFileManager);
}

void CoreTools::FileAsynchronousTesting::ReadFileResultTest(ReadFileManager& readFileManager)
{
    auto size = FileSizeTest(readFileManager);

    ASSERT_NOT_THROW_EXCEPTION_2(ReadFileManagerSize, readFileManager, size);
}

size_t CoreTools::FileAsynchronousTesting::FileSizeTest(ReadFileManager& readFileManager)
{
    size_t size{ 0u };
    readFileManager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, GetContentSize());

    return size;
}

void CoreTools::FileAsynchronousTesting::ReadFileManagerSize(ReadFileManager& readFileManager, size_t size)
{
    BufferType buffer(size);
    readFileManager.Read(sizeof(char), size, buffer.data());

    const std::string content{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(content, GetContent());
}
