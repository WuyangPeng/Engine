///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 19:06)

#include "MessageBoxSelectionUseYesNoCancelTesting.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxSelectionUseYesNoCancelTesting::MessageBoxSelectionUseYesNoCancelTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxSelectionUseYesNoCancelTesting)

void System::MessageBoxSelectionUseYesNoCancelTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxSelectionUseYesNoCancelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MessageBoxSelectionWithCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageBoxSelectionWithWCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageBoxSelectionWithTCharTest);
}

void System::MessageBoxSelectionUseYesNoCancelTesting::MessageBoxSelectionWithCharTest()
{
    const auto type = MessageBoxSelectionWithChar("����Ի���ֻ�ǲ��ԣ��������ⰴť��", "����");

    ASSERT_TRUE(type == DialogBoxCommand::IDYes || type == DialogBoxCommand::IDNo || type == DialogBoxCommand::IDCancel);
}

void System::MessageBoxSelectionUseYesNoCancelTesting::MessageBoxSelectionWithWCharTest()
{
    const auto type = MessageBoxSelectionWithWChar(L"����Ի���ֻ�ǲ��ԣ��������ⰴť��", L"����");

    ASSERT_TRUE(type == DialogBoxCommand::IDYes || type == DialogBoxCommand::IDNo || type == DialogBoxCommand::IDCancel);
}

void System::MessageBoxSelectionUseYesNoCancelTesting::MessageBoxSelectionWithTCharTest()
{
    const auto type = MessageBoxSelectionWithTChar(SYSTEM_TEXT("����Ի���ֻ�ǲ��ԣ��������ⰴť��"), SYSTEM_TEXT("����"));

    ASSERT_TRUE(type == DialogBoxCommand::IDYes || type == DialogBoxCommand::IDNo || type == DialogBoxCommand::IDCancel);
}
