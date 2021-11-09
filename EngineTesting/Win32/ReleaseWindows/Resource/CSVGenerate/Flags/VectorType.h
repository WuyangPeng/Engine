/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef C_S_V_CONFIGURE_VECTOR_TYPE_H
#define C_S_V_CONFIGURE_VECTOR_TYPE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/EnumMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVRow.h"

#include <iostream>

namespace CSVConfigure
{
    enum class VectorType
    {
        Two = 2,  // ��ά
        Three = 3,  // ��ά
        Four = 4,  // ��ά
    };

    NODISCARD VectorType StringCastVectorType(const System::String& describe);
    NODISCARD System::String EnumCastString(VectorType type);
    NODISCARD System::String GetEnumDescribe(VectorType type);

    ENUM_ADDABLE_OPERATOR_DEFINE(VectorType);
    ENUM_SUBTRACTABLE_OPERATOR_DEFINE(VectorType);
    ENUM_MULTIPLICATION_OPERATOR_DEFINE(VectorType);
    ENUM_NEGATE_OPERATOR_DEFINE(VectorType);
    ENUM_INCREMENTABLE_OPERATOR_DEFINE(VectorType);
    ENUM_DECREMENTABLE_OPERATOR_DEFINE(VectorType);
    ENUM_ANDABLE_OPERATOR_DEFINE(VectorType);
    ENUM_ORABLE_OPERATOR_DEFINE(VectorType);
    ENUM_XORABLE_OPERATOR_DEFINE(VectorType);
    ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE(VectorType);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(VectorType);
    ENUM_LEFT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(VectorType);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(VectorType);
}

template <>
NODISCARD CSVConfigure::VectorType CoreTools::CSVRow::StringCastEnum<CSVConfigure::VectorType>(const String& describe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return CSVConfigure::StringCastVectorType(describe);
}

#endif  // C_S_V_CONFIGURE_VECTOR_TYPE_H
