///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 14:32)

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