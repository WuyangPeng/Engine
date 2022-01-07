///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:37)

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