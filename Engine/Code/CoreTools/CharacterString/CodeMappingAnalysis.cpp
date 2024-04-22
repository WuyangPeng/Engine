/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/29 23:09)

#include "CoreTools/CoreToolsExport.h"

#include "CodeMappingAnalysis.h"
#include "Detail/CodeMappingAnalysisImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CodeMappingAnalysis::CodeMappingAnalysis(const std::wstring& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CodeMappingAnalysis::CodeMappingAnalysis(const std::string& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CodeMappingAnalysis)

System::String CoreTools::CodeMappingAnalysis::GetElement(const String& codeKey) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetElement(codeKey);
}
