///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:03)

#include "CoreTools/CoreToolsExport.h"

#include "WindowsError.h"
#include "CoreTools/CharacterString/FormatErrorMessage.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::WindowsError::WindowsError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
    : ParentType{ functionDescribed, message }, lastError{ lastError }, windowsErrorDescribed(FormatErrorMessage{ lastError }.GetErrorMessage())
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WindowsError)

System::String CoreTools::WindowsError::GetError() const
{
    CLASS_IS_VALID_CONST_9;

    auto error = windowsErrorDescribed;

    if (!error.empty())
    {
        error += SYSTEM_TEXT(" ");
    }

    error += ParentType::GetError();

    return error;
}
