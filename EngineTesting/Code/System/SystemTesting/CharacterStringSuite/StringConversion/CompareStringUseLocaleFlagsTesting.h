///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:02)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H

#include "CompareStringUseLocaleTestingBase.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

namespace System
{
    class CompareStringUseLocaleFlagsTesting final : public CompareStringUseLocaleTestingBase
    {
    public:
        using ClassType = CompareStringUseLocaleFlagsTesting;
        using ParentType = CompareStringUseLocaleTestingBase;

    public:
        explicit CompareStringUseLocaleFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CompareStringUseLocaleFlagsTest();
        void CompareStringTest(size_t index);

        void CompareStringEqualTest(LanguageLocale languageLocale, Compares compare, const String& comparesString);
        void CompareStringOppositeTest(LanguageLocale languageLocale, Compares compare, const String& lhsComparesString, const String& rhsComparesString);

    private:
        using LanguageLocaleContainer = std::vector<LanguageLocale>;
        using ComparesStringContainer = std::vector<String>;

    private:
        LanguageLocaleContainer languageLocales;
        ComparesStringContainer comparesStrings;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H