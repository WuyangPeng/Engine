///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 17:33)

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