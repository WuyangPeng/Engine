// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 14:51)

#ifndef IMAGICS_BINARY_OPERATIONS_BINARY3D_H
#define IMAGICS_BINARY_OPERATIONS_BINARY3D_H

#include "Imagics/ImagicsDll.h"

#include "Imagics/Images/ImagesTypedef.h"

#include <vector>

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE Binary3D
	{
	public:
		// Operations on binary images.  Let the image have b0 columns, b1 rows,
		// and b2 slices.  The input image must have zeros on its boundaries
		// x = 0, x = b0-1, y = 0, y = b1-1, z = 0, and z = b2-1.  The 0-valued
		// pixels are considered to be background.  Non-zero pixels are considered
		// to be foreground, although typically these are 1-valued.
		
		// Some of the operations return collections of indices.  An index i
		// corresponds to coordinates
		//   (x,y,z) = (i % b0, (i / b0) % b1, (i / b0) / b1)
		using IndexArray = std::vector<int>;
		
		// Compute the 26-connected components of a binary image.  The input
		// image is modified to avoid the cost of making a copy.  On output,
		// the image values are the labels for the components.  If storeZeros is
		// true, components[0] contains the indices for the background pixels;
		// otherwise, this array is empty.  When the background is large, the
		// construction of components[0] is time consuming.  The array
		// components[i], i >= 1, contains the indices for the i-th component.
		static void GetComponents26 (ImageInt3D& image, bool storeZeros, std::vector<IndexArray>& components);
		
		// Compute the 18-connected components of a binary image.  The input
		// image is modified to avoid the cost of making a copy.  On output,
		// the image values are the labels for the components.  If storeZeros is
		// true, components[0] contains the indices for the background pixels;
		// otherwise, this array is empty.  When the background is large, the
		// construction of components[0] is time consuming.  The array
		// components[i], i >= 1, contains the indices for the i-th component.
		static void GetComponents18 (ImageInt3D& image, bool storeZeros, std::vector<IndexArray>& components);
		
		// Compute the 6-connected components of a binary image.  The input
		// image is modified to avoid the cost of making a copy.  On output,
		// the image values are the labels for the components.  If storeZeros is
		// true, components[0] contains the indices for the background pixels;
		// otherwise, this array is empty.  When the background is large, the
		// construction of components[0] is time consuming.  The array
		// components[i], i >= 1, contains the indices for the i-th component.
		static void GetComponents6 (ImageInt3D& image, bool storeZeros, std::vector<IndexArray>& components);
		
	private:
		// The heart of the component labeling.
		static void GetComponents (const int numNeighbors, const int delta[], bool storeZeros, ImageInt3D& image, std::vector<IndexArray>& components);
	};
}

#endif // IMAGICS_BINARY_OPERATIONS_BINARY3D_H
