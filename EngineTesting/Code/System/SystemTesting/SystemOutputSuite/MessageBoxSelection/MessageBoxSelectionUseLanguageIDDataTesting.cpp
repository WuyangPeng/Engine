///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/23 13:54)

#include "MessageBoxSelectionUseLanguageIDDataTesting.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxSelectionUseLanguageIDDataTesting::MessageBoxSelectionUseLanguageIDDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxSelectionUseLanguageIDDataTesting)

void System::MessageBoxSelectionUseLanguageIDDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxSelectionUseLanguageIDDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OkCancelTest);

    // SystemWindowsTesting��hwnd��Ϊ��ʱ�Ĳ��ԡ�
}

void System::MessageBoxSelectionUseLanguageIDDataTesting::OkCancelTest()
{
    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::OkCancel,
                                             MessageBoxIcon::Error,
                                             MessageBoxDefault::Button2,
                                             MessageBoxMode::ApplModal,
                                             MessageBoxMisc::TopMost };

    constexpr LanguageIDData languageIDData{};

    const auto type = MessageBoxSelection(nullptr, SYSTEM_TEXT("����Ի���ֻ�ǲ��ԣ��������ⰴť��"), SYSTEM_TEXT("����"), flagsData, languageIDData);

    ASSERT_TRUE(type == DialogBoxCommand::IDOk || type == DialogBoxCommand::IDCancel);
}
