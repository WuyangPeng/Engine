///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:12)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H

#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class LanguageIdDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LanguageIdDataTesting;
        using ParentType = UnitTest;

    public:
        explicit LanguageIdDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void FlagsTest();

        void DefaultFlagTest() noexcept;
        void DoFlagsTest(size_t index);

    private:
        using PrimaryLanguageFlagsContainer = std::vector<PrimaryLanguage>;
        using SubLanguageFlagsContainer = std::vector<SubLanguage>;

    private:
        PrimaryLanguageFlagsContainer primaryLanguages;
        SubLanguageFlagsContainer subLanguages;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H