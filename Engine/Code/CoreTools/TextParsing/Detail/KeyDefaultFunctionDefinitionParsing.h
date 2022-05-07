///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:33)

#ifndef CORE_TOOLS_TEXT_KEY_PARSING_DEFAULT_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_KEY_PARSING_DEFAULT_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "DefaultFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE KeyDefaultFunctionDefinitionParsing final : public DefaultFunctionDefinitionParsing
    {
    public:
        using ClassType = KeyDefaultFunctionDefinitionParsing;
        using ParentType = DefaultFunctionDefinitionParsing;

    public:
        explicit KeyDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateKeyConstructorDefinition() const;

    private:
        NODISCARD String GenerateKeyMember() const;
    };
}

#endif  // CORE_TOOLS_TEXT_KEY_PARSING_DEFAULT_FUNCTION_DEFINITION_PARSING_H