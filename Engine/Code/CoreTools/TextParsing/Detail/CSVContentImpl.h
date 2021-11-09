///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/29 10:42)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CONTENT_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CONTENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/EnumCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVContentImpl final
    {
    public:
        using ClassType = CSVContentImpl;
        using String = System::String;

    public:
        explicit CSVContentImpl(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CSVHead GetCSVHead() const;
        NODISCARD int GetCount() const;
        NODISCARD String GetContent(int index) const;
        NODISCARD String GetCSVClassName() const;

    private:
        using FileContent = std::vector<String>;

    private:
        void Parsing();

    private:
        String fileName;
        FileContent fileContent;

        static constexpr auto fileHeaderSize = System::EnumCastUnderlying<decltype(fileContent.size())>(CSVType::VariableName);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CONTENT_IMPL_H