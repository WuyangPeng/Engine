///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.1 (2023/11/21 18:11)

#include "Rendering/RenderingExport.h"

#include "ViewVolume.h"
#include "Detail/ViewVolumeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ViewVolume);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ViewVolume);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, ViewVolume);
CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, ViewVolume);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ViewVolume)

Rendering::ViewVolume::ViewVolume(bool isPerspective, DepthType depthType, float epsilon)
    : ParentType{ "ViewVolume" }, impl{ isPerspective, depthType, epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ViewVolume)

void Rendering::ViewVolume::SetPosition(const APoint& position)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetPosition(position);
}

void Rendering::ViewVolume::SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAxes(directionVector, upVector, rightVector);
}

void Rendering::ViewVolume::SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetFrame(position, directionVector, upVector, rightVector);
}

Rendering::ViewVolume::APoint Rendering::ViewVolume::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPosition();
}

Rendering::ViewVolume::AVector Rendering::ViewVolume::GetDirectionVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDirectionVector();
}

Rendering::ViewVolume::AVector Rendering::ViewVolume::GetUpVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetUpVector();
}

Rendering::ViewVolume::AVector Rendering::ViewVolume::GetRightVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRightVector();
}

Rendering::ViewVolume::Matrix Rendering::ViewVolume::GetViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetViewMatrix();
}

Rendering::ViewVolume::Matrix Rendering::ViewVolume::GetInverseViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetInverseViewMatrix();
}

Rendering::ViewVolume::Matrix Rendering::ViewVolume::GetProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectionMatrix();
}

void Rendering::ViewVolume::SetProjectionMatrix(const Matrix& projectionMatrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetProjectionMatrix(projectionMatrix);
}

Rendering::ViewVolume::Matrix Rendering::ViewVolume::GetProjectionViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectionViewMatrix();
}

void Rendering::ViewVolume::SetProjectionViewMatrix(const Matrix& projectionMatrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetProjectionViewMatrix(projectionMatrix);
}

Rendering::DepthType Rendering::ViewVolume::GetDepthType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDepthType();
}

bool Rendering::ViewVolume::IsPerspective() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsPerspective();
}

void Rendering::ViewVolume::SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);
    UpdateProjectionViewMatrix();
}

void Rendering::ViewVolume::SetFrustum(const Container& frustum)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetFrustum(frustum);
    UpdateProjectionViewMatrix();
}

void Rendering::ViewVolume::SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);
    UpdateProjectionViewMatrix();
}

Rendering::ViewVolume::Container Rendering::ViewVolume::GetFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFrustum();
}

Rendering::CameraFrustumData Rendering::ViewVolume::GetSymmetricFrustum() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetSymmetricFrustum();
}

float Rendering::ViewVolume::GetDirectionMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDirectionMin();
}

float Rendering::ViewVolume::GetDirectionMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDirectionMax();
}

float Rendering::ViewVolume::GetUpMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetUpMin();
}

float Rendering::ViewVolume::GetUpMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetUpMax();
}

float Rendering::ViewVolume::GetRightMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRightMin();
}

float Rendering::ViewVolume::GetRightMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRightMax();
}

void Rendering::ViewVolume::UpdateProjectionViewMatrix() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->UpdateProjectionViewMatrix();
}
