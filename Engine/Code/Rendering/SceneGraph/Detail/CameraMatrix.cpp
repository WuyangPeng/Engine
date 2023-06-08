///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 11:33)

#include "Rendering/RenderingExport.h"

#include "CameraMatrix.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/SceneGraph/CameraManager.h"

Rendering::CameraMatrix::CameraMatrix(const WorldCoordinateFrame& worldCoordinateFrame, const CameraFrustum& cameraFrustum, float epsilon)
    : worldCoordinateFrame{ worldCoordinateFrame },
      cameraFrustum{ cameraFrustum },
      projectionMatrix{ Matrix{}, Matrix{} },
      projectionViewMatrix{ Matrix{}, Matrix{} },
      preViewMatrix{ Mathematics::MatrixF::GetIdentityMatrix() },
      preViewIsIdentity{ true },
      postProjectionMatrix{ Mathematics::MatrixF::GetIdentityMatrix() },
      postProjectionIsIdentity{ true },
      depthType{ CAMERA_MANAGE_SINGLETON.GetDepthType() },
      epsilon{ epsilon }
{
    OnFrustumChange();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CameraMatrix::CameraMatrix(float epsilon)
    : worldCoordinateFrame{ epsilon },
      cameraFrustum{ true },
      projectionMatrix{ Matrix{}, Matrix{} },
      projectionViewMatrix{ Matrix{}, Matrix{} },
      preViewMatrix{ Mathematics::MatrixF::GetIdentityMatrix() },
      preViewIsIdentity{ true },
      postProjectionMatrix{ Mathematics::MatrixF::GetIdentityMatrix() },
      postProjectionIsIdentity{ true },
      depthType{ CAMERA_MANAGE_SINGLETON.GetDepthType() },
      epsilon{ epsilon }
{
    OnFrustumChange();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::CameraMatrix::OnFrustumChange()
{
    const auto directionMin = cameraFrustum.GetDirectionMin();
    const auto directionMax = cameraFrustum.GetDirectionMax();
    const auto upMin = cameraFrustum.GetUpMin();
    const auto upMax = cameraFrustum.GetUpMax();
    const auto rightMin = cameraFrustum.GetRightMin();
    const auto rightMax = cameraFrustum.GetRightMax();

    // N (near), F (far), B (bottom), T (top),
    // L (left), 和 R (right)

    // 1 / (F - N)
    const auto invDirectionDifference = 1.0f / (directionMax - directionMin);

    // 1 / (T - B)
    const auto invUpDifference = 1.0f / (upMax - upMin);

    // 1 / (R - L)
    const auto invRightDifference = 1.0f / (rightMax - rightMin);

    // (R + L) / ( R - L)
    const auto rightSumDivideDifference = (rightMin + rightMax) * invRightDifference;

    // (T + B) / (T - B)
    const auto upSumDivideDifference = (upMin + upMax) * invUpDifference;

    // (F + N) / (F - N)
    const auto directionSumDivideDifference = (directionMin + directionMax) * invDirectionDifference;

    if (cameraFrustum.IsPerspective())
    {
        // 2 * N / (R - L)
        const auto twoDirectionMinMultiplyInvRightDifference = 2.0f * directionMin * invRightDifference;

        // 2 * N / (T - B)
        const auto twoDirectionMinMultiplyInvUpDifference = 2.0f * directionMin * invUpDifference;
        // F / (F - N)
        const auto directionMaxMultiplyInvDirectionDifference = directionMax * invDirectionDifference;

        // N * F / (F - N)
        const auto directionProductDivideDifference = directionMin * directionMaxMultiplyInvDirectionDifference;

        // 2 * N * F / (F - N)
        const auto twoDirectionProductDivideDifference = 2.0f * directionProductDivideDifference;

        if (depthType == DepthType::ZeroToOne)
        {
            // 映射 (x,y,z) 到 [-1,1]x[-1,1]x[0,1].
            auto& projection = projectionMatrix.at(System::EnumCastUnderlying(DepthType::ZeroToOne));
            projection(0, 0) = twoDirectionMinMultiplyInvRightDifference;
            projection(0, 1) = 0.0f;
            projection(0, 2) = -rightSumDivideDifference;
            projection(0, 3) = 0.0f;
            projection(1, 0) = 0.0f;
            projection(1, 1) = twoDirectionMinMultiplyInvUpDifference;
            projection(1, 2) = -upSumDivideDifference;
            projection(1, 3) = 0.0f;
            projection(2, 0) = 0.0f;
            projection(2, 1) = 0.0f;
            projection(2, 2) = directionMaxMultiplyInvDirectionDifference;
            projection(2, 3) = -directionProductDivideDifference;
            projection(3, 0) = 0.0f;
            projection(3, 1) = 0.0f;
            projection(3, 2) = 1.0f;
            projection(3, 3) = 0.0f;
        }
        else
        {
            // 映射 (x,y,z) 到 [-1,1]x[-1,1]x[-1,1].
            auto& projection = projectionMatrix.at(System::EnumCastUnderlying(DepthType::MinusOneToOne));
            projection(0, 0) = twoDirectionMinMultiplyInvRightDifference;
            projection(0, 1) = 0.0f;
            projection(0, 2) = -rightSumDivideDifference;
            projection(0, 3) = 0.0f;
            projection(1, 0) = 0.0f;
            projection(1, 1) = twoDirectionMinMultiplyInvUpDifference;
            projection(1, 2) = -upSumDivideDifference;
            projection(1, 3) = 0.0f;
            projection(2, 0) = 0.0f;
            projection(2, 1) = 0.0f;
            projection(2, 2) = directionSumDivideDifference;
            projection(2, 3) = -twoDirectionProductDivideDifference;
            projection(3, 0) = 0.0f;
            projection(3, 1) = 0.0f;
            projection(3, 2) = 1.0f;
            projection(3, 3) = 0.0f;
        }
    }
    else
    {
        // 2 / (R - L)
        const auto twoInvRightDifference = 2.0f * invRightDifference;

        // 2 / (T - B)
        const auto twoInvUpDifference = 2.0f * invUpDifference;

        // 2 / (F - N)
        const auto twoInvDirectionDifference = 2.0f * invDirectionDifference;

        // N / (F - N)
        const auto directionMinMultiplyInvDirectionDifference = directionMin * invDirectionDifference;

        if (depthType == DepthType::ZeroToOne)
        {
            // 映射 (x,y,z) 到 [-1,1]x[-1,1]x[0,1].
            auto& projection = projectionMatrix.at(System::EnumCastUnderlying(DepthType::ZeroToOne));
            projection(0, 0) = twoInvRightDifference;
            projection(0, 1) = 0.0f;
            projection(0, 2) = 0.0f;
            projection(0, 3) = -rightSumDivideDifference;
            projection(1, 0) = 0.0f;
            projection(1, 1) = twoInvUpDifference;
            projection(1, 2) = 0.0f;
            projection(1, 3) = -upSumDivideDifference;
            projection(2, 0) = 0.0f;
            projection(2, 1) = 0.0f;
            projection(2, 2) = invDirectionDifference;
            projection(2, 3) = -directionMinMultiplyInvDirectionDifference;
            projection(3, 0) = 0.0f;
            projection(3, 1) = 0.0f;
            projection(3, 2) = 0.0f;
            projection(3, 3) = 1.0f;
        }
        else
        {
            // 映射 (x,y,z) 到 [-1,1]x[-1,1]x[-1,1].
            auto& projection = projectionMatrix.at(System::EnumCastUnderlying(DepthType::MinusOneToOne));
            projection(0, 0) = twoInvRightDifference;
            projection(0, 1) = 0.0f;
            projection(0, 2) = 0.0f;
            projection(0, 3) = -rightSumDivideDifference;
            projection(1, 0) = 0.0f;
            projection(1, 1) = twoInvUpDifference;
            projection(1, 2) = 0.0f;
            projection(1, 3) = -upSumDivideDifference;
            projection(2, 0) = 0.0f;
            projection(2, 1) = 0.0f;
            projection(2, 2) = twoInvDirectionDifference;
            projection(2, 3) = -directionSumDivideDifference;
            projection(3, 0) = 0.0f;
            projection(3, 1) = 0.0f;
            projection(3, 2) = 0.0f;
            projection(3, 3) = 1.0f;
        }
    }

    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix::UpdateProjectionViewMatrix()
{
    auto& aProjectionMatrix = projectionMatrix.at(System::EnumCastUnderlying(depthType));
    auto& aProjectionViewMatrix = projectionViewMatrix.at(System::EnumCastUnderlying(depthType));

    aProjectionViewMatrix = aProjectionMatrix * worldCoordinateFrame.GetViewMatrix();
    if (!postProjectionIsIdentity)
    {
        aProjectionViewMatrix = postProjectionMatrix * aProjectionViewMatrix;
    }
    if (!preViewIsIdentity)
    {
        aProjectionViewMatrix = aProjectionViewMatrix * preViewMatrix;
    }
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraMatrix)

Rendering::CameraMatrix::Matrix Rendering::CameraMatrix::GetProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return projectionMatrix.at(System::EnumCastUnderlying(depthType));
}

void Rendering::CameraMatrix::SetProjectionMatrix(const Matrix& aProjectionMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    projectionMatrix.at(System::EnumCastUnderlying(depthType)) = aProjectionMatrix;
    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix::SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(0.0f < nearExtrude, "nearExtrude必须大于0\n");
    RENDERING_ASSERTION_1(nearExtrude < farExtrude, "farExtrude必须大于nearExtrude\n");

    // 计算最近面的视图体积
    const auto q000 = Mathematics::APointF::GetOrigin() + nearExtrude * (p00 - Mathematics::APointF::GetOrigin());
    const auto q100 = Mathematics::APointF::GetOrigin() + nearExtrude * (p10 - Mathematics::APointF::GetOrigin());
    const auto q110 = Mathematics::APointF::GetOrigin() + nearExtrude * (p11 - Mathematics::APointF::GetOrigin());
    const auto q010 = Mathematics::APointF::GetOrigin() + nearExtrude * (p01 - Mathematics::APointF::GetOrigin());

    // 计算最远面的视图体积
    const auto q001 = Mathematics::APointF::GetOrigin() + farExtrude * (p00 - Mathematics::APointF::GetOrigin());
    const auto q101 = Mathematics::APointF::GetOrigin() + farExtrude * (p10 - Mathematics::APointF::GetOrigin());
    const auto q111 = Mathematics::APointF::GetOrigin() + farExtrude * (p11 - Mathematics::APointF::GetOrigin());
    const auto q011 = Mathematics::APointF::GetOrigin() + farExtrude * (p01 - Mathematics::APointF::GetOrigin());

    // 计算q111的表示
    const auto u0 = q100 - q000;
    const auto u1 = q010 - q000;
    const auto u2 = q001 - q000;

    const Matrix matrix{ u0, u1, u2, q000, Mathematics::MatrixMajorFlags::Column };
    const auto inverseMatrix = matrix.Inverse(epsilon);
    auto point = inverseMatrix * q111;

    // 计算分段线性变换的参数。
    //   y[i] = n[i] * x[i] / (d[0] * x[0] + d[1] * x[1] + d[2] * x[2] + d[3])
    const auto twoPoint0 = 2.0f * point[0];
    const auto twoPoint1 = 2.0f * point[1];
    const auto twoPoint2 = 2.0f * point[2];
    auto d0 = +point[0] - point[1] - point[2] + 1.0f;
    auto d1 = -point[0] + point[1] - point[2] + 1.0f;
    auto d2 = -point[0] - point[1] + point[2] + 1.0f;
    auto d3 = +point[0] + point[1] + point[2] - 1.0f;

    // 计算透视投影从规范化长方体到规范化立方体[-1,1]^2 x [0,1]
    auto twoPoint2divide0 = twoPoint2 / twoPoint0;
    auto twoPoint2divide1 = twoPoint2 / twoPoint1;

    Matrix project{};
    project(0, 0) = twoPoint2divide0 * (2.0f * d3 + d0);
    project(0, 1) = twoPoint2divide1 * d1;
    project(0, 2) = d2;
    project(0, 3) = -twoPoint2;
    project(1, 0) = twoPoint2divide0 * d0;
    project(1, 1) = twoPoint2divide1 * (2.0f * d3 + d1);
    project(1, 2) = d2;
    project(1, 3) = -twoPoint2;

    if (depthType == DepthType::ZeroToOne)
    {
        project(2, 0) = 0.0f;
        project(2, 1) = 0.0f;
        project(2, 2) = d3;
        project(2, 3) = 0.0f;
    }
    else
    {
        project(2, 0) = twoPoint2divide0 * d0;
        project(2, 1) = twoPoint2divide1 * d1;
        project(2, 2) = 2.0f * d3 + d2;
        project(2, 3) = -twoPoint2;
    }

    project(3, 0) = -twoPoint2divide0 * d0;
    project(3, 1) = -twoPoint2divide1 * d1;
    project(3, 2) = -d2;
    project(3, 3) = twoPoint2;

    // 需要映射挤压四边形投影视图体积到规范的长方体，
    // 然后后面跟着透视投影到规范化立方体。
    SetProjectionMatrix(project * inverseMatrix);
}

Rendering::DepthType Rendering::CameraMatrix::GetDepthType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthType;
}

Rendering::CameraMatrix::Matrix Rendering::CameraMatrix::GetProjectionViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return projectionViewMatrix.at(System::EnumCastUnderlying(depthType));
}

