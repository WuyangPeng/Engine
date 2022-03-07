///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/09 12:35)

#include "CoreTools/CoreToolsExport.h"

#include "StringReplacing.h"
#include "Detail/StringReplacingImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

CoreTools::StringReplacing::StringReplacing(const string& configurationFileName)
    : impl{ configurationFileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StringReplacing)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, StringReplacing, GetReplacing, String, const System::String);
