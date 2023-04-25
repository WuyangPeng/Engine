///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 10:27)

#include "MethodPropertyTesting.h"
#include "Detail/MethodProperty.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MethodPropertyTesting::MethodPropertyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MethodPropertyTesting)

void CoreTools::MethodPropertyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MethodPropertyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetTest);
}

void CoreTools::MethodPropertyTesting::GetTest()
{
    MethodProperty methodProperty{};

    ASSERT_EQUAL(methodProperty.getType, 0);

    methodProperty.setType = 1;

    ASSERT_EQUAL(methodProperty.getSetType, 1);

    methodProperty.getSetType = 2;

    ASSERT_EQUAL(methodProperty.getType, 2);

    methodProperty.setExternalType = 3;

    ASSERT_EQUAL(methodProperty.getSetExternalType, 3);

    methodProperty.getSetExternalType = 4;

    ASSERT_EQUAL(methodProperty.getExternalType, 4);
}
