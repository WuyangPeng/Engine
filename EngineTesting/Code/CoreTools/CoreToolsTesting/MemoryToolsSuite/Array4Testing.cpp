/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 15:57)

#include "Array4Testing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/Array4Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace CoreTools
{
    template class Array4<float>;
}

CoreTools::Array4Testing::Array4Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Array4Testing)

void CoreTools::Array4Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::Array4Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Array4Test);
}

void CoreTools::Array4Testing::Array4Test()
{
    ArrayType array4{ bound0, bound1, bound2, bound3 };

    ASSERT_EQUAL(array4.GetBound0(), bound0);
    ASSERT_EQUAL(array4.GetBound1(), bound1);
    ASSERT_EQUAL(array4.GetBound2(), bound2);
    ASSERT_EQUAL(array4.GetBound3(), bound3);

    ASSERT_NOT_THROW_EXCEPTION_1(InitArray, array4);
    ASSERT_NOT_THROW_EXCEPTION_1(ResultTest, array4);
}

void CoreTools::Array4Testing::InitArray(ArrayType& array4)
{
    auto count = 0;
    for (auto bound3Index = 0; bound3Index < bound3; ++bound3Index)
    {
        for (auto bound2Index = 0; bound2Index < bound2; ++bound2Index)
        {
            for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
            {
                for (auto bound0Index = 0; bound0Index < bound0; ++bound0Index)
                {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                    array4[bound3Index][bound2Index][bound1Index][bound0Index] = count;

#include SYSTEM_WARNING_POP

                    ++count;
                }
            }
        }
    }
}

void CoreTools::Array4Testing::ResultTest(const ArrayType& array4)
{
    auto count = 0;
    for (auto bound3Index = 0; bound3Index < bound3; ++bound3Index)
    {
        for (auto bound2Index = 0; bound2Index < bound2; ++bound2Index)
        {
            for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
            {
                for (auto bound0Index = 0; bound0Index < bound0; ++bound0Index)
                {
                    ASSERT_EQUAL(array4(bound3Index, bound2Index, bound1Index, bound0Index), count);

                    ++count;
                }
            }
        }
    }
}
