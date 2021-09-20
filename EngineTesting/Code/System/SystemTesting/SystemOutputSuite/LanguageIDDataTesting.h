///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/23 11:00)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H

#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class LanguageIDDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LanguageIDDataTesting;
        using ParentType = UnitTest;

    public:
        explicit LanguageIDDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void FlagsTest();
        void DefaultFlagTest() noexcept;

    private:
        using PrimaryLanguageFlagsCollection = std::vector<PrimaryLanguage>;
        using SubLanguageFlagsCollection = std::vector<SubLanguage>;

    private:
        PrimaryLanguageFlagsCollection primaryLanguageFlags;
        SubLanguageFlagsCollection subLanguageFlags;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H