///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:33)

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