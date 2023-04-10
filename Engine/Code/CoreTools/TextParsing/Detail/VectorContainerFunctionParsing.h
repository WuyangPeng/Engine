///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:11)

#ifndef CORE_TOOLS_TEXT_PARSING_VECTOR_CONTAINER_FUNCTION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_VECTOR_CONTAINER_FUNCTION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerFunctionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE VectorContainerFunctionParsing final : public ContainerFunctionParsing
    {
    public:
        using ClassType = VectorContainerFunctionParsing;
        using ParentType = ContainerFunctionParsing;

    public:
        VectorContainerFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunction() const override;

    private:
        NODISCARD String GenerateGetFirstByKey() const;
        NODISCARD String GenerateGetContainerByKey() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_VECTOR_CONTAINER_FUNCTION_PARSING_H