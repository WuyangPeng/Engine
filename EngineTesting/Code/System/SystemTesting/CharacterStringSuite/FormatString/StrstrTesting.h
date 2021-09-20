///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/06 19:15)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STRSTR_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STRSTR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class StrstrTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StrstrTesting;
        using ParentType = UnitTest;

    public:
        explicit StrstrTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StrstrTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_STRSTR_TESTING_H