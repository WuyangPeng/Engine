// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/21 15:54)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectLink.h"
#include "Detail/ObjectLinkImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::ObjectLink
	::ObjectLink()
	:m_Impl{ make_shared<ImplType>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ObjectLink)

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, ObjectLink);

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectLink, GetObjectPtr, uint64_t, CoreTools::ObjectInterfaceSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectLink, GetOrderedSize, int)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectLink, operator[], int, CoreTools::ObjectInterfaceSmartPointer&)

void CoreTools::ObjectLink
	::Insert(uint64_t uniqueID, const ObjectInterfaceSmartPointer& ptr)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(uniqueID, ptr);
}

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectLink, Sort, void)

