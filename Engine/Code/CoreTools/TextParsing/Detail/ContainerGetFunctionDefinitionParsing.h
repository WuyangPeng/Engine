///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:17)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "GetFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ContainerGetFunctionDefinitionParsing : public GetFunctionDefinitionParsing
    {
    public:
        using ClassType = ContainerGetFunctionDefinitionParsing;
        using ParentType = GetFunctionDefinitionParsing;
        using ContainerGetFunctionDefinitionParsingSharedPtr = std::shared_ptr<ContainerGetFunctionDefinitionParsing>;

        NODISCARD static ContainerGetFunctionDefinitionParsingSharedPtr Create(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe);

    protected:
        ContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD String GenerateGetFirstDefinition(const String& lowerClassName) const;
        NODISCARD String GenerateGetContainerDefinition(const String& lowerClassName, const StringView& containerName) const;

        NODISCARD String GenerateLambdaFunctionInit() const;
        NODISCARD String GenerateLambdaFunctionFind(const String& lowerClassName) const;
        NODISCARD String GenerateLambdaFunctionResult(const String& lowerClassName) const;

        NODISCARD String GenerateLambdaFunctionThrowException(const String& lowerClassName) const;

    private:
        NODISCARD String GenerateGetFirstFunction() const;
        NODISCARD String GenerateGetReturnFirst(const String& lowerClassName) const;
        NODISCARD String GenerateGetContainerFunction(const StringView& containerName) const;
        NODISCARD String GenerateReturnContainer(const String& lowerClassName) const;

        NODISCARD String GenerateLambdaFunctionResultJudge(const String& lowerClassName) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTAINER_GET_FUNCTION_DEFINITION_PARSING_H