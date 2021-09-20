///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/26 14:58)

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