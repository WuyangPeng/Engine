///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:32)

#ifndef CORE_TOOLS_TEXT_PARSING_FORMAT_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_FORMAT_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FormatParsing final
    {
    public:
        using ClassType = FormatParsing;
        using String = System::String;
        using FileContent = std::vector<String>;

    public:
        explicit FormatParsing(const FileContent& fileContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetKey() const;
        NODISCARD String GetMapping(int index) const;
        NODISCARD bool HasMapping() const noexcept;
        NODISCARD String GetScope(int index) const;
        NODISCARD bool HasScope() const noexcept;
        NODISCARD String GetDefaultValue(int index) const;

    private:
        using Mapping = std::vector<String>;
        using Scope = std::vector<String>;
        using DefaultValue = std::vector<String>;
        using Element = std::vector<String>;

    private:
        void Parsing(const FileContent& fileContent);
        void Parsing(const String& formatContent);
        void ParsingColumn(const String& column, bool firstIndex);

        void EmplaceBackEmpty(bool isScope, bool isMapping, bool isDefaultValue);
        void ParsingMapping(bool isMapping, bool firstIndex, const String& single);
        void ParsingDefaultValue(bool isDefaultValue, bool firstIndex, const String& single);
        void ParsingScope(bool isScope, const String& single);
        void ParsingKey(const String& single);

        NODISCARD Element GetElement(const String& column) const;
        NODISCARD Element SplitEqualSign(const String& single) const;
        NODISCARD bool IsInterval(const String& single) const noexcept;

    private:
        String key;
        Mapping mapping;
        Scope scope;
        DefaultValue defaultValue;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_FORMAT_PARSING_H