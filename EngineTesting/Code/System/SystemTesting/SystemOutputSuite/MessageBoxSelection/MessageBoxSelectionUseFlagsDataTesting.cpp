///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/07 19:23)

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
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxSelectionUseFlagsDataTesting)

void System::MessageBoxSelectionUseFlagsDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxSelectionUseFlagsDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(YesNoTest);

    // SystemWindowsTesting��hwnd��Ϊ��ʱ�Ĳ��ԡ�
}

void System::MessageBoxSelectionUseFlagsDataTesting::YesNoTest()
{
    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::YesNo,
                                             MessageBoxIcon::Error,
                                             MessageBoxDefault::Button2,
                                             MessageBoxMode::ApplModal,
                                             MessageBoxMisc::TopMost };

    const auto type = MessageBoxSelection(nullptr, SYSTEM_TEXT("����Ի���ֻ�ǲ��ԣ��������ⰴť��"), SYSTEM_TEXT("����"), flagsData);

    ASSERT_TRUE(type == DialogBoxCommand::IDYes || type == DialogBoxCommand::IDNo);
}