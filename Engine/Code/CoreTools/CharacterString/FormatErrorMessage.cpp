///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:10)

#include "CoreTools/CoreToolsExport.h"

#include "FormatErrorMessage.h"
#include "Detail/FormatErrorMessageImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::FormatErrorMessage::FormatErrorMessage(WindowError lastError)
    : impl{ lastError }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FormatErrorMessage)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FormatErrorMessage, GetErrorMessage, System::String)
