///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/29 13:45)

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
