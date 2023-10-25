///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:41)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_BASE_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_BASE_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/PropertyDetail.h"

namespace CoreTools
{
    class PropertiesBase
    {
    public:
        using ClassType = PropertiesBase;

    public:
        PropertiesBase() noexcept;

        CLASS_INVARIANT_DECLARE;

    private:
        NODISCARD int GetValue() const noexcept;
        void SetValue(int aValue) noexcept;

    public:
        class PropValue
        {
        };

        Property<PropValue, ClassType, int, int, &ClassType::SetValue, &ClassType::GetValue> propValue;

    private:
        int value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_BASE_H