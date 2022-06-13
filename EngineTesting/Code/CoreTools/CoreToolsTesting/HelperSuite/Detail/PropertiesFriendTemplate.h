///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:15)

#ifndef CORE_TOOLS_HELPER_SUITE_PROPERTIES_FRIEND_TEMPLATE_H
#define CORE_TOOLS_HELPER_SUITE_PROPERTIES_FRIEND_TEMPLATE_H

#include "CoreTools/Helper/PropertiesMacro.h"
#include "CoreTools/Helper/UserMacro.h"

namespace CoreTools
{
    template <typename T>
    class PropertiesFriendTemplate final
    {
    public:
        using ClassType = PropertiesFriendTemplate<T>;

    public:
        PropertiesFriendTemplate() noexcept;

        CLASS_INVARIANT_DECLARE;

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(T);

    private:
        int value;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_PROPERTIES_FRIEND_TEMPLATE_H