///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:52)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_HEADER_FILE_GENERATION_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_HEADER_FILE_GENERATION_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CharacterStringFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/DatabaseEntityCodeGeneration/DatabaseEntityCodeGenerationFwd.h"

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(EntityHeaderFileGenerationImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE EntityHeaderFileGeneration final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(EntityHeaderFileGeneration);

        using String = System::String;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;

    public:
        EntityHeaderFileGeneration(const String& fileName, const String& namespaceName, const CodeEntityClass& codeEntityClass, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetContent() const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_HEADER_FILE_GENERATION_H
