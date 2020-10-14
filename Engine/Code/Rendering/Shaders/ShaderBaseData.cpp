// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:01)

#include "Rendering/RenderingExport.h"

#include "ShaderBaseData.h"
#include "Detail/ShaderBaseDataImpl.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::ShaderBaseData
	::ShaderBaseData( int number )
	:m_Impl{ make_shared<ImplType>(number) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderBaseData
	::ShaderBaseData()
	:m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering, ShaderBaseData);

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, ShaderBaseData)

void Rendering::ShaderBaseData
	::SetData( int index, const string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->SetData(index,name, type, semantic);
}

void Rendering::ShaderBaseData
	::InsertData(const string& name, ShaderFlags::VariableType type, 
	             ShaderFlags::VariableSemantic semantic)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->InsertData(name, type, semantic);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderBaseData,GetNumber,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData,GetName,int,const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData,GetType,int,Rendering::ShaderFlags::VariableType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData,GetSemantic,int,Rendering::ShaderFlags::VariableSemantic) 
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBaseData,Resize,int,void)
 
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderBaseData, Load, CoreTools::BufferSourceSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderBaseData, Save, CoreTools::BufferTargetSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,ShaderBaseData,GetStreamingSize,int) 

#include STSTEM_WARNING_POP