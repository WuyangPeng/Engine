///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 19:07)

#include "Rendering/RenderingExport.h"

#include "WorldCoordinateFrame.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalizeDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

Rendering::WorldCoordinateFrame::WorldCoordinateFrame(float epsilon)  
    : worldPosition{ Mathematics::APointF::GetOrigin() },
      worldDirectionVector{ -Mathematics::AVectorF::GetUnitZ() },
      worldUpVector{ Mathematics::AVectorF::GetUnitY() },
      worldRightVector{ Mathematics::AVectorF::GetUnitX() },
      viewMatrix{ Mathematics::MatrixF::GetZeroMatrix() },
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
        if (worldDirectionVector.IsNormalize(epsilon) &&
            worldUpVector.IsNormalize(epsilon) &&
            worldRightVector.IsNormalize(epsilon) &&
            Math::FAbs(Dot(worldDirectionVector, worldUpVector)) <= epsilon &&
            Math::FAbs(Dot(worldUpVector, worldRightVector)) <= epsilon &&
            Math::FAbs(Dot(worldRightVector, worldDirectionVector)) <= epsilon)
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

void Rendering::WorldCoordinateFrame::SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_1;

    worldPosition = position;

    SetAxes(directionVector, upVector, rightVector);
}

void Rendering::WorldCoordinateFrame::SetPosition(const APoint& position)
{
    RENDERING_CLASS_IS_VALID_1;

    worldPosition = position;

    OnFrameChange();
}

void Rendering::WorldCoordinateFrame::SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_1;

    worldDirectionVector = directionVector;
    worldUpVector = upVector;
    worldRightVector = rightVector;

    auto det = Dot(worldDirectionVector, Cross(worldUpVector, worldRightVector));
    if (epsilon < Mathematics::MathF::FAbs(1.0f - det))
    {
        // 输入向量并没有形成一个标准正交集合。这里重新正交化
        const auto orthonormalize = Orthonormalize(worldDirectionVector, worldUpVector, worldRightVector, epsilon);

        worldDirectionVector = orthonormalize.GetUVector();
        worldUpVector = orthonormalize.GetVVector();
        worldRightVector = orthonormalize.GetWVector();
    }

    OnFrameChange();
}
 
Rendering::WorldCoordinateFrame::APoint Rendering::WorldCoordinateFrame::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return worldPosition;
}

Rendering::WorldCoordinateFrame::AVector Rendering::WorldCoordinateFrame::GetDirectionVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return worldDirectionVector;
}

Rendering::WorldCoordinateFrame::AVector Rendering::WorldCoordinateFrame::GetUpVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return worldUpVector;
}

Rendering::WorldCoordinateFrame::AVector Rendering::WorldCoordinateFrame::GetRightVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return worldRightVector;
}

Rendering::WorldCoordinateFrame::Matrix Rendering::WorldCoordinateFrame::GetViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return viewMatrix;
}

// private
void Rendering::WorldCoordinateFrame::OnFrameChange()
{
    viewMatrix(0, 0) = worldRightVector[0];
    viewMatrix(0, 1) = worldRightVector[1];
    viewMatrix(0, 2) = worldRightVector[2];
    viewMatrix(0, 3) = -Dot(worldPosition, worldRightVector);
    viewMatrix(1, 0) = worldUpVector[0];
    viewMatrix(1, 1) = worldUpVector[1];
    viewMatrix(1, 2) = worldUpVector[2];
    viewMatrix(1, 3) = -Dot(worldPosition, worldUpVector);
    viewMatrix(2, 0) = worldDirectionVector[0];
    viewMatrix(2, 1) = worldDirectionVector[1];
    viewMatrix(2, 2) = worldDirectionVector[2];
    viewMatrix(2, 3) = -Dot(worldPosition, worldDirectionVector);
    viewMatrix(3, 0) = 0.0f;
    viewMatrix(3, 1) = 0.0f;
    viewMatrix(3, 2) = 0.0f;
    viewMatrix(3, 3) = 1.0f;
}

void Rendering::WorldCoordinateFrame::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadAggregate(worldPosition);
    source.ReadAggregate(worldDirectionVector);
    source.ReadAggregate(worldUpVector);
    source.ReadAggregate(worldRightVector);
    source.Read(epsilon);

    OnFrameChange();
}

void Rendering::WorldCoordinateFrame::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteAggregate(worldPosition);
    target.WriteAggregate(worldDirectionVector);
    target.WriteAggregate(worldUpVector);
    target.WriteAggregate(worldRightVector);
    target.Write(epsilon);
}

int Rendering::WorldCoordinateFrame::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = MATHEMATICS_STREAM_SIZE(worldPosition);

    size += MATHEMATICS_STREAM_SIZE(worldDirectionVector);
    size += MATHEMATICS_STREAM_SIZE(worldUpVector);
    size += MATHEMATICS_STREAM_SIZE(worldRightVector);

    size += CoreTools::GetStreamSize(epsilon);

    return size;
}
