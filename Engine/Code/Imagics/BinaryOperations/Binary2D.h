// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/30 14:51)

#ifndef IMAGICS_BINARY_OPERATIONS_BINARY2D_H
#define IMAGICS_BINARY_OPERATIONS_BINARY2D_H

#include "Imagics/ImagicsDll.h"

#include "Imagics/Images/ImagesTypedef.h"

#include <vector>

namespace Imagics
{
    class IMAGICS_DEFAULT_DECLARE Binary2D
    {
    public:
        // Operations on binary images.  Let the image have b0 columns and b1
        // rows.  The input image must have zeros on its boundaries x = 0,
        // x = b0-1, y = 0, and y = b1-1.  The 0-valued pixels are considered
        // to be background.  The 1-valued pixels are considered to be foreground.
        // Comments about the algorithms are provided in the cpp file.  To save
        // the memory and time, the input image is modified by the algorithms.
        // If you need to preserve the input image, make a copy of it before
        // calling these functions.

        // Some of the operations return collections of indices.  An index i
        // corresponds to coordinates (x,y) = (i % b0, i / b0).
        using IndexArray = std::vector<int>;

        // Extract boundaries from 1-valued blobs.  The blob interiors are
        // 4-connected and the blob boundaries are 8-connected.  The output is
        // an array of boundaries, each boundary containing a list of pixels
        // in clockwise order in the right-handed (x,y) system [counterclockwise
        // in the left-handed (x,y) system].
        static void GetBoundaries(const ImageInt2D& image, std::vector<IndexArray>& boundaries);

        // Compute the 8-connected components of a binary image.  The input
        // image is modified to avoid the cost of making a copy.  On output,
        // the image values are the labels for the components.  If storeZeros is
        // true, components[0] contains the indices for the background pixels;
        // otherwise, this array is empty.  When the background is large, the
        // construction of components[0] is time consuming.  The array
        // components[i], i >= 1, contains the indices for the i-th component.
        static void GetComponents8(const ImageInt2D& image, bool storeZeros, std::vector<IndexArray>& components);

        // Compute the 4-connected components of a binary image.  The input
        // image is modified to avoid the cost of making a copy.  On output,
        // the image values are the labels for the components.  If storeZeros is
        // true, components[0] contains the indices for the background pixels;
        // otherwise, this array is empty.  When the background is large, the
        // construction of components[0] is time consuming.  The array
        // components[i], i >= 1, contains the indices for the i-th component.
        static void GetComponents4(const ImageInt2D& image, bool storeZeros, std::vector<IndexArray>& components);

        // Compute the L1 distance transform.  Given a pixel (x,y), the neighbors
        // (x+1,y), (x-1,y), (x,y+1), and (x,y-1) are 1 unit of distance from
        // (x,y).  The neighbors (x+1,y+1), (x+1,y-1), (x-1,y+1), and (x-1,y-1)
        // are 2 units of distance from (x,y).  On output, the image is the
        // distance transform.
        static void GetL1Distance(const ImageInt2D& image, int& maxDistance) noexcept;

        // Compute the L2 distance transform (Euclidean distance transform).  The
        // distances are exact as long as they are smaller than 100 (see the
        // comments in the source code).  The 'transform' should be the same
        // dimensions as 'image' and its values are all set in this function, so
        // it does not matter what they are on input.
        static void GetL2Distance(const ImageInt2D& image, double& maxDistance, const ImageDouble2D& transform);

        // Compute a skeleton of the image.  Pixels are trimmed from outside to
        // inside using L1 distance.  Connectivity and cycles of the original
        // blobs are preserved.  The 'skeleton' should be the same dimensions as
        // 'image' and its values are all set in this function, so it does not
        // matter what they are on input.  On output, the image is the skeleton.
        static void GetSkeleton(const ImageInt2D& image) noexcept;

    protected:
        // The heart of the boundary extraction.
        static void ExtractBoundary(int x0, int y0, const ImageInt2D& image, IndexArray& boundary);

        // The heart of the component labeling.
        static void GetComponents(const int numNeighbors, const int delta[], bool storeZeros, const ImageInt2D& image, std::vector<IndexArray>& components);

        // Helper for computing the L2 distance transform.
        static void L2Check(int x, int y, int dx, int dy, const ImageInt2D& xNear, const ImageInt2D& yNear, const ImageInt2D& dist) noexcept;

        // Helpers for skeletonization.
        typedef bool (*InteriorFunction)(const ImageInt2D&, int, int);
        static bool Interior4(const ImageInt2D& image, int x, int y) noexcept;
        static bool Interior3(const ImageInt2D& image, int x, int y) noexcept;
        static bool Interior2(const ImageInt2D& image, int x, int y) noexcept;
        static bool MarkInterior(const ImageInt2D& image, int value, InteriorFunction function) noexcept;
        static bool IsArticulation(const ImageInt2D& image, int x, int y) noexcept;
        static bool ClearInteriorAdjacent(const ImageInt2D& image, int value) noexcept;
        static const int msArticulation[256];
    };
}

#endif  // IMAGICS_BINARY_OPERATIONS_BINARY2D_H
