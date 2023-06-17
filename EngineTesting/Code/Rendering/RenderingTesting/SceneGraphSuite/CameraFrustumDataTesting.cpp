///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:31)

#include "CameraFrustumDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"

Rendering::CameraFrustumDataTesting::CameraFrustumDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CameraFrustumDataTesting)

void Rendering::CameraFrustumDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
