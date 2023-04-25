///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/14 10:16)

#include "Array3Testing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/Array3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::Array3Testing::Array3Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Array3Testing)

void CoreTools::Array3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::Array3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Array3Test);
}

void CoreTools::Array3Testing::Array3Test()
{
    ArrayType array3{ bound0, bound1, bound2 };

    ASSERT_EQUAL(array3.GetBound0(), bound0);
    ASSERT_EQUAL(array3.GetBound1(), bound1);
    ASSERT_EQUAL(array3.GetBound2(), bound2);

    ASSERT_NOT_THROW_EXCEPTION_1(InitArray, array3);
    ASSERT_NOT_THROW_EXCEPTION_1(ResultTest, array3);
}

void CoreTools::Array3Testing::InitArray(ArrayType& array3)
{
    auto count = 0;
    for (auto bound2Index = 0; bound2Index < bound2; ++bound2Index)
    {
        for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
        {
            for (auto bound0Index = 0; bound0Index < bound0; ++bound0Index)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                array3[bound2Index][bound1Index][bound0Index] = count;

#include STSTEM_WARNING_POP

                ++count;
            }
        }
    }
}

void CoreTools::Array3Testing::ResultTest(const ArrayType& array3)
{
    auto resultCount = 0;

    for (auto bound2Index = 0; bound2Index < bound2; ++bound2Index)
    {
        for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
        {
            for (auto bound0Index = 0; bound0Index < bound0; ++bound0Index)
            {
                 ASSERT_EQUAL(array3.Get(bound0Index, bound1Index, bound2Index), resultCount);

                ++resultCount;
            }
        }
    }
}
