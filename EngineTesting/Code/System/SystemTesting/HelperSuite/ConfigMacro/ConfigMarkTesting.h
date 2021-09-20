///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/08 13:02)

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
