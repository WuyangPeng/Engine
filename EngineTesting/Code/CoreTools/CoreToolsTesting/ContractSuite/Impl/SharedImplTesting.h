///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 16:29)

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
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_SHARED_IMPL_TESTING_H