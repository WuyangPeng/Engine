// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:03)

#include "Rendering/RenderingExport.h"

#include "ShaderConstantsData.h"
#include "Detail/ShaderConstantsDataImpl.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;

Rendering::ShaderConstantsData
	::ShaderConstantsData( int numConstants )
	:m_Impl{ make_shared<ImplType>(numConstants) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderConstantsData
	::ShaderConstantsData()
	:m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,ShaderConstantsData)

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering, ShaderConstantsData);


IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData,Resize,int,void)

void Rendering::ShaderConstantsData
	::SetConstant( int index, const string& name, int numRegistersUsed )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetConstant(index, name, numRegistersUsed);
}


void Rendering::ShaderConstantsData
	::InsertData(const string& name, int numRegistersUsed)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->InsertData( name, numRegistersUsed);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderConstantsData,GetNumConstants, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData,GetConstantName, int,const string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData,GetNumRegistersUsed, int,int)
 
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderConstantsData,Load,BufferSource&,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderConstantsData,Save,BufferTarget&,void)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,ShaderConstantsData,GetStreamingSize,int) 

