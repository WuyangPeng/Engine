///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 14:41)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    // �����ṩ��ӵĻ��ڷ�����ֻд���Է���
    // �����ඨ����һ��set������ ����������һ����̬���������������������������ڵ�ƫ������
    // Ȼ��ʹ���������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������

    template <typename Reference,  // ��������
              typename Container,  // �����
              ptrdiff_t (*FunctionOffset)(),  // ָ�뺯���ṩ������ƫ������
              void (Container::*FunctionSet)(Reference)>  // ָ�뵽һ����Ա��������R
    class MethodPropertySetExternal final
    {
    public:
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = MethodPropertySetExternal<ReferenceType, ContainerType, FunctionOffset, FunctionSet>;

    public:
        CLASS_INVARIANT_DECLARE;

        // �ṩ�Ը����Ե�ֻд����
        MethodPropertySetExternal& operator=(ReferenceType value) noexcept;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_H