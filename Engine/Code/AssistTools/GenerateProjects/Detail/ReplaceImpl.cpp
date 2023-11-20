﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/16 09:43)

#include "AssistTools/AssistToolsExport.h"

#include "ReplaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::ReplaceImpl::ReplaceImpl(StringView keyCode, String parameter) noexcept
    : keyCode{ keyCode }, parameter{ std::move(parameter) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ReplaceImpl)

System::StringView AssistTools::ReplaceImpl::GetKeyCode() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return keyCode;
}

System::String AssistTools::ReplaceImpl::GetParameter() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return parameter;
}
