// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:55)

#include "Rendering/RenderingExport.h"

#include "PickRecordContainer.h"
#include "Detail/PickRecordContainerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
DELAY_COPY_CONSTRUCTION_DEFINE(Rendering, PickRecordContainer)

Rendering::PickRecordContainer
	::PickRecordContainer()
	:m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, PickRecordContainer)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, PickRecordContainer,InsertPickRecord,PickRecord,void)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRecordContainer,GetSize,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRecordContainer,IsEmpty,bool)									
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecordContainer,GetPickRecord,int,const Rendering::PickRecord)

void Rendering::PickRecordContainer
	::InsertPickRecord(const PickRecordContainer& pickRecordContainerImpl)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->InsertPickRecord(*pickRecordContainerImpl.m_Impl);	 
}
#include STSTEM_WARNING_POP