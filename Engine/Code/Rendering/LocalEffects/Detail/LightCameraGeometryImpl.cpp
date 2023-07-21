///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 10:08)

#include "Rendering/RenderingExport.h"

#include "LightCameraGeometryImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::LightCameraGeometryImpl::LightCameraGeometryImpl() noexcept
    : lightModelPosition{ 0.0f, 0.0f, 0.0f, 1.0f },
      lightModelDirection{ 0.0f, 0.0f, -1.0f, 0.0f },
      lightModelUp{ 0.0f, 1.0f, 0.0f, 0.0f },
      lightModelRight{ 1.0f, 0.0f, 0.0f, 0.0f },
      cameraModelPosition{ 0.0f, 0.0f, 0.0f, 1.0f },
      cameraModelDirection{ 0.0f, 0.0f, -1.0f, 0.0f },
      cameraModelUp{ 0.0f, 1.0f, 0.0f, 0.0f },
      cameraModelRight{ 1.0f, 0.0f, 0.0f, 0.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightCameraGeometryImpl)

Rendering::LightCameraGeometryImpl::Colour Rendering::LightCameraGeometryImpl::GetLightModelPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lightModelPosition;
}

void Rendering::LightCameraGeometryImpl::SetLightModelPosition(const Colour& aLightModelPosition) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->lightModelPosition = aLightModelPosition;
}

Rendering::LightCameraGeometryImpl::Colour Rendering::LightCameraGeometryImpl::GetLightModelDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lightModelDirection;
}

void Rendering::LightCameraGeometryImpl::SetLightModelDirection(const Colour& aLightModelDirection) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->lightModelDirection = aLightModelDirection;
}

Rendering::LightCameraGeometryImpl::Colour Rendering::LightCameraGeometryImpl::GetLightModelUp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lightModelUp;
}

void Rendering::LightCameraGeometryImpl::SetLightModelUp(const Colour& aLightModelUp) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->lightModelUp = aLightModelUp;
}

Rendering::LightCameraGeometryImpl::Colour Rendering::LightCameraGeometryImpl::GetLightModelRight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lightModelRight;
}

void Rendering::LightCameraGeometryImpl::SetLightModelRight(const Colour& aLightModelRight) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->lightModelRight = aLightModelRight;
}

Rendering::LightCameraGeometryImpl::Colour Rendering::LightCameraGeometryImpl::GetCameraModelPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraModelPosition;
}

void Rendering::LightCameraGeometryImpl::SetCameraModelPosition(const Colour& aCameraModelPosition) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->cameraModelPosition = aCameraModelPosition;
}

Rendering::LightCameraGeometryImpl::Colour Rendering::LightCameraGeometryImpl::GetCameraModelDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraModelDirection;
}

void Rendering::LightCameraGeometryImpl::SetCameraModelDirection(const Colour& aCameraModelDirection) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->cameraModelDirection = aCameraModelDirection;
}

Rendering::LightCameraGeometryImpl::Colour Rendering::LightCameraGeometryImpl::GetCameraModelUp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraModelUp;
}

void Rendering::LightCameraGeometryImpl::SetCameraModelUp(const Colour& aCameraModelUp) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->cameraModelUp = aCameraModelUp;
}

Rendering::LightCameraGeometryImpl::Colour Rendering::LightCameraGeometryImpl::GetCameraModelRight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraModelRight;
}

void Rendering::LightCameraGeometryImpl::SetCameraModelRight(const Colour& aCameraModelRight) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->cameraModelRight = aCameraModelRight;
}

int Rendering::LightCameraGeometryImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = Rendering::GetStreamSize(lightModelPosition);

    size += Rendering::GetStreamSize(lightModelPosition);
    size += Rendering::GetStreamSize(lightModelDirection);
    size += Rendering::GetStreamSize(lightModelUp);
    size += Rendering::GetStreamSize(lightModelRight);
    size += Rendering::GetStreamSize(cameraModelPosition);
    size += Rendering::GetStreamSize(cameraModelDirection);
    size += Rendering::GetStreamSize(cameraModelUp);
    size += Rendering::GetStreamSize(cameraModelRight);

    return size;
}

void Rendering::LightCameraGeometryImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteAggregate(lightModelPosition);
    target.WriteAggregate(lightModelDirection);
    target.WriteAggregate(lightModelUp);
    target.WriteAggregate(lightModelRight);
    target.WriteAggregate(cameraModelPosition);
    target.WriteAggregate(cameraModelDirection);
    target.WriteAggregate(cameraModelUp);
    target.WriteAggregate(cameraModelRight);
}

void Rendering::LightCameraGeometryImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadAggregate(lightModelPosition);
    source.ReadAggregate(lightModelDirection);
    source.ReadAggregate(lightModelUp);
    source.ReadAggregate(lightModelRight);
    source.ReadAggregate(cameraModelPosition);
    source.ReadAggregate(cameraModelDirection);
    source.ReadAggregate(cameraModelUp);
    source.ReadAggregate(cameraModelRight);
}