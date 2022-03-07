// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:14)

#ifndef MATHEMATICS_MESHES_ET_MANIFOLD_MESH_H
#define MATHEMATICS_MESHES_ET_MANIFOLD_MESH_H

#include "Mathematics/MathematicsDll.h"

#include "EdgeKey.h"
#include "TriangleKey.h"

#include <map>

namespace Mathematics
{
    class ETManifoldMesh
    {
    public:
        // Edge data types.
        class Edge;
        typedef Edge* EPtr;
        typedef const Edge* ECPtr;
        typedef EPtr (*ECreator)(int, int);
        typedef std::map<EdgeKey, Edge*> EMap;
        typedef EMap::iterator EMapIterator;
        typedef EMap::const_iterator EMapCIterator;

        // Triangle data types.
        class Triangle;
        typedef Triangle* TPtr;
        typedef const Triangle* TCPtr;
        typedef TPtr (*TCreator)(int, int, int);
        typedef std::map<TriangleKey, Triangle*> TMap;
        typedef TMap::iterator TMapIterator;
        typedef TMap::const_iterator TMapCIterator;

        // Edge object.
        class Edge
        {
        public:
            Edge(int v0, int v1) noexcept;
            virtual ~Edge() noexcept;
            Edge(const Edge&) = default;
            Edge& operator=(const Edge&) = default;
            Edge(Edge&&) = default;
            Edge& operator=(Edge&&) = default;

            int V[2];
            TPtr T[2];
        };

        // Triangle object.
        class Triangle
        {
        public:
            Triangle(int v0, int v1, int v2) noexcept;
            virtual ~Triangle() noexcept;
            Triangle(const Triangle&) = default;
            Triangle& operator=(const Triangle&) = default;
            Triangle(Triangle&&) = default;
            Triangle& operator=(Triangle&&) = default;

            // Vertices, listed in counterclockwise order (V[0],V[1],V[2]).
            int V[3];

            // Adjacent edges:
            //   E[0] points to edge (V[0],V[1])
            //   E[1] points to edge (V[1],V[2])
            //   E[2] points to edge (V[2],V[0])
            EPtr E[3];

            // Adjacent triangles:
            //   T[0] points to triangle sharing edge E[0]
            //   T[1] points to triangle sharing edge E[1]
            //   T[2] points to triangle sharing edge E[2]
            TPtr T[3];
        };

        // Construction and destruction.
        ETManifoldMesh(ECreator eCreator = 0, TCreator tCreator = 0) noexcept;
        virtual ~ETManifoldMesh();

        ETManifoldMesh(const ETManifoldMesh&) = default;
        ETManifoldMesh& operator=(const ETManifoldMesh&) = default;
        ETManifoldMesh(ETManifoldMesh&&) = default;
        ETManifoldMesh& operator=(ETManifoldMesh&&) = default;

        // Member access.
        const EMap& GetEdges() const noexcept;
        const TMap& GetTriangles() const noexcept;

        // Mesh manipulation.
        TPtr InsertTriangle(int v0, int v1, int v2);
        bool RemoveTriangle(int v0, int v1, int v2);

        // Manifold mesh is closed if each edge is shared twice.
        bool IsClosed() const noexcept;

        // For debugging.
        void Print(const char* acFilename);

    protected:
        // The edge data.
        static EPtr CreateEdge(int v0, int v1) noexcept;
        ECreator mECreator;
        EMap mEMap;

        // The triangle data.
        static TPtr CreateTriangle(int v0, int v1, int v2) noexcept;
        TCreator mTCreator;
        TMap mTMap;
    };
}

#endif  // MATHEMATICS_MESHES_ET_MANIFOLD_MESH_H
