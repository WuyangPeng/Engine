///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/04 21:56)

#ifndef ENTITY_BATCH_CONVERSION_HELPER_H
#define ENTITY_BATCH_CONVERSION_HELPER_H

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

#endif  // ENTITY_BATCH_CONVERSION_HELPER_H