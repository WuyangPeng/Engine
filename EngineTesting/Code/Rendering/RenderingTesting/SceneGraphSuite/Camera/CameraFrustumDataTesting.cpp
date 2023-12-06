/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 14:42)

#include "CameraFrustumDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
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
    const CameraFrustumData cameraFrustumData0{};

    ASSERT_FALSE(cameraFrustumData0.IsSymmetric());

    constexpr auto epsilon = Mathematics::MathF::GetZeroTolerance();
    constexpr auto upFieldOfViewDegrees = 90.0f;
    constexpr auto aspectRatio = 1.0f;
    constexpr auto directionMin = 1.0f;
    constexpr auto directionMax = 10000.0f;

    const CameraFrustumData cameraFrustumData1{ upFieldOfViewDegrees, aspectRatio, directionMin, directionMax };

    ASSERT_TRUE(cameraFrustumData1.IsSymmetric());

    ASSERT_APPROXIMATE(cameraFrustumData1.GetUpFieldOfViewDegrees(), upFieldOfViewDegrees, epsilon);
    ASSERT_APPROXIMATE(cameraFrustumData1.GetAspectRatio(), aspectRatio, epsilon);
    ASSERT_APPROXIMATE(cameraFrustumData1.GetDirectionMin(), directionMin, epsilon);
    ASSERT_APPROXIMATE(cameraFrustumData1.GetDirectionMax(), directionMax, epsilon);
}
