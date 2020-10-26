//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:11)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    // �����ṩ�˻��ڷ�����ֻ�����Է���

    // �����ඨ����һ��get������ ����������һ����̬���������������������������ڵ�ƫ������
    // Ȼ��ʹ���������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������
    template <typename ConstReference,  // ��������
              typename Container,  // �����
              ptrdiff_t (*FO)(),  // ָ�뺯���ṩ������ƫ������
              ConstReference (Container::*FG)() const>  // ָ��ָ��һ��const��Ա��������CR
    class MethodPropertyGetExternal final
    {
    public:
        using ConstReferenceType = ConstReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGetExternal<ConstReferenceType, ContainerType, FO, FG>;

    public:
        CLASS_INVARIANT_DECLARE;

        // �ṩ�Ը����Ե�ֻ������
        [[nodiscard]] operator ConstReferenceType() const;

        // ���ַ��������صģ��Է�ֹ��Ϥ�������û��ڰ��������ж�����ʵ��ʹ��operator=��
        // ��Ϊʹ��MethodPropertyGetSet<>�ᵼ������ѭ����
        MethodPropertyGetExternal& operator=(ConstReferenceType value) = delete;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H