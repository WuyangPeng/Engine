/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_LINE_TYPE_H
#define C_S_V_CONFIGURE_LINE_TYPE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/EnumOperator.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

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

}

template <>
NODISCARD CSVConfigure::LineType CoreTools::CSVRow::StringCastEnum<CSVConfigure::LineType>(const String& describe) const;

#endif  // C_S_V_CONFIGURE_LINE_TYPE_H
