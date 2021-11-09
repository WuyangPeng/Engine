///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/04 23:08)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_DEFINITION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_DEFINITION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateGetFunctionDefinition final
    {
    public:
        using ClassType = CSVGenerateGetFunctionDefinition;
        using String = System::String;

    public:
        explicit CSVGenerateGetFunctionDefinition(const CSVHead& csvHead, const String& suffix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateBaseGetFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateGetFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateContainerFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateContainerDetailDefinition() const;
        NODISCARD String GenerateStringCastEnumDefinition() const;

    private:
        NODISCARD String GenerateBaseGetFunctionDefinition(int index) const;
        NODISCARD String GenerateBaseGetFunctionReturnDefinition(CSVDataType dataType, const String& actualType) const;
        NODISCARD String GenerateBaseGetFunctionArrayDefinition(int index) const;
        NODISCARD String GenerateBaseGetFunctionMappingDefinition(int index) const;

        NODISCARD String GenerateGetFunctionDefinition(int index) const;
        NODISCARD String GenerateGetFunctionArrayDefinition(int index) const;
        NODISCARD String GenerateGetFunctionMappingDefinition(int index) const;

        NODISCARD String GenerateUserClassIsValidConst() const;

        NODISCARD String GenerateDefaultContainerFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateVectorContainerFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateMapContainerFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateKeyContainerFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateUniqueContainerFunctionDefinition() const;

        NODISCARD String GenerateDefaultContainerDetailDefinition() const;
        NODISCARD String GenerateMapContainerDetailDefinition() const;

    private:
        CSVHead csvHead;
        String suffix;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_DEFINITION_H