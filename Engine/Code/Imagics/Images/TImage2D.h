// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:14)

#ifndef IMAGICS_IMAGICS_TIMAGE2D_H
#define IMAGICS_IMAGICS_TIMAGE2D_H

#include "Imagics/ImagicsDll.h"

#include "TImage.h"

namespace Imagics
{
	template <typename T>
	class TImage2D : public TImage<T>
	{
	public:
		// Construction and destruction.  TImage2D accepts responsibility for
		// deleting the input data array.
		TImage2D (int xBound, int yBound, T* data = 0);
		TImage2D (const TImage2D& image);
		TImage2D (const char* filename);
		~TImage2D() = default;
		
		// Data access.
		T& operator() (int x, int y) const noexcept;
		
		// Conversion between 2D coordinates and 1D indexing.
		int GetIndex (int x, int y) const noexcept;
		void GetCoordinates (int index, int& x, int& y) const noexcept;
		
		// Assignment.
		TImage2D& operator= (const TImage2D& image);
                TImage2D& operator=(T value) noexcept;
		
		TImage2D& operator= (TImage2D&& image)= default;
		TImage2D (TImage2D&& image)= default;
		
	protected:
		using TImage<T>::SetBounds;
		using TImage<T>::SetData;
		using TImage<T>::mBounds;
		using TImage<T>::mData;
	};
}

#endif // IMAGICS_IMAGICS_TIMAGE2D_H
