///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/14 19:08)

#include "CameraFrustumDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CameraFrustumDataTesting)

void Rendering::CameraFrustumDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DataTest);
}

void Rendering::CameraFrustumDataTesting::DataTest()
{
    const CameraFrustumData firstCameraFrustumData;

    ASSERT_FALSE(firstCameraFrustumData.IsSymmetric());

    const CameraFrustumData secondCameraFrustumData(3.0f, 1.0f, 1.0f, 10.0f);

    ASSERT_TRUE(secondCameraFrustumData.IsSymmetric());

    ASSERT_APPROXIMATE(secondCameraFrustumData.GetUpFieldOfViewDegrees(), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondCameraFrustumData.GetAspectRatio(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondCameraFrustumData.GetDirectionMin(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondCameraFrustumData.GetDirectionMax(), 10.0f, 1e-8f);
}
