///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/03 16:26)

#ifndef MATHEMATICS_MESHES_SUITE_EDGE_KEY_TESTING_H
#define MATHEMATICS_MESHES_SUITE_EDGE_KEY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class EdgeKeyTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EdgeKeyTesting);

    private:
        void MainTest();
        void KeyTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_MESHES_SUITE_EDGE_KEY_TESTING_H