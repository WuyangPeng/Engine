//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/20 10:09)

#include "CoreTools/CoreToolsExport.h"

#include "MD5Context.h"
#include "Detail/MD5ContextImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::MD5Context::MD5Context(  DisableNotThrow disableNotThrow)
    : impl{ disableNotThrow }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MD5Context)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, MD5Context, MD5Init, void);

void CoreTools::MD5Context::MD5Update(uint8_t const* buffer, uint32_t length) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2)
{
    

    return impl->MD5Update(buffer, length);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MD5Context, MD5Final, uint8_t*, void);