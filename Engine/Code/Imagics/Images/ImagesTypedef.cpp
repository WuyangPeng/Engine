// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:15)

#include "Imagics/ImagicsExport.h"

#include "ImagesTypedef.h"
#include "TImageDetail.h"
#include "TImage2DDetail.h"
#include "TImage3DDetail.h"

// Explicit instantiation.

namespace Imagics
{
	template class TImage<Echar>;
	template class TImage<Euchar>;
	template class TImage<Eshort>;
	template class TImage<Eushort>;
	template class TImage<Eint>;
	template class TImage<Euint>;
	template class TImage<Elong>;
	template class TImage<Eulong>;
	template class TImage<Efloat>;
	template class TImage<Edouble>;
	template class TImage<Ergb5>;
	template class TImage<Ergb8>;
	
	template class TImage2D<Echar>;
	template class TImage2D<Euchar>;
	template class TImage2D<Eshort>;
	template class TImage2D<Eushort>;
	template class TImage2D<Eint>;
	template class TImage2D<Euint>;
	template class TImage2D<Elong>;
	template class TImage2D<Eulong>;
	template class TImage2D<Efloat>;
	template class TImage2D<Edouble>;
	template class TImage2D<Ergb5>;
	template class TImage2D<Ergb8>;
	
	template class TImage3D<Echar>;
	template class TImage3D<Euchar>;
	template class TImage3D<Eshort>;
	template class TImage3D<Eushort>;
	template class TImage3D<Eint>;
	template class TImage3D<Euint>;
	template class TImage3D<Elong>;
	template class TImage3D<Eulong>;
	template class TImage3D<Efloat>;
	template class TImage3D<Edouble>;
	template class TImage3D<Ergb5>;
	template class TImage3D<Ergb8>;
}

