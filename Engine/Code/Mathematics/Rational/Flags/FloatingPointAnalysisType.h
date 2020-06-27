// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 09:43)

#ifndef MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H
#define MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H

namespace Mathematics
{
	enum class FloatingPointAnalysisType
	{
		// 当指数位不全为1且不全为0时，
		Valid,
		// 当指数位全为0时，
		Zero,
		// 当指数位全为1且尾数位为0时，
		Infinity,
		// 当指数位全为1且尾数位不为0时，
		QuietNaN,
		SignalingNaN,
	};
}

#endif // MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H
