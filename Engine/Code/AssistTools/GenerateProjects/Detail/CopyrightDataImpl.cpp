///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:50)

#include "AssistTools/AssistToolsExport.h"

#include "CopyrightDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::CopyrightDataImpl::CopyrightDataImpl(int endYear, const System::String& versions, const System::String& projectChineseName)
    : endYear{ endYear }, versions{ versions }, projectChineseName{ projectChineseName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, CopyrightDataImpl)

int AssistTools::CopyrightDataImpl::GetEndYear() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return endYear;
}

System::String AssistTools::CopyrightDataImpl::GetVersions() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return versions;
}

System::String AssistTools::CopyrightDataImpl::GetProjectChineseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return projectChineseName;
}
