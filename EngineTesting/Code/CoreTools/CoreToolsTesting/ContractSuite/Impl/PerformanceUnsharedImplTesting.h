/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 10:20)

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
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultTest();
        void UseFactoryTest();
        void UseUseDefaultConstructionTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_PERFORMANCE_UNSHARED_IMPL_TESTING_H