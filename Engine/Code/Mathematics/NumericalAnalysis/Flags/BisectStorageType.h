///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 13:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT_STORAGE_TYPE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT_STORAGE_TYPE_H

namespace Mathematics
{
    enum class Bisect2StorageType
    {
        BeginXAndBeginY,
        EndXAndBeginY,
        BeginXAndEndY,
        EndXAndEndY,
        BeginXAndMidY,
        EndXAndMidY,
        MidXAndBeginY,
        MidXAndEndY,
        MidXAndMidY,
    };

    enum class Bisect3StorageType
    {
        BeginXBeginYBeginZ,
        EndXBeginYBeginZ,
        BeginXEndYBeginZ,
        EndXEndYBeginZ,
        BeginXBeginYEndZ,
        EndXBeginYEndZ,
        BeginXEndYEndZ,
        EndXEndYEndZ,
        BeginXBeginYMidZ,
        EndXBeginYMidZ,
        BeginXEndYMidZ,
        EndXEndYMidZ,
        BeginXMidYBeginZ,
        EndXMidYBeginZ,
        BeginXMidYEndZ,
        EndXMidYEndZ,
        MidXBeginYBeginZ,
        MidXEndYBeginZ,
        MidXBeginYEndZ,
        MidXEndYEndZ,
        BeginXMidYMidZ,
        MidXBeginYMidZ,
        MidXMidYBeginZ,
        EndXMidYMidZ,
        MidXEndYMidZ,
        MidXMidYEndZ,
        MidXMidYMidZ,
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT_STORAGE_TYPE_H
