///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:45)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_CONSTRAINT_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_CONSTRAINT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class ConstraintTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ConstraintTesting);

    private:
        void MainTest();
        void MustBePodTest() noexcept;
        void MustBeSameSizeTest() noexcept;
        void MustBeSubscriptableTest() noexcept;
        void MustHaveBaseTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_CONSTRAINT_TESTING_H
