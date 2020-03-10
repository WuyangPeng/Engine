// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 10:44)

#ifndef MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H
#define MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H

namespace Mathematics
{
	enum class FloatingPointAnalysisType
	{
		// ��ָ��λ��ȫΪ1�Ҳ�ȫΪ0ʱ��
		Valid,
		// ��ָ��λȫΪ0ʱ��
		Zero,
		// ��ָ��λȫΪ1��β��λΪ0ʱ��
		Infinity,
		// ��ָ��λȫΪ1��β��λ��Ϊ0ʱ��
		QuietNaN,
		SignalingNaN,
	};
}

#endif // MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H
