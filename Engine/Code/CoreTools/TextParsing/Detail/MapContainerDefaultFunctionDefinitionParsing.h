///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:34)

#ifndef CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerDefaultFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MapContainerDefaultFunctionDefinitionParsing : public ContainerDefaultFunctionDefinitionParsing
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