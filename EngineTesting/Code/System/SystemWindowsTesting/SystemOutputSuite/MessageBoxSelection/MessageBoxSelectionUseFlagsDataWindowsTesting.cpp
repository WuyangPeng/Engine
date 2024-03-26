/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 12:27)

#include "MessageBoxSelectionUseFlagsDataWindowsTesting.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxSelectionUseFlagsDataWindowsTesting::MessageBoxSelectionUseFlagsDataWindowsTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream },
      hWnd{ hWnd },
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
      modeFlags{ MessageBoxMode::ApplicationModal,
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
                 MessageBoxMisc::ServiceNotificationNt3X },
      returnCollections{ { MessageBoxType::Ok, { DialogBoxCommand::IdOk } },
                         { MessageBoxType::OkCancel, { DialogBoxCommand::IdOk, DialogBoxCommand::IdCancel } },
                         { MessageBoxType::AbortRetryIgnore, { DialogBoxCommand::IdAbort, DialogBoxCommand::IdRetry, DialogBoxCommand::IdIgnore } },
                         { MessageBoxType::YesNoCancel, { DialogBoxCommand::IdYes, DialogBoxCommand::IdNo, DialogBoxCommand::IdCancel } },
                         { MessageBoxType::YesNo, { DialogBoxCommand::IdYes, DialogBoxCommand::IdNo } },
                         { MessageBoxType::RetryCancel, { DialogBoxCommand::IdRetry, DialogBoxCommand::IdCancel } },
                         { MessageBoxType::CancelTryContinue, { DialogBoxCommand::IdCancel, DialogBoxCommand::IdTryAgain, DialogBoxCommand::IdContinue } } },
      iconDescriptions{ { MessageBoxIcon::NoIcon, SYSTEM_TEXT("��ͼ��") },
                        { MessageBoxIcon::Hand, SYSTEM_TEXT("����") },
                        { MessageBoxIcon::Question, SYSTEM_TEXT("�ʺ�") },
                        { MessageBoxIcon::Exclamation, SYSTEM_TEXT("����") },
                        { MessageBoxIcon::Asterisk, SYSTEM_TEXT("��Ϣ") },
                        { MessageBoxIcon::UserIcon, SYSTEM_TEXT("��ͼ��") },
                        { MessageBoxIcon::Waning, SYSTEM_TEXT("����") },
                        { MessageBoxIcon::Error, SYSTEM_TEXT("����") },
                        { MessageBoxIcon::Information, SYSTEM_TEXT("��Ϣ") },
                        { MessageBoxIcon::Stop, SYSTEM_TEXT("����") } },
      defaultDescriptions{ { MessageBoxDefault::Button1, SYSTEM_TEXT("����ť1��") },
                           { MessageBoxDefault::Button2, SYSTEM_TEXT("����ť2��") },
                           { MessageBoxDefault::Button3, SYSTEM_TEXT("����ť3��") },
                           { MessageBoxDefault::Button4, SYSTEM_TEXT("����ť4��") } },
      modeDescriptions{ { MessageBoxMode::ApplicationModal, SYSTEM_TEXT("ApplModal��ʽ") },
                        { MessageBoxMode::SystemModal, SYSTEM_TEXT("SystemModal��ʽ") },
                        { MessageBoxMode::TaskModal, SYSTEM_TEXT("TaskModal��ʽ") } },
      miscDescriptions{ { MessageBoxMisc::NoMisc, SYSTEM_TEXT("��û�����") },
                        { MessageBoxMisc::Help, SYSTEM_TEXT("����ʾ������ť��") },
                        { MessageBoxMisc::NoFocus, SYSTEM_TEXT("��MessageBox��ʹ�ô˱�־��") },
                        { MessageBoxMisc::SetForeground, SYSTEM_TEXT("����Ϣ��Ϊǰ�����ڣ�") },
                        { MessageBoxMisc::DefaultDesktopOnly, SYSTEM_TEXT("����������ĵ�ǰ����һ����һ��ȱʡ���棩") },
                        { MessageBoxMisc::TopMost, SYSTEM_TEXT("����Ϣ����WS_EX_TOPMOST����������������") },
                        { MessageBoxMisc::Right, SYSTEM_TEXT("���ı��Ҷ��룩") },
                        { MessageBoxMisc::RightToLeftReading, SYSTEM_TEXT("��ָ���ı�ӦΪ��ϣ�����Ͱ�������ϵͳ�еĴ��ҵ�����ʾ��") },
                        { MessageBoxMisc::ServiceNotification, SYSTEM_TEXT("����������֪ͨ�û��¼��ķ���") },
                        { MessageBoxMisc::ServiceNotificationNt3X, SYSTEM_TEXT("��MessageBox��ʹ�ô˱�־��") } },
      maxSize{ CoreTools::MaxElement<size_t>({ typeFlags.size(), iconFlags.size(), defaultFlags.size(), modeFlags.size(), miscFlags.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool System::MessageBoxSelectionUseFlagsDataWindowsTesting::IsValid() const noexcept
{
    return ParentType::IsValid() && hWnd != nullptr;
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
    std::ranges::shuffle(typeFlags, randomEngine);
    std::ranges::shuffle(iconFlags, randomEngine);
    std::ranges::shuffle(defaultFlags, randomEngine);
    std::ranges::shuffle(modeFlags, randomEngine);
    std::ranges::shuffle(miscFlags, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(MessageBoxTest);

    return true;
}

void System::MessageBoxSelectionUseFlagsDataWindowsTesting::MessageBoxTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoMessageBoxTest, index);
    }
}

void System::MessageBoxSelectionUseFlagsDataWindowsTesting::DoMessageBoxTest(size_t index)
{
    const auto typeFlag = typeFlags.at(index % typeFlags.size());
    const auto iconFlag = iconFlags.at(index % iconFlags.size());
    const auto defaultFlag = defaultFlags.at(index % defaultFlags.size());
    const auto modeFlag = modeFlags.at(index % modeFlags.size());
    const auto miscFlag = miscFlags.at(index % miscFlags.size());

    const MessageBoxFlagsData flagsData{ typeFlag, iconFlag, defaultFlag, modeFlag, miscFlag };

    const auto caption = iconDescriptions[iconFlag] + defaultDescriptions[defaultFlag];
    const auto text = modeDescriptions[modeFlag] + miscDescriptions[miscFlag];

    const auto flag = MessageBoxSelection(GetHWnd(miscFlag), text.c_str(), caption.c_str(), flagsData);

    ASSERT_ENUM_UNEQUAL(DialogBoxCommand::IdCreationFailed, flag);

    const auto collection = returnCollections[typeFlag];

    const auto iter = std::ranges::find(collection, flag);

    ASSERT_UNEQUAL(iter, collection.cend());
}

System::WindowsHWnd System::MessageBoxSelectionUseFlagsDataWindowsTesting::GetHWnd(MessageBoxMisc miscFlag) const noexcept
{
    if (miscFlag != MessageBoxMisc::ServiceNotification && miscFlag != MessageBoxMisc::DefaultDesktopOnly)
    {
        return hWnd;
    }
    else
    {
        return nullptr;
    }
}
