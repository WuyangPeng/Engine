///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:31)

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
        NODISCARD int GetFifthValue() const noexcept;
        void SetFifthValue(int value) noexcept;

    public:
        class PropFifthValue
        {
        };

        CoreTools::Property<PropFifthValue, ClassType, int, int, &ClassType::SetFifthValue, &ClassType::GetFifthValue> FifthValue;

    private:
        int fifthValue;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_BASE_H