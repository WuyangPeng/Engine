///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:07)

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
        explicit ClassNameParsing(int indentationCount, String className) noexcept;

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