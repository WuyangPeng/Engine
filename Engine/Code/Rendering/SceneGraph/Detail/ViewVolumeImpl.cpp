/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:52)

#include "Rendering/RenderingExport.h"

#include "ViewVolumeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ViewVolumeImpl::ViewVolumeImpl() noexcept
    : worldCoordinateFrame{}, projectionMatrix{ DepthType::Quantity }, cameraFrustum{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ViewVolumeImpl::ViewVolumeImpl(bool isPerspective, DepthType depthType, float epsilon)
    : worldCoordinateFrame{ epsilon }, projectionMatrix{ depthType }, cameraFrustum{ isPerspective, epsilon }
{
    OnFrustumChange();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ViewVolumeImpl)

void Rendering::ViewVolumeImpl::SetPosition(const APoint& position)
{
    RENDERING_CLASS_IS_VALID_9;

    worldCoordinateFrame.SetPosition(position);
    UpdateProjectionViewMatrix();
}

void Rendering::ViewVolumeImpl::SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;

    worldCoordinateFrame.SetAxes(directionVector, upVector, rightVector);
    UpdateProjectionViewMatrix();
}

void Rendering::ViewVolumeImpl::SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;

    worldCoordinateFrame.SetFrame(position, directionVector, upVector, rightVector);
    UpdateProjectionViewMatrix();
}

void Rendering::ViewVolumeImpl::UpdateProjectionViewMatrix() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    projectionMatrix.UpdateProjectionViewMatrix(worldCoordinateFrame.GetViewMatrix());
}

