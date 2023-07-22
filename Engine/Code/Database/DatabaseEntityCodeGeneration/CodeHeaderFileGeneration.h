///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/02 20:05)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_HEADER_FILE_GENERATION_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_HEADER_FILE_GENERATION_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
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

    public:
        CodeHeaderFileGeneration(const String& fileName, const CodeEntityAnalysis& codeEntityAnalysis, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetContent() const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_HEADER_FILE_GENERATION_HA