///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:35)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_CID_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_CID_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    class MakeLanguageCidTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MakeLanguageCidTesting;
        using ParentType = UnitTest;

    public:
        explicit MakeLanguageCidTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool MakeLanguageCidTest();

    private:
        static constexpr WindowsWord maxSortId{ 0x4 };
        static constexpr WindowsWord maxLanguageShiftNum{ 16 };
        static constexpr WindowsWord maxLanguageId{ (1 << maxLanguageShiftNum) - 1 };

        std::default_random_engine randomEngine;
        std::uniform_int_distribution<WindowsWord> sortDistribution;
        std::uniform_int_distribution<WindowsWord> languageDistribution;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_CID_TESTING_H
