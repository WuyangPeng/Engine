///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:49)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CLASS_NAME_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CLASS_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
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

    private:
        CSVHead csvHead;
        String suffix;
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CLASS_NAME_H