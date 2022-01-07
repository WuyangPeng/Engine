///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/23 18:01)

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
        NODISCARD operator ConstReferenceType() const noexcept;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H