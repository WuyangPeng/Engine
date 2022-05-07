///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:45)

#include "AssistTools/AssistToolsExport.h"

#include "CopyrightData.h"
#include "Detail/CopyrightDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

AssistTools::CopyrightData::CopyrightData(int endYear, const System::String& versions, const System::String& projectChineseName)
    : impl{ endYear, versions, projectChineseName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, CopyrightData)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(AssistTools, CopyrightData, GetEndYear, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(AssistTools, CopyrightData, GetVersions, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(AssistTools, CopyrightData, GetProjectChineseName, System::String)
