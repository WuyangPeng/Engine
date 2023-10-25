///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 20:36)

#include "WriteBufferIOTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadBufferIO.h"
#include "CoreTools/FileManager/WriteBufferIO.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

using namespace std::literals;

std::string CoreTools::WriteBufferIOTesting::GetBufferIOContent()
{
    return "BufferIO Testing Text"s;
}

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

    const auto size = boost::numeric_cast<int>(content.size());
    WriteBufferIO writeBuffer{ size };

    ASSERT_EQUAL(writeBuffer.GetBytesTotal(), size);
    ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), 0);

    writeBuffer.IncrementBytesProcessed(size / 2);

    ASSERT_EQUAL(writeBuffer.GetBytesTotal(), size);
    ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), size / 2);
}

void CoreTools::WriteBufferIOTesting::WriteBufferIOWriteTest()
{
    const auto content = GetBufferIOContent();
    const auto size = content.size();
    const auto bufferSize = size + sizeof(decltype(size));

    WriteBufferIO writeBuffer{ boost::numeric_cast<int>(bufferSize) };

    writeBuffer.Write(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), boost::numeric_cast<int>(sizeof(decltype(size))));

    writeBuffer.Write(sizeof(char), size, content.c_str());

    ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), writeBuffer.GetBytesTotal());
    ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), boost::numeric_cast<int>(bufferSize));

    const auto fileBuffer = writeBuffer.GetFileBuffer();

    ReadBufferIO readBuffer{ fileBuffer };

    size_t resultSize{};
    readBuffer.Read(sizeof(decltype(size)), &resultSize);
    ASSERT_EQUAL(size, resultSize);

    BufferType result(resultSize);
    readBuffer.Read(sizeof(char), resultSize, result.data());
    const std::string testResult{ result.begin(), result.end() };
    ASSERT_EQUAL(testResult, content);
}
