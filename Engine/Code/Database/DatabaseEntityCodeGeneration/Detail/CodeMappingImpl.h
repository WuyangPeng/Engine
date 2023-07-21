///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 18:10)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_IMPL_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_IMPL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <map>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE CodeMappingImpl final
    {
    public:
        using ClassType = CodeMappingImpl;

        using String = System::String;

    public:
        CodeMappingImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Insert(const String& codeKey, const String& element);
        NODISCARD String GetElement(const String& codeKey) const;

    private:
        using MappingType = std::map<String, String>;

    private:
        MappingType codeMapping;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_IMPL_H
