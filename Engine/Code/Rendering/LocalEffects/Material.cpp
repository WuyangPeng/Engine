/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 20:36)

#include "Rendering/RenderingExport.h"

#include "Material.h"
#include "Detail/MaterialImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Material)

CORE_TOOLS_RTTI_DEFINE(Rendering, Material)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Material);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Material);

Rendering::Material::MaterialSharedPtr Rendering::Material::Create(const std::string& name)
{
    return std::make_shared<ClassType>(MaterialCreate::Init, name);
}

Rendering::Material::MaterialSharedPtr Rendering::Material::Create(const std::string& name, const ColourType& emissive, const ColourType& ambient, const ColourType& diffuse, const ColourType& specular)
{
    return std::make_shared<ClassType>(MaterialCreate::Init, name, emissive, ambient, diffuse, specular);
}

Rendering::Material::Material(MaterialCreate materialCreate, const std::string& name)
    : ParentType{ name },
      impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(materialCreate);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Material::Material(MaterialCreate materialCreate, const std::string& name, const ColourType& emissive, const ColourType& ambient, const ColourType& diffuse, const ColourType& specular)
    : ParentType{ name },
      impl{ emissive, ambient, diffuse, specular }
{
    System::UnusedFunction(materialCreate);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Material)

Rendering::Material::Material(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::Material::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Material::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Material::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

int64_t Rendering::Material::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Material::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::Material::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Material::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::Material::ColourType Rendering::Material::GetEmissive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetEmissive();
}

Rendering::Material::ColourType Rendering::Material::GetAmbient() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetAmbient();
}

Rendering::Material::ColourType Rendering::Material::GetDiffuse() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDiffuse();
}

Rendering::Material::ColourType Rendering::Material::GetSpecular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetSpecular();
}

void Rendering::Material::SetEmissive(const ColourType& emissive) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetEmissive(emissive);
}

void Rendering::Material::SetAmbient(const ColourType& ambient) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetAmbient(ambient);
}

void Rendering::Material::SetDiffuse(const ColourType& diffuse) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetDiffuse(diffuse);
}

void Rendering::Material::SetSpecular(const ColourType& specular) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetSpecular(specular);
}

float Rendering::Material::GetAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetAlpha();
}

float Rendering::Material::GetSpecularExponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetSpecularExponent();
}