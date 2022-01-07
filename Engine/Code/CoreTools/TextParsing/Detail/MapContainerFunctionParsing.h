///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:34)

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