///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:59)

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

using std::make_shared;
using std::string;
using std::vector;
using namespace std::literals;

CoreTools::FileAsynchronousTesting::FileAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }, callBackCount{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileAsynchronousTesting)

void CoreTools::FileAsynchronousTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FileAsynchronousTesting::MainTest()
{
    FileAsynchronous::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(ClearFile);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisteredWriteFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisteredWriteFileByEventTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisteredReadFileTest);

    FileAsynchronous::Destroy();
}

void CoreTools::FileAsynchronousTesting::ClearFile()
{
    WriteFileHandle handle{ GetFileName() };
}

void CoreTools::FileAsynchronousTesting::RegisteredWriteFileTest()
{
    FILE_ASYNCHRONOUS_SINGLETON.Run();

    const auto content = GetContent();
    const auto size = content.size();
    const auto bufferSize = size + sizeof(decltype(size));

    WriteBufferIO writeBuffer{ boost::numeric_cast<int>(bufferSize) };

    writeBuffer.Write(sizeof(decltype(size)), &size);
    writeBuffer.Write(sizeof(char), size, content.c_str());

    const auto fileBuffer = writeBuffer.GetFileBuffer();

    FILE_ASYNCHRONOUS_SINGLETON.RegisteredWriteFile(GetFileName(), true, fileBuffer, false);

    FILE_ASYNCHRONOUS_SINGLETON.Stop();
}

void CoreTools::FileAsynchronousTesting::RegisteredWriteFileByEventTest()
{
    FILE_ASYNCHRONOUS_SINGLETON.Run();

    const auto content = GetContent();
    const auto size = content.size();
    const auto bufferSize = size + sizeof(decltype(size));

    WriteBufferIO writeBuffer{ boost::numeric_cast<int>(bufferSize) };

    writeBuffer.Write(sizeof(decltype(size)), &size);
    writeBuffer.Write(sizeof(char), size, content.c_str());

    const auto fileBuffer = writeBuffer.GetFileBuffer();

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

System::String CoreTools::FileAsynchronousTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/FileAsynchronousTesting/FileAsynchronousText.txt"s);
}

string CoreTools::FileAsynchronousTesting::GetContent()
{
    return "FileAsynchronous Testing Text"s;
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

    ASSERT_EQUAL_FAILURE_THROW(fileBuffer.GetSize(), (GetContent().size() + sizeof(size_t)) * 2, "文件读取内容错误。");

    const auto content = GetContent();
    ReadBufferIO readBuffer{ make_shared<FileBuffer>(fileBuffer) };

    size_t size{ 0 };
    readBuffer.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, content.size());

    vector<char> buffer0(size);
    readBuffer.Read(sizeof(char), size, buffer0.data());

    string bufferContent0{ buffer0.begin(), buffer0.end() };

    ASSERT_EQUAL(bufferContent0, content);

    readBuffer.Read(sizeof(decltype(size)), &size);
    ASSERT_EQUAL(size, content.size());

    vector<char> buffer1(size);
    readBuffer.Read(sizeof(char), size, buffer1.data());

    string bufferContent1{ buffer1.begin(), buffer1.end() };

    ASSERT_EQUAL(bufferContent1, content);
}

void CoreTools::FileAsynchronousTesting::WriteEventFunction(const FileAsynchronousParameter& fileAsynchronousParameter)
{
    ASSERT_EQUAL(fileAsynchronousParameter.GetFileName(), GetFileName());
    ASSERT_FALSE(fileAsynchronousParameter.IsBinaryFile());
    ASSERT_EQUAL(fileAsynchronousParameter.GetEvent().lock(), shared_from_this());
    ASSERT_TRUE(fileAsynchronousParameter.IsAppend());

    const auto content = GetContent();
    ReadFileManager readFileManager{ GetFileName() };

    size_t size{ 0 };
    readFileManager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, content.size());

    vector<char> buffer0(size);
    readFileManager.Read(sizeof(char), size, buffer0.data());

    string bufferContent0{ buffer0.begin(), buffer0.end() };

    ASSERT_EQUAL(bufferContent0, content);

    readFileManager.Read(sizeof(decltype(size)), &size);
    ASSERT_EQUAL(size, content.size());

    vector<char> buffer1(size);
    readFileManager.Read(sizeof(char), size, buffer1.data());

    string bufferContent1{ buffer1.begin(), buffer1.end() };

    ASSERT_EQUAL(bufferContent1, content);
}
