///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 13:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOT_TYPE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOT_TYPE_H

// 二分法解方程的根的类型
namespace Mathematics
{
    enum class BisectRootType
    {
        HaveSolution,  // 有解
        NoSolution,  // 无解
        Unknown,  // 未知，迭代超过次数
    };

    enum class BrentsMethodRootType
    {
        HaveSolution,  // 有解
        NoSolution,  // 无解
        Unknown,  // 未知，迭代超过次数
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOT_TYPE_H
