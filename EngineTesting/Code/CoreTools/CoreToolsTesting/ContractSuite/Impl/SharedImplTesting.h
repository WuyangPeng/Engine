///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:29)

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
        void DoRunUnitTest() final;
        void MainTest();

        void DefaultTest();
        void UseFactoryTest();
        void UseUseDefaultConstructionTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_SHARED_IMPL_TESTING_H