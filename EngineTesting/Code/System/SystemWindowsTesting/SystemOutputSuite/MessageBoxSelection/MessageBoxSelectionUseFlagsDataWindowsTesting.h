/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 12:26)

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
    /// @brief 消息框选择模块使用标志数据的测试。
    /// 这里只测试hWnd参数不为空的情况。
    /// SystemTesting有hWnd参数为空时的测试。
    class MessageBoxSelectionUseFlagsDataWindowsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBoxSelectionUseFlagsDataWindowsTesting;
        using ParentType = UnitTest;

    public:
        MessageBoxSelectionUseFlagsDataWindowsTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void MessageBoxTest();

        void DoMessageBoxTest(size_t index);

        MAYBE_NULLPTR WindowsHWnd GetHWnd(MessageBoxMisc miscFlag) const noexcept;

    private:
        using TypeFlagsContainer = std::vector<MessageBoxType>;
        using IconFlagsContainer = std::vector<MessageBoxIcon>;
        using DefaultFlagsContainer = std::vector<MessageBoxDefault>;
        using ModeFlagsContainer = std::vector<MessageBoxMode>;
        using MiscFlagsContainer = std::vector<MessageBoxMisc>;
        using CommandFlagsContainer = std::vector<DialogBoxCommand>;
        using MessageBoxReturnContainer = std::map<MessageBoxType, CommandFlagsContainer>;
        using IconDescription = std::map<MessageBoxIcon, String>;
        using DefaultDescription = std::map<MessageBoxDefault, String>;
        using ModeDescription = std::map<MessageBoxMode, String>;
        using MiscDescription = std::map<MessageBoxMisc, String>;

    private:
        WindowsHWnd hWnd;
        TypeFlagsContainer typeFlags;
        IconFlagsContainer iconFlags;
        DefaultFlagsContainer defaultFlags;
        ModeFlagsContainer modeFlags;
        MiscFlagsContainer miscFlags;
        MessageBoxReturnContainer returnCollections;
        IconDescription iconDescriptions;
        DefaultDescription defaultDescriptions;
        ModeDescription modeDescriptions;
        MiscDescription miscDescriptions;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_WINDOWS_TESTING_H