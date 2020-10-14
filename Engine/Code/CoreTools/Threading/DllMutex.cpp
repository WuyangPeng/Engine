//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 19:05)

#include "CoreTools/CoreToolsExport.h"

#include "DllMutex.h"
#include "Detail/MutexFactory.h"
#include "Detail/MutexImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::DllMutex::DllMutex(MutexCreate mutexCreate)
    : m_Impl{ MutexFactory::GenerateMutex(mutexCreate) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, DllMutex)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, DllMutex, Initialize, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DllMutex, Delete, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, DllMutex, Enter, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, DllMutex, TryEnter, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DllMutex, Leave, void)
