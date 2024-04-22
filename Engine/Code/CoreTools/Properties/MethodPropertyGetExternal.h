/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:05)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    /// �����ṩ�˻��ڷ�����ֻ�����Է���

    /// �����ඨ����һ��get������
    /// ����������һ����̬���������������������������ڵ�ƫ������
    /// Ȼ��ʹ���������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������
    template <typename ConstReference,  /// ��������
              typename Container,  /// �����
              ptrdiff_t (*FunctionOffset)(),  /// ָ�뺯���ṩ������ƫ������
              ConstReference (Container::*FunctionGet)() const>  /// ָ��ָ��һ��const��Ա��������CR
    class MethodPropertyGetExternal final
    {
    public:
        using ConstReferenceType = ConstReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGetExternal<ConstReferenceType, ContainerType, FunctionOffset, FunctionGet>;

        MethodPropertyGetExternal() noexcept = default;
        ~MethodPropertyGetExternal() noexcept = default;
        MethodPropertyGetExternal(const MethodPropertyGetExternal& rhs) noexcept = delete;
        MethodPropertyGetExternal& operator=(const MethodPropertyGetExternal& rhs) noexcept = delete;
        MethodPropertyGetExternal(MethodPropertyGetExternal&& rhs) noexcept = delete;
        MethodPropertyGetExternal& operator=(MethodPropertyGetExternal&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        /// �ṩ�Ը����Ե�ֻ������
        NODISCARD operator ConstReferenceType() const noexcept;

        /// ���ַ��������صģ��Է�ֹ��Ϥ�������û��ڰ��������ж�����ʵ��ʹ��operator=��
        /// ��Ϊʹ��MethodPropertyGetSet<>�ᵼ������ѭ����
        MethodPropertyGetExternal& operator=(ConstReferenceType value) = delete;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H