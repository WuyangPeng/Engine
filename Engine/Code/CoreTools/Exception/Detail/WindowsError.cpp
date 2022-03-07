///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 12:33)

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

const System::String CoreTools::WindowsError::GetError() const
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
