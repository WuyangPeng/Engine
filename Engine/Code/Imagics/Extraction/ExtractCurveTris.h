// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:01)

#ifndef IMAGICS_EXTRACTION_EXTRACT_CURVE_TRIS_H
#define IMAGICS_EXTRACTION_EXTRACT_CURVE_TRIS_H

#include "Imagics/ImagicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Meshes/EdgeKey.h"

#include <vector>

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE ExtractCurveTris
	{
	public:		
		typedef Mathematics::EdgeKey EdgeKey;

	public:
		// The input is a 2D image with lexicographically ordered pixels (x,y)
		// stored in a linear array.  Pixel (x,y) is stored in the array at
		// location x+xbound*y.  The caller is responsible for deleting data if
		// it was dynamically allocated.
		ExtractCurveTris (int xBound, int yBound, int* data) noexcept;
		
		// Extract a level curve of the specified level value.
		void ExtractContour (int level, std::vector<Mathematics::Vector2F>& vertices, std::vector<EdgeKey>& edges);
		
		// The extraction has duplicate vertices on edges shared by pixels.  This
		// function will eliminate the duplication.
		void MakeUnique (std::vector<Mathematics::Vector2F>& vertices, std::vector<EdgeKey>& edges);

	protected:
		// Since the level value is an integer, the vertices of the extracted
		// level curve are stored internally as rational numbers.
		class Vertex
		{
		public:
			Vertex (int xNumer = 0, int xDenom = 0, int yNumer = 0,int yDenom = 0) noexcept;
			
			int XNumer, XDenom, YNumer, YDenom;
		};
		
		void AddVertex (std::vector<Vertex>& vertices, int xNumer, int xDenom,int yNumer, int yDenom);
		
		void AddEdge (std::vector<Vertex>& vertices, std::vector<EdgeKey>& edges,  int xNumer0, int xDenom0, int yNumer0, int yDenom0, int xNumer1, int xDenom1, int yNumer1, int yDenom1);
		
		void ProcessTriangle (std::vector<Vertex>& vertices, std::vector<EdgeKey>& edges, int x0, int y0, int f0, int x1,
							  int y1, int f1, int x2, int y2, int f2);
		
		int mXBound, mYBound, mQuantity;
		int* mData;
	};
}

#endif // IMAGICS_EXTRACTION_EXTRACT_CURVE_TRIS_H
