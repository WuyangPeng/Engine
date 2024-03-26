/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 10:19)

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

        void DefaultFlagTest() const noexcept;
        void DoFlagsTest(size_t index);

    private:
        using PrimaryLanguageContainer = std::vector<PrimaryLanguage>;
        using SubLanguageContainer = std::vector<SubLanguage>;

    private:
        PrimaryLanguageContainer primaryLanguages;
        SubLanguageContainer subLanguages;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H