/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 10:20)

#ifndef CORE_TOOLS_CONTRACT_SUITE_SHARED_IMPL_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_SHARED_IMPL_TESTING_H

#include "CoreTools/Contract/SharedImpl.h"
#include "CoreTools/CoreToolsTesting/ContractSuite/Detail/Impl.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SharedImplTesting final : public UnitTest
    {
    public:
        using ClassType = SharedImplTesting;
        using ParentType = UnitTest;

        using TestingType = SharedImpl<Impl>;

    public:
        explicit SharedImplTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultTest();
        void UseFactoryTest();
        void UseUseDefaultConstructionTest();

        void CountTest(TestingType& sharedImpl, int aCount);
        void AddressEqualTest(const TestingType& lhs, const TestingType& rhs, int aCount);

    private:
        static constexpr auto count = 12;
        static constexpr auto modify = 1;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_SHARED_IMPL_TESTING_H