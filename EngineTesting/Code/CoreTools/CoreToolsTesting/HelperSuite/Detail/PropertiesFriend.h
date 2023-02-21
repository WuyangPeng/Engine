///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/16 20:47)

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