///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 19:55)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_KEY_INFO_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_KEY_INFO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class ControllerKeyInfoTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ControllerKeyInfoTesting);

    private:
        void MainTest();
        void InitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_KEY_INFO_TESTING_H