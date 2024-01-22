/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:50)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_CLASS_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_CLASS_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/DatabaseEntityCodeGeneration/DatabaseEntityCodeGenerationFwd.h"

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(CodeEntityClassImpl);

#include <vector>

namespace Database
{
    class DATABASE_DEFAULT_DECLARE CodeEntityClass final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CodeEntityClass);

        using String = System::String;
        using FieldContainer = std::vector<CodeEntity>;
        using FieldContainerConstIter = FieldContainer::const_iterator;

    public:
        CodeEntityClass(const String& entityClassName, const String& databaseName, const FieldContainer& codeEntity);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetEntityClassName() const;
        NODISCARD String GetDatabaseName() const;
        NODISCARD String GetKeyType() const;
        NODISCARD String GetKeyName() const;

        NODISCARD FieldContainerConstIter begin() const noexcept;
        NODISCARD FieldContainerConstIter end() const noexcept;
        NODISCARD int GetSize() const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_CLASS_H
