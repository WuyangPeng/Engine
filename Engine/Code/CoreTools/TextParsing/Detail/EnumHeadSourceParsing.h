///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:09)

#ifndef CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_SOURCE_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_SOURCE_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnumHeadSourceParsing final : public Parsing
    {
    public:
        using ClassType = EnumHeadSourceParsing;
        using ParentType = Parsing;
        using StringView = System::StringView;

    public:
        EnumHeadSourceParsing(CSVHead csvHead, CSVContent csvContent, String className) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateEnumFunctionDefinition() const;

    private:
        CSVHead csvHead;
        CSVContent csvContent;
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_SOURCE_PARSING_H