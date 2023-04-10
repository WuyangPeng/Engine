///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:08)

#ifndef CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerDefaultFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DefaultContainerDefaultFunctionDefinitionParsing final : public ContainerDefaultFunctionDefinitionParsing
    {
    public:
        using ClassType = DefaultContainerDefaultFunctionDefinitionParsing;
        using ParentType = ContainerDefaultFunctionDefinitionParsing;

    public:
        explicit DefaultContainerDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD String GenerateContainerAddDataDefinition() const override;

        NODISCARD String GenerateFind() const;
        NODISCARD String GenerateLog() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H