///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/14 14:09)

#ifndef USER_INFO_PLACEHOLDER_PLACEHOLDER_H
#define USER_INFO_PLACEHOLDER_PLACEHOLDER_H

#include "UserInfo/UserInfoDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace UserInfo
{
    class USER_INFO_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // USER_INFO_PLACEHOLDER_PLACEHOLDER_H
