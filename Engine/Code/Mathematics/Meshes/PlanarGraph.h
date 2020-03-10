// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:15)

#ifndef MATHEMATICS_MESHES_PLANAR_GRAPH_H
#define MATHEMATICS_MESHES_PLANAR_GRAPH_H

#include "Mathematics/MathematicsDll.h"

#include "EdgeKey.h"
#include "CoreTools/Helper/MemoryMacro.h"

// The Point2 template class must represent a 2-tuple, each component of some
// scalar type Numeric.  Point2 must define the following member functions.
//     Point2::Point2 ();
//     Point2::(Numeric, Numeric);
//     Point2::~Point2 ();
//     Point2& Point2::operator= (const Point2&);
//     Point2 Point2::operator- (const Point2&) const;
//     Numeric Point2::operator[] (int i) const;

namespace Mathematics
{
	template <typename Point2>
	class PlanarGraph
	{
	public:
		PlanarGraph ();
		virtual ~PlanarGraph ();
		
		class Vertex
		{
		public:
			Vertex (const Point2& position, int index);
			~Vertex ();
			
			void Insert (Vertex* adjacent);
			void Remove (Vertex* adjacent);
			
			// The planar position for the vertex.
			Point2 Position;
			
			// A unique identifier for the vertex.
			int Index;
			
			// The adjacent vertices.
			std::vector<Vertex*> Adjacent;
		};
		
		typedef std::map<int,Vertex*> Vertices;
		typedef std::map<EdgeKey,bool> Edges;
		
		const Vertices& GetVertices () const;
		const Vertex* GetVertex (int iIndex) const;
		bool InsertVertex (const Point2& position, int iIndex);
		bool RemoveVertex (int iIndex);
		
		const Edges& GetEdges () const;
		bool InsertEdge (int iIndex0, int iIndex1);
		bool RemoveEdge (int iIndex0, int iIndex1);
		
		// Traverse the graph and extract the isolated vertices, filaments, and
		// minimal cycles.  See MinimalCycleBasis.pdf for the details.
		
		enum PrimitiveType
		{
			PT_ISOLATED_VERTEX,
			PT_FILAMENT,
			PT_MINIMAL_CYCLE
		};
		
		class Primitive
		{
		public:
			Primitive (PrimitiveType type);
			
			PrimitiveType Type;
			std::vector<std::pair<Point2,int> > Sequence;
		};
		
		// The extraction of primitives destroys the graph.  If you need the
		// graph to persist, make a copy of it and call this function from the
		// copy.
		void ExtractPrimitives (std::vector<Primitive*>& primitives);
		
	protected:
		// For sorting of the heap of vertex pointers.
		class VertexPtr
		{
		public:
			VertexPtr (Vertex* vertex);
			
			inline operator Vertex* ()
			{
				return mVertex;
			}
			
			// Lexicographical ordering of vertices.  The query (x0,y0) < (x1,y1)
			// is true iff ((x0 < x1) || ((x0 == x1) && (y0 < y1))).
			bool operator< (const VertexPtr& vertexPtr) const;
			
		private:
			Vertex* mVertex;
		};
		
		void SetCycleEdge (int index0, int index1, bool cycleEdge);
		bool GetCycleEdge (int index0, int index1) const;
		
		void ExtractIsolatedVertex (Vertex* V0, std::set<VertexPtr>& heap, std::vector<Primitive*>& primitives);
		
		void ExtractFilament (Vertex* V0, Vertex* V1,  std::set<VertexPtr>& heap, std::vector<Primitive*>& primitives);
		
		void ExtractPrimitive (Vertex* V0, std::set<VertexPtr>& heap,   std::vector<Primitive*>& primitives);
		
		Vertex* GetClockwiseMost (Vertex* VPrev, Vertex* VCurr);
		Vertex* GetCounterclockwiseMost (Vertex* VPrev, Vertex* VCurr);
		
		Vertices mVertices;
		Edges mEdges;
	};
}

#endif // MATHEMATICS_MESHES_PLANAR_GRAPH_H
