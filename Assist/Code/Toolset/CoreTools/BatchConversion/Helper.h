///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.11 (2023/05/30 21:34)

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
        void Conversion();
    };
}

#endif  // BATCH_CONVERSION_HELPER_H