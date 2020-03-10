// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:10)

#include "CoreTools/CoreToolsExport.h"

#include "CommonDataResource.h"
#include "Detail/CommonDataResourceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::CommonDataResource
	::CommonDataResource(PriorityType priority, uint32_t size)
	:ParentType(priority), m_Impl{ make_shared<ImplType>(size) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CommonDataResource
	::~CommonDataResource()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(CoreTools, CommonDataResource)

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(CoreTools, CommonDataResource)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommonDataResource, GetSize, uint32_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommonDataResource, IsDisposed, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommonDataResource, Recreate, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommonDataResource, Dispose, void)

void CoreTools::CommonDataResource
	::SetData(int index, uint8_t value)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetData(index, value);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CommonDataResource, GetData, int, uint8_t)



