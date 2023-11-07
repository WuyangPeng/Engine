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

        const float* firstFrustum = firstCamera.GetFrustum();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

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

        CameraFrustumData data = firstCamera.GetFrustumData();

        ASSERT_APPROXIMATE(data.GetUpFieldOfViewDegrees(), upFieldOfViewDegrees, 1e-5f);
        ASSERT_APPROXIMATE(data.GetAspectRatio(), aspectRatio, 1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMin(), directionMin, 1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMax(), directionMax, 1e-5f);
        ASSERT_TRUE(data.IsSymmetric());

        Projector secondCamera(DepthType::ZeroToOne, false);

        secondCamera.SetFrustum(frustum.data());

        ASSERT_FALSE(secondCamera.IsPerspective());

        firstFrustum = secondCamera.GetFrustum();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

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

        data = secondCamera.GetFrustumData();

        ASSERT_FALSE(data.IsSymmetric());

        Projector thirdCamera(DepthType::MinusOneToOne, false);

        thirdCamera.SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

        ASSERT_FALSE(thirdCamera.IsPerspective());

        firstFrustum = thirdCamera.GetFrustum();

        const float halfAngleRadians = 0.5f * upFieldOfViewDegrees * Mathematics::MathF::GetDegreeToRadian();

        const float tanHalfAngleRadians = Mathematics::MathF::Tan(halfAngleRadians);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

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

        data = thirdCamera.GetFrustumData();

        ASSERT_APPROXIMATE(data.GetUpFieldOfViewDegrees(), upFieldOfViewDegrees, 1e-4f);
        ASSERT_APPROXIMATE(data.GetAspectRatio(), aspectRatio, 1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMin(), directionMin, 1e-5f);
        ASSERT_APPROXIMATE(data.GetDirectionMax(), directionMax, 1e-5f);
        ASSERT_TRUE(data.IsSymmetric());
    }
}

