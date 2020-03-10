// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 14:25)

#include "Mathematics/MathematicsExport.h"
 
#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_MATRIX_DETAIL
	#define MATHEMATICS_INCLUDED_MATRIX_DETAIL
#endif // MATHEMATICS_INCLUDED_MATRIX_DETAIL

#include "MatrixDetail.h" 
#include "Matrix3Detail.h"
#include "APointDetail.h"
#include "AVectorDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Matrix<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Matrix<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE
 


 