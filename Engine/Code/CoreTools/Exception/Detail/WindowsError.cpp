//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 14:28)

#include "CoreTools/CoreToolsExport.h"

#include "WindowsError.h"
#include "CoreTools/CharacterString/FormatErrorMessage.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::WindowsError::WindowsError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
    : ParentType{ functionDescribed, message }, m_LastError{ lastError }, m_WindowsErrorDescribed(FormatErrorMessage{ m_LastError }.GetErrorMessage())
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WindowsError)

const System::String CoreTools::WindowsError::GetError() const
{
    CLASS_IS_VALID_CONST_9;

    auto error = m_WindowsErrorDescribed;

    if (!error.empty())
    {
        error += SYSTEM_TEXT(" ");
    }

    error += ParentType::GetError();

    return error;
}