void Rendering::CameraMatrix::SetPreViewMatrix(const Matrix& aPreViewMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    preViewMatrix = aPreViewMatrix;
    preViewIsIdentity = Approximate(preViewMatrix, Mathematics::MatrixF::GetIdentityMatrix(), epsilon);

    UpdateProjectionViewMatrix();
}

Rendering::CameraMatrix::Matrix Rendering::CameraMatrix::GetPreViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return preViewMatrix;
}

bool Rendering::CameraMatrix::PreViewIsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return preViewIsIdentity;
}

void Rendering::CameraMatrix::SetPostProjectionMatrix(const Matrix& postProjMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    postProjectionMatrix = postProjMatrix;
    postProjectionIsIdentity = Approximate(postProjectionMatrix, Mathematics::MatrixF::GetIdentityMatrix(), epsilon);

    UpdateProjectionViewMatrix();
}

Rendering::CameraMatrix::Matrix Rendering::CameraMatrix::GetPostProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return postProjectionMatrix;
}

bool Rendering::CameraMatrix::PostProjectionIsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return postProjectionIsIdentity;
}

void Rendering::CameraMatrix::OnFrustumChange(const CameraFrustum& aCameraFrustum)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraFrustum = aCameraFrustum;

    OnFrustumChange();
}

