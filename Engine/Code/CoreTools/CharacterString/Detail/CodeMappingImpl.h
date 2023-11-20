///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/08 10:14)

#ifndef CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_IMPL_H
#define CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <map>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CodeMappingImpl final
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

#endif  // CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_IMPL_H
