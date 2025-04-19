﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 12:20)

#include "MessageBoxSelectionUseYesNoCancelTesting.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxSelectionUseYesNoCancelTesting::MessageBoxSelectionUseYesNoCancelTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    const auto type = MessageBoxSelectionWithChar("这个对话框只是测试，请点击任意按钮。", "测试");

    ASSERT_TRUE(type == DialogBoxCommand::IdYes || type == DialogBoxCommand::IdNo || type == DialogBoxCommand::IdCancel);
}

void System::MessageBoxSelectionUseYesNoCancelTesting::MessageBoxSelectionWithWCharTest()
{
    const auto type = MessageBoxSelectionWithWChar(L"这个对话框只是测试，请点击任意按钮。", L"测试");

    ASSERT_TRUE(type == DialogBoxCommand::IdYes || type == DialogBoxCommand::IdNo || type == DialogBoxCommand::IdCancel);
}

void System::MessageBoxSelectionUseYesNoCancelTesting::MessageBoxSelectionWithTCharTest()
{
    const auto type = MessageBoxSelectionWithTChar(SYSTEM_TEXT("这个对话框只是测试，请点击任意按钮。"), SYSTEM_TEXT("测试"));

    ASSERT_TRUE(type == DialogBoxCommand::IdYes || type == DialogBoxCommand::IdNo || type == DialogBoxCommand::IdCancel);
}
