///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 09:18)

#ifndef CORE_TOOLS_TEXT_PARSING_KEY_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_KEY_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerGetFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE KeyContainerGetFunctionDefinitionParsing final : public ContainerGetFunctionDefinitionParsing
    {
    public:
        using ClassType = KeyContainerGetFunctionDefinitionParsing;
        using ParentType = ContainerGetFunctionDefinitionParsing;

    public:
        KeyContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe);

    public:
        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunctionDefinition() const override;

    private:
        NODISCARD String GenerateGetKeyDefinition() const;
        NODISCARD String GenerateGetDefinition(const String& lowerClassName) const;

        NODISCARD String GenerateGetKeyFunction() const;
        NODISCARD String GenerateReturnGenerateKey() const;

        NODISCARD String GenerateGetFunction() const;
        NODISCARD String GenerateGetKeyFunctionList() const;
        NODISCARD String GenerateGetKeyFunctionCall() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_KEY_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H