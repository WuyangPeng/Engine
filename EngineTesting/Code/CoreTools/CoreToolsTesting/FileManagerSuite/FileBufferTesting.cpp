/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/04 23:18)

#include "FileBufferTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    FileBuffer buffer{ bufferSize };

    ASSERT_EQUAL(buffer.GetSize(), bufferSize);

    const auto begin = buffer.GetBufferBegin();

    ASSERT_UNEQUAL_NULL_PTR(begin);
}

void CoreTools::FileBufferTesting::DelayCopyTest()
{
    FileBuffer buffer0{ bufferSize };
    const auto beginPtr0 = buffer0.GetBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr0, "beginPtr0指针为空。");

    ASSERT_NOT_THROW_EXCEPTION_2(Init, buffer0, 0);

    const FileBuffer buffer1{ buffer0 };
    const auto beginPtr1 = ShallowCopyTest(buffer0, beginPtr0, buffer1);

    FileBuffer buffer2{ buffer0 };

    ASSERT_NOT_THROW_EXCEPTION_3(DeepCopyTest, beginPtr0, beginPtr1, buffer2);

    ASSERT_NOT_THROW_EXCEPTION_2(Init, buffer2, bufferSize);
    ASSERT_NOT_THROW_EXCEPTION_2(NoChangeTest, buffer0, buffer1);
}

const char* CoreTools::FileBufferTesting::ShallowCopyTest(const FileBuffer& lhs, const char* lhsPtr, const FileBuffer& rhs)
{
    ASSERT_EQUAL(rhs.GetSize(), lhs.GetSize());

    const auto rhsPtr = rhs.GetConstBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(rhsPtr, "rhsPtr指针为空。");

    /// lhsPtr和rhsPtr依然指向同一个副本。
    ASSERT_EQUAL(lhsPtr, rhsPtr);

    return rhsPtr;
}

void CoreTools::FileBufferTesting::DeepCopyTest(const char* ptr0, const char* ptr1, FileBuffer& fileBuffer)
{
    const auto ptr2 = fileBuffer.GetBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(ptr2, "beginPtr2指针为空。");

    /// ptr2指向另一个副本。
    ASSERT_UNEQUAL(ptr0, ptr2);
    ASSERT_UNEQUAL(ptr1, ptr2);
}

void CoreTools::FileBufferTesting::NoChangeTest(const FileBuffer& lhs, const FileBuffer& rhs)
{
    /// ptr0和ptr1的值没有改变
    for (auto i = 0; i < lhs.GetSize(); ++i)
    {
        ASSERT_EQUAL(*lhs.GetConstBuffer(i), *rhs.GetConstBuffer(i));
        ASSERT_EQUAL(*rhs.GetConstBuffer(i), boost::numeric_cast<char>(i));
    }
}

void CoreTools::FileBufferTesting::Init(FileBuffer& fileBuffer, int step) const
{
    for (auto i = 0; i < fileBuffer.GetSize(); ++i)
    {
        *fileBuffer.GetBuffer(i) = boost::numeric_cast<char>(i + step);
    }
}

void CoreTools::FileBufferTesting::BufferTest()
{
    FileBuffer buffer0{ bufferSize };

    ASSERT_NOT_THROW_EXCEPTION_2(Init, buffer0, 0);

    const FileBuffer buffer1{ buffer0 };
    ASSERT_NOT_THROW_EXCEPTION_2(GetBufferEqualTest, buffer0, buffer1);
}

void CoreTools::FileBufferTesting::GetBufferEqualTest(const FileBuffer& lhs, const FileBuffer& rhs)
{
    for (auto i = 0; i < lhs.GetSize(); ++i)
    {
        ASSERT_EQUAL(*lhs.GetConstBuffer(i), *rhs.GetBuffer(i));
    }
}

void CoreTools::FileBufferTesting::ForEachTest()
{
    FileBuffer buffer0{ bufferSize };

    ASSERT_NOT_THROW_EXCEPTION_1(InitByForEach, buffer0);

    const FileBuffer buffer1{ buffer0 };
    ASSERT_NOT_THROW_EXCEPTION_1(CopyByForEachTest, buffer1);
}

void CoreTools::FileBufferTesting::InitByForEach(FileBuffer& fileBuffer)
{
    auto index = 0;
    for (auto& element : fileBuffer)
    {
        element = boost::numeric_cast<char>(index);

        ++index;
    }
}

void CoreTools::FileBufferTesting::CopyByForEachTest(const FileBuffer& fileBuffer)
{
    auto index = 0;

    for (const auto& element : fileBuffer)
    {
        ASSERT_EQUAL(element, static_cast<char>(index));

        ++index;
    }
}

void CoreTools::FileBufferTesting::CopyBufferTest()
{
    FileBuffer buffer{ bufferSize };
    const auto beginPtr = buffer.GetBufferBegin();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(beginPtr, "beginPtr0指针为空。");

    ASSERT_NOT_THROW_EXCEPTION_2(Init, buffer, 0);

    ASSERT_NOT_THROW_EXCEPTION_1(DoCopyTest, buffer);
}

void CoreTools::FileBufferTesting::DoCopyTest(const FileBuffer& fileBuffer)
{
    FileBuffer result{ bufferSize };
    result.CopyBuffer(fileBuffer.begin(), fileBuffer.end());

    ASSERT_NOT_THROW_EXCEPTION_1(CopyByForEachTest, result);
}
