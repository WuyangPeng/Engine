///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:15)

#ifndef CORE_TOOLS_HELPER_SUITE_PROPERTIES_FRIEND_H
#define CORE_TOOLS_HELPER_SUITE_PROPERTIES_FRIEND_H

#include "CoreTools/Helper/UserMacro.h"

#include "PropertiesFriendTemplate.h"

namespace CoreTools
{
    class PropertiesFriend final
    {
    public:
        using ClassType = PropertiesFriend;
        using TemplateType = PropertiesFriendTemplate<PropertiesFriend>;

    public:
        PropertiesFriend() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetValue() const noexcept;

    private:
        TemplateType templateType;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_PROPERTIES_FRIEND_H