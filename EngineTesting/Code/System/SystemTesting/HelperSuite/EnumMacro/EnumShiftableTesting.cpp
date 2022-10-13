///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/25 20:02)

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
    cout << "������һ���������֣�";

    SignedNumber number{};

    cin >> number;

    cout << "������ʾ�ղ���������֣�" << number << '\n';

    wcout << L"��������һ���������֣�";

    wcin >> number;

    wcout << L"������ʾ�ղ���������֣�" << number << '\n';
}
