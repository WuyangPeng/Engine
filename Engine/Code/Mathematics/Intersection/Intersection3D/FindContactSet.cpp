// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/11 14:18)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_FIND_CONTACT_SET_DETAIL
	#define MATHEMATICS_INCLUDED_FIND_CONTACT_SET_DETAIL
#endif // MATHEMATICS_INCLUDED_FIND_CONTACT_SET_DETAIL

#include "FindContactSetDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class FindContactSet<float>;	
	
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class FindContactSet<double>; 
}

#endif // MATHEMATICS_EXPORT_TEMPLATE