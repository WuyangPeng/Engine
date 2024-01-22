/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:47)

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
