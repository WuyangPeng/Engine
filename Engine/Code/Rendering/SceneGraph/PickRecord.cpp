// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:54)

#include "Rendering/RenderingExport.h"

#include "PickRecord.h"
#include "Detail/PickRecordImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering, PickRecord) 

Rendering::PickRecord
	::PickRecord()
	:m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,PickRecord)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRecord,GetIntersected,Rendering::ConstSpatialSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRecord,GetParameter,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRecord,GetTriangle,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecord,GetBary,int,float) 

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, PickRecord,SetIntersected,ConstSpatialSmartPointer,void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecord,SetParameter,float,void) 
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecord,SetTriangle,int,void) 
 

void Rendering::PickRecord
	::SetBary(float firstBary, float secondBary) 
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetBary(firstBary, secondBary);
}

bool Rendering::PickRecord
	::operator==(const PickRecord& rhs) const 
{
    RENDERING_CLASS_IS_VALID_CONST_1;

	return *m_Impl == *rhs.m_Impl;
}

bool Rendering::PickRecord
	::operator<(const PickRecord& rhs) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

	return *m_Impl < *rhs.m_Impl;
}


 