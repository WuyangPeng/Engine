///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.11 (2023/06/07 22:11)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONFIGURE_LOADING_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONFIGURE_LOADING_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CSVConfigureLoadingTesting final : public UnitTest
    {
    public:
        using ClassType = CSVConfigureLoadingTesting;
        using ParentType = UnitTest;

    public:
        explicit CSVConfigureLoadingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CSVConfigureContainerTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONFIGURE_LOADING_TESTING_H
