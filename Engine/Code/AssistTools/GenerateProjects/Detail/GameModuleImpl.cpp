﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 10:48)

#include "AssistTools/AssistToolsExport.h"

#include "GameModuleImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GameModuleImpl::GameModuleImpl(String moduleName, String chineseName, bool isClient, String uppercaseName) noexcept
    : moduleName{ std::move(moduleName) }, chineseName{ std::move(chineseName) }, isClient{ isClient }, uppercaseName{ std::move(uppercaseName) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GameModuleImpl)

System::String AssistTools::GameModuleImpl::GetModuleName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return moduleName;
}

System::String AssistTools::GameModuleImpl::GetChineseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return chineseName;
}

bool AssistTools::GameModuleImpl::IsClient() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return isClient;
}

System::String AssistTools::GameModuleImpl::GetUppercaseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return uppercaseName;
}
