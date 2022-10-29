///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/05 22:17)

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
      iconDescription{ { MessageBoxIcon::NoIcon, SYSTEM_TEXT("��ͼ��") },
                       { MessageBoxIcon::Hand, SYSTEM_TEXT("����") },
                       { MessageBoxIcon::Question, SYSTEM_TEXT("�ʺ�") },
                       { MessageBoxIcon::Exclamation, SYSTEM_TEXT("����") },
                       { MessageBoxIcon::Asterisk, SYSTEM_TEXT("��Ϣ") },
                       { MessageBoxIcon::UserIcon, SYSTEM_TEXT("��ͼ��") },
                       { MessageBoxIcon::Waning, SYSTEM_TEXT("����") },
                       { MessageBoxIcon::Error, SYSTEM_TEXT("����") },
                       { MessageBoxIcon::Information, SYSTEM_TEXT("��Ϣ") },
                       { MessageBoxIcon::Stop, SYSTEM_TEXT("����") } },
      defaultDescription{ { MessageBoxDefault::Button1, SYSTEM_TEXT("����ť1��") },
                          { MessageBoxDefault::Button2, SYSTEM_TEXT("����ť2��") },
                          { MessageBoxDefault::Button3, SYSTEM_TEXT("����ť3��") },
                          { MessageBoxDefault::Button4, SYSTEM_TEXT("����ť4��") } },
      modeDescription{ { MessageBoxMode::ApplModal, SYSTEM_TEXT("ApplModal��ʽ") },
                       { MessageBoxMode::SystemModal, SYSTEM_TEXT("SystemModal��ʽ") },
                       { MessageBoxMode::TaskModal, SYSTEM_TEXT("TaskModal��ʽ") } },
      miscDescription{ { MessageBoxMisc::NoMisc, SYSTEM_TEXT("��û�����") },
                       { MessageBoxMisc::Help, SYSTEM_TEXT("����ʾ������ť��") },
                       { MessageBoxMisc::NoFocus, SYSTEM_TEXT("��MessageBox��ʹ�ô˱�־��") },
                       { MessageBoxMisc::SetForeground, SYSTEM_TEXT("����Ϣ��Ϊǰ�����ڣ�") },
                       { MessageBoxMisc::DefaultDesktopOnly, SYSTEM_TEXT("����������ĵ�ǰ����һ����һ��ȱʡ���棩") },
                       { MessageBoxMisc::TopMost, SYSTEM_TEXT("����Ϣ����WS_EX_TOPMOST����������������") },
                       { MessageBoxMisc::Right, SYSTEM_TEXT("���ı��Ҷ��룩") },
                       { MessageBoxMisc::RightToLeftReading, SYSTEM_TEXT("��ָ���ı�ӦΪ��ϣ�����Ͱ�������ϵͳ�еĴ��ҵ�����ʾ��") },
                       { MessageBoxMisc::ServiceNotification, SYSTEM_TEXT("����������֪ͨ�û��¼��ķ���") },
                       { MessageBoxMisc::ServiceNotificationNt3x, SYSTEM_TEXT("��MessageBox��ʹ�ô˱�־��") } },
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
