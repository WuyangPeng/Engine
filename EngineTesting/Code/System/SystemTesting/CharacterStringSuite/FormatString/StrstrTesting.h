///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:59)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STR_STR_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STR_STR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class StrStrTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StrStrTesting;
        using ParentType = UnitTest;

    public:
        explicit StrStrTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StrStrTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_STR_STR_TESTING_H