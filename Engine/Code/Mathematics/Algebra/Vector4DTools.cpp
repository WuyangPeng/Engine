// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 14:26)

#include "Mathematics/MathematicsExport.h"
 
#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_DETAIL
	#define MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_DETAIL
#endif // MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_DETAIL

#include "Vector4DDetail.h"  
#include "Vector4DToolsDetail.h"  
#include "AxesAlignBoundingBox4DDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Vector4DTools<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Vector4DTools<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE
 


 