void Rendering::ViewVolumeImpl::OnFrustumChange()
{
    RENDERING_CLASS_IS_VALID_9;

    // ZeroToOne:  映射 (x,y,z) 到 [-1,1]x[-1,1]x[0,1].
    // MinusOneToOne: 映射 (x,y,z) 到 [-1,1]x[-1,1]x[-1,1].
    const auto directionMin = cameraFrustum.GetDirectionMin();
    const auto directionMax = cameraFrustum.GetDirectionMax();
    const auto upMin = cameraFrustum.GetUpMin();
    const auto upMax = cameraFrustum.GetUpMax();
    const auto rightMin = cameraFrustum.GetRightMin();
    const auto rightMax = cameraFrustum.GetRightMax();
    const auto invDirectionDiff = 1.0f / (directionMax - directionMin);
    const auto invUpDiff = 1.0f / (upMax - upMin);
    const auto invRightDiff = 1.0f / (rightMax - rightMin);

    Matrix result{};

    if (IsPerspective())
    {
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

        if (GetDepthType() == DepthType::ZeroToOne)
        {
            result(0, 0) = 2.0f * directionMin * invRightDiff;
            result(0, 1) = 0.0f;
            result(0, 2) = -(rightMin + rightMax) * invRightDiff;
            result(0, 3) = 0.0f;
            result(1, 0) = 0.0f;
            result(1, 1) = 2.0f * directionMin * invUpDiff;
            result(1, 2) = -(upMin + upMax) * invUpDiff;
            result(1, 3) = 0.0f;
            result(2, 0) = 0.0f;
            result(2, 1) = 0.0f;
            result(2, 2) = directionMax * invDirectionDiff;
            result(2, 3) = -directionMin * directionMax * invDirectionDiff;
            result(3, 0) = 0.0f;
            result(3, 1) = 0.0f;
            result(3, 2) = 1.0f;
            result(3, 3) = 0.0f;
        }
        else
        {
            result(0, 0) = 2.0f * directionMin * invRightDiff;
            result(0, 1) = 0.0f;
            result(0, 2) = -(rightMin + rightMax) * invRightDiff;
            result(0, 3) = 0.0f;
            result(1, 0) = 0.0f;
            result(1, 1) = 2.0f * directionMin * invUpDiff;
            result(1, 2) = -(upMin + upMax) * invUpDiff;
            result(1, 3) = 0.0f;
            result(2, 0) = 0.0f;
            result(2, 1) = 0.0f;
            result(2, 2) = (directionMin + directionMax) * invDirectionDiff;
            result(2, 3) = -2.0f * directionMin * directionMax * invDirectionDiff;
            result(3, 0) = 0.0f;
            result(3, 1) = 0.0f;
            result(3, 2) = 1.0f;
            result(3, 3) = 0.0f;
        }

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

        if (GetDepthType() == DepthType::ZeroToOne)
        {
            result(0, 0) = 2.0f * directionMin * invRightDiff;
            result(1, 0) = 0.0f;
            result(2, 0) = -(rightMin + rightMax) * invRightDiff;
            result(3, 0) = 0.0f;
            result(0, 1) = 0.0f;
            result(1, 1) = 2.0f * directionMin * invUpDiff;
            result(2, 1) = -(upMin + upMax) * invUpDiff;
            result(3, 1) = 0.0f;
            result(0, 2) = 0.0f;
            result(1, 2) = 0.0f;
            result(2, 2) = directionMax * invDirectionDiff;
            result(3, 2) = -directionMin * directionMax * invDirectionDiff;
            result(0, 3) = 0.0f;
            result(1, 3) = 0.0f;
            result(2, 3) = 1.0f;
            result(3, 3) = 0.0f;
        }
        else
        {
            result(0, 0) = 2.0f * directionMin * invRightDiff;
            result(1, 0) = 0.0f;
            result(2, 0) = -(rightMin + rightMax) * invRightDiff;
            result(3, 0) = 0.0f;
            result(0, 1) = 0.0f;
            result(1, 1) = 2.0f * directionMin * invUpDiff;
            result(2, 1) = -(upMin + upMax) * invUpDiff;
            result(3, 1) = 0.0f;
            result(0, 2) = 0.0f;
            result(1, 2) = 0.0f;
            result(2, 2) = (directionMin + directionMax) * invDirectionDiff;
            result(3, 2) = -2.0f * directionMin * directionMax * invDirectionDiff;
            result(0, 3) = 0.0f;
            result(1, 3) = 0.0f;
            result(2, 3) = 1.0f;
            result(3, 3) = 0.0f;
        }

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
    }
    else
    {
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

        if (GetDepthType() == DepthType::ZeroToOne)
        {
            result(0, 0) = 2.0f * invRightDiff;
            result(0, 1) = 0.0f;
            result(0, 2) = 0.0f;
            result(0, 3) = -(rightMin + rightMax) * invRightDiff;
            result(1, 0) = 0.0f;
            result(1, 1) = 2.0f * invUpDiff;
            result(1, 2) = 0.0f;
            result(1, 3) = -(upMin + upMax) * invUpDiff;
            result(2, 0) = 0.0f;
            result(2, 1) = 0.0f;
            result(2, 2) = invDirectionDiff;
            result(2, 3) = -directionMin * invDirectionDiff;
            result(3, 0) = 0.0f;
            result(3, 1) = 0.0f;
            result(3, 2) = 0.0f;
            result(3, 3) = 1.0f;
        }
        else
        {
            result(0, 0) = 2.0f * invRightDiff;
            result(0, 1) = 0.0f;
            result(0, 2) = 0.0f;
            result(0, 3) = -(rightMin + rightMax) * invRightDiff;
            result(1, 0) = 0.0f;
            result(1, 1) = 2.0f * invUpDiff;
            result(1, 2) = 0.0f;
            result(1, 3) = -(upMin + upMax) * invUpDiff;
            result(2, 0) = 0.0f;
            result(2, 1) = 0.0f;
            result(2, 2) = 2.0f * invDirectionDiff;
            result(2, 3) = -(directionMin + directionMax) * invDirectionDiff;
            result(3, 0) = 0.0f;
            result(3, 1) = 0.0f;
            result(3, 2) = 0.0f;
            result(3, 3) = 1.0f;
        }

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

        if (GetDepthType() == DepthType::ZeroToOne)
        {
            result(0, 0) = 2.0f * invRightDiff;
            result(1, 0) = 0.0f;
            result(2, 0) = 0.0f;
            result(3, 0) = -(rightMin + rightMax) * invRightDiff;
            result(0, 1) = 0.0f;
            result(1, 1) = 2.0f * invUpDiff;
            result(2, 1) = 0.0f;
            result(3, 1) = -(upMin + upMax) * invUpDiff;
            result(0, 2) = 0.0f;
            result(1, 2) = 0.0f;
            result(2, 2) = invDirectionDiff;
            result(3, 2) = -directionMin * invDirectionDiff;
            result(0, 3) = 0.0f;
            result(1, 3) = 0.0f;
            result(2, 3) = 0.0f;
            result(3, 3) = 1.0f;
        }
        else
        {
            result(0, 0) = 2.0f * invRightDiff;
            result(1, 0) = 0.0f;
            result(2, 0) = 0.0f;
            result(3, 0) = -(rightMin + rightMax) * invRightDiff;
            result(0, 1) = 0.0f;
            result(1, 1) = 2.0f * invUpDiff;
            result(2, 1) = 0.0f;
            result(3, 1) = -(upMin + upMax) * invUpDiff;
            result(0, 2) = 0.0f;
            result(1, 2) = 0.0f;
            result(2, 2) = invDirectionDiff;
            result(3, 2) = -(directionMin + directionMax) * invDirectionDiff;
            result(0, 3) = 0.0f;
            result(1, 3) = 0.0f;
            result(2, 3) = 0.0f;
            result(3, 3) = 1.0f;
        }

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
    }

    projectionMatrix.SetProjectionMatrix(result, worldCoordinateFrame.GetViewMatrix());
}

