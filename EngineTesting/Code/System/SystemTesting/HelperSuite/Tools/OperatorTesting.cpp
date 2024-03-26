/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:26)

#include "OperatorTesting.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OperatorTesting::OperatorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OperatorTesting)

void System::OperatorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OperatorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PlusTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MinusTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProductTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DivideTest);
}

void System::OperatorTesting::PlusTest()
{
    ASSERT_EQUAL(GetPlus(2, 3), 2 + 3);
}

void System::OperatorTesting::MinusTest()
{
    ASSERT_EQUAL(GetMinus(12, 3), 12 - 3);
}

void System::OperatorTesting::ProductTest()
{
    ASSERT_EQUAL(GetProduct(5, 3), 5 * 3);
}

void System::OperatorTesting::DivideTest()
{
    ASSERT_EQUAL(GetDivide(15, 3), 15 / 3);
}
