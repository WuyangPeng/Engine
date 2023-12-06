/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/21 13:51)

#include "Rendering/RenderingExport.h"

#include "WorldCoordinateFrame.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalizeDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

Rendering::WorldCoordinateFrame::WorldCoordinateFrame() noexcept
    : position{},
      directionVector{ -Mathematics::AVectorF::GetUnitZ() },
      upVector{ Mathematics::AVectorF::GetUnitY() },
      rightVector{ Mathematics::AVectorF::GetUnitX() },
      viewMatrix{},
      inverseViewMatrix{},

#ifdef RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

      validateCoordinateFrame{ true },

#endif  // RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

      epsilon{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::WorldCoordinateFrame::WorldCoordinateFrame(float epsilon)
    : position{ Mathematics::APointF::GetOrigin() },
      directionVector{ -Mathematics::AVectorF::GetUnitZ() },
      upVector{ Mathematics::AVectorF::GetUnitY() },
      rightVector{ Mathematics::AVectorF::GetUnitX() },
      viewMatrix{ Mathematics::MatrixF::GetZeroMatrix() },
      inverseViewMatrix{ Mathematics::MatrixF::GetZeroMatrix() },

#ifdef RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

      validateCoordinateFrame{ true },

#endif  // RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

      epsilon{ epsilon }
{
    OnFrameChange();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::WorldCoordinateFrame::IsValid() const noexcept
{
    try
    {
        if (directionVector.IsNormalize(epsilon) &&
            upVector.IsNormalize(epsilon) &&
            rightVector.IsNormalize(epsilon) &&
            Math::FAbs(Dot(directionVector, upVector)) <= epsilon &&
            Math::FAbs(Dot(upVector, rightVector)) <= epsilon &&
            Math::FAbs(Dot(rightVector, directionVector)) <= epsilon)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::WorldCoordinateFrame::SetFrame(const APoint& aPosition, const AVector& aDirectionVector, const AVector& aUpVector, const AVector& aRightVector)
{
    RENDERING_CLASS_IS_VALID_1;

    position = aPosition;

    SetAxes(aDirectionVector, aUpVector, aRightVector);
}

void Rendering::WorldCoordinateFrame::SetPosition(const APoint& aPosition)
{
    RENDERING_CLASS_IS_VALID_1;

    position = aPosition;

    OnFrameChange();
}

void Rendering::WorldCoordinateFrame::SetAxes(const AVector& aDirectionVector, const AVector& aUpVector, const AVector& aRightVector)
{
    RENDERING_CLASS_IS_VALID_1;

    directionVector = aDirectionVector;
    upVector = aUpVector;
    rightVector = aRightVector;

    if (const auto det = Dot(directionVector, Cross(upVector, rightVector));
        epsilon < Mathematics::MathF::FAbs(1.0f - Mathematics::MathF::FAbs(det)))
    {
#ifdef RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

        if (validateCoordinateFrame)
        {
            validateCoordinateFrame = false;

            const auto directionLength = directionVector.Length();
            const auto upLength = upVector.Length();
            const auto rightLength = rightVector.Length();
            const auto dotDirectionUp = Dot(directionVector, upVector);
            const auto dotDpRight = Dot(upVector, rightVector);
            const auto dotUpRight = Dot(upVector, rightVector);
            if (epsilon < Mathematics::MathF::FAbs(1.0f - directionLength) ||
                epsilon < Mathematics::MathF::FAbs(1.0f - upLength) ||
                epsilon < Mathematics::MathF::FAbs(1.0f - rightLength) ||
                epsilon < Mathematics::MathF::FAbs(dotDirectionUp) ||
                epsilon < Mathematics::MathF::FAbs(dotDpRight) ||
                epsilon < Mathematics::MathF::FAbs(dotUpRight))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("坐标系不是正交的！"));
            }
        }

#endif  // RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

        // 输入向量并没有形成一个标准正交集合。这里重新正交化
        const auto orthonormalize = Orthonormalize(directionVector, upVector, rightVector, epsilon);

        directionVector = orthonormalize.GetUVector();
        upVector = orthonormalize.GetVVector();
        rightVector = orthonormalize.GetWVector();
    }

    OnFrameChange();
}

Rendering::WorldCoordinateFrame::APoint Rendering::WorldCoordinateFrame::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return position;
}

Rendering::WorldCoordinateFrame::AVector Rendering::WorldCoordinateFrame::GetDirectionVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return directionVector;
}

Rendering::WorldCoordinateFrame::AVector Rendering::WorldCoordinateFrame::GetUpVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return upVector;
}

Rendering::WorldCoordinateFrame::AVector Rendering::WorldCoordinateFrame::GetRightVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rightVector;
}

Rendering::WorldCoordinateFrame::Matrix Rendering::WorldCoordinateFrame::GetViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return viewMatrix;
}

