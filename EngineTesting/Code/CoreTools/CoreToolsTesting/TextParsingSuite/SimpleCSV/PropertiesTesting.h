///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 15:13)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_PROPERTIES_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_PROPERTIES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class PropertiesTesting final : public UnitTest
    {
    public:
        using ClassType = PropertiesTesting;
        using ParentType = UnitTest;

    public:
        explicit PropertiesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PropertiesTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_PROPERTIES_TESTING_H