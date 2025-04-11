/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 11:02)

#include "EnumShiftableTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <iostream>

System::EnumShiftableTesting::EnumShiftableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumShiftableTesting)

void System::EnumShiftableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumShiftableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ShiftableTest);
}

void System::EnumShiftableTesting::ShiftableTest() const
{
    std::cout << "请输入一个测试数字：";

    SignedNumber number{};

    std::cin >> number;

    std::cout << "这里显示刚才输入的数字：" << number << '\n';

    std::wcout << L"请再输入一个测试数字：";

    std::wcin >> number;

    std::wcout << L"这里显示刚才输入的数字：" << number << '\n';
}

void System::EnumShiftableTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要控制台输入。\n";

    SystemPause();
}
