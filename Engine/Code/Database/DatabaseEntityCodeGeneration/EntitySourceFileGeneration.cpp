/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:52)

#include "Database/DatabaseExport.h"

#include "EntitySourceFileGeneration.h"
#include "Detail/EntitySourceFileGenerationImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::EntitySourceFileGeneration::EntitySourceFileGeneration(const String& fileName, const String& namespaceName, const CodeEntityClass& codeEntityClass, const CodeMappingAnalysis& codeMappingAnalysis)
    : impl{ fileName, namespaceName, codeEntityClass, codeMappingAnalysis }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, EntitySourceFileGeneration)

System::String Database::EntitySourceFileGeneration::GetContent() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetContent();
}
