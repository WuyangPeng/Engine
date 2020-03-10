// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/21 13:35)

#include "CoreTools/CoreToolsExport.h"

#include "MD5Context.h"
#include "Detail/MD5ContextImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::MD5Context
	::MD5Context()
	:m_Impl{ make_shared<ImplType>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, MD5Context)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, MD5Context, MD5Init, void);

void CoreTools::MD5Context
	::MD5Update(uint8_t const* buffer, uint32_t length)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->MD5Update(buffer, length);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MD5Context, MD5Final, uint8_t*, void);