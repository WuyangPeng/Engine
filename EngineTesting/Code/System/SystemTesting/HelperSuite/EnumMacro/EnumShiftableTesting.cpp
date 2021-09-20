///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/17 18:39)

#include "EnumShiftableTesting.h"
#include "System/Helper/EnumMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::cin;
using std::cout;
using std::wcin;
using std::wcout;

ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE(System::SignedNumber);
ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(System::SignedNumber);
ENUM_LEFT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(System::SignedNumber);
ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(System::SignedNumber);

System::EnumShiftableTesting::EnumShiftableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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

void System::EnumShiftableTesting::ShiftableTest()
{
    cout << "请输入一个测试数字：";

    SignedNumber number{};

    cin >> number;

    cout << "这里显示刚才输入的数字：" << number << '\n';

    wcout << L"请再输入一个测试数字：";

    wcin >> number;

    wcout << L"这里显示刚才输入的数字：" << number << '\n';
}
