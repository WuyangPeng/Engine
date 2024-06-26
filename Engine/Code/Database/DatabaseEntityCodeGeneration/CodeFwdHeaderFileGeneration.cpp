/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:52)

#include "Database/DatabaseExport.h"

#include "CodeFwdHeaderFileGeneration.h"
#include "Detail/CodeFwdHeaderFileGenerationImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::CodeFwdHeaderFileGeneration::CodeFwdHeaderFileGeneration(const String& fileName, const CodeEntityAnalysis& codeEntityAnalysis, const CodeMappingAnalysis& codeMappingAnalysis)
    : impl{ fileName, codeEntityAnalysis, codeMappingAnalysis }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeFwdHeaderFileGeneration)

System::String Database::CodeFwdHeaderFileGeneration::GetContent() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetContent();
}
