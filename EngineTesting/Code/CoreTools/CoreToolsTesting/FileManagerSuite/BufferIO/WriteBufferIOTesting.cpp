/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/28 21:52)

#include "WriteBufferIOTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadBufferIO.h"
#include "CoreTools/FileManager/WriteBufferIO.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

CoreTools::WriteBufferIOTesting::WriteBufferIOTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WriteBufferIOTesting)

void CoreTools::WriteBufferIOTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::WriteBufferIOTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteBufferIOBasisTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteBufferIOWriteTest);
}

void CoreTools::WriteBufferIOTesting::WriteBufferIOBasisTest()
{
    const auto content = GetBufferIOContent();
    const auto bufferSize = GetBufferSize();

    WriteBufferIO writeBuffer{ bufferSize };

    ASSERT_NOT_THROW_EXCEPTION_3(BytesTest, bufferSize, 0, writeBuffer);

    const auto halfSize = boost::numeric_cast<int>(bufferSize / 2);

    writeBuffer.IncrementBytesProcessed(halfSize);

    ASSERT_NOT_THROW_EXCEPTION_3(BytesTest, bufferSize, halfSize, writeBuffer);
}

void CoreTools::WriteBufferIOTesting::BytesTest(int bytesTotal, int bytesProcessed, const WriteBufferIO& writeBuffer)
{
    ASSERT_EQUAL(writeBuffer.GetBytesTotal(), bytesTotal);
    ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), bytesProcessed);
}

void CoreTools::WriteBufferIOTesting::WriteBufferIOWriteTest()
{
    const auto content = GetBufferIOContent();
    const auto size = GetBufferIOContentSize();
    const auto bufferSize = GetBufferSize();

    WriteBufferIO writeBuffer{ bufferSize };
    WriteTest(content, size, bufferSize, writeBuffer);

    const auto fileBuffer = writeBuffer.GetFileBuffer();

    ReadBufferIO readBuffer{ fileBuffer };
    ASSERT_NOT_THROW_EXCEPTION_3(ReadBufferTest, content, size, readBuffer);
}

void CoreTools::WriteBufferIOTesting::WriteTest(const std::string& content, size_t size, int bufferSize, WriteBufferIO& writeBuffer)
{
    writeBuffer.Write(sizeof(decltype(size)), &size);
    ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), boost::numeric_cast<int>(sizeof(decltype(size))));

    writeBuffer.Write(sizeof(char), size, content.c_str());
    ASSERT_NOT_THROW_EXCEPTION_3(BytesTest, bufferSize, writeBuffer.GetBytesTotal(), writeBuffer);
    ASSERT_NOT_THROW_EXCEPTION_3(BytesTest, bufferSize, bufferSize, writeBuffer);
}

void CoreTools::WriteBufferIOTesting::ReadBufferTest(const std::string& content, size_t size, ReadBufferIO& readBuffer)
{
    ASSERT_NOT_THROW_EXCEPTION_2(SizeTest, size, readBuffer);

    ASSERT_NOT_THROW_EXCEPTION_3(DoReadBufferTest, content, size, readBuffer);
}

void CoreTools::WriteBufferIOTesting::SizeTest(size_t size, ReadBufferIO& readBuffer)
{
    size_t result{};
    readBuffer.Read(sizeof(decltype(size)), &result);
    ASSERT_EQUAL(size, result);
}

void CoreTools::WriteBufferIOTesting::DoReadBufferTest(const std::string& content, size_t size, CoreTools::ReadBufferIO& readBuffer)
{
    BufferType buffer(size);
    readBuffer.Read(sizeof(char), size, buffer.data());
    const std::string result{ buffer.begin(), buffer.end() };
    ASSERT_EQUAL(result, content);
}
