///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/23 13:44)

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

    // SystemWindowsTesting有hwnd不为空时的测试。
}

void System::MessageBoxSelectionUseFlagsDataTesting::YesNoTest()
{
    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::YesNo,
                                             MessageBoxIcon::Error,
                                             MessageBoxDefault::Button2,
                                             MessageBoxMode::ApplModal,
                                             MessageBoxMisc::TopMost };

    const auto type = MessageBoxSelection(nullptr, SYSTEM_TEXT("这个对话框只是测试，请点击任意按钮。"), SYSTEM_TEXT("测试"), flagsData);

    ASSERT_TRUE(type == DialogBoxCommand::IDYes || type == DialogBoxCommand::IDNo);
}