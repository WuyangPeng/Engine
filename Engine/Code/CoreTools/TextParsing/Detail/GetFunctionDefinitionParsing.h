///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:33)

#ifndef CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE GetFunctionDefinitionParsing : public Parsing
    {
    public:
        using ClassType = GetFunctionDefinitionParsing;
        using ParentType = Parsing;

    public:
        GetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual String GenerateGetFunctionDefinition() const = 0;

    protected:
        NODISCARD String GetCSVClassName() const;
        NODISCARD String GetKeyTypeDescribe() const;
        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD int GetCSVHeadCount() const;

        NODISCARD String GenerateReturnKey(int addIndentationCount = 0) const;
        NODISCARD String GenerateGetFunctionArrayCount(const String& functionVariableName) const;
        NODISCARD String GenerateGetFunctionArrayConstIterator(const String& actualType, const String& functionVariableName, const StringView& endDescribe) const;

        NODISCARD String GenerateLambdaFunctionReturnIter() const;

    private:
        String className;
        String keyTypeDescribe;
        CSVHead m_CSVHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_DEFINITION_PARSING_H