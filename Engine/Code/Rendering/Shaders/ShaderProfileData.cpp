///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:53)

#include "Rendering/RenderingExport.h"

#include "ShaderProfileData.h"
#include "Detail/ShaderProfileDataImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderProfileData)

CORE_TOOLS_RTTI_DEFINE(Rendering, ShaderProfileData);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ShaderProfileData);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, ShaderProfileData);

Rendering::ShaderProfileData::ShaderProfileData(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ShaderProfileData)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ShaderProfileData)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ShaderProfileData)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ShaderProfileData)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ShaderProfileData)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ShaderProfileData)

Rendering::ShaderProfileData::ShaderProfileData(int numConstants, int numSamplers)
    : ParentType{ "ShaderProfileData" }, impl{ numConstants, numSamplers }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderProfileData)

void Rendering::ShaderProfileData::SetBaseRegister(int profile, int index, int baseRegister)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetBaseRegister(profile, index, baseRegister);
}

void Rendering::ShaderProfileData::SetTextureUnit(int profile, int index, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTextureUnit(profile, index, textureUnit);
}

void Rendering::ShaderProfileData::SetProgram(int profile, const std::string& program)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetProgram(profile, program);
}

int Rendering::ShaderProfileData::GetBaseRegister(int profile, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetBaseRegister(profile, index);
}

int Rendering::ShaderProfileData::GetTextureUnit(int profile, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetTextureUnit(profile, index);
}

std::string Rendering::ShaderProfileData::GetProgram(int profile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetProgram(profile);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderProfileData, GetBaseRegisterSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderProfileData, GetTextureUnitSize, int)

CoreTools::ObjectInterfaceSharedPtr Rendering::ShaderProfileData::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
