///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/26 14:58)

#ifndef CORE_TOOLS_CONTRACT_SUITE_PERFORMANCE_UNSHARED_IMPL_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_PERFORMANCE_UNSHARED_IMPL_TESTING_H

#include "CoreTools/Contract/PerformanceUnsharedImpl.h"
#include "CoreTools/CoreToolsTesting/ContractSuite/Detail/Impl.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class PerformanceUnsharedImplTesting final : public UnitTest
    {
    public:
        using ClassType = PerformanceUnsharedImplTesting;
        using ParentType = UnitTest;
        using TestingType = PerformanceUnsharedImpl<Impl>;

    public:
        explicit PerformanceUnsharedImplTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DefaultTest();
        void UseFactoryTest();
        void UseUseDefaultConstructionTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_PERFORMANCE_UNSHARED_IMPL_TESTING_H