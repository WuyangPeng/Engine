///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:34)

#include "ProjectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/Projector.h"

#include <random>
#include <vector>

Rendering::ProjectorTesting::ProjectorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ProjectorTesting)

void Rendering::ProjectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ProjectorTesting::MainTest()
{
    CameraManager::Create();

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Default);

    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(FrameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrustumTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionMatrixTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AxesAlignBoundingBoxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminator();

    CameraManager::Destroy();
}

void Rendering::ProjectorTesting::FrameTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const Camera::APoint firstPosition(firstFloatRandomDistribution(generator),
                                           firstFloatRandomDistribution(generator),
                                           firstFloatRandomDistribution(generator));

        Camera::AVector firstVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));

        firstVector.Normalize();

        Camera::AVector secondVector(firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator));

        secondVector.Normalize();

        Camera::AVector thirdVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));

        thirdVector.Normalize();
    }
}

void Rendering::ProjectorTesting::FrustumTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        float directionMin(-Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));

        float directionMax = -directionMin;

        float upMin(-Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));

        float upMax = -upMin;

        float rightMin(-Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));

        float rightMax = -rightMin;

        const std::array<float, 6> frustum{ directionMin * 2.0f, directionMax, upMin / 2.0f, upMax, rightMin, rightMax * 1.5f };

        const float ratio = upMax / directionMin;
        const float upFieldOfViewDegrees = 2.0f * Mathematics::MathF::ATan(ratio) * Mathematics::MathF::GetRadianToDegree();
        const float aspectRatio = rightMin / upMin;

        Projector firstCamera(DepthType::MinusOneToOne, true);

        firstCamera.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);

        ASSERT_TRUE(firstCamera.IsPerspective());

        auto firstFrustum = firstCamera.GetFrustum();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26446)

        ASSERT_APPROXIMATE(firstFrustum[0], directionMin, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[1], directionMax, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[2], upMin, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[3], upMax, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[4], rightMin, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[5], rightMax, 1e-5f);

#include SYSTEM_WARNING_POP

        ASSERT_APPROXIMATE(firstCamera.GetDirectionMin(), directionMin, 1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetDirectionMax(), directionMax, 1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetUpMin(), upMin, 1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetUpMax(), upMax, 1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetRightMin(), rightMin, 1e-5f);
        ASSERT_APPROXIMATE(firstCamera.GetRightMax(), rightMax, 1e-5f);

        CameraFrustumData data = firstCamera.GetSymmetricFrustum();

        ASSERT_APPROXIMATE(data.GetUpFieldOfViewDegrees(), upFieldOfViewDegrees, 1e-5f);
        ASSERT_APPROXIMATE(data.GetAspectRatio(), aspectRatio, 1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMin(), directionMin, 1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMax(), directionMax, 1e-5f);
        ASSERT_TRUE(data.IsSymmetric());

        Projector secondCamera(DepthType::ZeroToOne, false);

        secondCamera.SetFrustum(frustum);

        ASSERT_FALSE(secondCamera.IsPerspective());

        firstFrustum = secondCamera.GetFrustum();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26446)

        ASSERT_APPROXIMATE(firstFrustum[0], directionMin * 2.0f, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[1], directionMax, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[2], upMin / 2.0f, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[3], upMax, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[4], rightMin, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[5], rightMax * 1.5f, 1e-5f);

#include SYSTEM_WARNING_POP

        ASSERT_APPROXIMATE(secondCamera.GetDirectionMin(), directionMin * 2.0f, 1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetDirectionMax(), directionMax, 1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetUpMin(), upMin / 2.0f, 1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetUpMax(), upMax, 1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetRightMin(), rightMin, 1e-5f);
        ASSERT_APPROXIMATE(secondCamera.GetRightMax(), rightMax * 1.5f, 1e-5f);

        data = secondCamera.GetSymmetricFrustum();

        ASSERT_FALSE(data.IsSymmetric());

        Projector thirdCamera(DepthType::MinusOneToOne, false);

        thirdCamera.SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

        ASSERT_FALSE(thirdCamera.IsPerspective());

        firstFrustum = thirdCamera.GetFrustum();

        const float halfAngleRadians = 0.5f * upFieldOfViewDegrees * Mathematics::MathF::GetDegreeToRadian();

        const float tanHalfAngleRadians = Mathematics::MathF::Tan(halfAngleRadians);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26446)

        ASSERT_APPROXIMATE(firstFrustum[0], directionMin, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[1], directionMax, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[2], -directionMin * tanHalfAngleRadians, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[3], directionMin * tanHalfAngleRadians, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[4], -aspectRatio * directionMin * tanHalfAngleRadians, 1e-5f);
        ASSERT_APPROXIMATE(firstFrustum[5], aspectRatio * directionMin * tanHalfAngleRadians, 1e-5f);

#include SYSTEM_WARNING_POP

        ASSERT_APPROXIMATE(thirdCamera.GetDirectionMin(), directionMin, 1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetDirectionMax(), directionMax, 1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetUpMin(), -directionMin * tanHalfAngleRadians, 1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetUpMax(), directionMin * tanHalfAngleRadians, 1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetRightMin(), -aspectRatio * directionMin * tanHalfAngleRadians, 1e-5f);
        ASSERT_APPROXIMATE(thirdCamera.GetRightMax(), aspectRatio * directionMin * tanHalfAngleRadians, 1e-5f);

        data = thirdCamera.GetSymmetricFrustum();

        ASSERT_APPROXIMATE(data.GetUpFieldOfViewDegrees(), upFieldOfViewDegrees, 1e-4f);
        ASSERT_APPROXIMATE(data.GetAspectRatio(), aspectRatio, 1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMin(), directionMin, 1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMax(), directionMax, 1e-5f);
        ASSERT_TRUE(data.IsSymmetric());
    }
}

void Rendering::ProjectorTesting::ProjectionMatrixTest() noexcept
{
}

void Rendering::ProjectorTesting::AxesAlignBoundingBoxTest() noexcept
{
}

void Rendering::ProjectorTesting::StreamTest() noexcept
{
}
