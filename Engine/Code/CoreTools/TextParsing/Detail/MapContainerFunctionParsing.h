///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 09:18)

#ifndef CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_FUNCTION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_FUNCTION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerFunctionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MapContainerFunctionParsing final : public ContainerFunctionParsing
    {
    public:
        using ClassType = MapContainerFunctionParsing;
        using ParentType = ContainerFunctionParsing;

    public:
        MapContainerFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunction() const override;

    private:
        NODISCARD String GenerateGetFirst() const;
        NODISCARD String GenerateGet() const;
        NODISCARD String GenerateGetFirstTemplate() const;
        NODISCARD String GenerateGetTemplate() const;

        NODISCARD String GenerateGetMappingContainer() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_MAP_CONTAINER_FUNCTION_PARSING_H