///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/01 23:55)

#include "Database/DatabaseExport.h"

#include "EntityHeaderFileGeneration.h"
#include "Detail/EntityHeaderFileGenerationImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::EntityHeaderFileGeneration::EntityHeaderFileGeneration(const String& fileName, const String& namespaceName, const CodeEntityClass& codeEntityClass, const CodeMappingAnalysis& codeMappingAnalysis)
    : impl{ fileName, namespaceName, codeEntityClass, codeMappingAnalysis }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, EntityHeaderFileGeneration)

System::String Database::EntityHeaderFileGeneration::GetContent() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetContent();
}
