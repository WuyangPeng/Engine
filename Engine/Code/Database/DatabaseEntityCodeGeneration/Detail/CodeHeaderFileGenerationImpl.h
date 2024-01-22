/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 13:50)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_HEADER_FILE_GENERATION_IMPL_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_HEADER_FILE_GENERATION_IMPL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityAnalysis.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE CodeHeaderFileGenerationImpl final
    {
    public:
        using ClassType = CodeHeaderFileGenerationImpl;

        using String = System::String;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;

    public:
        CodeHeaderFileGenerationImpl(String fileName, CodeEntityAnalysis codeEntityAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetContent() const;

    private:
        String fileName;
        CodeEntityAnalysis codeEntityAnalysis;
        CodeMappingAnalysis codeMappingAnalysis;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_HEADER_FILE_GENERATION_IMPL_H
