///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:41)

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