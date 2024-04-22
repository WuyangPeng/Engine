/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:11)

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

std::string CoreTools::ReadBufferIOTesting::GetBufferIOContent()
{
    return "BufferIO Testing Text";
}

void CoreTools::ReadBufferIOTesting::ReadBufferIOBasisTest()
{
    const auto content = GetBufferIOContent();
    const auto size = content.size();
    const auto bufferSize = size + sizeof(decltype(size));

    WriteBufferIO writeBuffer{ boost::numeric_cast<int>(bufferSize) };

    writeBuffer.Write(sizeof(decltype(size)), &size);
    writeBuffer.Write(sizeof(char), size, content.c_str());

    const auto fileBuffer = writeBuffer.GetFileBuffer();

    ReadBufferIO readBuffer{ fileBuffer };

    ASSERT_EQUAL(readBuffer.GetBytesTotal(), boost::numeric_cast<int>(bufferSize));
    ASSERT_EQUAL(readBuffer.GetBytesProcessed(), 0);

    readBuffer.IncrementBytesProcessed(boost::numeric_cast<int>(size / 2));

    ASSERT_EQUAL(readBuffer.GetBytesTotal(), boost::numeric_cast<int>(bufferSize));
    ASSERT_EQUAL(readBuffer.GetBytesProcessed(), boost::numeric_cast<int>(size / 2));
}

void CoreTools::ReadBufferIOTesting::ReadBufferIOReadTest()
{
    const auto content = GetBufferIOContent();
    const auto size = content.size();
    const auto bufferSize = size + sizeof(decltype(size));

    WriteBufferIO writeBuffer{ boost::numeric_cast<int>(bufferSize) };

    writeBuffer.Write(sizeof(decltype(size)), &size);
    writeBuffer.Write(sizeof(char), size, content.c_str());

    const auto fileBuffer = writeBuffer.GetFileBuffer();

    ReadBufferIO readBuffer{ fileBuffer };

    size_t resultSize{};
    readBuffer.Read(sizeof(decltype(size)), &resultSize);
    ASSERT_EQUAL(size, resultSize);

    ASSERT_EQUAL(readBuffer.GetBytesProcessed(), boost::numeric_cast<int>(sizeof(decltype(size))));

    BufferType result(resultSize);
    readBuffer.Read(sizeof(char), resultSize, result.data());
    const std::string testResult{ result.begin(), result.end() };
    ASSERT_EQUAL(testResult, content);

    ASSERT_EQUAL(readBuffer.GetBytesProcessed(), readBuffer.GetBytesTotal());
    ASSERT_EQUAL(readBuffer.GetBytesProcessed(), boost::numeric_cast<int>(bufferSize));
}

void CoreTools::ReadBufferIOTesting::GetTextTest()
{
    const auto content = GetBufferIOContent();
    const auto size = content.size();
    const auto bufferSize = size + sizeof(decltype(size));

    WriteBufferIO writeBuffer{ boost::numeric_cast<int>(bufferSize) };

    writeBuffer.Write(sizeof(decltype(size)), &size);
    writeBuffer.Write(sizeof(char), size, content.c_str());

    const auto fileBuffer = writeBuffer.GetFileBuffer();

    ReadBufferIO readBuffer{ fileBuffer };

    size_t resultSize{};
    readBuffer.Read(sizeof(decltype(size)), &resultSize);
    ASSERT_EQUAL(size, resultSize);

    ASSERT_EQUAL(readBuffer.GetBytesProcessed(), boost::numeric_cast<int>(sizeof(decltype(size))));

    const auto testResult = readBuffer.GetText(boost::numeric_cast<int>(resultSize));
    ASSERT_EQUAL(testResult, content);
}
