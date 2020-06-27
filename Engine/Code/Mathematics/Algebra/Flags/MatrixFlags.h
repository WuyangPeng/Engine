// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 09:47)

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
		Row, // 行矩阵
		Column // 列矩阵
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
