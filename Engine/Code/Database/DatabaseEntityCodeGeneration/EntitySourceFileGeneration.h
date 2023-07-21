///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 20:05)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_SOURCE_FILE_GENERATION_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_SOURCE_FILE_GENERATION_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/DatabaseEntityCodeGeneration/DatabaseEntityCodeGenerationFwd.h"

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(EntitySourceFileGenerationImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE EntitySourceFileGeneration final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(EntitySourceFileGeneration);

        using String = System::String;

    public:
        EntitySourceFileGeneration(const String& fileName, const String& namespaceName, const CodeEntityClass& codeEntityClass, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetContent() const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_ENTITY_SOURCE_FILE_GENERATION_H
