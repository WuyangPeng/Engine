///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:17)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTAINER_GET_FUNCTION_DETAIL_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CONTAINER_GET_FUNCTION_DETAIL_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "GetFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ContainerGetFunctionDetailDefinitionParsing : public GetFunctionDefinitionParsing
    {
    public:
        using ClassType = ContainerGetFunctionDetailDefinitionParsing;
        using ParentType = GetFunctionDefinitionParsing;
        using ContainerGetFunctionDetailDefinitionParsingSharedPtr = std::shared_ptr<ContainerGetFunctionDetailDefinitionParsing>;

        NODISCARD static ContainerGetFunctionDetailDefinitionParsingSharedPtr Create(const CSVHead& csvHead, const String& className);

    protected:
        ContainerGetFunctionDetailDefinitionParsing(const CSVHead& csvHead, const String& className);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateGetFunctionDefinition() const final;

    protected:
        NODISCARD String GenerateFindIf(const String& lowerClassName) const;
        NODISCARD String GenerateIterIf(const String& lowerClassName) const;
        NODISCARD String GenerateThrowException(const String& lowerClassName) const;

        NODISCARD String GenerateLoopInit(const String& lowerClassName) const;

    private:
        NODISCARD String GenerateGetFirstFunction(const String& lowerClassName) const;
        NODISCARD String GenerateGetFunction(const String& lowerClassName) const;

        NODISCARD String GenerateGetContainer() const;
        NODISCARD String GenerateGetFindResult(const String& lowerClassName) const;

        NODISCARD String GenerateContainerInit() const;
        NODISCARD String GenerateReturnResult() const;

        NODISCARD virtual String GenerateGetFirstContainer() const = 0;
        NODISCARD virtual String GenerateFind(const String& lowerClassName) const = 0;
        NODISCARD virtual String GenerateEmplaceBack() const = 0;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTAINER_GET_FUNCTION_DETAIL_DEFINITION_PARSING_H