///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:31)

#ifndef CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_SOURCE_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_SOURCE_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnumHeadSourceParsing final : public Parsing
    {
    public:
        using ClassType = EnumHeadSourceParsing;
        using ParentType = Parsing;
        using StringView = System::StringView;

    public:
        EnumHeadSourceParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateEnumFunctionDefinition() const;

    private:
        CSVHead csvHead;
        CSVContent csvContent;
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_SOURCE_PARSING_H