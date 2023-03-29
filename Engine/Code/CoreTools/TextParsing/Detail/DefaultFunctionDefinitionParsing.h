///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 09:11)

#ifndef CORE_TOOLS_TEXT_PARSING_DEFAULT_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_DEFAULT_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h" 

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DefaultFunctionDefinitionParsing : public Parsing
    {
    public:
        using ClassType = DefaultFunctionDefinitionParsing;
        using ParentType = Parsing;
        using StringView = System::StringView;

    public:
        explicit DefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateClassInvariantStubDefine() const;

    protected:
        NODISCARD String GenerateConstructor(StringView parameter) const;

        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD int GetCSVHeadCount() const;
        NODISCARD bool HasCSVHeadScope() const noexcept;
        NODISCARD String GetCSVClassName() const;
        NODISCARD String GetNameSpace() const;

    private:
        CSVHead head;
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DEFAULT_FUNCTION_DEFINITION_PARSING_H