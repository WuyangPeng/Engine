///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/14 1:16)

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