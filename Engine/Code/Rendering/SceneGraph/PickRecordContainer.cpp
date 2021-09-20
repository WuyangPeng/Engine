// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/22 17:55)

#include "Rendering/RenderingExport.h"

#include "Detail/PickRecordImpl.h"
#include "PickRecordContainer.h"
#include "Detail/PickRecordContainerImpl.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

Rendering::PickRecordContainer ::PickRecordContainer()
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRecordContainer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, PickRecordContainer, InsertPickRecord, PickRecord, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRecordContainer, GetSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRecordContainer, IsEmpty, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecordContainer, GetPickRecord, int, const Rendering::PickRecord)
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, PickRecordContainer)
void Rendering::PickRecordContainer ::InsertPickRecord(const PickRecordContainer& pickRecordContainerImpl)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->InsertPickRecord(*pickRecordContainerImpl.impl);
}
#include STSTEM_WARNING_POP