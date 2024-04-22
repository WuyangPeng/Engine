/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/29 23:52)

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