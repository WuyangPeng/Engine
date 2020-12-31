///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/19 13:53)

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
