///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:08)

#ifndef CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_GET_FUNCTION_DETAIL_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_GET_FUNCTION_DETAIL_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerGetFunctionDetailDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DefaultContainerGetFunctionDetailDefinitionParsing final : public ContainerGetFunctionDetailDefinitionParsing
    {
    public:
        using ClassType = DefaultContainerGetFunctionDetailDefinitionParsing;
        using ParentType = ContainerGetFunctionDetailDefinitionParsing;

    public:
        DefaultContainerGetFunctionDetailDefinitionParsing(const CSVHead& csvHead, const String& className);

    public:
        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GenerateGetFirstContainer() const override;
        NODISCARD String GenerateFind(const String& lowerClassName) const override;
        NODISCARD String GenerateEmplaceBack() const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_GET_FUNCTION_DETAIL_DEFINITION_PARSING_H