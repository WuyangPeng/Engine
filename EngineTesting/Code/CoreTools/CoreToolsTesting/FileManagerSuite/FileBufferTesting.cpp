// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/05 15:43)

#include "FileBufferTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FileBufferTesting)

void CoreTools::FileBufferTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyTest);
}

void CoreTools::FileBufferTesting ::ValueTest()
{
    FileBuffer buffer{ 10 };

    ASSERT_EQUAL(buffer.GetSize(), 10u);

    auto ptr = buffer.GetBufferBegin();

    ASSERT_UNEQUAL_NULL_PTR(ptr);
}

void CoreTools::FileBufferTesting ::DelayCopyTest() noexcept
{
//     FileBuffer firstBuffer{ 11 };
// 
//     auto firstPtr = firstBuffer.GetBufferBegin();
// 
//     for (auto i = 0u; i < firstBuffer.GetSize(); ++i)
//     {
//         firstPtr[i] = static_cast<char>(i);
//     }
// 
//     const FileBuffer secondBuffer{ firstBuffer };
// 
//     ASSERT_EQUAL(secondBuffer.GetSize(), 11u);
// 
//     auto secondPtr = secondBuffer.GetBufferBegin();
// 
//     // firstBuffer和secondPtr依然指向同一个副本。
// 
//     ASSERT_EQUAL(firstPtr, secondPtr);
// 
//     FileBuffer thirdBuffer{ firstBuffer };
// 
//     auto thirdPtr = thirdBuffer.GetBufferBegin();
// 
//     ASSERT_UNEQUAL(firstPtr, thirdPtr);
//     ASSERT_UNEQUAL(secondPtr, thirdPtr);
// 
//     // thirdBuffer指向另一个副本。
// 
//     for (auto i = 0u; i < thirdBuffer.GetSize(); ++i)
//     {
//         thirdPtr[i] = static_cast<char>(i + 100);
//     }
// 
//     // firstBuffer和secondBuffer的值没有改变
//     firstPtr = firstBuffer.GetBufferBegin();
//     secondPtr = secondBuffer.GetBufferBegin();
// 
//     ASSERT_UNEQUAL(firstPtr, secondPtr);
// 
//     for (auto i = 0u; i < firstBuffer.GetSize(); ++i)
//     {
//         ASSERT_EQUAL(firstPtr[i], secondPtr[i]);
//         ASSERT_EQUAL(firstPtr[i], static_cast<char>(i));
//     }
}

