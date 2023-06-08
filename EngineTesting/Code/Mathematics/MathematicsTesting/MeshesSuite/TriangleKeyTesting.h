///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/03 16:26)

#ifndef MATHEMATICS_MESHES_SUITE_TRIANGLE_KEY_TESTING_H
#define MATHEMATICS_MESHES_SUITE_TRIANGLE_KEY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class TriangleKeyTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = TriangleKeyTesting;
        using ParentType = UnitTest;

    public:
        explicit TriangleKeyTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void KeyTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_MESHES_SUITE_TRIANGLE_KEY_TESTING_H