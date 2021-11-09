/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef C_S_V_CONFIGURE_LINE_TYPE_H
#define C_S_V_CONFIGURE_LINE_TYPE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/EnumMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVRow.h"

#include <iostream>

namespace CSVConfigure
{
    enum class LineType
    {
        Two = 2,  // 二维
        Three = 3,  // 三维
        Four = 4,  // 四维
    };

    NODISCARD LineType StringCastLineType(const System::String& describe);
    NODISCARD System::String EnumCastString(LineType type);
    NODISCARD System::String GetEnumDescribe(LineType type);

    ENUM_ADDABLE_OPERATOR_DEFINE(LineType);
    ENUM_SUBTRACTABLE_OPERATOR_DEFINE(LineType);
    ENUM_MULTIPLICATION_OPERATOR_DEFINE(LineType);
    ENUM_NEGATE_OPERATOR_DEFINE(LineType);
    ENUM_INCREMENTABLE_OPERATOR_DEFINE(LineType);
    ENUM_DECREMENTABLE_OPERATOR_DEFINE(LineType);
    ENUM_ANDABLE_OPERATOR_DEFINE(LineType);
    ENUM_ORABLE_OPERATOR_DEFINE(LineType);
    ENUM_XORABLE_OPERATOR_DEFINE(LineType);
    ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE(LineType);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(LineType);
    ENUM_LEFT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(LineType);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(LineType);
}

template <>
NODISCARD CSVConfigure::LineType CoreTools::CSVRow::StringCastEnum<CSVConfigure::LineType>(const String& describe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return CSVConfigure::StringCastLineType(describe);
}

#endif  // C_S_V_CONFIGURE_LINE_TYPE_H
