// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 13:33)

#include "CoreTools/CoreToolsExport.h"

#include "BufferPool.h"
#include "Buffer.h"
#include "PoolDetail.h"
#include "Detail/BufferPoolImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::BufferPool
	::BufferPool()
	:m_Impl{ make_shared<ImplType>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, BufferPool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferPool, Get, CoreTools::Buffer*);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferPool, Release, Buffer*, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferPool, GetBuffer, int, CoreTools::Buffer*);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferPool, FreeAll, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferPool, GetAvailableCount, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferPool, GetAllocatedCount, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferPool, GetTotalCount, int);
