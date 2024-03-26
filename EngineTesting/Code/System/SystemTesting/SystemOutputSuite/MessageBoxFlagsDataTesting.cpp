/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 10:20)

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
      messageBoxTypes{ MessageBoxType::Ok,
                       MessageBoxType::OkCancel,
                       MessageBoxType::AbortRetryIgnore,
                       MessageBoxType::YesNoCancel,
                       MessageBoxType::YesNo,
                       MessageBoxType::RetryCancel,
                       MessageBoxType::CancelTryContinue },
      messageBoxIcons{ MessageBoxIcon::NoIcon,
                       MessageBoxIcon::Hand,
                       MessageBoxIcon::Question,
                       MessageBoxIcon::Exclamation,
                       MessageBoxIcon::Asterisk,
                       MessageBoxIcon::UserIcon,
                       MessageBoxIcon::Waning,
                       MessageBoxIcon::Error,
                       MessageBoxIcon::Information,
                       MessageBoxIcon::Stop },
      messageBoxDefaults{ MessageBoxDefault::Button1,
                          MessageBoxDefault::Button2,
                          MessageBoxDefault::Button3,
                          MessageBoxDefault::Button4 },
      messageBoxModes{ MessageBoxMode::ApplicationModal,
                       MessageBoxMode::SystemModal,
                       MessageBoxMode::TaskModal },
      messageBoxMisc{ MessageBoxMisc::NoMisc,
                      MessageBoxMisc::Help,
                      MessageBoxMisc::NoFocus,
                      MessageBoxMisc::SetForeground,
                      MessageBoxMisc::DefaultDesktopOnly,
                      MessageBoxMisc::TopMost,
                      MessageBoxMisc::Right,
                      MessageBoxMisc::RightToLeftReading,
                      MessageBoxMisc::ServiceNotification,
                      MessageBoxMisc::ServiceNotificationNt3X },
      maxSize{ CoreTools::MaxElement<size_t>({ messageBoxTypes.size(), messageBoxIcons.size(), messageBoxDefaults.size(), messageBoxModes.size(), messageBoxMisc.size() }) },
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
    std::ranges::shuffle(messageBoxTypes, randomEngine);
    std::ranges::shuffle(messageBoxIcons, randomEngine);
    std::ranges::shuffle(messageBoxDefaults, randomEngine);
    std::ranges::shuffle(messageBoxModes, randomEngine);
    std::ranges::shuffle(messageBoxMisc, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(FlagsTest);

    return true;
}

void System::MessageBoxFlagsDataTesting::FlagsTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoFlagsTest, index);
    }
}

void System::MessageBoxFlagsDataTesting::DoFlagsTest(size_t index)
{
    const auto typeFlag = messageBoxTypes.at(index % messageBoxTypes.size());
    const auto iconFlag = messageBoxIcons.at(index % messageBoxIcons.size());
    const auto defaultFlag = messageBoxDefaults.at(index % messageBoxDefaults.size());
    const auto modeFlag = messageBoxModes.at(index % messageBoxModes.size());
    const auto miscFlag = messageBoxMisc.at(index % messageBoxMisc.size());

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