void Rendering::ProjectorTesting::ProjectionMatrixTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    const std::uniform_real<float> secondFloatRandomDistribution(0.0f, 180.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const float directionMin(-Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));

        const float directionMax = -directionMin;

        const float upMin(-Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));

        const float upMax = -upMin;

        const float rightMin(-Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));

        const float rightMax = -rightMin;

        Projector firstCamera(DepthType::MinusOneToOne, true);

        firstCamera.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);

        DepthType depthType = firstCamera.GetDepthType();

        const float invDirectionDifference = 1.0f / (directionMax - directionMin);
        const float invUpDifference = 1.0f / (upMax - upMin);
        const float invRightDifference = 1.0f / (rightMax - rightMin);
        const float rightSumDivideDifference = (rightMin + rightMax) * invRightDifference;
        const float upSumDivideDifference = (upMin + upMax) * invUpDifference;
        const float directionSumDivideDifference = (directionMin + directionMax) * invDirectionDifference;

        const float twoDirectionMinMultiplyInvRightDifference = 2.0f * directionMin * invRightDifference;
        const float twoDirectionMinMultiplyInvUpDifference = 2.0f * directionMin * invUpDifference;
        const float directionMaxMultiplyInvDirectionDifference = directionMax * invDirectionDifference;
        const float directionProductDivideDifference = directionMin * directionMaxMultiplyInvDirectionDifference;
        const float twoDirectionProductDivideDifference = 2.0f * directionProductDivideDifference;

        if (depthType == DepthType::ZeroToOne)
        {
            const Camera::Matrix projection(twoDirectionMinMultiplyInvRightDifference, 0.0f, -rightSumDivideDifference, 0.0f,
                                            0.0f, twoDirectionMinMultiplyInvUpDifference, -upSumDivideDifference, 0.0f,
                                            0.0f, 0.0f, directionMaxMultiplyInvDirectionDifference, -directionProductDivideDifference,
                                            0.0f, 0.0f, 1.0f, 0.0f);

            ASSERT_TRUE(Approximate(firstCamera.GetProjectionMatrix(), projection, 1e-5f));
            ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix(), projection * firstCamera.GetViewMatrix(), 1e-5f));
        }
        else
        {
            const Camera::Matrix projection(twoDirectionMinMultiplyInvRightDifference, 0.0f, -rightSumDivideDifference, 0.0f,
                                            0.0f, twoDirectionMinMultiplyInvUpDifference, -upSumDivideDifference, 0.0f,
                                            0.0f, 0.0f, directionSumDivideDifference, -twoDirectionProductDivideDifference,
                                            0.0f, 0.0f, 1.0f, 0.0f);

            ASSERT_TRUE(Approximate(firstCamera.GetProjectionMatrix(), projection, 1e-5f));
            ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix(), projection * firstCamera.GetViewMatrix(), 1e-5f));
        }

        Projector secondCamera(DepthType::ZeroToOne, false);

        secondCamera.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);

        depthType = secondCamera.GetDepthType();
        const float twoInvRightDifference = 2.0f * invRightDifference;

        const float twoInvUpDifference = 2.0f * invUpDifference;

        const float twoInvDirectionDifference = 2.0f * invDirectionDifference;

        const float directionMinMultiplyInvDirectionDifference = directionMin * invDirectionDifference;

        if (depthType == DepthType::ZeroToOne)
        {
            const Camera::Matrix projection(twoInvRightDifference, 0.0f, 0.0f, -rightSumDivideDifference,
                                            0.0f, twoInvUpDifference, 0.0f, -upSumDivideDifference,
                                            0.0f, 0.0f, invDirectionDifference, -directionMinMultiplyInvDirectionDifference,
                                            0.0f, 0.0f, 0.0f, 1.0f);

            ASSERT_TRUE(Approximate(secondCamera.GetProjectionMatrix(), projection, 1e-5f));
            ASSERT_TRUE(Approximate(secondCamera.GetProjectionViewMatrix(), projection * secondCamera.GetViewMatrix(), 1e-5f));
        }
        else
        {
            const Camera::Matrix projection(twoInvRightDifference, 0.0f, 0.0f, -rightSumDivideDifference,
                                            0.0f, twoInvUpDifference, 0.0f, -upSumDivideDifference,
                                            0.0f, 0.0f, twoInvDirectionDifference, -directionSumDivideDifference,
                                            0.0f, 0.0f, 0.0f, 1.0f);

            ASSERT_TRUE(Approximate(secondCamera.GetProjectionMatrix(), projection, 1e-5f));
            ASSERT_TRUE(Approximate(secondCamera.GetProjectionViewMatrix(),
                                    projection * secondCamera.GetViewMatrix(), 1e-5f));
        }

        const Camera::Matrix firstMatrix(firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator));

        firstCamera.SetProjectionMatrix(firstMatrix);
        secondCamera.SetProjectionMatrix(firstMatrix);

        ASSERT_TRUE(Approximate(firstCamera.GetProjectionMatrix(), firstMatrix, 1e-5f));
        ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix(),
                                firstMatrix * firstCamera.GetViewMatrix(), 1e-5f));

        ASSERT_TRUE(Approximate(secondCamera.GetProjectionMatrix(), firstMatrix, 1e-5f));
        ASSERT_TRUE(Approximate(secondCamera.GetProjectionViewMatrix(),
                                firstMatrix * secondCamera.GetViewMatrix(), 1e-5f));

        ASSERT_TRUE(firstCamera.PreViewIsIdentity());
        ASSERT_TRUE(secondCamera.PreViewIsIdentity());
        ASSERT_TRUE(firstCamera.PostProjectionIsIdentity());
        ASSERT_TRUE(secondCamera.PostProjectionIsIdentity());

        ASSERT_TRUE(Approximate(firstCamera.GetPreViewMatrix(), Camera::Matrix::GetIdentityMatrix(), 1e-5f));
        ASSERT_TRUE(Approximate(firstCamera.GetPostProjectionMatrix(), Camera::Matrix::GetIdentityMatrix(), 1e-5f));

        ASSERT_TRUE(Approximate(secondCamera.GetPreViewMatrix(), Camera::Matrix::GetIdentityMatrix(), 1e-5f));
        ASSERT_TRUE(Approximate(secondCamera.GetPostProjectionMatrix(), Camera::Matrix::GetIdentityMatrix(), 1e-5f));

        const Camera::Matrix secondMatrix(firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator));

        const Camera::Matrix thirdMatrix(firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator));

        firstCamera.SetPreViewMatrix(secondMatrix);

        ASSERT_FALSE(firstCamera.PreViewIsIdentity());
        ASSERT_TRUE(Approximate(firstCamera.GetPreViewMatrix(), secondMatrix, 1e-5f));
        ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix(),
                                (firstMatrix * firstCamera.GetViewMatrix()) * secondMatrix, 1e-5f));

        secondCamera.SetPostProjectionMatrix(secondMatrix);

        ASSERT_FALSE(secondCamera.PostProjectionIsIdentity());
        ASSERT_TRUE(Approximate(secondCamera.GetPostProjectionMatrix(), secondMatrix, 1e-5f));
        ASSERT_TRUE(Approximate(secondCamera.GetProjectionViewMatrix(),
                                secondMatrix * (firstMatrix * secondCamera.GetViewMatrix()), 1e-5f));

        firstCamera.SetPostProjectionMatrix(thirdMatrix);

        ASSERT_FALSE(firstCamera.PostProjectionIsIdentity());
        ASSERT_TRUE(Approximate(firstCamera.GetPostProjectionMatrix(), thirdMatrix, 1e-5f));
        ASSERT_TRUE(Approximate(firstCamera.GetProjectionViewMatrix(),
                                (thirdMatrix * (firstMatrix * firstCamera.GetViewMatrix())) * secondMatrix, 1e-5f));

        const Camera::APoint p00(-12.0f, -1.0f, 1.0);
        const Camera::APoint p10(1.0f, -11.0f, 2.0);
        const Camera::APoint p11(1.0f, 2.0f, 3.0);
        const Camera::APoint p01(-1.0f, 3.0f, -1.0);

        const float nearExtrude = Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator));
        const float farExtrude = nearExtrude + 100.0f;

        Projector thirdCamera(DepthType::ZeroToOne, false);
        thirdCamera.SetProjectionMatrix(p00, p10, p11, p01, nearExtrude, farExtrude);

        const Camera::APoint q000 = nearExtrude * p00;
        const Camera::APoint q100 = nearExtrude * p10;
        const Camera::APoint q110 = nearExtrude * p11;
        const Camera::APoint q010 = nearExtrude * p01;

        const Camera::APoint q001 = farExtrude * p00;
        const Camera::APoint q101 = farExtrude * p10;
        const Camera::APoint q111 = farExtrude * p11;
        const Camera::APoint q011 = farExtrude * p01;

        const Camera::AVector u0 = q100 - q000;
        const Camera::AVector u1 = q010 - q000;
        const Camera::AVector u2 = q001 - q000;

        const Camera::Matrix fourthMatrix(u0, u1, u2, q000, Mathematics::MatrixMajorFlags::Column);
        const Camera::Matrix inverseMatrix = fourthMatrix.Inverse();
        Camera::APoint point = inverseMatrix * q111;

        const float twoPoint0 = 2.0f * point[0];
        const float twoPoint1 = 2.0f * point[1];
        float twoPoint2 = 2.0f * point[2];
        float d0 = +point[0] - point[1] - point[2] + 1.0f;
        float d1 = -point[0] + point[1] - point[2] + 1.0f;
        float d2 = -point[0] - point[1] + point[2] + 1.0f;
        float d3 = +point[0] + point[1] + point[2] - 1.0f;

        float twoPoint2divide0 = twoPoint2 / twoPoint0;
        float twoPoint2divide1 = twoPoint2 / twoPoint1;

        Camera::Matrix fifthMatrix;
        fifthMatrix(0, 0) = twoPoint2divide0 * (2.0f * d3 + d0);
        fifthMatrix(0, 1) = twoPoint2divide1 * d1;
        fifthMatrix(0, 2) = d2;
        fifthMatrix(0, 3) = -twoPoint2;
        fifthMatrix(1, 0) = twoPoint2divide0 * d0;
        fifthMatrix(1, 1) = twoPoint2divide1 * (2.0f * d3 + d1);
        fifthMatrix(1, 2) = d2;
        fifthMatrix(1, 3) = -twoPoint2;

        if (depthType == DepthType::ZeroToOne)
        {
            fifthMatrix(2, 0) = 0.0f;
            fifthMatrix(2, 1) = 0.0f;
            fifthMatrix(2, 2) = d3;
            fifthMatrix(2, 3) = 0.0f;
        }
        else
        {
            fifthMatrix(2, 0) = twoPoint2divide0 * d0;
            fifthMatrix(2, 1) = twoPoint2divide1 * d1;
            fifthMatrix(2, 2) = 2.0f * d3 + d2;
            fifthMatrix(2, 3) = -twoPoint2;
        }

        fifthMatrix(3, 0) = -twoPoint2divide0 * d0;
        fifthMatrix(3, 1) = -twoPoint2divide1 * d1;
        fifthMatrix(3, 2) = -d2;
        fifthMatrix(3, 3) = twoPoint2;

        ASSERT_TRUE(Approximate(thirdCamera.GetProjectionMatrix(), fifthMatrix * inverseMatrix, 1e-5f));
    }
}

