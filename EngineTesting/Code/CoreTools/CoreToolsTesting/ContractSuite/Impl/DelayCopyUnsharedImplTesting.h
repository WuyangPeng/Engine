///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/02/23 14:30)

#ifndef CORE_TOOLS_CONTRACT_SUITE_DELAY_COPY_UNSHARED_IMPL_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_DELAY_COPY_UNSHARED_IMPL_TESTING_H

#include "CoreTools/CoreToolsTesting/ContractSuite/Detail/Impl.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DelayCopyUnsharedImplTesting final : public UnitTest
    {
    public:
        using ClassType = DelayCopyUnsharedImplTesting;
        using ParentType = UnitTest;

    public:
        explicit DelayCopyUnsharedImplTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultTest();
        void UseFactoryTest();
        void UseUseDefaultConstructionTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_DELAY_COPY_UNSHARED_IMPL_TESTING_H