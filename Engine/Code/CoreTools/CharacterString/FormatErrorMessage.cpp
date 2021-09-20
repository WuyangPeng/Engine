///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/27 18:23)

#include "CoreTools/CoreToolsExport.h"

#include "FormatErrorMessage.h"
#include "Detail/FormatErrorMessageImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::FormatErrorMessage::FormatErrorMessage(WindowError lastError)
    : impl{ lastError }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FormatErrorMessage)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FormatErrorMessage, GetErrorMessage, const System::String)