void Rendering::ProjectorTesting::AxesAlignBoundingBoxTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const float directionMin(-Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));
        const float directionMax = -directionMin;
        const float upMin(-Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));
        const float upMax = -upMin;
        const float rightMin(-Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));
        const float rightMax = -rightMin;

        const Camera::Matrix firstMatrix(firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator),
                                         firstFloatRandomDistribution(generator));

        Projector firstCamera(DepthType::ZeroToOne, true);
        firstCamera.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);

        const Camera::Matrix viewProjectionMatrix = firstCamera.GetProjectionMatrix() * firstCamera.GetViewMatrix();
        const Camera::Matrix worldViewProjectionMatrix = viewProjectionMatrix * firstMatrix;

        std::vector<float> buffer;
        constexpr int numVertices = 100;

        for (int i = 0; i < numVertices * 3; ++i)
        {
            buffer.push_back(firstFloatRandomDistribution(generator));
        }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const Camera::AxesAlignBoundingBox2D aabb = firstCamera.ComputeBoundingAABB(numVertices, reinterpret_cast<const char*>(&buffer.at(0)), sizeof(float) * 3, firstMatrix);

#include SYSTEM_WARNING_POP

        float xmin = Mathematics::MathF::maxReal;
        float xmax = -Mathematics::MathF::maxReal;
        float ymin = Mathematics::MathF::maxReal;
        float ymax = -Mathematics::MathF::maxReal;
        for (int i = 0; i < numVertices; ++i)
        {
            const auto index = i * 3;
            const float* vertex = &buffer.at(index);

            if (vertex == nullptr)
            {
                return;
            }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            const Mathematics::HomogeneousPointF position(vertex[0], vertex[1], vertex[2], 1.0f);

#include SYSTEM_WARNING_POP

            Mathematics::HomogeneousPointF homogeneousPosition = worldViewProjectionMatrix * position;
            const float invW = 1.0f / homogeneousPosition[3];
            const float xNormalizeDeviceCoordinate = homogeneousPosition[0] * invW;
            const float yNormalizeDeviceCoordinate = homogeneousPosition[1] * invW;
            if (xNormalizeDeviceCoordinate < xmin)
            {
                xmin = xNormalizeDeviceCoordinate;
            }
            if (xmax < xNormalizeDeviceCoordinate)
            {
                xmax = xNormalizeDeviceCoordinate;
            }
            if (yNormalizeDeviceCoordinate < ymin)
            {
                ymin = yNormalizeDeviceCoordinate;
            }
            if (ymax < yNormalizeDeviceCoordinate)
            {
                ymax = yNormalizeDeviceCoordinate;
            }
        }

        const Camera::AxesAlignBoundingBox2D resultAabb = Camera::AxesAlignBoundingBox2D(xmin, xmax, ymin, ymax);

        ASSERT_TRUE(Mathematics::Vector2ToolsF::Approximate(resultAabb.GetMinPoint(), aabb.GetMinPoint(), 1e-4f));
        ASSERT_TRUE(Mathematics::Vector2ToolsF::Approximate(resultAabb.GetMaxPoint(), aabb.GetMaxPoint(), 1e-3f));
    }
}

void Rendering::ProjectorTesting::StreamTest() noexcept
{
}
