/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/30 19:45)

#include "ReadBufferIOTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadBufferIO.h"
#include "CoreTools/FileManager/WriteBufferIO.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

CoreTools::ReadBufferIOTesting::ReadBufferIOTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ReadBufferIOTesting)

void CoreTools::ReadBufferIOTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ReadBufferIOTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReadBufferIOBasisTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadBufferIOReadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetTextTest);
}

void CoreTools::ReadBufferIOTesting::ReadBufferIOBasisTest()
{
    const auto content = GetBufferIOContent();
    const auto size = GetBufferIOContentSize();
    const auto bufferSize = GetBufferSize();

    auto readBuffer = GetReadBufferIO(bufferSize, size, content);

    ASSERT_NOT_THROW_EXCEPTION_3(BytesTest, bufferSize, 0, readBuffer);

    const auto halfSize = boost::numeric_cast<int>(size / 2);

    readBuffer.IncrementBytesProcessed(halfSize);

    ASSERT_NOT_THROW_EXCEPTION_3(BytesTest, bufferSize, halfSize, readBuffer);
}

void CoreTools::ReadBufferIOTesting::BytesTest(int bytesTotal, int bytesProcessed, const ReadBufferIO& readBuffer)
{
    ASSERT_EQUAL(readBuffer.GetBytesTotal(), bytesTotal);
    ASSERT_EQUAL(readBuffer.GetBytesProcessed(), bytesProcessed);
}

CoreTools::ReadBufferIO CoreTools::ReadBufferIOTesting::GetReadBufferIO(int bufferSize, size_t size, const std::string& content)
{
    const auto writeBuffer = GetWriteBufferIO(bufferSize, size, content);

    const auto fileBuffer = writeBuffer.GetFileBuffer();

    return ReadBufferIO{ fileBuffer };
}

CoreTools::WriteBufferIO CoreTools::ReadBufferIOTesting::GetWriteBufferIO(int bufferSize, size_t size, const std::string& content)
{
    WriteBufferIO writeBuffer{ bufferSize };

    writeBuffer.Write(sizeof(decltype(size)), &size);
    writeBuffer.Write(sizeof(char), size, content.c_str());

    return writeBuffer;
}

void CoreTools::ReadBufferIOTesting::ReadBufferIOReadTest()
{
    const auto content = GetBufferIOContent();
    const auto size = GetBufferIOContentSize();
    const auto bufferSize = GetBufferSize();

    auto readBuffer = GetReadBufferIO(bufferSize, size, content);

    ASSERT_NOT_THROW_EXCEPTION_2(SizeTest, size, readBuffer);
    ASSERT_NOT_THROW_EXCEPTION_3(ResultTest, content, size, readBuffer);
    ASSERT_NOT_THROW_EXCEPTION_3(BytesTest, bufferSize, readBuffer.GetBytesTotal(), readBuffer);
    ASSERT_NOT_THROW_EXCEPTION_3(BytesTest, bufferSize, bufferSize, readBuffer);
}

void CoreTools::ReadBufferIOTesting::ResultTest(const std::string& content, size_t size, ReadBufferIO& readBuffer)
{
    BufferType read(size);
    readBuffer.Read(sizeof(char), size, read.data());

    const std::string result{ read.begin(), read.end() };
    ASSERT_EQUAL(result, content);
}

void CoreTools::ReadBufferIOTesting::SizeTest(size_t size, ReadBufferIO& readBuffer)
{
    size_t resultSize{};
    readBuffer.Read(sizeof(decltype(size)), &resultSize);
    ASSERT_EQUAL(size, resultSize);

    ASSERT_EQUAL(readBuffer.GetBytesProcessed(), boost::numeric_cast<int>(sizeof(decltype(size))));
}

void CoreTools::ReadBufferIOTesting::GetTextTest()
{
    const auto content = GetBufferIOContent();
    const auto size = GetBufferIOContentSize();
    const auto bufferSize = GetBufferSize();

    auto readBuffer = GetReadBufferIO(bufferSize, size, content);

    ASSERT_NOT_THROW_EXCEPTION_2(SizeTest, size, readBuffer);
    ASSERT_NOT_THROW_EXCEPTION_3(DoGetTextTest, content, size, readBuffer);
}

void CoreTools::ReadBufferIOTesting::DoGetTextTest(const std::string& content, size_t size, const ReadBufferIO& readBuffer)
{
    const auto result = readBuffer.GetText(boost::numeric_cast<int>(size));
    ASSERT_EQUAL(result, content);
}