/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 09:48)

#include "Rendering/RenderingExport.h"

#include "LightCameraGeometry.h"
#include "Detail/LightCameraGeometryImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/DataTypes/SpecializedIO.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, LightCameraGeometry)

Rendering::LightCameraGeometry::LightCameraGeometrySharedPtr Rendering::LightCameraGeometry::Create()
{
    return std::make_shared<ClassType>(LightCameraGeometryCreate::Init);
}

Rendering::LightCameraGeometry::LightCameraGeometry(LightCameraGeometryCreate lightCameraGeometryCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(lightCameraGeometryCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightCameraGeometry)

Rendering::LightCameraGeometry::ColourType Rendering::LightCameraGeometry::GetLightModelPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLightModelPosition();
}

void Rendering::LightCameraGeometry::SetLightModelPosition(const ColourType& lightModelPosition) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLightModelPosition(lightModelPosition);
}

Rendering::LightCameraGeometry::ColourType Rendering::LightCameraGeometry::GetLightModelDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLightModelDirection();
}

void Rendering::LightCameraGeometry::SetLightModelDirection(const ColourType& lightModelDirection) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLightModelDirection(lightModelDirection);
}

Rendering::LightCameraGeometry::ColourType Rendering::LightCameraGeometry::GetLightModelUp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLightModelUp();
}

void Rendering::LightCameraGeometry::SetLightModelUp(const ColourType& lightModelUp) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLightModelUp(lightModelUp);
}

Rendering::LightCameraGeometry::ColourType Rendering::LightCameraGeometry::GetLightModelRight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLightModelRight();
}

void Rendering::LightCameraGeometry::SetLightModelRight(const ColourType& lightModelRight) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLightModelRight(lightModelRight);
}

Rendering::LightCameraGeometry::ColourType Rendering::LightCameraGeometry::GetCameraModelPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraModelPosition();
}

void Rendering::LightCameraGeometry::SetCameraModelPosition(const ColourType& cameraModelPosition) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCameraModelPosition(cameraModelPosition);
}

Rendering::LightCameraGeometry::ColourType Rendering::LightCameraGeometry::GetCameraModelDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraModelDirection();
}

void Rendering::LightCameraGeometry::SetCameraModelDirection(const ColourType& cameraModelDirection) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCameraModelDirection(cameraModelDirection);
}

Rendering::LightCameraGeometry::ColourType Rendering::LightCameraGeometry::GetCameraModelUp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraModelUp();
}

void Rendering::LightCameraGeometry::SetCameraModelUp(const ColourType& cameraModelUp) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCameraModelUp(cameraModelUp);
}

Rendering::LightCameraGeometry::ColourType Rendering::LightCameraGeometry::GetCameraModelRight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraModelRight();
}

void Rendering::LightCameraGeometry::SetCameraModelRight(const ColourType& cameraModelRight) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCameraModelRight(cameraModelRight);
}

int Rendering::LightCameraGeometry::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStreamingSize();
}

void Rendering::LightCameraGeometry::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Save(target);
}

void Rendering::LightCameraGeometry::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Load(source);
}