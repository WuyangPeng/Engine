///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:08)

#ifndef CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerGetFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DefaultContainerGetFunctionDefinitionParsing final : public ContainerGetFunctionDefinitionParsing
    {
    public:
        using ClassType = DefaultContainerGetFunctionDefinitionParsing;
        using ParentType = ContainerGetFunctionDefinitionParsing;

    public:
        DefaultContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe);

    public:
        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunctionDefinition() const override;

    private:
        NODISCARD String GenerateGetDefinition(const String& lowerClassName) const;

        NODISCARD String GenerateGetFunction() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H