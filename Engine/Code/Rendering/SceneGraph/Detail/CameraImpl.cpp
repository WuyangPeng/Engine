/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 11:14)

#include "Rendering/RenderingExport.h"

#include "CameraImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::CameraImpl::CameraImpl(float epsilon) noexcept
    : cameraMatrix{ epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraImpl)

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

Rendering::CameraImpl::Matrix Rendering::CameraImpl::GetProjectionViewMatrix(const Matrix& projectionViewMatrix) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetProjectionViewMatrix(projectionViewMatrix);
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

    return cameraMatrix.GetStreamingSize();
}

float Rendering::CameraImpl::GetEpsilon() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraMatrix.GetEpsilon();
}
