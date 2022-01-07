///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:30)

#ifndef CORE_TOOLS_TEXT_PARSING_DEFAULT_FUNCTION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_DEFAULT_FUNCTION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DefaultFunctionParsing final : public Parsing
    {
    public:
        using ClassType = DefaultFunctionParsing;
        using ParentType = Parsing;

    public:
        DefaultFunctionParsing(int indentationCount, const String& className);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateDefaultConstructor() const;
        NODISCARD String GenerateKeyConstructor() const;
        NODISCARD String GenerateCSVRowConstructor() const;
        NODISCARD String GenerateCSVContentConstructor() const;
        NODISCARD String GenerateDestructor() const;
        NODISCARD String GenerateCopyConstructor() const;
        NODISCARD String GenerateCopyAssignment() const;
        NODISCARD String GenerateMoveConstructor() const;
        NODISCARD String GenerateMoveAssignment() const;

        NODISCARD String GenerateClassInvariantDeclare() const;
        NODISCARD String GenerateClassInvariantVirtualDeclare() const;
        NODISCARD String GenerateClassInvariantFinalDeclare() const;

    private:
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DEFAULT_FUNCTION_PARSING_H