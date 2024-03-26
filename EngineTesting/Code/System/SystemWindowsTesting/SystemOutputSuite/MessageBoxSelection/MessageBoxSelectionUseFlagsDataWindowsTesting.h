/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 12:26)

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
    /// @brief ��Ϣ��ѡ��ģ��ʹ�ñ�־���ݵĲ��ԡ�
    /// ����ֻ����hWnd������Ϊ�յ������
    /// SystemTesting��hWnd����Ϊ��ʱ�Ĳ��ԡ�
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