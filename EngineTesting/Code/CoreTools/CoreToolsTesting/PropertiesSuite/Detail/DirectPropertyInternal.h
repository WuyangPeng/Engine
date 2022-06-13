///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:41)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_H

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/DirectPropertyGetInternalDetail.h"
#include "CoreTools/Properties/DirectPropertySetInternalDetail.h"

#include <string>

namespace CoreTools
{
    class DirectPropertyInternal
    {
    public:
        using ClassType = DirectPropertyInternal;

        CLASS_INVARIANT_DECLARE;

        explicit DirectPropertyInternal(DisableNotThrow disableNotThrow);

        void SetValue(const std::string& value);
        NODISCARD std::string GetValue() const;

    public:
        using GetType = DirectPropertyGetInternal<std::string, const std::string&, ClassType>;
        using SetType = DirectPropertySetInternal<std::string, const std::string&, ClassType>;

        GetType getType;
        SetType setType;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_H
