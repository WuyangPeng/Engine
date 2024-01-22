/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:50)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_HEADER_FILE_GENERATION_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_HEADER_FILE_GENERATION_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CharacterStringFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/DatabaseEntityCodeGeneration/DatabaseEntityCodeGenerationFwd.h"

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(CodeHeaderFileGenerationImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE CodeHeaderFileGeneration final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CodeHeaderFileGeneration);

        using String = System::String;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;

    public:
        CodeHeaderFileGeneration(const String& fileName, const CodeEntityAnalysis& codeEntityAnalysis, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetContent() const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_HEADER_FILE_GENERATION_HA
