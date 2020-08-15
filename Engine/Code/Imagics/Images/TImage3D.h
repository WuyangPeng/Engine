// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:14)

#ifndef IMAGICS_IMAGICS_TIMAGE3D_H
#define IMAGICS_IMAGICS_TIMAGE3D_H

#include "Imagics/ImagicsDll.h"

#include "TImage.h"

namespace Imagics
{
	template <typename T>
	class TImage3D : public TImage<T>
	{
	public:
		// Construction and destruction.  TImage3D accepts responsibility for
		// deleting the input data array.
		TImage3D (int xBound, int yBound, int zBound, T* data = 0);
		TImage3D (const TImage3D& image);
		TImage3D (const char* filename);
		
		// Data access.
		T& operator() (int x, int y, int z) const noexcept;
		
		// Conversion between 3D coordinates and 1D indexing.
		int GetIndex (int x, int y, int z) const noexcept;
		void GetCoordinates (int index, int& x, int& y, int& z) const noexcept;
		
		// Assignment.
		TImage3D& operator= (const TImage3D& image);
                TImage3D& operator=(T value) noexcept;
		
		~TImage3D() = default;
		TImage3D& operator= (TImage3D&& image)= default;
		TImage3D (TImage3D&& image)= default;
		
	protected:
		using TImage<T>::SetBounds;
		using TImage<T>::SetData;
		using TImage<T>::mBounds;
		using TImage<T>::mData;
	};
}

#endif // IMAGICS_IMAGICS_TIMAGE3D_H
