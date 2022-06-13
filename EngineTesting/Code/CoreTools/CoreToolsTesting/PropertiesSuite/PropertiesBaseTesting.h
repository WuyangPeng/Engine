///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:39)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTIES_BASE_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTIES_BASE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <string>

namespace CoreTools
{
    class PropertiesBaseTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PropertiesBaseTesting);

    private:
        void MainTest();
        void GetSetTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTIES_BASE_TESTING_H
