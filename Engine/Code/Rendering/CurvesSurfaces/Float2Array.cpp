// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 16:43)

#include "Rendering/RenderingExport.h"

#include "Float2Array.h"
#include "Detail/Float2ArrayImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"

using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, Float2Array);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Float2Array);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Float2Array); 
CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, Float2Array);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, Float2Array);

Rendering::Float2Array
	::Float2Array( const Float2Vector& data )
	:ParentType("Float2Array"),m_Impl{ make_shared<ImplType>(data) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Float2Array
	::~Float2Array()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, Float2Array)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Float2Array,operator[], int,const Rendering::Float2Array::Float2&)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Float2Array,operator[], int, Rendering::Float2Array::Float2&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Float2Array,GetNumElements, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Float2Array,GetData, const Rendering::Float2Array::Float2*)
 


 