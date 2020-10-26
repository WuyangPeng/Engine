//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/19 13:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_H
#define CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_H

#include "CoreTools/CoreToolsDll.h"

#include <cstdlib>

// Ĭ���ڴ���䡣
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DefaultMemory final
    {
    public:
        using ClassType = DefaultMemory;

    public:
        // �� 1D ����:  data[bound]
        template <typename T>
        [[nodiscard]] static T* New1DArray(const int bound);

        // �� 2D ����:  data[bound2][bound1]
        template <typename T>
        [[nodiscard]] static T** New2DArray(const int bound1, const int bound2);

        // �� 3D ����:  data[bound3][bound2][bound1]
        template <typename T>
        [[nodiscard]] static T*** New3DArray(const int bound1, const int bound2, const int bound3);

        // �� 4D ����:  data[bound4][bound3][bound2][bound1]
        template <typename T>
        [[nodiscard]] static T**** New4DArray(const int bound1, const int bound2, const int bound3, const int bound4);

        // �Ե���
        template <typename T>
        static void DeleteSingle(T*& data) noexcept;

        // �� 1D ����:  data[bound1]
        template <typename T>
        static void Delete1DArray(T*& data) noexcept;

        // �� 2D ����:  data[bound2][bound1]
        template <typename T>
        static void Delete2DArray(T**& data) noexcept;

        // �� 3D ����:  data[bound3][bound2][bound1]
        template <typename T>
        static void Delete3DArray(T***& data) noexcept;

        // �� 4D ����:  data[bound4][bound3][bound2][bound1]
        template <typename T>
        static void Delete4DArray(T****& data) noexcept;

    private:
        template <typename T>
        static void NewArrayUseFailureDelete(T**& data, int bound);

        template <typename T>
        static void NewArrayUseFailureDelete(T***& data, int bound, int innerBound);

        template <typename T>
        static void NewArrayUseFailureDelete(T****& data, int bound, int innerBound, int innermostBound);
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_H
