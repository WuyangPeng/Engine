///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/25 19:19)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_JSON_FLAGS_H

#include "System/Helper/EnumOperator.h"

namespace CoreTools
{
    enum class JsonDataType
    {
        Null,

        String,
        Bool,
        Int,
        Int64,
        Double,
        Nested,

        StringArray,
        BoolArray,
        IntArray,
        Int64Array,
        DoubleArray,
        NestedArray,

        StringMap,
        BoolMap,
        IntMap,
        Int64Map,
        DoubleMap,
    };

    enum class JsonGenerateType
    {
        Head,
        DetailHead,
        Source,
        Total,
        EnumHead,
        EnumSource,
        EnumTotal,
    };

    enum class JsonTotalGenerateType
    {
        Head,
        FwdHead,
        ContainerHead,
        ContainerSource,
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_FLAGS_H