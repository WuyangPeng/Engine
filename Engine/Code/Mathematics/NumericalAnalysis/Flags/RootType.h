///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:21)

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
