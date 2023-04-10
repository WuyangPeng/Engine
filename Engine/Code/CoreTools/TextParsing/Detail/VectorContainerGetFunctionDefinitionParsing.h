///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:11)

#ifndef CORE_TOOLS_TEXT_PARSING_VECTOR_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_VECTOR_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerGetFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE VectorContainerGetFunctionDefinitionParsing final : public ContainerGetFunctionDefinitionParsing
    {
    public:
        using ClassType = VectorContainerGetFunctionDefinitionParsing;
        using ParentType = ContainerGetFunctionDefinitionParsing;

    public:
        VectorContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe);

    public:
        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunctionDefinition() const override;

    private:
        NODISCARD String GenerateGetDefinition(const String& lowerClassName) const;
        NODISCARD String GenerateGetAllContainerDefinition(const String& lowerClassName) const;

        NODISCARD String GenerateGetFunction() const;
        NODISCARD String GenerateEqualRange(const String& lowerClassName) const;
        NODISCARD String GenerateFindResult(const String& lowerClassName) const;
        NODISCARD String GenerateReturnRangeFirst() const;
        NODISCARD String GenerateRangeFirst(const String& lowerClassName) const;

        NODISCARD String GenerateGetContainerFunction() const;
        NODISCARD String GenerateReturnContainer() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_VECTOR_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H