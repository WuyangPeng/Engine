/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 10:20)

#ifndef CORE_TOOLS_CONTRACT_SUITE_COPY_UNSHARED_IMPL_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_COPY_UNSHARED_IMPL_TESTING_H

#include "CoreTools/Contract/CopyUnsharedImpl.h"
#include "CoreTools/CoreToolsTesting/ContractSuite/Detail/Impl.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CopyUnsharedImplTesting final : public UnitTest
    {
    public:
        using ClassType = CopyUnsharedImplTesting;
        using ParentType = UnitTest;

        using TestingType = CopyUnsharedImpl<ClassType, Impl>;
        using ImplSharedPtr = Impl::ImplSharedPtr;

    public:
        explicit CopyUnsharedImplTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

        static NODISCARD ImplSharedPtr Clone(const Impl& impl);

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultTest();
        void UseFactoryTest();
        void UseUseDefaultConstructionTest();

        void CountTest(TestingType& copyUnsharedImpl, int aCount);
        void AddressUnequalTest(const TestingType& lhs, const TestingType& rhs, int aCount);
        void SetCountTest(TestingType& lhs, const TestingType& rhs);

    private:
        static constexpr auto count = 12;
        static constexpr auto modify = 1;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_COPY_UNSHARED_IMPL_TESTING_H