///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 09:17)

#ifndef CORE_TOOLS_TEXT_PARSING_KEY_CONTAINER_FUNCTION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_KEY_CONTAINER_FUNCTION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerFunctionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE KeyContainerFunctionParsing final : public ContainerFunctionParsing
    {
    public:
        using ClassType = KeyContainerFunctionParsing;
        using ParentType = ContainerFunctionParsing;

    public:
        KeyContainerFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunction() const override;

    private:
        NODISCARD String GenerateGetKey() const;

        NODISCARD String GenerateGetKeyName() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_KEY_CONTAINER_FUNCTION_PARSING_H