///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:03)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

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
        NODISCARD String GenerateStringCastEnumFunction() const;

    private:
        CSVHead csvHead;
        String keyTypeDescribe;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_H