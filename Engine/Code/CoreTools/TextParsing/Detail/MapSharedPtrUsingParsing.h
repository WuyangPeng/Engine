///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:34)

#ifndef CORE_TOOLS_TEXT_PARSING_MAP_SHARED_PTR_USING_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_MAP_SHARED_PTR_USING_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "SharedPtrUsingParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MapSharedPtrUsingParsing final : public SharedPtrUsingParsing
    {
    public:
        using ClassType = MapSharedPtrUsingParsing;
        using ParentType = SharedPtrUsingParsing;

    public:
        explicit MapSharedPtrUsingParsing(int indentationCount, const String& className, const String& keyTypeDescribe, StringView mappingName);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateSharedPtrUsing() const final;

    private:
        String keyTypeDescribe;
        StringView mappingName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_MAP_SHARED_PTR_USING_PARSING_H