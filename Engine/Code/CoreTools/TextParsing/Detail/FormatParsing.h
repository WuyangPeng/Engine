/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 18:05)

#ifndef CORE_TOOLS_TEXT_PARSING_FORMAT_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_FORMAT_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

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

        NODISCARD static Element GetElement(const String& column);
        NODISCARD static Element SplitEqualSign(const String& single);
        NODISCARD static bool IsInterval(const String& single) noexcept;

    private:
        String key;
        Mapping mapping;
        Scope scope;
        DefaultValue defaultValue;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_FORMAT_PARSING_H