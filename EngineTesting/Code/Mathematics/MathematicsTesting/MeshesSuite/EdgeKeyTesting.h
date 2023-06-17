///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:54)

#ifndef MATHEMATICS_MESHES_SUITE_EDGE_KEY_TESTING_H
#define MATHEMATICS_MESHES_SUITE_EDGE_KEY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class EdgeKeyTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = EdgeKeyTesting;
        using ParentType = UnitTest;

    public:
        explicit EdgeKeyTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void KeyTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_MESHES_SUITE_EDGE_KEY_TESTING_H