const Rendering::CameraFrustum& Rendering::CameraMatrix::GetCameraFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return cameraFrustum;
}

const Rendering::WorldCoordinateFrame& Rendering::CameraMatrix::GetWorldCoordinateFrame() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldCoordinateFrame;
}

void Rendering::CameraMatrix::SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;

    worldCoordinateFrame.SetFrame(position, directionVector, upVector, rightVector);
    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix::SetPosition(const APoint& position)
{
    RENDERING_CLASS_IS_VALID_9;

    worldCoordinateFrame.SetPosition(position);
    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix::SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;

    worldCoordinateFrame.SetAxes(directionVector, upVector, rightVector);
    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    worldCoordinateFrame.Load(source);
    cameraFrustum.Load(source);

    source.ReadAggregate(preViewMatrix);
    preViewIsIdentity = source.ReadBool();
    source.ReadAggregate(postProjectionMatrix);
    postProjectionIsIdentity = source.ReadBool();
    source.Read(epsilon);

    // 计算m_ProjectionMatrix[].
    OnFrustumChange();
}

void Rendering::CameraMatrix::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    worldCoordinateFrame.Save(target);
    cameraFrustum.Save(target);

    target.WriteAggregate(preViewMatrix);
    target.Write(preViewIsIdentity);
    target.WriteAggregate(postProjectionMatrix);
    target.Write(postProjectionIsIdentity);

    target.Write(epsilon);

    // 这里不保存m_ProjectionMatrix[]和m_ProjectionViewMatrix[]。
}

int Rendering::CameraMatrix::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = worldCoordinateFrame.GetStreamingSize();

    size += cameraFrustum.GetStreamingSize();

    size += Mathematics::GetStreamSize(preViewMatrix);
    size += CoreTools::GetStreamSize(preViewIsIdentity);
    size += Mathematics::GetStreamSize(postProjectionMatrix);
    size += CoreTools::GetStreamSize(postProjectionIsIdentity);

    size += CoreTools::GetStreamSize(epsilon);

    return size;
}

float Rendering::CameraMatrix::GetEpsilon() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return epsilon;
}

void Rendering::CameraMatrix::SetDepthType(DepthType aDepthType)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    depthType = aDepthType;

    // 设置m_DepthType并更新投影矩阵,投影矩阵取决于深度类型。
    // 因为我们已经改变了深度类型,我们需要再次更新投影矩阵。
    OnFrustumChange();
}
