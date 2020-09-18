// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:10)

#include "Rendering/RenderingExport.h"

#include "SingleShaderBaseData.h"
#include "Detail/SingleShaderBaseDataImpl.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::SingleShaderBaseData
	::SingleShaderBaseData( const string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic )
	:m_Impl{ make_shared<ImplType>(name,type,semantic) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderBaseData
	::SingleShaderBaseData()
	:m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering,SingleShaderBaseData);

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,SingleShaderBaseData)

void Rendering::SingleShaderBaseData
	::SetData( const string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->SetData(name,type,semantic);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,SingleShaderBaseData,GetName,const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering,SingleShaderBaseData,GetType,Rendering::ShaderFlags::VariableType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderBaseData, GetSemantic, Rendering::ShaderFlags::VariableSemantic) 

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering,SingleShaderBaseData,Load,BufferSource&,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SingleShaderBaseData, Save, CoreTools::BufferTargetSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,SingleShaderBaseData,GetStreamingSize,int) 
 #include STSTEM_WARNING_POP