// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 11:19)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_VARIABLE_MATRIX_DETAIL
	#define MATHEMATICS_INCLUDED_VARIABLE_MATRIX_DETAIL
#endif // MATHEMATICS_INCLUDED_VARIABLE_MATRIX_DETAIL

#include "VariableMatrixDetail.h"  
#include "VariableLengthVectorDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class VariableMatrix<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class VariableMatrix<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE



