/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/27 14:42)

#ifndef RENDERING_SCENE_GRAPH_SUITE_CAMERA_FRUSTUM_DATA_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_CAMERA_FRUSTUM_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class CameraFrustumDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CameraFrustumDataTesting;
        using ParentType = UnitTest;

    public:
        explicit CameraFrustumDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
        void DataTest();
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_CAMERA_FRUSTUM_DATA_TESTING_H