Rendering::WorldCoordinateFrame::Matrix Rendering::WorldCoordinateFrame::GetInverseViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return inverseViewMatrix;
}

void Rendering::WorldCoordinateFrame::OnFrameChange()
{
#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    viewMatrix(0, 0) = rightVector[0];
    viewMatrix(0, 1) = rightVector[1];
    viewMatrix(0, 2) = rightVector[2];
    viewMatrix(0, 3) = -Dot(position, rightVector);
    viewMatrix(1, 0) = upVector[0];
    viewMatrix(1, 1) = upVector[1];
    viewMatrix(1, 2) = upVector[2];
    viewMatrix(1, 3) = -Dot(position, upVector);
    viewMatrix(2, 0) = directionVector[0];
    viewMatrix(2, 1) = directionVector[1];
    viewMatrix(2, 2) = directionVector[2];
    viewMatrix(2, 3) = -Dot(position, directionVector);
    viewMatrix(3, 0) = 0.0f;
    viewMatrix(3, 1) = 0.0f;
    viewMatrix(3, 2) = 0.0f;
    viewMatrix(3, 3) = 1.0f;

    inverseViewMatrix(0, 0) = rightVector[0];
    inverseViewMatrix(0, 1) = upVector[0];
    inverseViewMatrix(0, 2) = directionVector[0];
    inverseViewMatrix(0, 3) = position[0];
    inverseViewMatrix(1, 0) = rightVector[1];
    inverseViewMatrix(1, 1) = upVector[1];
    inverseViewMatrix(1, 2) = directionVector[1];
    inverseViewMatrix(1, 3) = position[1];
    inverseViewMatrix(2, 0) = rightVector[2];
    inverseViewMatrix(2, 1) = upVector[2];
    inverseViewMatrix(2, 2) = directionVector[2];
    inverseViewMatrix(2, 3) = position[2];
    inverseViewMatrix(3, 0) = 0.0f;
    inverseViewMatrix(3, 1) = 0.0f;
    inverseViewMatrix(3, 2) = 0.0f;
    inverseViewMatrix(3, 3) = 1.0f;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    viewMatrix(0, 0) = rightVector[0];
    viewMatrix(1, 0) = rightVector[1];
    viewMatrix(2, 0) = rightVector[2];
    viewMatrix(3, 0) = -Dot(position, rightVector);
    viewMatrix(0, 1) = upVector[0];
    viewMatrix(1, 1) = upVector[1];
    viewMatrix(2, 1) = upVector[2];
    viewMatrix(3, 1) = -Dot(position, upVector);
    viewMatrix(0, 2) = directionVector[0];
    viewMatrix(1, 2) = directionVector[1];
    viewMatrix(2, 2) = directionVector[2];
    viewMatrix(3, 2) = -Dot(position, directionVector);
    viewMatrix(0, 3) = 0.0f;
    viewMatrix(1, 3) = 0.0f;
    viewMatrix(2, 3) = 0.0f;
    viewMatrix(3, 3) = 1.0f;

    inverseViewMatrix(0, 0) = rightVector[0];
    inverseViewMatrix(1, 0) = upVector[0];
    inverseViewMatrix(2, 0) = directionVector[0];
    inverseViewMatrix(3, 0) = position[0];
    inverseViewMatrix(0, 1) = rightVector[1];
    inverseViewMatrix(1, 1) = upVector[1];
    inverseViewMatrix(2, 1) = directionVector[1];
    inverseViewMatrix(3, 1) = position[1];
    inverseViewMatrix(0, 2) = rightVector[2];
    inverseViewMatrix(1, 2) = upVector[2];
    inverseViewMatrix(2, 2) = directionVector[2];
    inverseViewMatrix(3, 2) = position[2];
    inverseViewMatrix(0, 3) = 0.0f;
    inverseViewMatrix(1, 3) = 0.0f;
    inverseViewMatrix(2, 3) = 0.0f;
    inverseViewMatrix(3, 3) = 1.0f;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

void Rendering::WorldCoordinateFrame::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadAggregate(position);
    source.ReadAggregate(directionVector);
    source.ReadAggregate(upVector);
    source.ReadAggregate(rightVector);
    source.Read(epsilon);

    OnFrameChange();
}

void Rendering::WorldCoordinateFrame::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteAggregate(position);
    target.WriteAggregate(directionVector);
    target.WriteAggregate(upVector);
    target.WriteAggregate(rightVector);
    target.Write(epsilon);
}

int Rendering::WorldCoordinateFrame::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = GetStreamSize(position);

    size += GetStreamSize(directionVector);
    size += GetStreamSize(upVector);
    size += GetStreamSize(rightVector);

    size += Mathematics::GetStreamSize(epsilon);

    return size;
}
