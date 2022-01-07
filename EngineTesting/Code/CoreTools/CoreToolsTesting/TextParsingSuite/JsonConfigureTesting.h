///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.6 (2021/11/19 13:57)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_JSON_CONFIGURE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_JSON_CONFIGURE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class JsonConfigureTesting final : public UnitTest
    {
    public:
        using ClassType = JsonConfigureTesting;
        using ParentType = UnitTest;

    public:
        explicit JsonConfigureTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void JsonConfigureTest() noexcept;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_JSON_CONFIGURE_TESTING_H
