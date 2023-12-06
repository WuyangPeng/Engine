/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 23:03)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_TESTING_RENDERING_MANAGER_TESTING_H
#define DATABASE_GENERATE_MIDDLE_LAYER_TESTING_RENDERING_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateMiddleLayerTesting
{
    class RenderingManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RenderingManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit RenderingManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void RenderingManagerTest();
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_TESTING_RENDERING_MANAGER_TESTING_H