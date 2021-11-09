///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/28 18:26)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_CSV_FLAGS_H

#include "System/Helper/EnumMacro.h"

namespace CoreTools
{
    enum class CSVType
    {
        Format = 1,
        Annotation,
        DataType,
        VariableName,
    };

    enum class CSVFormatType
    {
        Default,
        Ignore,
        Vector,
        TreeMap,
        HashMap,
        Key,
        Enum,
        Unique,
    };

    // Bit，Vector2等数据使用分隔符|，Array数据使用分隔符&。
    enum class CSVDataType
    {
        String,
        Bool,
        Char,
        Int,
        Int64,
        Double,
        Enum,
        Bit,
        Vector2,
        Vector3,
        Vector4,
        IntVector2,
        IntVector3,
        IntVector4,

        BoolArray,
        CharArray,
        IntArray,
        Int64Array,
        DoubleArray,
        EnumArray,
        BitArray,
        Vector2Array,
        Vector3Array,
        Vector4Array,
        IntVector2Array,
        IntVector3Array,
        IntVector4Array,
    };

    enum class CSVGenerateType
    {
        BaseHead,
        ChildHead,
        DataHead,
        ContainerHead,
        ContainerDetailHead,
        BaseSource,
        ChildSource,
        DataSource,
        ContainerSource,
        Total,
        EnumHead,
        EnumSource,
        EnumTotal,
    };

    enum class CSVTotalGenerateType
    {
        Head,
        FwdHead,
        ContainerHead,
        ContainerSource,
    };

    enum class CSVPoistionType
    {
        Begin,
        Middle,
        End,
    };

    ENUM_INCREMENTABLE_OPERATOR_DEFINE(CSVType)
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_FLAGS_H