///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 15:54)

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
