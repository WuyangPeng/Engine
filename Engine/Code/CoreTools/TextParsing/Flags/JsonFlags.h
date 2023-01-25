///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:38)

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