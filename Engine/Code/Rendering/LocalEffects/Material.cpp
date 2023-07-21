///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 15:37)

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

CORE_TOOLS_RTTI_DEFINE(Rendering, Material);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Material);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Material);

Rendering::Material::MaterialSharedPtr Rendering::Material::Create()
{
    return std::make_shared<ClassType>(MaterialCreate::Init);
}

Rendering::Material::MaterialSharedPtr Rendering::Material::Create(const Colour& emissive, const Colour& ambient, const Colour& diffuse, const Colour& specular)
{
    return std::make_shared<ClassType>(MaterialCreate::Init, emissive, ambient, diffuse, specular);
}

Rendering::Material::Material(MaterialCreate materialCreate)
    : ParentType{ "Material" },
      impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(materialCreate);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Material::Material(MaterialCreate materialCreate, const Colour& emissive, const Colour& ambient, const Colour& diffuse, const Colour& specular)
    : ParentType{ "Material" },
      impl{ emissive, ambient, diffuse, specular }
{
    System::UnusedFunction(materialCreate);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Material)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Material, GetEmissive, Rendering::Material::Colour)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Material, GetAmbient, Rendering::Material::Colour)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Material, GetDiffuse, Rendering::Material::Colour)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Material, GetSpecular, Rendering::Material::Colour)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Material, SetEmissive, Colour, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Material, SetAmbient, Colour, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Material, SetDiffuse, Colour, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Material, SetSpecular, Colour, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Material, GetAlpha, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Material, GetSpecularExponent, float)

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
