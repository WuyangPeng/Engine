/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 20:32)

#include "Rendering/RenderingExport.h"

#include "Lighting.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/LocalEffects/Detail/LightingImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Lighting)

CORE_TOOLS_RTTI_DEFINE(Rendering, Lighting)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Lighting);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Lighting);

Rendering::Lighting::LightSharedPtr Rendering::Lighting::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name, Mathematics::MathF::GetZeroTolerance());
}

Rendering::Lighting::Lighting(const std::string& name, float epsilon)
    : ParentType{ name }, impl{ epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Lighting)

void Rendering::Lighting::SetAttenuation(float constant, float linear, float quadratic, float intensity) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetAttenuation(constant, linear, quadratic, intensity);
}

Rendering::Lighting::Lighting(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Lighting::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Lighting::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Lighting::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Lighting::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Lighting::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Lighting::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Lighting::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::Lighting::SetAngle(float angle)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetAngle(angle);
}

void Rendering::Lighting::SetExponent(float exponent) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetExponent(exponent);
}

float Rendering::Lighting::GetAngle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetAngle();
}

float Rendering::Lighting::GetCosAngle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetCosAngle();
}

float Rendering::Lighting::GetSinAngle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetSinAngle();
}

float Rendering::Lighting::GetExponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetExponent();
}

void Rendering::Lighting::SetAmbient(const Colour& ambient) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetAmbient(ambient);
}

void Rendering::Lighting::SetDiffuse(const Colour& diffuse) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetDiffuse(diffuse);
}

void Rendering::Lighting::SetSpecular(const Colour& specular) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetSpecular(specular);
}

Rendering::Lighting::Colour Rendering::Lighting::GetAmbient() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetAmbient();
}

Rendering::Lighting::Colour Rendering::Lighting::GetDiffuse() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDiffuse();
}

Rendering::Lighting::Colour Rendering::Lighting::GetSpecular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetSpecular();
}

float Rendering::Lighting::GetConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstant();
}

float Rendering::Lighting::GetLinear() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetLinear();
}

float Rendering::Lighting::GetQuadratic() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetQuadratic();
}

float Rendering::Lighting::GetIntensity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetIntensity();
}