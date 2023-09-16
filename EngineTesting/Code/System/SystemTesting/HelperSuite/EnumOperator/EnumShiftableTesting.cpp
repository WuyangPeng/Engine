///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:45)

#include "EnumShiftableTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    std::cout << "������һ���������֣�";

    SignedNumber number{};

    std::cin >> number;

    std::cout << "������ʾ�ղ���������֣�" << number << '\n';

    std::wcout << L"��������һ���������֣�";

    std::wcin >> number;

    std::wcout << L"������ʾ�ղ���������֣�" << number << '\n';
}

void System::EnumShiftableTesting::PrintTipsMessage()
{
    GetStream() << "���������Ҫ����̨���롣\n";

    SystemPause();
}
