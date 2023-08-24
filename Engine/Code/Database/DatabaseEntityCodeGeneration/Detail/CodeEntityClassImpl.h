///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 15:50)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_CLASS_IMPL_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_CLASS_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/DatabaseEntityCodeGeneration/CodeEntity.h"

#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE CodeEntityClassImpl final
    {
    public:
        using ClassType = CodeEntityClassImpl;

        using String = System::String;
        using FieldContainer = std::vector<CodeEntity>;
        using FieldContainerConstIter = FieldContainer::const_iterator;

    public:
        CodeEntityClassImpl(String entityClassName, String databaseName, FieldContainer codeEntity);

        NODISCARD bool IsValid() const noexcept;

        NODISCARD String GetEntityClassName() const;
        NODISCARD String GetDatabaseName() const;
        NODISCARD String GetKeyType() const;
        NODISCARD String GetKeyName() const;

        NODISCARD FieldContainerConstIter GetBegin() const noexcept;
        NODISCARD FieldContainerConstIter GetEnd() const noexcept;

        NODISCARD int GetSize() const;

    private:
        String entityClassName;
        String databaseName;
        FieldContainer codeEntity;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_CLASS_IMPL_H
