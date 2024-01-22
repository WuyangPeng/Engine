/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:41)

#ifndef CORE_TOOLS_TEXT_PARSING_FORMAT_TYPE_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_FORMAT_TYPE_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FormatTypeParsing final
    {
    public:
        using ClassType = FormatTypeParsing;

        using String = System::String;

    public:
        explicit FormatTypeParsing(const String& formatTypeContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CSVFormatType GetCSVFormatType() const noexcept;

    private:
        void Parsing(const String& formatTypeContent);

    private:
        CSVFormatType formatType;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_FORMAT_TYPE_PARSING_H