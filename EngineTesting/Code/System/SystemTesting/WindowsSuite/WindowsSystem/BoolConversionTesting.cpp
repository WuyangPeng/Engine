///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/08 22:42)

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
    ASSERT_EQUAL(BoolConversion(false), g_False);
    ASSERT_EQUAL(BoolConversion(true), g_True);

    auto value = false;
    BoolConversion(g_True, &value);
    ASSERT_EQUAL(value, true);

    BoolConversion(g_False, &value);
    ASSERT_EQUAL(value, false);

    BoolConversion(g_False, nullptr);
}