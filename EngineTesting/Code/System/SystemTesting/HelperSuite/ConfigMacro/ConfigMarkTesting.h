///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/16 22:26)

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
