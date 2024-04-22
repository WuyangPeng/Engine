/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 23:52)

#ifndef CORE_TOOLS_EXCEPTION_FWD_H
#define CORE_TOOLS_EXCEPTION_FWD_H

#include <type_traits>

namespace CoreTools
{
    class LastError;
    class Error;

    template <typename E>
    requires(std::is_enum_v<E>)
    class GameError;
}

#endif  // CORE_TOOLS_EXCEPTION_FWD_H