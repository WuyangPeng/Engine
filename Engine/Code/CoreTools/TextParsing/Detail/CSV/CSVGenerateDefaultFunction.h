///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:02)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateDefaultFunction final
    {
    public:
        using ClassType = CSVGenerateDefaultFunction;
        using String = System::String;

    public:
        explicit CSVGenerateDefaultFunction(const CSVHead& csvHead, const String& suffix, const String& keyTypeDescribe);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateBaseDefaultFunction() const;
        NODISCARD String GenerateChildDefaultFunction() const;
        NODISCARD String GenerateDefaultFunction() const;
        NODISCARD String GenerateContainerDefaultFunction() const;

    private:
        CSVHead csvHead;
        String suffix;
        String keyTypeDescribe;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_H