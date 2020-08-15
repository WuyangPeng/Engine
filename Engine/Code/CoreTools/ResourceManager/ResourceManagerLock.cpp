// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:10)

#include "CoreTools/CoreToolsExport.h"

#include "ResourceManagerLock.h"
#include "Detail/ResourceManagerLockImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::ResourceManagerLock
	::ResourceManagerLock(BaseResourceManager& manager, uint32_t uniqueID)
	:m_Impl{ make_shared<ImplType>(manager,uniqueID) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ResourceManagerLock)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ResourceManagerLock, GetResourceSharedPtr, const CoreTools::ResourceManagerLock::ResourceSharedPtr)


