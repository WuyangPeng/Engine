///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/18 11:55)

#ifndef CORE_TOOLS_HELPER_SUITE_PROPERTIES_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_PROPERTIES_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class PropertiesMacroTesting final : public UnitTest
    {
    public:
        using ClassType = PropertiesMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit PropertiesMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PropertiesFriendTest();
        void PropertiesValue0Test();
        void PropertiesValue1Test();
        void PropertiesValue2Test();
        void PropertiesValue3Test();
        void PropertiesValue4Test();
        void PropertiesValue5Test();
        void PropertiesValue6Test();
        void PropertiesValue8Test();
        void PropertiesValue9Test();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_PROPERTIES_MACRO_TESTING_H