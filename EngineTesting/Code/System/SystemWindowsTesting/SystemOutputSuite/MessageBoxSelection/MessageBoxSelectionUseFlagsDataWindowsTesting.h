///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/23 20:12)

#ifndef SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_WINDOWS_TESTING_H

#include "System/Helper/UnicodeUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>
#include <random>
#include <vector>

namespace System
{
    class MessageBoxSelectionUseFlagsDataWindowsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBoxSelectionUseFlagsDataWindowsTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageBoxSelectionUseFlagsDataWindowsTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void MessageBoxTest();

        MAYBE_NULLPTR WindowsHWnd GetHwnd(MessageBoxMisc miscFlag) const noexcept;

    private:
        using TypeFlagsCollection = std::vector<MessageBoxType>;
        using IconFlagsCollection = std::vector<MessageBoxIcon>;
        using DefaultFlagsCollection = std::vector<MessageBoxDefault>;
        using ModeFlagsCollection = std::vector<MessageBoxMode>;
        using MiscFlagsCollection = std::vector<MessageBoxMisc>;
        using CommandFlagsCollection = std::vector<DialogBoxCommand>;
        using MessageBoxReturnCollection = std::map<MessageBoxType, CommandFlagsCollection>;
        using IconDescription = std::map<MessageBoxIcon, String>;
        using DefaultDescription = std::map<MessageBoxDefault, String>;
        using ModeDescription = std::map<MessageBoxMode, String>;
        using MiscDescription = std::map<MessageBoxMisc, String>;

    private:
        WindowsHWnd hwnd;
        TypeFlagsCollection typeFlags;
        IconFlagsCollection iconFlags;
        DefaultFlagsCollection defaultFlags;
        ModeFlagsCollection modeFlags;
        MiscFlagsCollection miscFlags;
        MessageBoxReturnCollection returnCollection;
        IconDescription iconDescription;
        DefaultDescription defaultDescription;
        ModeDescription modeDescription;
        MiscDescription miscDescription;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_WINDOWS_TESTING_H