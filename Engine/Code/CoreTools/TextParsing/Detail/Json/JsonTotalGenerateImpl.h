///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 11:08)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <map>
#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonTotalGenerateImpl
    {
    public:
        using ClassType = JsonTotalGenerateImpl;
        using String = System::String;
        using FactoryType = JsonTotalGenerateFactory;
        using JsonHeadContainer = std::vector<JsonHead>;

    public:
        JsonTotalGenerateImpl(String nameSpace, JsonHeadContainer jsonHeadContainer) noexcept;
        virtual ~JsonTotalGenerateImpl() noexcept = default;
        JsonTotalGenerateImpl(const JsonTotalGenerateImpl& rhs) = default;
        JsonTotalGenerateImpl& operator=(const JsonTotalGenerateImpl& rhs) = default;
        JsonTotalGenerateImpl(JsonTotalGenerateImpl&& rhs) noexcept = default;
        JsonTotalGenerateImpl& operator=(JsonTotalGenerateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void GenerateFile(const String& directory) const;

    protected:
        NODISCARD static String GenerateCopyright();
        NODISCARD static String GenerateNewLine();
        NODISCARD String GenerateHeaderGuard() const;
        NODISCARD String GenerateContainerHeaderGuard() const;
        NODISCARD String GenerateHeaderGuardEndif() const;

        NODISCARD String GenerateHead() const;
        NODISCARD static String GenerateFwdHead();
        NODISCARD String GenerateContainerHead() const;
        NODISCARD String GenerateContainerSourceHead() const;
        NODISCARD String GenerateNameSpace() const;
        NODISCARD String GenerateFwd() const;
        NODISCARD String GenerateContainerClassName() const;
        NODISCARD String GenerateContainerDefaultFunction() const;
        NODISCARD String GenerateContainerDefaultFunctionDefinition() const;
        NODISCARD String GenerateContainerFunction() const;
        NODISCARD String GenerateContainerFunctionDefinition() const;
        NODISCARD String GenerateContainerMember() const;

    private:
        using EnumType = std::set<String>;
        using DataType = std::map<String, JsonHead>;
        using ClassNameType = std::set<String>;

    private:
        NODISCARD static String GetOldContent(const String& fileName);

        NODISCARD static String GenerateEnumHead(const EnumType& enumType);
        NODISCARD static String GenerateDataHead(const DataType& dataType);

        NODISCARD static String GenerateEnumFwd(const EnumType& enumType);
        NODISCARD String GenerateDataFwd(const DataType& dataType) const;

        NODISCARD virtual String GetFileSuffix() const = 0;
        NODISCARD virtual String GetContent() const = 0;

        NODISCARD static ClassNameType GetClassNameType(const JsonNode& jsonNode);
        NODISCARD String GenerateInnerNameSpaceBegin(const JsonHead& jsonHead) const;
        NODISCARD String GenerateInnerNameSpaceEnd() const;

    private:
        String nameSpace;
        JsonHeadContainer jsonHeadContainer;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_IMPL_H