///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 15:51)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(CodeEntityImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE CodeEntity final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CodeEntity);

        using String = System::String;

    public:
        CodeEntity(const String& fieldName, const String& dataType, const String& indexType);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFieldName() const;
        NODISCARD String GetDataType() const;
        NODISCARD String GetIndexType() const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_H
