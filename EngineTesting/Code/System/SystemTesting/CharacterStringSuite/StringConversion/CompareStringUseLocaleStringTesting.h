///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/02 15:09)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_STRING_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_STRING_TESTING_H

#include "CompareStringUseLocaleTestingBase.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

namespace System
{
    class CompareStringUseLocaleStringTesting final : public CompareStringUseLocaleTestingBase
    {
    public:
        using ClassType = CompareStringUseLocaleStringTesting;
        using ParentType = CompareStringUseLocaleTestingBase;

    public:
        explicit CompareStringUseLocaleStringTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CompareStringUseLocaleStringTest();
        void CompareStringTest(size_t index);

        void CompareStringEqualTest(const wchar_t* languageLocaleString, Compares compare, const String& comparesWString);
        void CompareStringOppositeTest(const wchar_t* languageLocaleString, Compares compare, const String& lhsComparesWString, const String& rhsComparesWString);

    private:
        using LanguageLocaleStringContainer = std::vector<const wchar_t*>;
        using ComparesWStringContainer = std::vector<std::wstring>;

    private:
        LanguageLocaleStringContainer languageLocaleStrings;
        ComparesWStringContainer comparesWStrings;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_STRING_TESTING_H