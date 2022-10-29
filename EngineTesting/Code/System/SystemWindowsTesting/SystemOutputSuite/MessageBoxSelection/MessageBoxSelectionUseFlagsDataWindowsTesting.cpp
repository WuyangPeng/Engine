///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/05 22:17)

#include "MessageBoxSelectionUseFlagsDataWindowsTesting.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <algorithm>

using std::vector;

System::MessageBoxSelectionUseFlagsDataWindowsTesting::MessageBoxSelectionUseFlagsDataWindowsTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream },
      hwnd{ hwnd },
      typeFlags{ MessageBoxType::Ok,
                 MessageBoxType::OkCancel,
                 MessageBoxType::AbortRetryIgnore,
                 MessageBoxType::YesNoCancel,
                 MessageBoxType::YesNo,
                 MessageBoxType::RetryCancel,
                 MessageBoxType::CancelTryContinue },
      iconFlags{ MessageBoxIcon::NoIcon,
                 MessageBoxIcon::Hand,
                 MessageBoxIcon::Question,
                 MessageBoxIcon::Exclamation,
                 MessageBoxIcon::Asterisk,
                 MessageBoxIcon::UserIcon,
                 MessageBoxIcon::Waning,
                 MessageBoxIcon::Error,
                 MessageBoxIcon::Information,
                 MessageBoxIcon::Stop },
      defaultFlags{ MessageBoxDefault::Button1,
                    MessageBoxDefault::Button2,
                    MessageBoxDefault::Button3,
                    MessageBoxDefault::Button4 },
      modeFlags{ MessageBoxMode::ApplModal,
                 MessageBoxMode::SystemModal,
                 MessageBoxMode::TaskModal },
      miscFlags{ MessageBoxMisc::NoMisc,
                 MessageBoxMisc::Help,
                 MessageBoxMisc::NoFocus,
                 MessageBoxMisc::SetForeground,
                 MessageBoxMisc::DefaultDesktopOnly,
                 MessageBoxMisc::TopMost,
                 MessageBoxMisc::Right,
                 MessageBoxMisc::RightToLeftReading,
                 MessageBoxMisc::ServiceNotification,
                 MessageBoxMisc::ServiceNotificationNt3x },
      returnCollection{ { MessageBoxType::Ok, { DialogBoxCommand::IDOk } },
                        { MessageBoxType::OkCancel, { DialogBoxCommand::IDOk, DialogBoxCommand::IDCancel } },
                        { MessageBoxType::AbortRetryIgnore, { DialogBoxCommand::IDAbort, DialogBoxCommand::IDRetry, DialogBoxCommand::IDIgnore } },
                        { MessageBoxType::YesNoCancel, { DialogBoxCommand::IDYes, DialogBoxCommand::IDNo, DialogBoxCommand::IDCancel } },
                        { MessageBoxType::YesNo, { DialogBoxCommand::IDYes, DialogBoxCommand::IDNo } },
                        { MessageBoxType::RetryCancel, { DialogBoxCommand::IDRetry, DialogBoxCommand::IDCancel } },
                        { MessageBoxType::CancelTryContinue, { DialogBoxCommand::IDCancel, DialogBoxCommand::IDTryAgain, DialogBoxCommand::IDContinue } } },
      iconDescription{ { MessageBoxIcon::NoIcon, SYSTEM_TEXT("无图标") },
                       { MessageBoxIcon::Hand, SYSTEM_TEXT("错误") },
                       { MessageBoxIcon::Question, SYSTEM_TEXT("问号") },
                       { MessageBoxIcon::Exclamation, SYSTEM_TEXT("警告") },
                       { MessageBoxIcon::Asterisk, SYSTEM_TEXT("信息") },
                       { MessageBoxIcon::UserIcon, SYSTEM_TEXT("无图标") },
                       { MessageBoxIcon::Waning, SYSTEM_TEXT("警告") },
                       { MessageBoxIcon::Error, SYSTEM_TEXT("错误") },
                       { MessageBoxIcon::Information, SYSTEM_TEXT("信息") },
                       { MessageBoxIcon::Stop, SYSTEM_TEXT("错误") } },
      defaultDescription{ { MessageBoxDefault::Button1, SYSTEM_TEXT("（按钮1）") },
                          { MessageBoxDefault::Button2, SYSTEM_TEXT("（按钮2）") },
                          { MessageBoxDefault::Button3, SYSTEM_TEXT("（按钮3）") },
                          { MessageBoxDefault::Button4, SYSTEM_TEXT("（按钮4）") } },
      modeDescription{ { MessageBoxMode::ApplModal, SYSTEM_TEXT("ApplModal样式") },
                       { MessageBoxMode::SystemModal, SYSTEM_TEXT("SystemModal样式") },
                       { MessageBoxMode::TaskModal, SYSTEM_TEXT("TaskModal样式") } },
      miscDescription{ { MessageBoxMisc::NoMisc, SYSTEM_TEXT("（没有杂项）") },
                       { MessageBoxMisc::Help, SYSTEM_TEXT("（显示帮助按钮）") },
                       { MessageBoxMisc::NoFocus, SYSTEM_TEXT("（MessageBox不使用此标志）") },
                       { MessageBoxMisc::SetForeground, SYSTEM_TEXT("（消息框为前景窗口）") },
                       { MessageBoxMisc::DefaultDesktopOnly, SYSTEM_TEXT("（接收输入的当前桌面一定是一个缺省桌面）") },
                       { MessageBoxMisc::TopMost, SYSTEM_TEXT("（消息框用WS_EX_TOPMOST窗口类型来创建）") },
                       { MessageBoxMisc::Right, SYSTEM_TEXT("（文本右对齐）") },
                       { MessageBoxMisc::RightToLeftReading, SYSTEM_TEXT("（指定文本应为在希伯来和阿拉伯语系统中的从右到左显示）") },
                       { MessageBoxMisc::ServiceNotification, SYSTEM_TEXT("（调用者是通知用户事件的服务）") },
                       { MessageBoxMisc::ServiceNotificationNt3x, SYSTEM_TEXT("（MessageBox不使用此标志）") } },
      maxSize{ CoreTools::MaxElement<size_t>({ typeFlags.size(), iconFlags.size(), defaultFlags.size(), modeFlags.size(), miscFlags.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool System::MessageBoxSelectionUseFlagsDataWindowsTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && hwnd != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void System::MessageBoxSelectionUseFlagsDataWindowsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxSelectionUseFlagsDataWindowsTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::MessageBoxSelectionUseFlagsDataWindowsTesting::RandomShuffleFlags()
{
    shuffle(typeFlags.begin(), typeFlags.end(), randomEngine);
    shuffle(iconFlags.begin(), iconFlags.end(), randomEngine);
    shuffle(defaultFlags.begin(), defaultFlags.end(), randomEngine);
    shuffle(modeFlags.begin(), modeFlags.end(), randomEngine);
    shuffle(miscFlags.begin(), miscFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(MessageBoxTest);

    return true;
}

void System::MessageBoxSelectionUseFlagsDataWindowsTesting::MessageBoxTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto typeFlag = typeFlags.at(index % typeFlags.size());
        auto iconFlag = iconFlags.at(index % iconFlags.size());
        auto defaultFlag = defaultFlags.at(index % defaultFlags.size());
        auto modeFlag = modeFlags.at(index % modeFlags.size());
        auto miscFlag = miscFlags.at(index % miscFlags.size());

        const MessageBoxFlagsData flagsData{ typeFlag, iconFlag, defaultFlag, modeFlag, miscFlag };

        auto caption = iconDescription[iconFlag] + defaultDescription[defaultFlag];
        auto text = modeDescription[modeFlag] + miscDescription[miscFlag];

        const auto flag = MessageBoxSelection(GetHwnd(miscFlag), text.c_str(), caption.c_str(), flagsData);

        ASSERT_ENUM_UNEQUAL(DialogBoxCommand::IDCreationFailed, flag);

        auto collection = returnCollection[typeFlag];

        auto iter = find(collection.cbegin(), collection.cend(), flag);

        ASSERT_UNEQUAL(iter, collection.cend());
    }
}

System::WindowsHWnd System::MessageBoxSelectionUseFlagsDataWindowsTesting::GetHwnd(MessageBoxMisc miscFlag) const noexcept
{
    if (miscFlag != MessageBoxMisc::ServiceNotification && miscFlag != MessageBoxMisc::DefaultDesktopOnly)
    {
        return hwnd;
    }
    else
    {
        return nullptr;
    }
}
