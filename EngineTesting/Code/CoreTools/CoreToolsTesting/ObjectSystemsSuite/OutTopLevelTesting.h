///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:37)
#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OUT_TOP_LEVEL_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OUT_TOP_LEVEL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class OutTopLevelTesting : public UnitTest
    {
    public:
        using ClassType = OutTopLevelTesting;
        using ParentType = UnitTest;

    public:
        explicit OutTopLevelTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void TopLevelTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OUT_TOP_LEVEL_TESTING_H