/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 10:20)

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void FlagsTest();

        void DoFlagsTest(size_t index);

    private:
        using TypeContainer = std::vector<MessageBoxType>;
        using IconContainer = std::vector<MessageBoxIcon>;
        using DefaultContainer = std::vector<MessageBoxDefault>;
        using ModeContainer = std::vector<MessageBoxMode>;
        using MiscContainer = std::vector<MessageBoxMisc>;

    private:
        TypeContainer messageBoxTypes;
        IconContainer messageBoxIcons;
        DefaultContainer messageBoxDefaults;
        ModeContainer messageBoxModes;
        MiscContainer messageBoxMisc;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_FLAGS_DATA_TESTING_H