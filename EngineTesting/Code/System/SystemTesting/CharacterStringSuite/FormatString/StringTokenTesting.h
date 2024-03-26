/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:04)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STRING_TOKEN_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STRING_TOKEN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class StringTokenTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StringTokenTesting;
        using ParentType = UnitTest;

    public:
        explicit StringTokenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StringTokenTest();

        void DoStringTokenTest(const std::string& separate, char* next, char* token);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_STRING_TOKEN_TESTING_H