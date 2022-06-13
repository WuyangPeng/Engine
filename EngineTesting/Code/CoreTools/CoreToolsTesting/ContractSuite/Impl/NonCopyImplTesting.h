///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:29)

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
        void DoRunUnitTest() final;
        void MainTest();

        void DefaultTest();
        void UseFactoryTest();
        void UseUseDefaultConstructionTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_NON_COPY_IMPL_TESTING_H