///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 17:22)

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