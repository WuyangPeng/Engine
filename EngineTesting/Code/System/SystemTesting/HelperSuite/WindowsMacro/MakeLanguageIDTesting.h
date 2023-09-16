///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:38)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_ID_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_ID_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    class MakeLanguageIdTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MakeLanguageIdTesting;
        using ParentType = UnitTest;

    public:
        explicit MakeLanguageIdTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool MakeLanguageIdTest();
        void MakeMaxLanguageIdTest();

    private:
        static constexpr WindowsWord maxPrimaryShiftNum{ 10 };
        static constexpr WindowsWord maxPrimaryId{ (1 << maxPrimaryShiftNum) - 1 };
        static constexpr WindowsWord maxSubId{ 0x15 };

        std::default_random_engine randomEngine;
        std::uniform_int_distribution<WindowsWord> primaryDistribution;
        std::uniform_int_distribution<WindowsWord> subDistribution;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_ID_TESTING_H
