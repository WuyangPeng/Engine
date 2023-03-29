///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 10:47)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CLASS_NAME_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CLASS_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateClassName final
    {
    public:
        using ClassType = CSVGenerateClassName;
        using String = System::String;

    public:
        explicit CSVGenerateClassName(const CSVHead& csvHead, const String& suffix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateParentClassName() const;
        NODISCARD String GenerateChildClassName() const;
        NODISCARD String GenerateClassName() const;
        NODISCARD String GenerateContainerClassName(const String& keyTypeDescribe) const;
        NODISCARD String GenerateEnumClassName() const;

    private:
        NODISCARD String GenerateSharedPtrUsing(const String& keyTypeDescribe) const;

    private:
        CSVHead csvHead;
        String suffix;
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CLASS_NAME_H