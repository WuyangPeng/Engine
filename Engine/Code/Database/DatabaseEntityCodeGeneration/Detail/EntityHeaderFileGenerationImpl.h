///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/02 20:09)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_HEADER_FILE_GENERATION_IMPL_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_HEADER_FILE_GENERATION_IMPL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityClass.h"
#include "Database/DatabaseEntityCodeGeneration/CodeMappingAnalysis.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE EntityHeaderFileGenerationImpl final
    {
    public:
        using ClassType = EntityHeaderFileGenerationImpl;

        using String = System::String;

    public:
        EntityHeaderFileGenerationImpl(String fileName, String namespaceName, CodeEntityClass codeEntityClass, CodeMappingAnalysis codeMappingAnalysis) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetContent() const;

    private:
        String fileName;
        String namespaceName;
        CodeEntityClass codeEntityClass;
        CodeMappingAnalysis codeMappingAnalysis;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_HEADER_FILE_GENERATION_IMPL_H