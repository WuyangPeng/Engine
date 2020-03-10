// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 14:45)

#ifndef MATHEMATICS_ALGEBRA_MATRIX_FLAGS_H
#define MATHEMATICS_ALGEBRA_MATRIX_FLAGS_H

#include "System/Helper/EnumMacro.h"

namespace Mathematics
{	
	enum class MatrixTypeFlags
	{
		Zero,
		Identity
	};		

	enum class MatrixMajorFlags
	{
		Row, // �о���
		Column // �о���
	};

	enum class MatrixRotationAxis
	{
		X,
		Y,
		Z,
		Count
	};

	enum class BandedMatrixSolveFlags
	{
		Unsolved,
		Succeed,
		Failure
	};

	ENUM_INCREMENTABLE_OPERATOR_DEFINE(MatrixRotationAxis);
}

#endif // MATHEMATICS_ALGEBRA_MATRIX_FLAGS_H
