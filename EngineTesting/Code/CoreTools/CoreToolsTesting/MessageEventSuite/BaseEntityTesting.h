///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/18 11:33)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_BASE_ENTITY_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_BASE_ENTITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BaseEntityTesting final : public UnitTest
    {
    public:
        using ClassType = BaseEntityTesting;
        using ParentType = UnitTest;

    public:
        explicit BaseEntityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void BaseTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_BASE_ENTITY_TESTING_H