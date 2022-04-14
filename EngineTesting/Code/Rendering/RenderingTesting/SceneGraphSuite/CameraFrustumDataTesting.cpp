// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 09:38)

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
