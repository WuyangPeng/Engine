///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:11)

#ifndef CORE_TOOLS_TEXT_PARSING_VECTOR_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_VECTOR_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerDefaultFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE VectorContainerDefaultFunctionDefinitionParsing : public ContainerDefaultFunctionDefinitionParsing
    {
    public:
        using ClassType = VectorContainerDefaultFunctionDefinitionParsing;
        using ParentType = ContainerDefaultFunctionDefinitionParsing;

    public:
        explicit VectorContainerDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD String GenerateContainerAddDataDefinition() const override;

        NODISCARD String GenerateFind() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_VECTOR_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H