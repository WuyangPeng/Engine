///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/11/04 15:59)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSVHead.h"
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
        NODISCARD String GenerateBaseGetFunction(int index) const;
        NODISCARD String GenerateChildGetFunction(int index) const;
        NODISCARD String GenerateGetKeyFunction() const;
        NODISCARD String GenerateGetFunction(int index) const;

        NODISCARD String GenerateDefaultContainerFunction() const;
        NODISCARD String GenerateVectorContainerFunction() const;
        NODISCARD String GenerateMapContainerFunction() const;
        NODISCARD String GenerateKeyContainerFunction() const;
        NODISCARD String GenerateUniqueContainerFunction() const;

    private:
        CSVHead csvHead;
        String keyTypeDescribe;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_H