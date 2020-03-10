// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:12)

#include "Rendering/RenderingExport.h"

#include "SingleShaderConstantsData.h"
#include "Detail/SingleShaderConstantsDataImpl.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;

Rendering::SingleShaderConstantsData
	::SingleShaderConstantsData( const string& name,int numRegistersUsed )
	:m_Impl{ make_shared<ImplType>(name,numRegistersUsed) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderConstantsData
	::SingleShaderConstantsData()
	:m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering, SingleShaderConstantsData);

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, SingleShaderConstantsData)

void Rendering::SingleShaderConstantsData
	::SetConstant( const string& name, int numRegistersUsed )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetConstant(name, numRegistersUsed);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderConstantsData,GetConstantName,const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderConstantsData,GetNumRegistersUsed,int) 

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderConstantsData,Load,BufferSource&,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,SingleShaderConstantsData,Save,BufferTarget&,void)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,SingleShaderConstantsData,GetStreamingSize,int) 