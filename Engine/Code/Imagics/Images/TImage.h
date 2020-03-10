// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:14)

#ifndef IMAGICS_IMAGICS_TIMAGE_H
#define IMAGICS_IMAGICS_TIMAGE_H

#include "Imagics/ImagicsDll.h"

#include "ImageConvert.h"
#include "Lattice.h"

namespace Imagics
{
	// The typename T is intended to be a wrapper of native data (int, float,
	// char, etc.).  The code uses memcpy, memcmp, and memset on the array of T
	// values.  Typename T must have the following member functions:
	//   T::T ()
	//   T& T::operator= (T)
	//   static const char* GetRTTI ()
	// The static member function returns a string that is used for streaming.
		
	template <typename T>
	class TImage : public Lattice
	{
	public:
		// Construction and destruction.  TImage accepts responsibility for
		// deleting the input arrays.
		TImage (int numDimensions, int* bounds, T* data = 0);
		TImage (const TImage& image);
		TImage (const char* filename);
		virtual ~TImage ();
		
		// Data access.
		T* GetData () const;
		T& operator[] (int i) const;
		
		// Assignment.
		TImage& operator= (const TImage& image);
		TImage& operator= (T value);
		
		// Comparison.
		bool operator== (const TImage& image) const;
		bool operator!= (const TImage& image) const;
		
		// Streaming.
		bool Load (const char* filename);
		bool Save (const char* filename) const;
		
	protected:
		// For deferred creation of bounds.
		TImage (int numDimensions);
		void SetData (T* data);
		
		T* mData;
	};
}

#endif // IMAGICS_IMAGICS_TIMAGE_H
