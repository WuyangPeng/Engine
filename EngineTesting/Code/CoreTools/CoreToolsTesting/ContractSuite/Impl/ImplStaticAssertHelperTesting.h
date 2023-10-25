///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 16:29)

#ifndef CORE_TOOLS_CONTRACT_SUITE_IMPL_STATIC_ASSERT_HELPER_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_IMPL_STATIC_ASSERT_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ImplStaticAssertHelperTesting final : public UnitTest
    {
    public:
        using ClassType = ImplStaticAssertHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit ImplStaticAssertHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StaticAssertTest() noexcept;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_IMPL_STATIC_ASSERT_HELPER_TESTING_H