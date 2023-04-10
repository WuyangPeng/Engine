///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:10)

#ifndef CORE_TOOLS_TEXT_PARSING_UNIQUE_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_UNIQUE_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerDefaultFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UniqueContainerDefaultFunctionDefinitionParsing : public ContainerDefaultFunctionDefinitionParsing
    {
    public:
        using ClassType = UniqueContainerDefaultFunctionDefinitionParsing;
        using ParentType = ContainerDefaultFunctionDefinitionParsing;

    public:
        explicit UniqueContainerDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD String GenerateContainerAddDataDefinition() const override;

        NODISCARD String GenerateZero() const;
        NODISCARD String GenerateSizeZero() const;
        NODISCARD String GenerateContainerZero() const;

        NODISCARD String GenerateMany() const;
        NODISCARD String GenerateSizeGreaterOne() const;

        NODISCARD String GenerateCreate() const;

        NODISCARD String GenerateCSVRowZeroInit() const;
        NODISCARD String GenerateMakeShared() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_UNIQUE_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H