/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 23:09)

#include "CoreTools/CoreToolsExport.h"

#include "FormatErrorMessage.h"
#include "Detail/FormatErrorMessageImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::FormatErrorMessage::FormatErrorMessage(WindowError lastError)
    : impl{ lastError }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FormatErrorMessage)

CoreTools::FormatErrorMessage::String CoreTools::FormatErrorMessage::GetErrorMessage() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetErrorMessage();
}
