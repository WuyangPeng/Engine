// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:07)

#include "Rendering/RenderingExport.h"

#include "ShaderProfileData.h"
#include "Detail/ShaderProfileDataImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering,ShaderProfileData);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,ShaderProfileData);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,ShaderProfileData); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering,ShaderProfileData);

CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, ShaderProfileData);

Rendering::ShaderProfileData
	::ShaderProfileData(int numConstants, int numSamplers)
	:ParentType{ "ShaderProfileData" }, m_Impl{ make_shared<ImplType>(numConstants, numSamplers) }
{  
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderProfileData
	::~ShaderProfileData()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, ShaderProfileData)

void Rendering::ShaderProfileData
    ::SetBaseRegister( int profile, int index, int baseRegister )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetBaseRegister(profile,index,baseRegister);
}

void Rendering::ShaderProfileData
	::SetTextureUnit( int profile, int index, int textureUnit )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetTextureUnit(profile, index, textureUnit);
}

void Rendering::ShaderProfileData
	::SetProgram( int profile, const std::string& program )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetProgram(profile, program);
}

int Rendering::ShaderProfileData
	::GetBaseRegister( int profile, int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetBaseRegister(profile, index);
}

int Rendering::ShaderProfileData
	::GetTextureUnit( int profile, int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetTextureUnit(profile, index);
}

const std::string Rendering::ShaderProfileData
	::GetProgram( int profile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetProgram(profile);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderProfileData, GetBaseRegisterSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderProfileData, GetTextureUnitSize, int)

CoreTools::ObjectInterfaceSharedPtr Rendering::ShaderProfileData::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP