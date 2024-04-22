/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:06)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

/// ʹ�÷�ʽ��
/// ��ͨ����Ԫʵ�ֶ����Ե�ֻ�����ʡ�
/// ��һ���࣬�������£�
/// class PropTester {
/// public: CoreTools::DirectPropertyGetInternal<int, int, PropTester> Prop;
/// �����Ҫ�ṩ�޸�ֵ�Ľӿڣ�
/// public: void SetPropValue(int i)	{ Prop.value = i;	}
/// };

/// ʹ�÷�ʽ���£�
/// PropTester tester{};
/// ֻ�����ʣ�
/// int i = tester.Prop;
/// ����ֵ��
/// tester.SetPropValue(100);

namespace CoreTools
{
    template <typename Value,  /// ʵ������ֵ����
              typename Reference,  /// ��������
              typename Container>  /// �����
    class DirectPropertyGetInternal final
    {
    public:
        using ValueType = Value;
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = DirectPropertyGetInternal<ValueType, ReferenceType, ContainerType>;

        CLASS_INVARIANT_DECLARE;

        ~DirectPropertyGetInternal() noexcept = default;
        DirectPropertyGetInternal(const DirectPropertyGetInternal& rhs) noexcept = delete;
        DirectPropertyGetInternal& operator=(const DirectPropertyGetInternal& rhs) noexcept = delete;
        DirectPropertyGetInternal(DirectPropertyGetInternal&& rhs) noexcept = delete;
        DirectPropertyGetInternal& operator=(DirectPropertyGetInternal&& rhs) noexcept = delete;

#if defined(TCRE_USE_DIGITAL_MARS)

    public:
#else  // TCRE_USE_DIGITAL_MARS

    private:

#endif  // TCRE_USE_DIGITAL_MARS

        DirectPropertyGetInternal();

    private:
        explicit DirectPropertyGetInternal(ReferenceType value);
        ClassType& operator=(ReferenceType aValue);

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        /// �ṩ�Ը����Ե�ֻ������
        NODISCARD operator ReferenceType() const noexcept;

    private:
        ValueType value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_H