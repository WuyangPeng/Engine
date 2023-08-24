///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 15:53)

#include "Database/DatabaseExport.h"

#include "CodeHeaderFileGeneration.h"
#include "Detail/CodeHeaderFileGenerationImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::CodeHeaderFileGeneration::CodeHeaderFileGeneration(const String& fileName, const CodeEntityAnalysis& codeEntityAnalysis, const CodeMappingAnalysis& codeMappingAnalysis)
    : impl{ fileName, codeEntityAnalysis, codeMappingAnalysis }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeHeaderFileGeneration)

System::String Database::CodeHeaderFileGeneration::GetContent() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetContent();
}
