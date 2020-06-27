// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOT_TYPE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOT_TYPE_H

// ���ַ��ⷽ�̵ĸ�������
namespace Mathematics
{
	enum class BisectRootType
	{
		HaveSolution, // �н�
		NoSolution, // �޽�
		Unknown, // δ֪��������������
	};

	enum class BrentsMethodRootType
	{
		HaveSolution, // �н�
		NoSolution, // �޽�
		Unknown, // δ֪��������������
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ROOT_TYPE_H
