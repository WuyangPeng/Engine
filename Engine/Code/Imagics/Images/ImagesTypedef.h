// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:03)

#ifndef IMAGICS_IMAGICS_IMAGICS_TYPEDEF_H
#define IMAGICS_IMAGICS_IMAGICS_TYPEDEF_H

#include "Imagics/ImagicsDll.h"

#include "Element.h"
#include "TImage.h"
#include "TImage2D.h"
#include "TImage3D.h"

namespace Imagics
{
	using ImageChar = TImage<Echar>;
	using ImageUChar = TImage<Euchar>;
	using ImageShort = TImage<Eshort>;
	using ImageUShort = TImage<Eushort>;
	using ImageInt = TImage<Eint>;
	using ImageUInt = TImage<Euint>;
	using ImageLong = TImage<Elong>;
	using ImageULong = TImage<Eulong>;
	using ImageFloat = TImage<Efloat>;
	using ImageDouble = TImage<Edouble>;
	using ImageRGB5 = TImage<Ergb5>;
	using ImageRGB8 = TImage<Ergb8>;
	
	using ImageChar2D = TImage2D<Echar>;
	using ImageUChar2D = TImage2D<Euchar>;
	using ImageShort2D = TImage2D<Eshort>;
	using ImageUShort2D = TImage2D<Eushort>;
	using ImageInt2D = TImage2D<Eint>;
	using ImageUInt2D = TImage2D<Euint>;
	using ImageLong2D = TImage2D<Elong>;
	using ImageULong2D = TImage2D<Eulong>;
	using ImageFloat2D = TImage2D<Efloat>;
	using ImageDouble2D = TImage2D<Edouble>;
	using ImageRGB52D = TImage2D<Ergb5>;
	using ImageRGB82D = TImage2D<Ergb8>;
	
	using ImageChar3D = TImage3D<Echar>;
	using ImageUChar3D = TImage3D<Euchar>;
	using ImageShort3D = TImage3D<Eshort>;
	using ImageUShort3D = TImage3D<Eushort>;
	using ImageInt3D = TImage3D<Eint>;
	using ImageUInt3D = TImage3D<Euint>;
	using ImageLong3D = TImage3D<Elong>;
	using ImageULong3D = TImage3D<Eulong>;
	using ImageFloat3D = TImage3D<Efloat>;
	using ImageDouble3D = TImage3D<Edouble>;
	using ImageRGB53D = TImage3D<Ergb5>;
	using ImageRGB83D = TImage3D<Ergb8>;
}

#endif // IMAGICS_IMAGICS_IMAGICS_TYPEDEF_H
