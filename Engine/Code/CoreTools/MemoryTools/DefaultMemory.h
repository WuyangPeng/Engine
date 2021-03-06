//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/19 13:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_H
#define CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_H

#include "CoreTools/CoreToolsDll.h"

#include <cstdlib>

// 默认内存分配。
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DefaultMemory final
    {
    public:
        using ClassType = DefaultMemory;

    public:
        // 对 1D 数组:  data[bound]
        template <typename T>
        [[nodiscard]] static T* New1DArray(const int bound);

        // 对 2D 数组:  data[bound2][bound1]
        template <typename T>
        [[nodiscard]] static T** New2DArray(const int bound1, const int bound2);

        // 对 3D 数组:  data[bound3][bound2][bound1]
        template <typename T>
        [[nodiscard]] static T*** New3DArray(const int bound1, const int bound2, const int bound3);

        // 对 4D 数组:  data[bound4][bound3][bound2][bound1]
        template <typename T>
        [[nodiscard]] static T**** New4DArray(const int bound1, const int bound2, const int bound3, const int bound4);

        // 对单例
        template <typename T>
        static void DeleteSingle(T*& data) noexcept;

        // 对 1D 数组:  data[bound1]
        template <typename T>
        static void Delete1DArray(T*& data) noexcept;

        // 对 2D 数组:  data[bound2][bound1]
        template <typename T>
        static void Delete2DArray(T**& data) noexcept;

        // 对 3D 数组:  data[bound3][bound2][bound1]
        template <typename T>
        static void Delete3DArray(T***& data) noexcept;

        // 对 4D 数组:  data[bound4][bound3][bound2][bound1]
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
