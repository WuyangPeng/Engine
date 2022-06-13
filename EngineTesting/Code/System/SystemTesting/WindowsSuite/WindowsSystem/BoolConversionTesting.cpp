///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 15:58)

#include "BoolConversionTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::BoolConversionTesting::BoolConversionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, BoolConversionTesting)

void System::BoolConversionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::BoolConversionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoolConversionTest);
}

void System::BoolConversionTesting::BoolConversionTest()
{
    ASSERT_EQUAL(BoolConversion(false), gFalse);
    ASSERT_EQUAL(BoolConversion(true), gTrue);

    auto value = false;
    BoolConversion(gTrue, &value);
    ASSERT_EQUAL(value, true);

    BoolConversion(gFalse, &value);
    ASSERT_EQUAL(value, false);

    BoolConversion(gFalse, nullptr);
}