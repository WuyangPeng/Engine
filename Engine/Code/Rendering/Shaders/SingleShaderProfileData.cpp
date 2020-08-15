// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:13)

#include "Rendering/RenderingExport.h"

#include "SingleShaderProfileData.h"
#include "Detail/SingleShaderProfileDataImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::SingleShaderProfileData
	::SingleShaderProfileData(int numConstants,int numSamplers)	
	:m_Impl{ make_shared<ImplType>(numConstants,numSamplers) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderProfileData
	::SingleShaderProfileData()
	:m_Impl{ make_shared<ImplType>(0,0) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering,SingleShaderProfileData);

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,SingleShaderProfileData)

void Rendering::SingleShaderProfileData
    ::SetBaseRegister( int index, int baseRegister )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetBaseRegister(index,baseRegister);
}

void Rendering::SingleShaderProfileData
	::SetTextureUnit( int index, int textureUnit )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetTextureUnit(index,textureUnit);
}


void Rendering::SingleShaderProfileData
	::ResetData(int numConstants, int numSamplers)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ResetData(numConstants, numSamplers);
}

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SingleShaderProfileData,SetProgram,string,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData,GetBaseRegister,int,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData,GetTextureUnit,int,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData,GetProgram,const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData,GetBaseRegisterSize,int) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData,GetTextureUnitSize,int) 
 
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData,Load,BufferSource&,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,SingleShaderProfileData,Save,BufferTarget&,void)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,SingleShaderProfileData,GetStreamingSize,int) 
#include STSTEM_WARNING_POP