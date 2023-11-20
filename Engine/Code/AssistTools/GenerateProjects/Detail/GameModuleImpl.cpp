///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:30)

#include "AssistTools/AssistToolsExport.h"

#include "GameModuleImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GameModuleImpl::GameModuleImpl(String moduleName, String chineseName, ProjectServiceType projectServiceType, String uppercaseName) noexcept
    : moduleName{ std::move(moduleName) },
      chineseName{ std::move(chineseName) },
      projectServiceType{ projectServiceType },
      uppercaseName{ std::move(uppercaseName) }
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

AssistTools::ProjectServiceType AssistTools::GameModuleImpl::GetProjectServiceType() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return projectServiceType;
}

System::String AssistTools::GameModuleImpl::GetUppercaseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return uppercaseName;
}
