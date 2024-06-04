/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.10 (2024/05/27 19:40)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/PropertyGetExternal.h"
#include "CoreTools/Properties/PropertyGetSetExternal.h"
#include "CoreTools/Properties/PropertySetExternal.h"

#include <string>

namespace CoreTools
{
    class PropertyExternal
    {
    public:
        using ClassType = PropertyExternal;

    public:
        PropertyExternal() noexcept;

        CLASS_INVARIANT_DECLARE;

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
