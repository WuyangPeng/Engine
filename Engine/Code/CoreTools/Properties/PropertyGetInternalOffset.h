//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:13)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

// ʹ�÷�ʽ��
// �������1�ֽڶ���
// #pragma pack(push, 1)
// ��Ҫ����һ����������ľ�̬������
// static ptrdiff_t GetOffset()
// { enum { offset = offsetof(Class, Property) }; return offset; }

namespace CoreTools
{
    template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
    class PropertyGetInternalOffset final
    {
    public:
        using ReferenceType = Reference;
        using ClassType = PropertyGetInternalOffset<T, V, ReferenceType, PF, FO>;

    public:
        CLASS_INVARIANT_DECLARE;

    private:
        explicit PropertyGetInternalOffset(ReferenceType value);

        PropertyGetInternalOffset& operator=(ReferenceType value);
        void SetValue(ReferenceType value);
        [[nodiscard]] ReferenceType GetValue() const;

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(T);

    public:
        operator ReferenceType() const;

    private:
        V m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_H