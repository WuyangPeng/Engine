// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 14:25)

#include "Mathematics/MathematicsExport.h"
 
#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_AQUATERNION_DETAIL
	#define MATHEMATICS_INCLUDED_AQUATERNION_DETAIL
#endif // MATHEMATICS_INCLUDED_AQUATERNION_DETAIL

#include "AQuaternionDetail.h" 
#include "AVectorDetail.h"
#include "MatrixDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class AQuaternion<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class AQuaternion<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE
 


 