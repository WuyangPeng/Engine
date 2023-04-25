///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 14:00)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_SQRT_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_SQRT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SqrtTesting final : public UnitTest
    {
    public:
        using ClassType = SqrtTesting;
        using ParentType = UnitTest;

    public:
        explicit SqrtTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void SqrtTest(); 

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_SQRT_TESTING_H
