///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:41)

#include "EngineeringNumDigitsTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

System::EngineeringNumDigitsTesting::EngineeringNumDigitsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EngineeringNumDigitsTesting)

void System::EngineeringNumDigitsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EngineeringNumDigitsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NumDigitsTest);
}

void System::EngineeringNumDigitsTesting::NumDigitsTest()
{
    ASSERT_EQUAL(NumDigits(1), 1);
    ASSERT_EQUAL(NumDigits(12), 2);
    ASSERT_EQUAL(NumDigits(123), 3);

    for (auto i = 0; i < 9; ++i)
    {
        ASSERT_EQUAL(NumDigits(boost::numeric_cast<int>(Mathematics::MathD::Pow(10, i) + 1)), i + 1);
    }
}
