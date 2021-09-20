///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/26 14:58)

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
        void DoRunUnitTest() final;
        void MainTest();

        void DefaultTest();
        void UseFactoryTest();
        void UseUseDefaultConstructionTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_COPY_UNSHARED_IMPL_TESTING_H