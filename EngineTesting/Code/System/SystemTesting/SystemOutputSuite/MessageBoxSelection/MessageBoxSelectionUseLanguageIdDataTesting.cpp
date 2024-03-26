/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 12:20)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxSelectionUseLanguageIdDataTesting)

void System::MessageBoxSelectionUseLanguageIdDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxSelectionUseLanguageIdDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OkCancelTest);
}

void System::MessageBoxSelectionUseLanguageIdDataTesting::OkCancelTest()
{
    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::OkCancel,
                                             MessageBoxIcon::Error,
                                             MessageBoxDefault::Button2,
                                             MessageBoxMode::ApplicationModal,
                                             MessageBoxMisc::TopMost };

    constexpr LanguageIdData languageIdData{};

    const auto type = MessageBoxSelection(nullptr, SYSTEM_TEXT("这个对话框只是测试，请点击任意按钮。"), SYSTEM_TEXT("测试"), flagsData, languageIdData);

    ASSERT_TRUE(type == DialogBoxCommand::IdOk || type == DialogBoxCommand::IdCancel);
}
