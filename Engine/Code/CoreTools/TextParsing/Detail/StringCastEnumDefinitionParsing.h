///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:35)

#ifndef CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE StringCastEnumDefinitionParsing : public Parsing
    {
    public:
        using ClassType = StringCastEnumDefinitionParsing;
        using ParentType = Parsing;

    public:
        StringCastEnumDefinitionParsing(const CSVHead& csvHead, const String& className);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateStringCastEnumDefinition() const;

    private:
        NODISCARD String GenerateStringCastEnum() const;
        NODISCARD String GenerateDescribe() const;

    private:
        String className;
        CSVHead m_CSVHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_PARSING_H