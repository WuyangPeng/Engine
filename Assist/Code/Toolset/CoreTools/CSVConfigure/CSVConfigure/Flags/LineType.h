/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef C_S_V_CONFIGURE_LINE_TYPE_H
#define C_S_V_CONFIGURE_LINE_TYPE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/EnumOperator.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

namespace CSVConfigure
{
    enum class LineType
    {
        Two = 2,  // ��ά
        Three = 3,  // ��ά
        Four = 4,  // ��ά
    };

    NODISCARD LineType StringCastLineType(const System::String& describe);
    NODISCARD System::String EnumCastString(LineType type);
    NODISCARD System::String GetEnumDescribe(LineType type);

}

template <>
NODISCARD CSVConfigure::LineType CoreTools::CSVRow::StringCastEnum<CSVConfigure::LineType>(const String& describe) const;

#endif  // C_S_V_CONFIGURE_LINE_TYPE_H
