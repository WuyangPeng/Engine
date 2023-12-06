/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/23 11:33)

#include "CameraFrustumTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTest.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"

Rendering::CameraFrustumTesting::CameraFrustumTesting(const OStreamShared& stream)
    : ParentType{ stream },
      viewVolumeTool{ GetEngineRandomSeed() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CameraFrustumTesting)

void Rendering::CameraFrustumTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::CameraFrustumTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PerspectiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(SetFrustumTest0);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(SetFrustumTest1);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(SetFrustumTest2);
}

void Rendering::CameraFrustumTesting::PerspectiveTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::MinusOneToOne, epsilon);

    ASSERT_FALSE(viewVolume->IsPerspective());
}

void Rendering::CameraFrustumTesting::DefaultTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::MinusOneToOne, epsilon);

    constexpr auto upFieldOfViewDegrees = 90.0f;
    constexpr auto aspectRatio = 1.0f;
    constexpr auto directionMin = 1.0f;
    constexpr auto directionMax = 10000.0f;

    const auto frustum = GetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

    ASSERT_APPROXIMATE(viewVolume->GetDirectionMin(), frustum.at(0), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetDirectionMax(), frustum.at(1), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetUpMin(), frustum.at(2), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetUpMax(), frustum.at(3), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetRightMin(), frustum.at(4), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetRightMax(), frustum.at(5), epsilon);

    const auto container = viewVolume->GetFrustum();

    for (auto i = 0; i < System::EnumCastUnderlying(ViewFrustum::Quantity); ++i)
    {
        ASSERT_APPROXIMATE(container.at(i), frustum.at(i), epsilon);
    }

    const auto symmetricFrustum = viewVolume->GetSymmetricFrustum();

    ASSERT_APPROXIMATE(symmetricFrustum.GetUpFieldOfViewDegrees(), upFieldOfViewDegrees, epsilon);
    ASSERT_APPROXIMATE(symmetricFrustum.GetAspectRatio(), aspectRatio, epsilon);
    ASSERT_APPROXIMATE(symmetricFrustum.GetDirectionMin(), directionMin, epsilon);
    ASSERT_APPROXIMATE(symmetricFrustum.GetDirectionMax(), directionMax, epsilon);
}

bool Rendering::CameraFrustumTesting::SetFrustumTest0()
{
    constexpr auto epsilon = 1e-4f;
    constexpr auto angle = 360.0f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::MinusOneToOne, epsilon);

    auto upFieldOfViewDegrees = Mathematics::MathF::FMod(90.0f * viewVolumeTool.GetRandomProportion(), angle);
    if (angle / 2.0f < upFieldOfViewDegrees)
    {
        upFieldOfViewDegrees -= angle / 2.0f;
    }

    const auto aspectRatio = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMin = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMax = 10000.0f * viewVolumeTool.GetRandomProportion();

    viewVolume->SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

    const auto frustum = GetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

    ASSERT_APPROXIMATE(viewVolume->GetDirectionMin(), frustum.at(0), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetDirectionMax(), frustum.at(1), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetUpMin(), frustum.at(2), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetUpMax(), frustum.at(3), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetRightMin(), frustum.at(4), epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetRightMax(), frustum.at(5), epsilon);

    const auto symmetricFrustum = viewVolume->GetSymmetricFrustum();

    ASSERT_APPROXIMATE(symmetricFrustum.GetUpFieldOfViewDegrees(), upFieldOfViewDegrees, epsilon);
    ASSERT_APPROXIMATE(symmetricFrustum.GetAspectRatio(), aspectRatio, epsilon);
    ASSERT_APPROXIMATE(symmetricFrustum.GetDirectionMin(), directionMin, epsilon);
    ASSERT_APPROXIMATE(symmetricFrustum.GetDirectionMax(), directionMax, epsilon);

    return true;
}

bool Rendering::CameraFrustumTesting::SetFrustumTest1()
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::MinusOneToOne, epsilon);

    const auto directionMin = viewVolume->GetDirectionMin() * viewVolumeTool.GetRandomProportion();
    const auto upMin = viewVolume->GetUpMin() * viewVolumeTool.GetRandomProportion();
    const auto rightMin = viewVolume->GetRightMin() * viewVolumeTool.GetRandomProportion();

    viewVolume->SetFrustum(directionMin, -directionMin, upMin, -upMin, rightMin, -rightMin);

    ASSERT_APPROXIMATE(viewVolume->GetDirectionMin(), directionMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetDirectionMax(), -directionMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetUpMin(), upMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetUpMax(), -upMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetRightMin(), rightMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetRightMax(), -rightMin, epsilon);
    return true;
}

bool Rendering::CameraFrustumTesting::SetFrustumTest2()
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::MinusOneToOne, epsilon);

    const auto directionMin = viewVolume->GetDirectionMin() * viewVolumeTool.GetRandomProportion();
    const auto upMin = viewVolume->GetUpMin() * viewVolumeTool.GetRandomProportion();
    const auto rightMin = viewVolume->GetRightMin() * viewVolumeTool.GetRandomProportion();

    const ViewVolumeTest::Container container{ directionMin, -directionMin, upMin, -upMin, rightMin, -rightMin };

    viewVolume->SetFrustum(container);

    ASSERT_APPROXIMATE(viewVolume->GetDirectionMin(), directionMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetDirectionMax(), -directionMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetUpMin(), upMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetUpMax(), -upMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetRightMin(), rightMin, epsilon);
    ASSERT_APPROXIMATE(viewVolume->GetRightMax(), -rightMin, epsilon);

    return true;
}