///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:20)

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