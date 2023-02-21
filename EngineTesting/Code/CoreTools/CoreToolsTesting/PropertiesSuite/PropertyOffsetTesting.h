///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:40)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_OFFSET_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_OFFSET_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <string>
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class PropertyOffsetTesting : public UnitTest
    {
    public:
        using ClassType = PropertyOffsetTesting;
        using ParentType = UnitTest;

    public:
        explicit PropertyOffsetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void GetTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_OFFSET_TESTING_H
