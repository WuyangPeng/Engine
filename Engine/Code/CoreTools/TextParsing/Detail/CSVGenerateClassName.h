///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/11/02 10:56)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CLASS_NAME_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CLASS_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateClassName final
    {
    public:
        using ClassType = CSVGenerateClassName;
        using String = System::String;

    public:
        explicit CSVGenerateClassName(const CSVHead& csvHead, const String& suffix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateParentClassName() const;
        NODISCARD String GenerateChildClassName() const;
        NODISCARD String GenerateClassName() const;
        NODISCARD String GenerateContainerClassName(const String& keyTypeDescribe) const;
        NODISCARD String GenerateEnumClassName() const;

    private:
        NODISCARD String GenerateSharedPtrUsing(const String& keyTypeDescribe) const;
        NODISCARD String GenerateSharedPtr(const String& prefix) const;
        NODISCARD String GenerateSharedPtrContainer(const String& prefix) const;
        NODISCARD String GenerateSharedPtrMappingContainer(const String& keyTypeDescribe, const String& mappingName) const;

    private:
        CSVHead csvHead;
        String suffix;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CLASS_NAME_H