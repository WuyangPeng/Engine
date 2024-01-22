/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:14)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    // �����ṩ��ӷ����Ķ�/д���Է���

    // �����ඨ��get��set������ ����������һ����̬���������а������������������ڵ�ƫ������
    // Ȼ��ʹ�������������ͣ���ȡ�������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������

    template <typename GetReference,
              typename SetReference,
              typename Container,
              ptrdiff_t (*FunctionOffset)(),
              GetReference (Container::*FunctionGet)() const,
              void (Container::*FunctionSet)(SetReference)>
    class MethodPropertyGetSetExternal final
    {
    public:
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGetSetExternal<GetReferenceType, SetReferenceType, ContainerType, FunctionOffset, FunctionGet, FunctionSet>;

        MethodPropertyGetSetExternal() noexcept = default;
        ~MethodPropertyGetSetExternal() noexcept = default;
        MethodPropertyGetSetExternal(const MethodPropertyGetSetExternal& rhs) noexcept = delete;
        MethodPropertyGetSetExternal& operator=(const MethodPropertyGetSetExternal& rhs) noexcept = delete;
        MethodPropertyGetSetExternal(MethodPropertyGetSetExternal&& rhs) noexcept = delete;
        MethodPropertyGetSetExternal& operator=(MethodPropertyGetSetExternal&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        // �ṩ�Ը����Ե�ֻ������
        NODISCARD operator GetReferenceType() const noexcept;

        // �ṩ�Ը����Ե�ֻд����
        MethodPropertyGetSetExternal& operator=(SetReferenceType value) noexcept;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_H