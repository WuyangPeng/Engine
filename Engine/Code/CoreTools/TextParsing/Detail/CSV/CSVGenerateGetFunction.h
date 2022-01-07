///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 11:50)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateGetFunction final
    {
    public:
        using ClassType = CSVGenerateGetFunction;
        using String = System::String;

    public:
        explicit CSVGenerateGetFunction(const CSVHead& csvHead, const String& keyTypeDescribe);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateBaseGetFunction() const;
        NODISCARD String GenerateChildGetFunction() const;
        NODISCARD String GenerateGetFunction() const;
        NODISCARD String GenerateContainerFunction() const;

    private:
        CSVHead csvHead;
        String keyTypeDescribe;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_H