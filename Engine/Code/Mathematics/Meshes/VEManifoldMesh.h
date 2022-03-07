// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:16)

#ifndef MATHEMATICS_MESHES_VE_MANIFOLD_MESH_H
#define MATHEMATICS_MESHES_VE_MANIFOLD_MESH_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning.h"
#include <map>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
namespace Mathematics
{
    class VEManifoldMesh
    {
    public:
        // Vertex data types.
        class Vertex;
        typedef Vertex* VPtr;
        typedef const Vertex* VCPtr;
        typedef VPtr (*VCreator)(int);
        typedef std::map<int, Vertex*> VMap;
        typedef VMap::iterator VMapIterator;
        typedef VMap::const_iterator VMapCIterator;

        // Edge data types.
        class Edge;
        typedef Edge* EPtr;
        typedef const Edge* ECPtr;
        typedef EPtr (*ECreator)(int, int);
        typedef std::map<std::pair<int, int>, Edge*> EMap;
        typedef EMap::iterator EMapIterator;
        typedef EMap::const_iterator EMapCIterator;

        // Vertex object.
        class MATHEMATICS_DEFAULT_DECLARE Vertex
        {
        public:
            Vertex(int v) noexcept;
            virtual ~Vertex();
            Vertex(const Vertex&) = default;
            Vertex& operator=(const Vertex&) = default;
            Vertex(Vertex&&) = default;
            Vertex& operator=(Vertex&&) = default;
            int V;
            EPtr E[2];
        };

        // Edge object.
        class MATHEMATICS_DEFAULT_DECLARE Edge
        {
        public:
            Edge(int v0, int v1) noexcept;
            virtual ~Edge();
            Edge(const Edge&) = default;
            Edge& operator=(const Edge&) = default;
            Edge(Edge&&) = default;
            Edge& operator=(Edge&&) = default;
            // Vertices, listed as a directed edge <V[0],V[1]>.
            int V[2];

            // Adjacent edges:
            //   T[0] points to edge sharing V[0]
            //   T[1] points to edge sharing V[1]
            EPtr E[2];
        };

        // Construction and destruction.
        VEManifoldMesh(VCreator vCreator = 0, ECreator eCreator = 0) noexcept;
        virtual ~VEManifoldMesh();
        VEManifoldMesh(const VEManifoldMesh&) = default;
        VEManifoldMesh& operator=(const VEManifoldMesh&) = default;
        VEManifoldMesh(VEManifoldMesh&&) = default;
        VEManifoldMesh& operator=(VEManifoldMesh&&) = default;
        // Member access.
        const VMap& GetVertices() const noexcept;
        const EMap& GetEdges() const noexcept;

        // Mesh manipulation.
        EPtr InsertEdge(int v0, int v1);
        bool RemoveEdge(int v0, int v1);

        // Manifold mesh is closed if each vertex is shared twice.
        bool IsClosed() const noexcept;

        // For debugging.
        void Print(const char* filename);

    protected:
        // The vertex data.
        static VPtr CreateVertex(int v0) noexcept;
        VCreator mVCreator;
        VMap mVMap;

        // The edge data.
        static EPtr CreateEdge(int v0, int v1) noexcept;
        ECreator mECreator;
        EMap mEMap;
    };
}
#include STSTEM_WARNING_POP
#endif  // MATHEMATICS_MESHES_VE_MANIFOLD_MESH_H
