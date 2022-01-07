///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:34)

#ifndef CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerGetFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MapContainerGetFunctionDefinitionParsing final : public ContainerGetFunctionDefinitionParsing
    {
    public:
        using ClassType = MapContainerGetFunctionDefinitionParsing;
        using ParentType = ContainerGetFunctionDefinitionParsing;

    public:
        MapContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe);

    public:
        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunctionDefinition() const final;

    private:
        NODISCARD String GenerateGetMapFirstDefinition(const String& lowerClassName) const;
        NODISCARD String GenerateGetMapDefinition(const String& lowerClassName) const;

        NODISCARD String GenerateGetFirstFunction() const;
        NODISCARD String GenerateGetMapReturnFirst(const String& lowerClassName) const;

        NODISCARD String GenerateIfEmpty(const String& lowerClassName) const;
        NODISCARD String GenerateThrowException(const String& lowerClassName) const;
        NODISCARD String GenerateReturnBegin(const String& lowerClassName) const;

        NODISCARD String GenerateGetFunction() const;
        NODISCARD String GenerateMapFind(const String& lowerClassName) const;
        NODISCARD String GenerateIterFind(const String& lowerClassName) const;
        NODISCARD String GenerateFindJudge(const String& lowerClassName) const;
        NODISCARD String GenerateMapFindDefinition(const String& lowerClassName) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H