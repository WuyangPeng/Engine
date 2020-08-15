// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:10)

#include "CoreTools/CoreToolsExport.h"

#include "BaseResource.h"
#include "Detail/BaseResourceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::BaseResource
	::BaseResource(PriorityType priority)
	:m_Impl{ make_shared<ImplType>(priority) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::BaseResource
	::~BaseResource()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

COPY_CONSTRUCTION_DO_NOT_USE_SWAP_DEFINE(CoreTools, BaseResource)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, BaseResource)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BaseResource, GetPriority, CoreTools::PriorityType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BaseResource, GetLastAccessTime, boost::posix_time::ptime)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BaseResource, IsLocked, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, BaseResource, SetPriority, PriorityType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BaseResource, SetCurrentTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BaseResource, Lock, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BaseResource, Unlock, void)

bool CoreTools
	::operator<(const BaseResource& lhs, const BaseResource& rhs)
{
	if (lhs.GetPriority() < rhs.GetPriority())
		return true;
	else if (rhs.GetPriority() < lhs.GetPriority())
		return false;
	else if (lhs.GetLastAccessTime() < rhs.GetLastAccessTime())
		return true;
	else if (rhs.GetLastAccessTime() < lhs.GetLastAccessTime())
		return false;
	else
		return lhs.GetSize() < rhs.GetSize();
}
