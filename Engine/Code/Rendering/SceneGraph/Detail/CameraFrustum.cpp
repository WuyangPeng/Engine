///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 11:15)

#include "Rendering/RenderingExport.h"

#include "CameraFrustum.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/MathDetail.h"

Rendering::CameraFrustum::CameraFrustum(bool isPerspective) noexcept
    : isPerspective{ isPerspective }, frustum{}
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

void Rendering::CameraFrustum::SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    frustum.at(System::EnumCastUnderlying(ViewFrustum::DirectionMin)) = directionMin;
    frustum.at(System::EnumCastUnderlying(ViewFrustum::DirectionMax)) = directionMax;
    frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMin)) = upMin;
    frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax)) = upMax;
    frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMin)) = rightMin;
    frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMax)) = rightMax;
}

void Rendering::CameraFrustum::SetFrustum(const float* aFrustum) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    if (aFrustum != nullptr)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        SetFrustum(aFrustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)],
                   aFrustum[System::EnumCastUnderlying(ViewFrustum::DirectionMax)],
                   aFrustum[System::EnumCastUnderlying(ViewFrustum::UpMin)],
                   aFrustum[System::EnumCastUnderlying(ViewFrustum::UpMax)],
                   aFrustum[System::EnumCastUnderlying(ViewFrustum::RightMin)],
                   aFrustum[System::EnumCastUnderlying(ViewFrustum::RightMax)]);

#include STSTEM_WARNING_POP
    }
}

void Rendering::CameraFrustum::SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    const auto halfAngleRadians = 0.5f * upFieldOfViewDegrees * Mathematics::MathF::GetDegreeToRadian();

    frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax)) = directionMin * Mathematics::MathF::Tan(halfAngleRadians);
    frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMax)) = aspectRatio * frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax));
    frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMin)) = -frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax));
    frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMin)) = -frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMax));
    frustum.at(System::EnumCastUnderlying(ViewFrustum::DirectionMin)) = directionMin;
    frustum.at(System::EnumCastUnderlying(ViewFrustum::DirectionMax)) = directionMax;
}

const float* Rendering::CameraFrustum::GetFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frustum.data();
}

Rendering::CameraFrustumData Rendering::CameraFrustum::GetFrustumData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMin)) == -frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMax)) &&
        frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMin)) == -frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax)))
    {
        const auto ratio = frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax)) / frustum.at(System::EnumCastUnderlying(ViewFrustum::DirectionMin));
        const auto upFieldOfViewDegrees = 2.0f * Mathematics::MathF::ATan(ratio) * Mathematics::MathF::GetRadianToDegree();
        const auto aspectRatio = frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMax)) / frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax));
        const auto directionMin = frustum.at(System::EnumCastUnderlying(ViewFrustum::DirectionMin));
        const auto directionMax = frustum.at(System::EnumCastUnderlying(ViewFrustum::DirectionMax));

        return CameraFrustumData{ upFieldOfViewDegrees, aspectRatio, directionMin, directionMax };
    }

    return CameraFrustumData{};
}

float Rendering::CameraFrustum::GetDirectionMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frustum.at(System::EnumCastUnderlying(ViewFrustum::DirectionMin));
}

float Rendering::CameraFrustum::GetDirectionMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frustum.at(System::EnumCastUnderlying(ViewFrustum::DirectionMax));
}

float Rendering::CameraFrustum::GetUpMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMin));
}

float Rendering::CameraFrustum::GetUpMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax));
}

float Rendering::CameraFrustum::GetRightMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMin));
}

float Rendering::CameraFrustum::GetRightMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frustum.at(System::EnumCastUnderlying(ViewFrustum::RightMax));
}

void Rendering::CameraFrustum::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadContainer(frustum);
    isPerspective = source.ReadBool();
}

void Rendering::CameraFrustum::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteContainer(frustum);
    target.Write(isPerspective);
}

int Rendering::CameraFrustum::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = System::EnumCastUnderlying(ViewFrustum::Quantity) * CoreTools::GetStreamSize(frustum.at(0));

    size += CoreTools::GetStreamSize(isPerspective);

    return size;
}
