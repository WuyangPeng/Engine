///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:48)

#ifndef SYSTEM_TESTING_CHARACTER_STRING_SUITE_LOCALE_TESTING_H
#define SYSTEM_TESTING_CHARACTER_STRING_SUITE_LOCALE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class LocaleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LocaleTesting;
        using ParentType = UnitTest;

    public:
        explicit LocaleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LocaleTest();
    };
}

#endif  // SYSTEM_TESTING_CHARACTER_STRING_SUITE_LOCALE_TESTING_H