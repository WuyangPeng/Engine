///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:07)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTAINER_FUNCTION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CONTAINER_FUNCTION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ContainerFunctionParsing : public Parsing
    {
    public:
        using ClassType = ContainerFunctionParsing;
        using ParentType = Parsing;
        using ContainerFunctionParsingUniquePtr = std::unique_ptr<ClassType>;

    public:
        NODISCARD static ContainerFunctionParsingUniquePtr Create(const CSVHead& csvHead, const String& keyTypeDescribe);

    protected:
        ContainerFunctionParsing(CSVHead csvHead, String keyTypeDescribe) noexcept;

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual String GenerateGetFunction() const = 0;
        NODISCARD String GenerateParsing() const;

    protected:
        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD String GetKeyTypeDescribe() const;

        NODISCARD String GenerateBaseGetFirst() const;
        NODISCARD String GenerateGetContainer() const;

        NODISCARD String GenerateBaseGetFirstTemplate() const;
        NODISCARD String GenerateBaseGetTemplate() const;

        NODISCARD String GenerateBaseGet() const;

    private:
        String keyTypeDescribe;
        CSVHead head;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTAINER_FUNCTION_PARSING_H