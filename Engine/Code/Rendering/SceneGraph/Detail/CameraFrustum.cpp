/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/21 15:47)

#include "Rendering/RenderingExport.h"

#include "CameraFrustum.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/MathDetail.h"

Rendering::CameraFrustum::CameraFrustum() noexcept
    : frustum{}, isPerspective{}, epsilon{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CameraFrustum::CameraFrustum(bool isPerspective, float epsilon)
    : frustum{}, isPerspective{ isPerspective }, epsilon{ epsilon }
{
    SetFrustum(90.0f, 1.0f, 1.0f, 10000.0f);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraFrustum)

bool Rendering::CameraFrustum::IsPerspective() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isPerspective;
}

void Rendering::CameraFrustum::SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax)
{
    RENDERING_CLASS_IS_VALID_9;

    GetFrustum(ViewFrustum::DirectionMin) = directionMin;
    GetFrustum(ViewFrustum::DirectionMax) = directionMax;
    GetFrustum(ViewFrustum::UpMin) = upMin;
    GetFrustum(ViewFrustum::UpMax) = upMax;
    GetFrustum(ViewFrustum::RightMin) = rightMin;
    GetFrustum(ViewFrustum::RightMax) = rightMax;
}

void Rendering::CameraFrustum::SetFrustum(const Container& aFrustum) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    frustum = aFrustum;
}

void Rendering::CameraFrustum::SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto halfAngleRadians = 0.5f * upFieldOfViewDegrees * Mathematics::MathF::GetDegreeToRadian();

    GetFrustum(ViewFrustum::UpMax) = directionMin * Mathematics::MathF::Tan(halfAngleRadians);
    GetFrustum(ViewFrustum::RightMax) = aspectRatio * GetFrustum(ViewFrustum::UpMax);
    GetFrustum(ViewFrustum::UpMin) = -GetFrustum(ViewFrustum::UpMax);
    GetFrustum(ViewFrustum::RightMin) = -GetFrustum(ViewFrustum::RightMax);
    GetFrustum(ViewFrustum::DirectionMin) = directionMin;
    GetFrustum(ViewFrustum::DirectionMax) = directionMax;
}

Rendering::CameraFrustum::Container Rendering::CameraFrustum::GetFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frustum;
}

Rendering::CameraFrustumData Rendering::CameraFrustum::GetSymmetricFrustum() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (Mathematics::MathF::Approximate(GetFrustum(ViewFrustum::RightMin), -GetFrustum(ViewFrustum::RightMax), epsilon) &&
        Mathematics::MathF::Approximate(GetFrustum(ViewFrustum::UpMin), -GetFrustum(ViewFrustum::UpMax), epsilon))
    {
        const auto ratio = GetFrustum(ViewFrustum::UpMax) / GetFrustum(ViewFrustum::DirectionMin);
        const auto upFieldOfViewDegrees = 2.0f * Mathematics::MathF::ATan(ratio) * Mathematics::MathF::GetRadianToDegree();
        const auto aspectRatio = GetFrustum(ViewFrustum::RightMax) / GetFrustum(ViewFrustum::UpMax);
        const auto directionMin = GetFrustum(ViewFrustum::DirectionMin);
        const auto directionMax = GetFrustum(ViewFrustum::DirectionMax);

        return CameraFrustumData{ upFieldOfViewDegrees, aspectRatio, directionMin, directionMax };
    }

    return CameraFrustumData{};
}

float Rendering::CameraFrustum::GetDirectionMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetFrustum(ViewFrustum::DirectionMin);
}

float Rendering::CameraFrustum::GetDirectionMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetFrustum(ViewFrustum::DirectionMax);
}

float Rendering::CameraFrustum::GetUpMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetFrustum(ViewFrustum::UpMin);
}

float Rendering::CameraFrustum::GetUpMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetFrustum(ViewFrustum::UpMax);
}

float Rendering::CameraFrustum::GetRightMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetFrustum(ViewFrustum::RightMin);
}

float Rendering::CameraFrustum::GetRightMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetFrustum(ViewFrustum::RightMax);
}

void Rendering::CameraFrustum::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadContainer(frustum);
    isPerspective = source.ReadBool();
}

void Rendering::CameraFrustum::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteContainer(frustum);
    target.Write(isPerspective);
}

int Rendering::CameraFrustum::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(frustum);

    size += CoreTools::GetStreamSize(isPerspective);

    return size;
}

float& Rendering::CameraFrustum::GetFrustum(ViewFrustum viewFrustum)
{
    RENDERING_CLASS_IS_VALID_9;

    return frustum.at(System::EnumCastUnderlying(viewFrustum));
}

float Rendering::CameraFrustum::GetFrustum(ViewFrustum viewFrustum) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frustum.at(System::EnumCastUnderlying(viewFrustum));
}
