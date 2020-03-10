// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 14:25)

#include "Mathematics/MathematicsExport.h"
 
#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_QUATERNION_DETAIL
	#define MATHEMATICS_INCLUDED_QUATERNION_DETAIL
#endif // MATHEMATICS_INCLUDED_QUATERNION_DETAIL

#include "QuaternionDetail.h" 
#include "Matrix3Detail.h"
#include "Vector3DDetail.h"
#include "Vector3DToolsDetail.h"
#include "QuaternionFactorDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Quaternion<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Quaternion<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE
 


 