///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/02 10:56)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_HEAD_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_HEAD_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateHead
    {
    public:
        using ClassType = CSVGenerateHead;
        using String = System::String;

    public:
        explicit CSVGenerateHead(const CSVHead& csvHead, const String& suffix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateCoreToolsHead() const;
        NODISCARD String GenerateCoreToolsChildHead() const;
        NODISCARD String GenerateVectorHead() const;
        NODISCARD String GenerateContainerHead() const;
        NODISCARD String GenerateContainerDetailHead() const;
        NODISCARD String GenerateBaseSourceHead() const;
        NODISCARD String GenerateSourceHead() const;
        NODISCARD String GenerateContainerSourceHead() const;
        NODISCARD String GenerateEnumSourceHead() const;
        NODISCARD String GenerateEnumHead() const;

    private:
        NODISCARD String GenerateCoreToolsShareHead() const;
        NODISCARD std::set<String> GetMappingHead() const;

    private:
        CSVHead csvHead;
        String suffix;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_HEAD_H