//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:53)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SEVEN_MOD_ELEVEN_CHECK_SUM_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SEVEN_MOD_ELEVEN_CHECK_SUM_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE SevenModElevenCheckSum final
    {
    public:
        using ClassType = SevenModElevenCheckSum;

    public:
        SevenModElevenCheckSum(const char* data, int length);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetCheckSum() const noexcept;

    private:
        void Calculation(const char* data, int length);

    private:
        static constexpr auto sm_PowersSize = 10;
        static const int GetPowers(int index);

    private:
        int m_CheckSum;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SEVEN_MOD_ELEVEN_CHECK_SUM_H
