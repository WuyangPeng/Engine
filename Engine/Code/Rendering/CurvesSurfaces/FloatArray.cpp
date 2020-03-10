// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 16:44)

#include "Rendering/RenderingExport.h"

#include "FloatArray.h"
#include "Detail/FloatArrayImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"

using std::make_shared;
 
CORE_TOOLS_RTTI_DEFINE(Rendering, FloatArray);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, FloatArray);
CORE_TOOLS_FACTORY_DEFINE(Rendering, FloatArray); 
CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, FloatArray);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, FloatArray);

Rendering::FloatArray
	::FloatArray( const FloatVector& data )
	:ParentType{ "FloatArray" }, m_Impl{ make_shared<ImplType>(data) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::FloatArray
	::~FloatArray()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering,FloatArray)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, FloatArray,operator[], int,const float&)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, FloatArray,operator[], int, float&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, FloatArray,GetNumElements, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, FloatArray,GetData, const float*)
 


 