///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/06 14:24)

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
        void DoRunUnitTest() final;
        void MainTest();

        void CaseInsensitiveComparisonTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_COMPARISON_TESTING_H