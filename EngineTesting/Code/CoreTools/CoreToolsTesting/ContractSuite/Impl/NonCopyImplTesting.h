/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 10:20)

#ifndef CORE_TOOLS_CONTRACT_SUITE_NON_COPY_IMPL_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_NON_COPY_IMPL_TESTING_H

#include "CoreTools/Contract/NonCopyImpl.h"
#include "CoreTools/CoreToolsTesting/ContractSuite/Detail/Impl.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class NonCopyImplTesting final : public UnitTest
    {
    public:
        using ClassType = NonCopyImplTesting;
        using ParentType = UnitTest;

        using TestingType = NonCopyImpl<Impl>;

    public:
        explicit NonCopyImplTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultTest();
        void UseFactoryTest();
        void UseUseDefaultConstructionTest();

    private:
        static constexpr auto count = 10;
        static constexpr auto modify = 1;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_NON_COPY_IMPL_TESTING_H