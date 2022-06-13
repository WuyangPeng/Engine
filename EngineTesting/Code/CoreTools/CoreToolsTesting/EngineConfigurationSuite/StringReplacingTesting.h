///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 13:41)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_STRING_REPLACING_TESTING_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_STRING_REPLACING_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class StringReplacingTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StringReplacingTesting);

    private:
        void MainTest();
        void StringReplacingTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_STRING_REPLACING_TESTING_H