///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 19:14)

#include "FileBufferTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <gsl/util>

CoreTools::FileBufferTesting::FileBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileBufferTesting)

void CoreTools::FileBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FileBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ForEachTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyBufferTest);
}

void CoreTools::FileBufferTesting::ValueTest()
{
    FileBuffer buffer{ 10 };

    ASSERT_EQUAL(buffer.GetSize(), 10);

    const auto begin = buffer.GetBufferBegin();

    ASSERT_UNEQUAL_NULL_PTR(begin);
}

void CoreTools::FileBufferTesting::Init(FileBuffer& fileBuffer, int step) const
{
    for (auto i = 0; i < fileBuffer.GetSize(); ++i)
    {
        *fileBuffer.GetBuffer(i) = boost::numeric_cast<char>(i + step);
    }
}

void CoreTools::FileBufferTesting::DelayCopyTest()
{
    FileBuffer buffer0{ 11 };
    const auto beginPtr0 = buffer0.GetBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr0, "beginPtr0指针为空。");

    ASSERT_NOT_THROW_EXCEPTION_2(Init, buffer0, 0);

    const FileBuffer buffer1{ buffer0 };
    ASSERT_EQUAL(buffer1.GetSize(), buffer0.GetSize());

    const auto beginPtr1 = buffer1.GetConstBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr1, "beginPtr1指针为空。");

    // beginPtr0和beginPtr1依然指向同一个副本。
    ASSERT_EQUAL(beginPtr0, beginPtr1);

    FileBuffer buffer2{ buffer0 };

    const auto beginPtr2 = buffer2.GetBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr2, "beginPtr2指针为空。");

    // beginPtr2指向另一个副本。
    ASSERT_UNEQUAL(beginPtr0, beginPtr2);
    ASSERT_UNEQUAL(beginPtr1, beginPtr2);

    ASSERT_NOT_THROW_EXCEPTION_2(Init, buffer2, 100);

    // beginPtr0和beginPtr1的值没有改变

    for (auto i = 0; i < buffer0.GetSize(); ++i)
    {
        ASSERT_EQUAL(*buffer0.GetConstBuffer(i), *buffer1.GetConstBuffer(i));
        ASSERT_EQUAL(*buffer1.GetConstBuffer(i), boost::numeric_cast<char>(i));
    }
}

void CoreTools::FileBufferTesting::BufferTest()
{
    FileBuffer buffer0{ 11 };

    ASSERT_NOT_THROW_EXCEPTION_2(Init, buffer0, 0);

    const FileBuffer buffer1{ buffer0 };
    for (auto i = 0; i < buffer0.GetSize(); ++i)
    {
        ASSERT_EQUAL(*buffer0.GetConstBuffer(i), *buffer1.GetBuffer(i));
    }
}

void CoreTools::FileBufferTesting::ForEachTest()
{
    FileBuffer buffer0{ 11 };

    int index = 0;
    for (auto& value : buffer0)
    {
        value = boost::numeric_cast<char>(index);

        ++index;
    }

    index = 0;

    for (const FileBuffer buffer1{ buffer0 }; const auto& value : buffer1)
    {
        ASSERT_EQUAL(value, static_cast<char>(index));

        ++index;
    }
}

void CoreTools::FileBufferTesting::CopyBufferTest()
{
    FileBuffer buffer0{ 11 };
    const auto beginPtr0 = buffer0.GetBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr0, "beginPtr0指针为空。");

    ASSERT_NOT_THROW_EXCEPTION_2(Init, buffer0, 0);

    FileBuffer buffer1{ 11 };
    buffer1.CopyBuffer(buffer0.begin(), buffer0.end());

    auto index = 0;
    for (const auto& value : buffer1)
    {
        ASSERT_EQUAL(value, static_cast<char>(index));

        ++index;
    }
}
