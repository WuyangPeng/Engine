///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/23 10:49)

#include "MessageBoxFlagsDataTesting.h"
#include "System/Helper/EnumCast.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxFlagsDataTesting::MessageBoxFlagsDataTesting(const OStreamShared& stream)
    : ParentType{ stream },
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
      maxSize{ CoreTools::MaxElement<size_t>({ typeFlags.size(), iconFlags.size(), defaultFlags.size(), modeFlags.size(), miscFlags.size() }) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxFlagsDataTesting)

void System::MessageBoxFlagsDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxFlagsDataTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::MessageBoxFlagsDataTesting::RandomShuffleFlags()
{
    shuffle(typeFlags.begin(), typeFlags.end(), randomEngine);
    shuffle(iconFlags.begin(), iconFlags.end(), randomEngine);
    shuffle(defaultFlags.begin(), defaultFlags.end(), randomEngine);
    shuffle(modeFlags.begin(), modeFlags.end(), randomEngine);
    shuffle(miscFlags.begin(), miscFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(FlagsTest);

    return true;
}

void System::MessageBoxFlagsDataTesting::FlagsTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        const auto typeFlag = typeFlags.at(index % typeFlags.size());
        const auto iconFlag = iconFlags.at(index % iconFlags.size());
        const auto defaultFlag = defaultFlags.at(index % defaultFlags.size());
        const auto modeFlag = modeFlags.at(index % modeFlags.size());
        const auto miscFlag = miscFlags.at(index % miscFlags.size());

        const auto flag = EnumCastUnderlying<WindowsUInt>(typeFlag) |
                          EnumCastUnderlying<WindowsUInt>(iconFlag) |
                          EnumCastUnderlying<WindowsUInt>(defaultFlag) |
                          EnumCastUnderlying<WindowsUInt>(modeFlag) |
                          EnumCastUnderlying<WindowsUInt>(miscFlag);

        const MessageBoxFlagsData flagsData{ typeFlag, iconFlag, defaultFlag, modeFlag, miscFlag };

        ASSERT_ENUM_EQUAL(flagsData.GetMessageBoxType(), typeFlag);
        ASSERT_ENUM_EQUAL(flagsData.GetMessageBoxIcon(), iconFlag);
        ASSERT_ENUM_EQUAL(flagsData.GetMessageBoxDefault(), defaultFlag);
        ASSERT_ENUM_EQUAL(flagsData.GetMessageBoxMode(), modeFlag);
        ASSERT_ENUM_EQUAL(flagsData.GetMessageBoxMisc(), miscFlag);

        ASSERT_EQUAL(flagsData.GetFlag(), flag);
    }
}