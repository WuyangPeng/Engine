/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:50)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_HEADER_FILE_GENERATION_IMPL_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_HEADER_FILE_GENERATION_IMPL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityClass.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE EntityHeaderFileGenerationImpl final
    {
    public:
        using ClassType = EntityHeaderFileGenerationImpl;

        using String = System::String;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;

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
