//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:13)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H

#include "CoreTools/CoreToolsDll.h"

// ʹ�÷�ʽ��
// �������1�ֽڶ���
// #pragma pack(push, 1)
// ��Ҫ����һ����������ľ�̬������
// static ptrdiff_t GetOffset()
// { enum { offset = offsetof(Class, Property) }; return offset; }

namespace CoreTools
{
    template <typename T, typename ConstReference, ConstReference (T::*PF)() const, ptrdiff_t (*FO)()>
    class PropertyGetExternalOffset final
    {
    public:
        using ConstReferenceType = ConstReference;
        using ClassType = PropertyGetExternalOffset<T, ConstReferenceType, PF, FO>;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] operator ConstReferenceType() const;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H