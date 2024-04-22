/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 16:41)

#ifndef BATCH_CONVERSION_HELPER_H
#define BATCH_CONVERSION_HELPER_H

#include "CoreTools/Helper/UserMacro.h"

namespace BatchConversion
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

        CLASS_INVARIANT_DECLARE;

        NODISCARD int Run();

    private:
        static void Conversion();
    };
}

#endif  // BATCH_CONVERSION_HELPER_H