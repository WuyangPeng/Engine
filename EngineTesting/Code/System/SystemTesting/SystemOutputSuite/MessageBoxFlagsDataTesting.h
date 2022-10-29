///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/07 19:22)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_FLAGS_DATA_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_FLAGS_DATA_TESTING_H

#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class MessageBoxFlagsDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBoxFlagsDataTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageBoxFlagsDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void FlagsTest();

    private:
        using TypeFlagsCollection = std::vector<MessageBoxType>;
        using IconFlagsCollection = std::vector<MessageBoxIcon>;
        using DefaultFlagsCollection = std::vector<MessageBoxDefault>;
        using ModeFlagsCollection = std::vector<MessageBoxMode>;
        using MiscFlagsCollection = std::vector<MessageBoxMisc>;

    private:
        TypeFlagsCollection typeFlags;
        IconFlagsCollection iconFlags;
        DefaultFlagsCollection defaultFlags;
        ModeFlagsCollection modeFlags;
        MiscFlagsCollection miscFlags;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_FLAGS_DATA_TESTING_H