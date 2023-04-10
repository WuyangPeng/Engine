///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:09)

#ifndef CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerDefaultFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MapContainerDefaultFunctionDefinitionParsing final : public ContainerDefaultFunctionDefinitionParsing
    {
    public:
        using ClassType = MapContainerDefaultFunctionDefinitionParsing;
        using ParentType = ContainerDefaultFunctionDefinitionParsing;

    public:
        explicit MapContainerDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD String GenerateContainerAddDataDefinition() const override;

        NODISCARD String GenerateLog() const;

        NODISCARD String GenerateCreateSharedPtr() const;
        NODISCARD String GenerateEmplaceSharedPtr() const;
        NODISCARD String GenerateGetKey() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H