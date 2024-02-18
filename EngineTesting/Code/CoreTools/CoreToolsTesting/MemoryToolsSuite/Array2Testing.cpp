///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:06)

#include "Array2Testing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/Array2Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace CoreTools
{
    template class Array2<float>;
}

CoreTools::Array2Testing::Array2Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Array2Testing)

void CoreTools::Array2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::Array2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Array2Test);
}

void CoreTools::Array2Testing::Array2Test()
{
    ArrayType array2{ bound0, bound1 };

    ASSERT_EQUAL(array2.GetBound0(), bound0);
    ASSERT_EQUAL(array2.GetBound1(), bound1);

    ASSERT_NOT_THROW_EXCEPTION_1(InitArray, array2);
    ASSERT_NOT_THROW_EXCEPTION_1(ResultTest, array2);
}

void CoreTools::Array2Testing::ResultTest(const ArrayType& array2)
{
    auto resultCount = 0;
    for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
    {
        if (const auto* result = array2[bound1Index];
            result != nullptr)
        {
            for (auto bound0Index = 0; bound0Index < bound0; ++bound0Index)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                ASSERT_EQUAL(result[bound0Index], resultCount);

#include SYSTEM_WARNING_POP

                ++resultCount;
            }
        }
    }
}

void CoreTools::Array2Testing::InitArray(ArrayType& array2)
{
    auto count = 0;
    for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
    {
        if (auto* result = array2[bound1Index];
            result != nullptr)
        {
            for (auto bound0Index = 0; bound0Index < bound0; ++bound0Index)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                result[bound0Index] = count;

#include SYSTEM_WARNING_POP

                ++count;
            }
        }
    }
}
