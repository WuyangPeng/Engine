///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/03 21:53)

#include "FileBufferTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

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
}

void CoreTools::FileBufferTesting::ValueTest()
{
    FileBuffer buffer{ 10 };

    ASSERT_EQUAL(buffer.GetSize(), 10u);

    auto beginPtr = buffer.GetBufferBegin();

    ASSERT_UNEQUAL_NULL_PTR(beginPtr);
}

void CoreTools::FileBufferTesting::DelayCopyTest()
{
    FileBuffer buffer0{ 11 };
    auto beginPtr0 = buffer0.GetBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr0, "beginPtr0指针为空。");

    for (auto i = 0u; i < buffer0.GetSize(); ++i)
    {
        *buffer0.GetBuffer(i) = boost::numeric_cast<char>(i);
    }

    FileBuffer buffer1{ buffer0 };
    ASSERT_EQUAL(buffer1.GetSize(), buffer0.GetSize());

    auto beginPtr1 = buffer1.GetConstBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr1, "beginPtr1指针为空。");

    // beginPtr0和beginPtr1依然指向同一个副本。
    ASSERT_EQUAL(beginPtr0, beginPtr1);

    FileBuffer buffer2{ buffer0 };

    auto beginPtr2 = buffer2.GetBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr2, "beginPtr2指针为空。");

    // beginPtr2指向另一个副本。
    ASSERT_UNEQUAL(beginPtr0, beginPtr2);
    ASSERT_UNEQUAL(beginPtr1, beginPtr2);

    for (auto i = 0u; i < buffer0.GetSize(); ++i)
    {
        *buffer2.GetBuffer(i) = boost::numeric_cast<char>(i + 100);
    }

    // beginPtr0和beginPtr1的值没有改变

    for (auto i = 0u; i < buffer0.GetSize(); ++i)
    {
        ASSERT_EQUAL(*buffer0.GetConstBuffer(i), *buffer1.GetConstBuffer(i));
        ASSERT_EQUAL(*buffer1.GetConstBuffer(i), boost::numeric_cast<char>(i));
    }
}

void CoreTools::FileBufferTesting::BufferTest()
{
    FileBuffer buffer0{ 11 };

    for (auto i = 0u; i < buffer0.GetSize(); ++i)
    {
        *buffer0.GetBuffer(i) = boost::numeric_cast<char>(i);
    }

    const FileBuffer buffer1{ buffer0 };
    for (auto i = 0u; i < buffer0.GetSize(); ++i)
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
    const FileBuffer buffer1{ buffer0 };
    for (const auto& value : buffer1)
    {
        ASSERT_EQUAL(value, static_cast<char>(index));

        ++index;
    }
}
