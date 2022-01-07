///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:35)

#include "CoreTools/CoreToolsExport.h"

#include "JsonHead.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Detail/Json/JsonHeadImpl.h"

CoreTools::JsonHead::JsonHead(const String& path)
    : impl{ path }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonHead)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, JsonHead, GetNameSpace, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, JsonHead, GetJsonClassName, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, JsonHead, GetCompleteClassName, System::String)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonHead, begin, CoreTools::JsonHead::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonHead, end, CoreTools::JsonHead::ContainerConstIter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonHead, HasNested, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonHead, HasArray, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonHead, HasBoolArray, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, JsonHead, GetSize, int)