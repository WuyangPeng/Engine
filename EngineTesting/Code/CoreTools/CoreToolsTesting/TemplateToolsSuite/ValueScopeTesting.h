///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 18:49)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ValueScopeTesting : public UnitTest
    {
    public:
        using ClassType = ValueScopeTesting;
        using ParentType = UnitTest;

    public:
        explicit ValueScopeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void CastTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H
