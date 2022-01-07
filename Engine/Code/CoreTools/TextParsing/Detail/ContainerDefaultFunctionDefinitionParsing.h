///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:15)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "DefaultFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ContainerDefaultFunctionDefinitionParsing : public DefaultFunctionDefinitionParsing
    {
    public:
        using ClassType = ContainerDefaultFunctionDefinitionParsing;
        using ParentType = DefaultFunctionDefinitionParsing;
        using ContainerDefaultFunctionDefinitionParsingSharedPtr = std::shared_ptr<ContainerDefaultFunctionDefinitionParsing>;

        NODISCARD static ContainerDefaultFunctionDefinitionParsingSharedPtr Create(const CSVHead& csvHead, const String& className);

    protected:
        explicit ContainerDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateContainerDefaultFunctionDefinition() const;
        NODISCARD String GenerateContainerParsingFunctionDefinition() const;

    protected:
        NODISCARD String GenerateLoop() const;
        NODISCARD String GenerateCSVRowInit() const;
        NODISCARD String GenerateEmplaceBack() const;
        NODISCARD String GenerateSort() const;
        NODISCARD String GenerateReturnKeyLess() const;
        NODISCARD String GenerateReturnKeyEqual() const;
        NODISCARD String GenerateLambdaEnd() const;
        NODISCARD String GenerateUnique() const;
        NODISCARD String GenerateIfIter() const;
        NODISCARD String GenerateWarnLog(int addIndentationCount) const;
        NODISCARD String GenerateRepeatKey(int addIndentationCount, StringView repeatKey) const;
        NODISCARD String GenerateLogAssert(int addIndentationCount) const;
        NODISCARD String GenerateEraseIter() const;

        NODISCARD String GetLowerClassName() const;

        NODISCARD String GenerateInit() const;

    private:
        NODISCARD virtual String GenerateContainerAddDataDefinition() const = 0;

        NODISCARD String GenerateContainerMember() const;
        NODISCARD String GenerateContainerParsing() const;
        NODISCARD String GenerateContainerParsingFunction() const;
        NODISCARD String GenerateContainerSize() const;

    private:
        String lowerClassName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTAINER_DEFAULT_FUNCTION_DEFINITION_PARSING_H