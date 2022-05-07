///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:15)

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
        ContainerFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe);

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
        CSVHead m_CSVHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTAINER_FUNCTION_PARSING_H