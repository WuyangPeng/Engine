/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:50)

#include "Rendering/RenderingExport.h"

#include "ProjectionMatrix.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

Rendering::ProjectionMatrix::ProjectionMatrix(DepthType depthType) noexcept
    : projectionMatrix{},
      projectionViewMatrix{},
      depthType{ depthType }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProjectionMatrix)

Rendering::ProjectionMatrix::Matrix Rendering::ProjectionMatrix::GetProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return projectionMatrix;
}

Rendering::ProjectionMatrix::Matrix Rendering::ProjectionMatrix::GetProjectionViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return projectionViewMatrix;
}

void Rendering::ProjectionMatrix::SetProjectionMatrix(const Matrix& aProjectionMatrix, const Matrix& viewMatrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    projectionMatrix = aProjectionMatrix;
    UpdateProjectionViewMatrix(viewMatrix);
}

void Rendering::ProjectionMatrix::SetProjectionViewMatrix(const Matrix& aProjectionViewMatrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    projectionViewMatrix = aProjectionViewMatrix;
}

Rendering::DepthType Rendering::ProjectionMatrix::GetDepthType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthType;
}

void Rendering::ProjectionMatrix::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadAggregate(projectionMatrix);
    source.ReadAggregate(projectionViewMatrix);
    source.ReadEnum(depthType);
}

void Rendering::ProjectionMatrix::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteAggregate(projectionMatrix);
    target.WriteAggregate(projectionViewMatrix);
    target.WriteEnum(depthType);
}

int Rendering::ProjectionMatrix::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = GetStreamSize(projectionMatrix);

    size += GetStreamSize(projectionViewMatrix);

    size += Mathematics::GetStreamSize(depthType);

    return size;
}

void Rendering::ProjectionMatrix::UpdateProjectionViewMatrix(const Matrix& viewMatrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    projectionViewMatrix = projectionMatrix * viewMatrix;

#else

    projectionViewMatrix = viewMatrix * projectionMatrix;

#endif
}
