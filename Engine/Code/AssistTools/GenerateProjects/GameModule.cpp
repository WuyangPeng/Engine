/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:57)

#include "AssistTools/AssistToolsExport.h"

#include "GameModule.h"
#include "Detail/GameModuleImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GameModule::GameModule(const String& moduleName, const String& chineseName, ProjectServiceType projectServiceType, const String& uppercaseName, const GuidContainer& guid)
    : impl{ moduleName, chineseName, projectServiceType, uppercaseName, guid }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GameModule)

System::String AssistTools::GameModule::GetModuleName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetModuleName();
}

System::String AssistTools::GameModule::GetChineseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetChineseName();
}

AssistTools::ProjectServiceType AssistTools::GameModule::GetProjectServiceType() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectServiceType();
}

System::String AssistTools::GameModule::GetUppercaseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetUppercaseName();
}

System::String AssistTools::GameModule::GetGuid(int index) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetGuid(index);
}
