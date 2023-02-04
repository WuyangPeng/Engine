///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 20:35)

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

    auto result = false;
    BoolConversion(gTrue, &result);
    ASSERT_EQUAL(result, true);

    BoolConversion(gFalse, &result);
    ASSERT_EQUAL(result, false);

    BoolConversion(gFalse, nullptr);
}