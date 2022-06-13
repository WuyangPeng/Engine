///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:15)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_APP_PROPERTIES_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_APP_PROPERTIES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AppPropertiesTesting final : public UnitTest
    {
    public:
        using ClassType = AppPropertiesTesting;
        using ParentType = UnitTest;

    public:
        explicit AppPropertiesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AppendSheetNameTest();
        void DeleteSheetNameTest();
        void SetSheetNameTest();
        void PropertyTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_APP_PROPERTIES_TESTING_H