// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:32)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H
#define MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H 

#include "System/Helper/EnumMacro.h"

namespace Mathematics
{
	// �����ཻ���ϵ���Ϣ
	enum class IntersectionType
	{
		Empty,
		Point,
		Segment,
		Ray,
		Line,
		Polygon,
		Plane,
		Polyhedron,
		Other
	};

	ENUM_INCREMENTABLE_OPERATOR_DEFINE(IntersectionType);
}

#endif // MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H
