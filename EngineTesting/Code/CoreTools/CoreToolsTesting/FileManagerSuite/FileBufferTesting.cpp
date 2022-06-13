///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 12:01)

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
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr0, "beginPtr0ָ��Ϊ�ա�");

    for (auto i = 0u; i < buffer0.GetSize(); ++i)
    {
        *buffer0.GetBuffer(i) = boost::numeric_cast<char>(i);
    }

    FileBuffer buffer1{ buffer0 };
    ASSERT_EQUAL(buffer1.GetSize(), buffer0.GetSize());

    auto beginPtr1 = buffer1.GetConstBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr1, "beginPtr1ָ��Ϊ�ա�");

    // beginPtr0��beginPtr1��Ȼָ��ͬһ��������
    ASSERT_EQUAL(beginPtr0, beginPtr1);

    FileBuffer buffer2{ buffer0 };

    auto beginPtr2 = buffer2.GetBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr2, "beginPtr2ָ��Ϊ�ա�");

    // beginPtr2ָ����һ��������
    ASSERT_UNEQUAL(beginPtr0, beginPtr2);
    ASSERT_UNEQUAL(beginPtr1, beginPtr2);

    for (auto i = 0u; i < buffer0.GetSize(); ++i)
    {
        *buffer2.GetBuffer(i) = boost::numeric_cast<char>(i + 100);
    }

    // beginPtr0��beginPtr1��ֵû�иı�

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
