///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 15:28)

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