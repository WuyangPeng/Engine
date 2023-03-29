///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 11:01)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_DEFINITION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_DEFINITION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateDefaultFunctionDefinition final
    {
    public:
        using ClassType = CSVGenerateDefaultFunctionDefinition;
        using String = System::String;

    public:
        explicit CSVGenerateDefaultFunctionDefinition(const CSVHead& csvHead, const String& suffix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateBaseDefaultFunctionDefinition() const;
        NODISCARD String GenerateChildDefaultFunctionDefinition() const;
        NODISCARD String GenerateDefaultFunctionDefinition() const;
        NODISCARD String GenerateContainerDefaultFunctionDefinition() const;

    private:
        CSVHead csvHead;
        String suffix;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_DEFINITION_H