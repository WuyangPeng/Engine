// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 09:47)

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
