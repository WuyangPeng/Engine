//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 14:47)

#include "CoreTools/CoreToolsExport.h"

#include "OStreamShared.h"
#include "Detail/OStreamImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::ostream;
using std::string;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::OStreamShared::OStreamShared()
    : impl{ true }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

CoreTools::OStreamShared::OStreamShared(bool isCout)
    : impl{ isCout }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::OStreamShared::OStreamShared(const string& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OStreamShared)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, GetStream, ostream&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsCout, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsCerr, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsFile, bool)
