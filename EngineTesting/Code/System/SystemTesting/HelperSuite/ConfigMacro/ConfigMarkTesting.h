///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 0:32)

#ifndef SYSTEM_TESTING_HELPER_SUITE_CONFIG_MARK_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_CONFIG_MARK_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ConfigMarkTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConfigMarkTesting;
        using ParentType = UnitTest;

    public:
        explicit ConfigMarkTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void UnusedTest() noexcept;
        void MaybeNullptrTest();
        void NnodiscardTest();
        NODISCARD int FallthroughTest() noexcept;
        int NoReturnTest();

        SYSTEM_DEPRECATED("Deprecate")
        void Deprecate() noexcept;

        MAYBE_NULLPTR const int* GetNullptr() noexcept;
        SYSTEM_NORETURN static void NoReturn();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_CONFIG_MARK_TESTING_H