Rendering::ViewVolumeImpl::APoint Rendering::ViewVolumeImpl::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldCoordinateFrame.GetPosition();
}

Rendering::ViewVolumeImpl::AVector Rendering::ViewVolumeImpl::GetDirectionVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldCoordinateFrame.GetDirectionVector();
}

Rendering::ViewVolumeImpl::AVector Rendering::ViewVolumeImpl::GetUpVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldCoordinateFrame.GetUpVector();
}

Rendering::ViewVolumeImpl::AVector Rendering::ViewVolumeImpl::GetRightVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldCoordinateFrame.GetRightVector();
}

Rendering::ViewVolumeImpl::Matrix Rendering::ViewVolumeImpl::GetViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldCoordinateFrame.GetViewMatrix();
}

Rendering::ViewVolumeImpl::Matrix Rendering::ViewVolumeImpl::GetInverseViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldCoordinateFrame.GetInverseViewMatrix();
}

Rendering::ViewVolumeImpl::Matrix Rendering::ViewVolumeImpl::GetProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return projectionMatrix.GetProjectionMatrix();
}

void Rendering::ViewVolumeImpl::SetProjectionMatrix(const Matrix& aProjectionMatrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    projectionMatrix.SetProjectionMatrix(aProjectionMatrix, worldCoordinateFrame.GetViewMatrix());
}

Rendering::ViewVolumeImpl::Matrix Rendering::ViewVolumeImpl::GetProjectionViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return projectionMatrix.GetProjectionViewMatrix();
}

void Rendering::ViewVolumeImpl::SetProjectionViewMatrix(const Matrix& aProjectionMatrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    projectionMatrix.SetProjectionViewMatrix(aProjectionMatrix);
}

Rendering::DepthType Rendering::ViewVolumeImpl::GetDepthType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return projectionMatrix.GetDepthType();
}

bool Rendering::ViewVolumeImpl::IsPerspective() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraFrustum.IsPerspective();
}

void Rendering::ViewVolumeImpl::SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraFrustum.SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);
    OnFrustumChange();
}

void Rendering::ViewVolumeImpl::SetFrustum(const Container& frustum)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraFrustum.SetFrustum(frustum);
    OnFrustumChange();
}

void Rendering::ViewVolumeImpl::SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax)
{
    RENDERING_CLASS_IS_VALID_9;

    cameraFrustum.SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);
    OnFrustumChange();
}

Rendering::ViewVolumeImpl::Container Rendering::ViewVolumeImpl::GetFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraFrustum.GetFrustum();
}

Rendering::CameraFrustumData Rendering::ViewVolumeImpl::GetSymmetricFrustum() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraFrustum.GetSymmetricFrustum();
}

float Rendering::ViewVolumeImpl::GetDirectionMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraFrustum.GetDirectionMin();
}

float Rendering::ViewVolumeImpl::GetDirectionMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraFrustum.GetDirectionMax();
}

float Rendering::ViewVolumeImpl::GetUpMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraFrustum.GetUpMin();
}

float Rendering::ViewVolumeImpl::GetUpMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraFrustum.GetUpMax();
}

float Rendering::ViewVolumeImpl::GetRightMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraFrustum.GetRightMin();
}

float Rendering::ViewVolumeImpl::GetRightMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraFrustum.GetRightMax();
}

void Rendering::ViewVolumeImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    worldCoordinateFrame.Load(source);
    projectionMatrix.Load(source);
    cameraFrustum.Load(source);

    UpdateProjectionViewMatrix();
}

void Rendering::ViewVolumeImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    worldCoordinateFrame.Save(target);
    projectionMatrix.Save(target);
    cameraFrustum.Save(target);
}

int Rendering::ViewVolumeImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldCoordinateFrame.GetStreamingSize() + projectionMatrix.GetStreamingSize() + cameraFrustum.GetStreamingSize();
}
