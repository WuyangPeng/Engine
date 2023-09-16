///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:13)

#include "MessageBoxSelectionUseFlagsDataTesting.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxSelectionUseFlagsDataTesting::MessageBoxSelectionUseFlagsDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxSelectionUseFlagsDataTesting)

void System::MessageBoxSelectionUseFlagsDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxSelectionUseFlagsDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(YesNoTest);

    // SystemWindowsTesting��hWnd��Ϊ��ʱ�Ĳ��ԡ�
}

void System::MessageBoxSelectionUseFlagsDataTesting::YesNoTest()
{
    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::YesNo,
                                             MessageBoxIcon::Error,
                                             MessageBoxDefault::Button2,
                                             MessageBoxMode::ApplModal,
                                             MessageBoxMisc::TopMost };

    const auto type = MessageBoxSelection(nullptr, SYSTEM_TEXT("����Ի���ֻ�ǲ��ԣ��������ⰴť��"), SYSTEM_TEXT("����"), flagsData);

    ASSERT_TRUE(type == DialogBoxCommand::IdYes || type == DialogBoxCommand::IdNo);
}