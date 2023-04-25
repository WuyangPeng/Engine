///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 14:00)

#include "SqrtTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Sqrt.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SqrtTesting::SqrtTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SqrtTesting)

void CoreTools::SqrtTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SqrtTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SqrtTest);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26812)

void CoreTools::SqrtTesting::SqrtTest()
{
    ASSERT_EQUAL(SqrtAlgorithm0<16>::Result, 4);
    ASSERT_EQUAL(SqrtAlgorithm0<25>::Result, 5);
    ASSERT_EQUAL(SqrtAlgorithm0<42>::Result, 6);
    ASSERT_EQUAL(SqrtAlgorithm0<1>::Result, 1);

    ASSERT_EQUAL(SqrtAlgorithm1<16>::Result, 4);
    ASSERT_EQUAL(SqrtAlgorithm1<25>::Result, 5);
    ASSERT_EQUAL(SqrtAlgorithm1<42>::Result, 6);
    ASSERT_EQUAL(SqrtAlgorithm1<1>::Result, 1);

    ASSERT_EQUAL(SqrtAlgorithm2<16>::Result, 4);
    ASSERT_EQUAL(SqrtAlgorithm2<25>::Result, 5);
    ASSERT_EQUAL(SqrtAlgorithm2<42>::Result, 7);
    ASSERT_EQUAL(SqrtAlgorithm2<48>::Result, 7);
    ASSERT_EQUAL(SqrtAlgorithm2<1>::Result, 1);

    ASSERT_EQUAL(SqrtAlgorithm3<16>::Result, 4);
    ASSERT_EQUAL(SqrtAlgorithm3<25>::Result, 5);
    ASSERT_EQUAL(SqrtAlgorithm3<42>::Result, 7);
    ASSERT_EQUAL(SqrtAlgorithm3<50>::Result, 8);
    ASSERT_EQUAL(SqrtAlgorithm3<1>::Result, 1);
}

#include STSTEM_WARNING_POP
