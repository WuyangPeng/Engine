///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/06 13:54)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H

#include "CompareStringTesting.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class CompareStringUseLocaleFlagsTesting final : public CompareStringTesting
    {
    public:
        using ClassType = CompareStringUseLocaleFlagsTesting;
        using ParentType = CompareStringTesting;

    public:
        explicit CompareStringUseLocaleFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CompareStringUseLocaleFlagsTest();

    private:
        using LanguageLocaleFlagsCollection = std::vector<LanguageLocale>;
        using ComparesFlagsCollection = std::vector<Compares>;
        using ComparesStringCollection = std::vector<String>;

    private:
        LanguageLocaleFlagsCollection languageLocaleFlags;
        ComparesFlagsCollection comparesFlags;
        ComparesStringCollection comparesString;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H