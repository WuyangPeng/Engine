// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:02)

#ifndef IMAGICS_EXTRACTION_EXTRACT_SURFACE_TETRA_H
#define IMAGICS_EXTRACTION_EXTRACT_SURFACE_TETRA_H

#include "Imagics/ImagicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Meshes/EdgeKey.h" 
#include "Mathematics/Meshes/TriangleKey.h" 

#include <map>
#include <set>
#include <vector>

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE ExtractSurfaceTetra
	{
	public:
		// The input is a 3D image with lexicographically ordered voxels in
		// (x,y,z) stored in a linear array.  Voxel (x,y,z) is stored in the
		// array at location x+xbound*(y+ybound*z).  The caller is responsible
		// for deleting data if it was dynamically allocated.
		ExtractSurfaceTetra (int xBound, int yBound, int zBound, int* data) noexcept;
		
		// The extraction assumes linear interpolation (decomposition of image
		// domain into tetrahedra).  The triangle ordering is selected so that
		// the triangle is counterclockwise with respect to the triangle normal
		// chosen to form an acute angle with the negative gradient of the
		// image at the centroid of the triangle.
		void ExtractContour(int level, std::vector<Mathematics::FloatVector3D>& vertices, std::vector<Mathematics::TriangleKey>& triangles);
		
		// The extraction has duplicate vertices on edges shared by voxels.  This
		// function will eliminate the duplication.
		void MakeUnique(std::vector<Mathematics::FloatVector3D>& vertices, std::vector<Mathematics::TriangleKey>& triangles);
		
		// The extraction does not use any topological information about the level
		// surface.  The triangles can be a mixture of clockwise-ordered and
		// counterclockwise-ordered.  This function is an attempt to give the
		// triangles a consistent ordering by selecting a normal in approximately
		// the same direction as the average gradient at the vertices (when
		// sameDir is true), or in the opposite direction (when sameDir is
		// false).  This might not always produce a consistent order, but is
		// fast.  A consistent order can be computed if you build a table of
		// vertex, edge, and face adjacencies, but the resulting data structure
		// is very expensive to process to reorient triangles.
		void OrientTriangles(std::vector<Mathematics::FloatVector3D>& vertices, std::vector<Mathematics::TriangleKey>& triangles, bool sameDir);
		
		// In case you want vertex normals for dynamic lighting of the mesh.
		void ComputeNormals(const std::vector<Mathematics::FloatVector3D>& vertices, const std::vector<Mathematics::TriangleKey>& triangles, std::vector<Mathematics::FloatVector3D>& normals);
		
	protected:
		class Vertex
		{
		public:
			Vertex (int xNumer = 0, int xDenom = 0, int yNumer = 0, int yDenom = 0, int zNumer = 0, int zDenom = 0) noexcept;
			
			// For STL maps.
			bool operator< (const Vertex& vertex) const noexcept;
			
			void GetTriple(Mathematics::FloatVector3D& meshVertex) const noexcept;
			
			// Vertices stored as rational numbers:
			//   (xnumer/xdenom, ynumer/ydenom, znumer/zdenom)
			int XNumer, XDenom, YNumer, YDenom, ZNumer, ZDenom;
		};
		
		// Support for extraction of level sets.
		typedef std::map<Vertex,int> VtxMap;
		typedef VtxMap::iterator VtxMapIterator;
		typedef std::set<Mathematics::EdgeKey> ESet;
		typedef ESet::iterator ESetIterator;
		typedef std::set<Mathematics::TriangleKey> TriSet;
		typedef TriSet::iterator TSetIterator;
		
		int AddVertex (VtxMap& vertexMap, int xNumer, int xDenom, int yNumer, int yDenom, int zNumer, int zDenom);
		
		void AddEdge (VtxMap& vertexMap, ESet& edgeSet, int xNumer0, int xDenom0, int yNumer0, int yDenom0, int zNumer0, int zDenom0,
					  int xNumer1, int xDenom1, int yNumer1, int yDenom1, int zNumer1, int zDenom1);
		
		void AddTriangle (VtxMap& vertexMap, ESet& edgeSet, TriSet& triangleSet, int xNumer0, int xDenom0, int yNumer0, int yDenom0, int zNumer0,
						  int zDenom0, int xNumer1, int xDenom1, int yNumer1, int yDenom1, int zNumer1, int zDenom1, int xNumer2, int xDenom2, int yNumer2, int yDenom2, int zNumer2, int zDenom2);
		
		// Support for extraction with linear interpolation.
		void ProcessTetrahedron (VtxMap& vertexMap, ESet& edgeSet, TriSet& triangleSet, int x0, int y0, int z0, int f0, int x1, int y1,
                                 int z1, int f1, int x2, int y2, int z2, int f2, int x3, int y3, int z3, int f3);
		
		// Function and gradient evaluated using trilinear interpolation.
                float GetFunction(const Mathematics::FloatVector3D& P) const noexcept;
                Mathematics::FloatVector3D GetGradient(const Mathematics::FloatVector3D& P) const noexcept;
		
		// For unique indexing of vertices.
		int mNextIndex = 0;
		
		int mXBound, mYBound, mZBound, mXYBound, mXYZBound;
		int* mData;
	};
}

#endif // IMAGICS_EXTRACTION_EXTRACT_SURFACE_TETRA_H
