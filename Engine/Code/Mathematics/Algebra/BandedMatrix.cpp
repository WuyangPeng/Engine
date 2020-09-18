// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 11:14)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE
 
#ifndef MATHEMATICS_INCLUDED_BANDED_MATRIX_DETAIL
	#define MATHEMATICS_INCLUDED_BANDED_MATRIX_DETAIL
#endif // MATHEMATICS_INCLUDED_BANDED_MATRIX_DETAIL

#include "BandedMatrixDetail.h" 
#include "VariableMatrixDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class BandedMatrix<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class BandedMatrix<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE



