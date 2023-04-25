///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:08)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/PropertyGetExternalDetail.h"
#include "CoreTools/Properties/PropertyGetSetExternalDetail.h"
#include "CoreTools/Properties/PropertySetExternalDetail.h"

#include <string>

namespace CoreTools
{
    class PropertyExternal
    {
    public:
        using ClassType = PropertyExternal;

        CLASS_INVARIANT_DECLARE;

        PropertyExternal() noexcept;

    private:
        std::string value;

        NODISCARD const std::string& GetValue() const noexcept;
        void SetValue(const std::string& aValue);

    public:
        using GetType = PropertyGetExternal<ClassType, const std::string&, &GetValue>;
        using SetType = PropertySetExternal<ClassType, const std::string&, &SetValue>;
        using GetSetType = PropertyGetSetExternal<ClassType, const std::string&, &GetValue, const std::string&, &SetValue>;

        GetType getType;
        SetType setType;
        GetSetType getSetType;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H
