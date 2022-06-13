///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:41)

#ifndef CORE_TOOLS_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_STRING_IOSTREAM_TESTING_H
#define CORE_TOOLS_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_STRING_IOSTREAM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CaseInsensitiveStringIOStreamTesting final : public UnitTest
    {
    public:
        using ClassType = CaseInsensitiveStringIOStreamTesting;
        using ParentType = UnitTest;

    public:
        explicit CaseInsensitiveStringIOStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StreamTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_STRING_IOSTREAM_TESTING_H
