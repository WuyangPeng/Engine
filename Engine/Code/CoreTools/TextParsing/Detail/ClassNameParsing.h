///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:15)

#ifndef CORE_TOOLS_TEXT_PARSING_CLASS_NAME_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CLASS_NAME_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ClassNameParsing final : public Parsing
    {
    public:
        using ClassType = ClassNameParsing;
        using ParentType = Parsing;

    public:
        explicit ClassNameParsing(int indentationCount, const String& className);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateParentClassName() const;
        NODISCARD String GenerateChildClassName() const;
        NODISCARD String GenerateClassName() const;
        NODISCARD String GenerateEnumClassName() const;

        NODISCARD String GenerateClassType() const;
        NODISCARD String GenerateParentType() const;

    private:
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CLASS_NAME_PARSING_H