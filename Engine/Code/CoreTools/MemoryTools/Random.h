//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/19 16:46)

#ifndef CORE_TOOLS_MEMORY_TOOLS_RANDOM_H
#define CORE_TOOLS_MEMORY_TOOLS_RANDOM_H

// һ���򵥵�α������������������ٲ���32λ�����������rand()��15λ����
// ����ڹ�����û�и������ӣ�״̬������Ϊһ���̶�ֵ�������������������Ǻ����õġ�

#include "CoreTools/CoreToolsDll.h"

#include <array>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Random final
    {
    public:
        using ClassType = Random;

    public:
        Random() noexcept;
        explicit Random(uint32_t seed) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ����һ��������32λ���������
        [[nodiscard]] uint32_t Generate() noexcept;

        // ����һ������32λ�������
        [[nodiscard]] int GeneratePositive() noexcept;

    private:
        void GenerateSeeds() noexcept;

        // ����һ���µ�������һ����������״̬�ļ�������������
        [[nodiscard]] uint32_t GenerateSimple() noexcept;

    private:
        static constexpr auto sm_TableSize = 250;

        // �����һ�����ӱ����ڳ�ʼ��һ���򵥵ķ�������
        uint32_t m_State;

        int m_Index0;
        int m_Index1;
        std::array<uint32_t, sm_TableSize> m_Table;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_RANDOM_H
