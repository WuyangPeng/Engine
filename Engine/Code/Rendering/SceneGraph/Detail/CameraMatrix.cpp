/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 11:12)

#include "Rendering/RenderingExport.h"

#include "CameraMatrix.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::CameraMatrix::CameraMatrix(float epsilon) noexcept
    : preViewMatrix{ Mathematics::MatrixF::GetIdentityMatrix() },
      preViewIsIdentity{ true },
      postProjectionMatrix{ Mathematics::MatrixF::GetIdentityMatrix() },
      postProjectionIsIdentity{ true },
      epsilon{ epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraMatrix)

void Rendering::CameraMatrix::SetPreViewMatrix(const Matrix& aPreViewMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    preViewMatrix = aPreViewMatrix;
    preViewIsIdentity = Approximate(preViewMatrix, Mathematics::MatrixF::GetIdentityMatrix(), epsilon);
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

void Rendering::CameraMatrix::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadAggregate(preViewMatrix);
    source.ReadAggregate(postProjectionMatrix);
    source.Read(epsilon);

    preViewIsIdentity = Approximate(preViewMatrix, Mathematics::MatrixF::GetIdentityMatrix(), epsilon);
    postProjectionIsIdentity = Approximate(postProjectionMatrix, Mathematics::MatrixF::GetIdentityMatrix(), epsilon);
}

void Rendering::CameraMatrix::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteAggregate(preViewMatrix);
    target.WriteAggregate(postProjectionMatrix);

    target.Write(epsilon);
}

int Rendering::CameraMatrix::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = Mathematics::GetStreamSize(preViewMatrix);
    size += Mathematics::GetStreamSize(postProjectionMatrix);
    size += CoreTools::GetStreamSize(epsilon);

    return size;
}

Rendering::CameraMatrix::Matrix Rendering::CameraMatrix::GetProjectionViewMatrix(const Matrix& matrix) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto result = matrix;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    if (!postProjectionIsIdentity)
    {
        result = postProjectionMatrix * result;
    }

    if (!preViewIsIdentity)
    {
        result = result * preViewMatrix;
    }

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

    if (!postProjectionIsIdentity)
    {
        result = result * postProjectionMatrix;
    }

    if (!preViewIsIdentity)
    {
        result = preViewMatrix * result;
    }

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return result;
}

float Rendering::CameraMatrix::GetEpsilon() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return epsilon;
}
