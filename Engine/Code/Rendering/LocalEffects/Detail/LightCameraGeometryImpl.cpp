/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 09:47)

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

Rendering::LightCameraGeometryImpl::ColourType Rendering::LightCameraGeometryImpl::GetLightModelPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lightModelPosition;
}

void Rendering::LightCameraGeometryImpl::SetLightModelPosition(const ColourType& aLightModelPosition) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->lightModelPosition = aLightModelPosition;
}

Rendering::LightCameraGeometryImpl::ColourType Rendering::LightCameraGeometryImpl::GetLightModelDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lightModelDirection;
}

void Rendering::LightCameraGeometryImpl::SetLightModelDirection(const ColourType& aLightModelDirection) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->lightModelDirection = aLightModelDirection;
}

Rendering::LightCameraGeometryImpl::ColourType Rendering::LightCameraGeometryImpl::GetLightModelUp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lightModelUp;
}

void Rendering::LightCameraGeometryImpl::SetLightModelUp(const ColourType& aLightModelUp) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->lightModelUp = aLightModelUp;
}

Rendering::LightCameraGeometryImpl::ColourType Rendering::LightCameraGeometryImpl::GetLightModelRight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lightModelRight;
}

void Rendering::LightCameraGeometryImpl::SetLightModelRight(const ColourType& aLightModelRight) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->lightModelRight = aLightModelRight;
}

Rendering::LightCameraGeometryImpl::ColourType Rendering::LightCameraGeometryImpl::GetCameraModelPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraModelPosition;
}

void Rendering::LightCameraGeometryImpl::SetCameraModelPosition(const ColourType& aCameraModelPosition) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->cameraModelPosition = aCameraModelPosition;
}

Rendering::LightCameraGeometryImpl::ColourType Rendering::LightCameraGeometryImpl::GetCameraModelDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraModelDirection;
}

void Rendering::LightCameraGeometryImpl::SetCameraModelDirection(const ColourType& aCameraModelDirection) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->cameraModelDirection = aCameraModelDirection;
}

Rendering::LightCameraGeometryImpl::ColourType Rendering::LightCameraGeometryImpl::GetCameraModelUp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraModelUp;
}

void Rendering::LightCameraGeometryImpl::SetCameraModelUp(const ColourType& aCameraModelUp) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->cameraModelUp = aCameraModelUp;
}

Rendering::LightCameraGeometryImpl::ColourType Rendering::LightCameraGeometryImpl::GetCameraModelRight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraModelRight;
}

void Rendering::LightCameraGeometryImpl::SetCameraModelRight(const ColourType& aCameraModelRight) noexcept
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