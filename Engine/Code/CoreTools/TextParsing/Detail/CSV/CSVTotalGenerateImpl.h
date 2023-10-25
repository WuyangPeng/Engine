///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/09 13:58)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <map>
#include <set>

namespace CoreTools
{

    class CORE_TOOLS_HIDDEN_DECLARE CSVTotalGenerateImpl
    {
    public:
        using ClassType = CSVTotalGenerateImpl;

        using String = System::String;
        using FactoryType = CSVTotalGenerateFactory;
        using CSVHeadContainer = std::vector<CSVHead>;

    public:
        CSVTotalGenerateImpl(String nameSpace, CSVHeadContainer csvHeadContainer, CodeMappingAnalysis codeMappingAnalysis) noexcept;
        virtual ~CSVTotalGenerateImpl() noexcept = default;
        CSVTotalGenerateImpl(const CSVTotalGenerateImpl& rhs) = default;
        CSVTotalGenerateImpl& operator=(const CSVTotalGenerateImpl& rhs) = default;
        CSVTotalGenerateImpl(CSVTotalGenerateImpl&& rhs) noexcept = default;
        CSVTotalGenerateImpl& operator=(CSVTotalGenerateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void GenerateFile(const String& codeDirectory, const String& directory) const;

    protected:
        using EnumType = std::set<String>;
        using DataType = std::map<String, CSVHead>;

    protected:
        NODISCARD CodeMappingAnalysis GetCodeMappingAnalysis() const noexcept;
        NODISCARD String GetNameSpace() const;
        NODISCARD CSVHeadContainer GetCSVHeadContainer() const;

        NODISCARD static String GetTemplateContent(const String& fileName);
        NODISCARD String ReplaceTemplate(const String& content) const;

    private:
        NODISCARD static String GetOldContent(const String& fileName);

        NODISCARD virtual String GetFileSuffix() const = 0;
        NODISCARD virtual String GetContent(const String& codeDirectory) const = 0;

    private:
        String nameSpace;
        CSVHeadContainer csvHeadContainer;
        CodeMappingAnalysis codeMappingAnalysis;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_IMPL_H