// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 15:00)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL
	#define MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL
#endif // MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL

#include "IntersectorAxisDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class IntersectorAxis<float>;	
	
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class IntersectorAxis<double>; 
}

#endif // MATHEMATICS_EXPORT_TEMPLATE