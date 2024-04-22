/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:52)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <map>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateImpl;
        using FactoryType = CSVGenerateFactory;

        using String = System::String;
        using StringView = System::StringView;

    public:
        CSVGenerateImpl(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept;
        virtual ~CSVGenerateImpl() noexcept = default;
        CSVGenerateImpl(const CSVGenerateImpl& rhs) noexcept = default;
        CSVGenerateImpl& operator=(const CSVGenerateImpl& rhs) noexcept = default;
        CSVGenerateImpl(CSVGenerateImpl&& rhs) noexcept = default;
        CSVGenerateImpl& operator=(CSVGenerateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void GenerateFile(const String& codeDirectory, const String& directory) const;

    protected:
        using CSVDataTypeIndex = std::pair<CSVDataType, CSVDataType>;
        using HeadContent = std::pair<CSVDataTypeIndex, StringView>;
        using HeadContentContainer = std::vector<HeadContent>;
        using ReplaceType = std::map<StringView, StringView>;

    protected:
        NODISCARD static String GetOldContent(const String& fileName);

        NODISCARD String GetCSVClassName() const;
        NODISCARD CSVFormatType GetCSVFormatType() const noexcept;
        NODISCARD bool IsCSVFormatTypeMap() const noexcept;
        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD bool HasDataType(CSVDataType csvDataType) const;
        NODISCARD bool HasMapping() const noexcept;
        NODISCARD bool HasVectorArrayDataType() const;
        NODISCARD bool HasArrayDataType() const;
        NODISCARD bool HasScope() const noexcept;

        NODISCARD String GetKeyTypeDescribe() const;
        NODISCARD String GetKey() const;

        NODISCARD CodeMappingAnalysis GetCodeMappingAnalysis() const noexcept;
        NODISCARD String GetCodeMappingElement(const String& codeKey) const;
        NODISCARD String GetNameSpace() const;
        NODISCARD static const HeadContentContainer& GetHeadContentContainer();

        NODISCARD static String GetTemplateContent(const String& fileName);
        NODISCARD String ReplaceTemplate(const String& content) const;
        NODISCARD static String GetCodeKey(const String& codeKey);

        NODISCARD static String GetReplaceContent(const String& data, StringView codeKey, StringView name);
        NODISCARD static String GetReplaceContent(const String& data, const ReplaceType& replace);

        NODISCARD static String GetElementIsNoexceptReplace(CSVDataType csvDataType);
        NODISCARD static String GetSmallElementTypeReplace(const String& valueType);
        NODISCARD static String GetElementTypeReplace(CSVDataType csvDataType, const String& abbreviation, const String& actualType);

        NODISCARD String GetDataIncludeContent(const String& codeKey) const;
        NODISCARD String GetDataIncludeContent(const String& dataInclude, CSVDataType first, CSVDataType second, StringView vectorName) const;
        NODISCARD String GetBaseClassUsingHasMappingContent() const;
        NODISCARD String GetBaseClassUsingHasMappingContent(int index) const;

    private:
        NODISCARD virtual String GetSuffix() const = 0;
        NODISCARD virtual String GetFilePrefix() const = 0;
        NODISCARD virtual String GetFileSuffix() const = 0;
        NODISCARD virtual String GetContent(const String& codeDirectory) const = 0;

    private:
        CSVHead csvHead;
        CodeMappingAnalysis codeMappingAnalysis;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_IMPL_H