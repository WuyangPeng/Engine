// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 10:46)

#ifndef MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H
#define MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H

namespace Mathematics
{		
	// ����ת������ȡŷ���ǡ�
	enum class ExtractEulerResultType
	{
		// ��������Ƕ�һ�޶��ġ� 
		Unique,

		// �����������Ψһ�ġ��Ƕ�֮���Ǻ㶨�ġ� 
		Sum,

		// �����������Ψһ�ġ��Ƕ�֮���Ǻ㶨�ġ�
		Difference
	};

	enum class ExtractEulerResultOrder
	{
		XYZ,
		XZY,
		YXZ,
		YZX,
		ZXY,
		ZYX,
		XYX,
		XZX,
		YXY,
		YZY,
		ZXZ,
		ZYZ,
	};		
}

#endif // MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H
