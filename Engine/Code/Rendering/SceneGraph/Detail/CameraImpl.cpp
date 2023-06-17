///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:12)

#include "Rendering/RenderingExport.h"

#include "CameraFrustum.h"
#include "CameraImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"

Rendering::CameraImpl::CameraImpl(bool isPerspective, float epsilon)
    : cameraMatrix{ WorldCoordinateFrame{ epsilon }, CameraFrustum{ isPerspective }, epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CameraImpl::CameraImpl(float epsilon)
    : cameraMatrix{ epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraImpl)

void Rendering::CameraImpl::SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraMatrix.SetFrame(position, directionVector, upVector, rightVector);
}

void Rendering::CameraImpl::SetPosition(const APoint& position)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraMatrix.SetPosition(position);
}

void Rendering::CameraImpl::SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraMatrix.SetAxes(directionVector, upVector, rightVector);
}

Rendering::CameraImpl::APoint Rendering::CameraImpl::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetWorldCoordinateFrame().GetPosition();
}

Rendering::CameraImpl::AVector Rendering::CameraImpl::GetDirectionVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetWorldCoordinateFrame().GetDirectionVector();
}

Rendering::CameraImpl::AVector Rendering::CameraImpl::GetUpVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetWorldCoordinateFrame().GetUpVector();
}

Rendering::CameraImpl::AVector Rendering::CameraImpl::GetRightVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetWorldCoordinateFrame().GetRightVector();
}

Rendering::CameraImpl::Matrix Rendering::CameraImpl::GetViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetWorldCoordinateFrame().GetViewMatrix();
}

bool Rendering::CameraImpl::IsPerspective() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetCameraFrustum().IsPerspective();
}

void Rendering::CameraImpl::SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax)
{
    RENDERING_CLASS_IS_VALID_9;

    CameraFrustum cameraFrustum{ IsPerspective() };

    cameraFrustum.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);

    cameraMatrix.OnFrustumChange(cameraFrustum);
}

void Rendering::CameraImpl::SetFrustum(const float* frustum)
{
    RENDERING_CLASS_IS_VALID_9;

    if (frustum != nullptr)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        SetFrustum(frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)],
                   frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMax)],
                   frustum[System::EnumCastUnderlying(ViewFrustum::UpMin)],
                   frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)],
                   frustum[System::EnumCastUnderlying(ViewFrustum::RightMin)],
                   frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)]);

#include STSTEM_WARNING_POP
    }
}

void Rendering::CameraImpl::SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax)
{
    RENDERING_CLASS_IS_VALID_9;

    CameraFrustum cameraFrustum{ IsPerspective() };

    cameraFrustum.SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

    cameraMatrix.OnFrustumChange(cameraFrustum);
}

const float* Rendering::CameraImpl::GetFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetCameraFrustum().GetFrustum();
}

Rendering::CameraFrustumData Rendering::CameraImpl::GetFrustumData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetCameraFrustum().GetFrustumData();
}

float Rendering::CameraImpl::GetDirectionMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetCameraFrustum().GetDirectionMin();
}

float Rendering::CameraImpl::GetDirectionMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetCameraFrustum().GetDirectionMax();
}

float Rendering::CameraImpl::GetUpMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetCameraFrustum().GetUpMin();
}

float Rendering::CameraImpl::GetUpMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetCameraFrustum().GetUpMax();
}

float Rendering::CameraImpl::GetRightMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetCameraFrustum().GetRightMin();
}

float Rendering::CameraImpl::GetRightMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetCameraFrustum().GetRightMax();
}

Rendering::CameraImpl::Matrix Rendering::CameraImpl::GetProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetProjectionMatrix();
}

void Rendering::CameraImpl::SetProjectionMatrix(const Matrix& projectionMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraMatrix.SetProjectionMatrix(projectionMatrix);
}

void Rendering::CameraImpl::SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraMatrix.SetProjectionMatrix(p00, p10, p11, p01, nearExtrude, farExtrude);
}

Rendering::DepthType Rendering::CameraImpl::GetDepthType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetDepthType();
}

Rendering::CameraImpl::Matrix Rendering::CameraImpl::GetProjectionViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetProjectionViewMatrix();
}

void Rendering::CameraImpl::SetPreViewMatrix(const Matrix& preViewMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraMatrix.SetPreViewMatrix(preViewMatrix);
}

Rendering::CameraImpl::Matrix Rendering::CameraImpl::GetPreViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetPreViewMatrix();
}

bool Rendering::CameraImpl::PreViewIsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.PreViewIsIdentity();
}

void Rendering::CameraImpl::SetPostProjectionMatrix(const Matrix& postProjMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraMatrix.SetPostProjectionMatrix(postProjMatrix);
}

Rendering::CameraImpl::Matrix Rendering::CameraImpl::GetPostProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetPostProjectionMatrix();
}

bool Rendering::CameraImpl::PostProjectionIsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.PostProjectionIsIdentity();
}

Rendering::CameraImpl::AxesAlignBoundingBox2D Rendering::CameraImpl::ComputeBoundingAABB(int numVertices, const char* vertices, int stride, const Matrix& worldMatrix) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    // 计算当前世界投影视图矩阵。
    auto viewProjectionMatrix = GetProjectionMatrix() * GetViewMatrix();
    if (!PostProjectionIsIdentity())
    {
        viewProjectionMatrix = GetPostProjectionMatrix() * viewProjectionMatrix;
    }
    const auto worldViewProjectionMatrix = viewProjectionMatrix * worldMatrix;

    // 计算正则化的包围盒矩形显示坐标。
    auto xmin = Mathematics::MathF::maxReal;
    auto xmax = -Mathematics::MathF::maxReal;
    auto ymin = Mathematics::MathF::maxReal;
    auto ymax = -Mathematics::MathF::maxReal;
    for (auto i = 0; i < numVertices; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26490)

        auto vertex = reinterpret_cast<const float*>(vertices);

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        const HomogeneousPoint position{ vertex[0], vertex[1], vertex[2], 1.0f };

#include STSTEM_WARNING_POP

        auto homogeneousPosition = worldViewProjectionMatrix * position;
        const auto invW = 1.0f / homogeneousPosition[3];
        auto xNormalizeDeviceCoordinate = homogeneousPosition[0] * invW;
        auto yNormalizeDeviceCoordinate = homogeneousPosition[1] * invW;
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        vertices += stride;

#include STSTEM_WARNING_POP
    }

    return AxesAlignBoundingBox2D{ xmin, xmax, ymin, ymax };
}

void Rendering::CameraImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraMatrix.Load(source);
}

void Rendering::CameraImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    cameraMatrix.Save(target);
}

int Rendering::CameraImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto size = cameraMatrix.GetStreamingSize();

    return size;
}

float Rendering::CameraImpl::GetEpsilon() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetEpsilon();
}

void Rendering::CameraImpl::SetDepthType(DepthType depthType)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    cameraMatrix.SetDepthType(depthType);
}
