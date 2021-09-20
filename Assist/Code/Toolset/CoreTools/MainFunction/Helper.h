///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/15 11:29)

#ifndef MAIN_FUCTION_HELPER_H
#define MAIN_FUCTION_HELPER_H

#include "System/Helper/ConfigMacro.h"

namespace MainFuction
{
    class Helper final
    {
    public:
        using ClassType = Helper;

    public:
        Helper(int argc, char** argv);
        ~Helper() noexcept;
        Helper(Helper& rhs) = delete;
        Helper& operator=(Helper& rhs) = delete;
        Helper(Helper&& rhs) noexcept = delete;
        Helper& operator=(Helper&& rhs) noexcept = delete;

        NODISCARD int Run();
    };
}

#endif  // MAIN_FUCTION_HELPER_H