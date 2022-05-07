// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.3 (2020/03/06 15:36)

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