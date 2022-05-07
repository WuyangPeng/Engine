///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:49)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateDefaultFunction final
    {
    public:
        using ClassType = CSVGenerateDefaultFunction;
        using String = System::String;

    public:
        explicit CSVGenerateDefaultFunction(const CSVHead& csvHead, const String& suffix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateBaseDefaultFunction() const;
        NODISCARD String GenerateChildDefaultFunction() const;
        NODISCARD String GenerateDefaultFunction() const;
        NODISCARD String GenerateContainerDefaultFunction() const;

    private:
        CSVHead csvHead;
        String suffix;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_H