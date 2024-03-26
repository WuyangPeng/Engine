/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:05)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_COMPARISON_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_COMPARISON_TESTING_H

#include "CompareStringTesting.h"

namespace System
{
    class CaseInsensitiveComparisonTesting final : public CompareStringTesting
    {
    public:
        using ClassType = CaseInsensitiveComparisonTesting;
        using ParentType = CompareStringTesting;

    public:
        explicit CaseInsensitiveComparisonTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CaseInsensitiveComparisonTest();

        void CompareStringOrdinalUseBinaryTest(wchar_t lower, wchar_t capital);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_COMPARISON_TESTING_H