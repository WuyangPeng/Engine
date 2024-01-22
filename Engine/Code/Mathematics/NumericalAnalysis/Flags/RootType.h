/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOT_TYPE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOT_TYPE_H

// ���ַ��ⷽ�̵ĸ�������
namespace Mathematics
{
    enum class BisectRootType
    {
        HaveSolution,  // �н�
        NoSolution,  // �޽�
        Unknown,  // δ֪��������������
    };

    enum class BrentsMethodRootType
    {
        HaveSolution,  // �н�
        NoSolution,  // �޽�
        Unknown,  // δ֪��������������
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOT_TYPE_H
