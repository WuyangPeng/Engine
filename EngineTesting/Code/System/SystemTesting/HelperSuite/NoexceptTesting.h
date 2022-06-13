///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 0:48)

#ifndef SYSTEM_TESTING_HELPER_SUITE_NOEXCEPT_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_NOEXCEPT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class NoexceptTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = NoexceptTesting;
        using ParentType = UnitTest;

    public:
        explicit NoexceptTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void NoexceptTest();

        SYSTEM_NORETURN static void Function0();
        SYSTEM_NORETURN static void Function1(int parameter0);
        SYSTEM_NORETURN static void Function2(int parameter0, int parameter1);
        SYSTEM_NORETURN static void Function3(int parameter0, int parameter1, int parameter2);
        SYSTEM_NORETURN static void Function4(int parameter0, int parameter1, int parameter2, int parameter3);

        static int Function5();
        static int Function6(int parameter0);
        static int Function7(int parameter0, int parameter1);
        static int Function8(int parameter0, int parameter1, int parameter2);
        static int Function9(int parameter0, int parameter1, int parameter2, int parameter3);
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_NOEXCEPT_TESTING_H
