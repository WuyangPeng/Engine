///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:58)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STR_LEN_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STR_LEN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class StrLenTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StrLenTesting;
        using ParentType = UnitTest;

    public:
        explicit StrLenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StrLenTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_STR_LEN_TESTING_H