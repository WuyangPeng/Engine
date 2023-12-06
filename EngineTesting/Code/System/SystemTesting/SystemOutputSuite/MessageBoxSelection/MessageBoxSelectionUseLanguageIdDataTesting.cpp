///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:13)

#include "MessageBoxSelectionUseLanguageIdDataTesting.h"
#include "System/SystemOutput/Data/LanguageIdData.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxSelectionUseLanguageIdDataTesting::MessageBoxSelectionUseLanguageIdDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxSelectionUseLanguageIdDataTesting)

void System::MessageBoxSelectionUseLanguageIdDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxSelectionUseLanguageIdDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OkCancelTest);

    // SystemWindowsTesting��hWnd��Ϊ��ʱ�Ĳ��ԡ�
}

void System::MessageBoxSelectionUseLanguageIdDataTesting::OkCancelTest()
{
    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::OkCancel,
                                             MessageBoxIcon::Error,
                                             MessageBoxDefault::Button2,
                                             MessageBoxMode::ApplModal,
                                             MessageBoxMisc::TopMost };

    constexpr LanguageIdData languageIdData{};

    const auto type = MessageBoxSelection(nullptr, SYSTEM_TEXT("����Ի���ֻ�ǲ��ԣ��������ⰴť��"), SYSTEM_TEXT("����"), flagsData, languageIdData);

    ASSERT_TRUE(type == DialogBoxCommand::IdOk || type == DialogBoxCommand::IdCancel);
}
