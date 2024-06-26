/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef ROBOT_CLIENT_CORE_ENGINE_PLACEHOLDER_H
#define ROBOT_CLIENT_CORE_ENGINE_PLACEHOLDER_H

#include "RobotClient/RobotClientCore/RobotClientCoreDll.h"

#include "RobotClient/RobotClientCore/Helper/ExportMacro.h"

namespace RobotClientCore
{
    class ROBOT_CLIENT_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // ROBOT_CLIENT_CORE_ENGINE_PLACEHOLDER_H