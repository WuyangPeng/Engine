// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 17:32)

#ifndef PHYSICS_INTERSECTION_EXTREMAL_QUERY3BSP_DETAIL_H
#define PHYSICS_INTERSECTION_EXTREMAL_QUERY3BSP_DETAIL_H

#include "ExtremalQuery3BSP.h"

#if !defined(PHYSICS_EXPORT_TEMPLATE) || defined(PHYSICS_INCLUDED_EXTREMAL_QUERY3BSP_DETAIL)

    #include "CoreTools/Helper/Assertion/PhysicsCustomAssertMacro.h"
    #include "Mathematics/Algebra/Vector3ToolsDetail.h"
    #include "Mathematics/Meshes/BasicMesh.h"
    #include "Mathematics/Objects3D/ConvexPolyhedron3Detail.h"
    #include <queue>
    #include <stack>

    #include "System/Helper/PragmaWarning.h"
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)
    #include SYSTEM_WARNING_DISABLE(26482)
    #include SYSTEM_WARNING_DISABLE(26446)
    #include SYSTEM_WARNING_DISABLE(26486)
    #include SYSTEM_WARNING_DISABLE(26489)
    #include SYSTEM_WARNING_DISABLE(26429)
    #include SYSTEM_WARNING_DISABLE(26472)
    #include SYSTEM_WARNING_DISABLE(26492)

namespace Physics
{
    template <typename Real>
    ExtremalQuery3BSP<Real>::ExtremalQuery3BSP(const ConvexPolyhedron3* polytope)
        : ExtremalQuery3<Real>(polytope)
    {
        // Create the adjacency information for the polytope.
        const int numVertices = mPolytope->GetNumVertices();
        const auto vertices = mPolytope->GetVertices();
        const int numTriangles = mPolytope->GetNumTriangles();
        const auto indices = mPolytope->GetIndices();
        BasicMesh mesh(numVertices, numTriangles, indices);

        // Create the set of unique arcs which are used to create the BSP tree.
        std::multiset<SphericalArc> arcs;
        CreateSphericalArcs(mesh, arcs);

        // Create the BSP tree to be used in the extremal query.
        std::vector<SphericalArc> nodes;
        CreateBSPTree(arcs, nodes);

        // Copy the nodes into a single, nonresizeable array.
        mNumNodes = static_cast<int>(nodes.size());
        mNodes = nullptr;  //NEW1<SphericalArc>(mNumNodes);
        memcpy(mNodes, &nodes.front(), mNumNodes * sizeof(SphericalArc));
    }

    template <typename Real>
    ExtremalQuery3BSP<Real>::~ExtremalQuery3BSP()
    {
        EXCEPTION_TRY
        {
            //DELETE1(mNodes);
        }
        EXCEPTION_ALL_CATCH(Physics)
    }

    template <typename Real>
    void ExtremalQuery3BSP<Real>::GetExtremeVertices(const typename ExtremalQuery3<Real>::Vector3D& direction, int& positiveDirection, int& negativeDirection) noexcept
    {
        // Do a nonrecursive depth-first search of the BSP tree to determine
        // spherical polygon contains the incoming direction D.  Index 0 is the
        // root of the BSP tree.
        int current = 0;
        while (current >= 0)
        {
            SphericalArc& node = mNodes[current];
            const int sign = static_cast<int>(Mathematics::Math<Real>::Sign(Mathematics::Vector3Tools<Real>::DotProduct(direction, node.Normal)));
            if (sign >= 0)
            {
                current = node.PosChild;
                if (current == -1)
                {
                    // At a leaf node.
                    positiveDirection = node.PosVertex;
                }
            }
            else
            {
                current = node.NegChild;
                if (current == -1)
                {
                    // At a leaf node.
                    positiveDirection = node.NegVertex;
                }
            }
        }

        // Do a nonrecursive depth-first search of the BSP tree to determine
        // spherical polygon contains the reverse incoming direction -D.
        current = 0;  // the root of the BSP tree
        while (current >= 0)
        {
            SphericalArc& node = mNodes[current];
            const int sign = static_cast<int>(-Mathematics::Math<Real>::Sign(Mathematics::Vector3Tools<Real>::DotProduct(direction, node.Normal)));
            if (sign >= 0)
            {
                current = node.PosChild;
                if (current == -1)
                {
                    // At a leaf node.
                    negativeDirection = node.PosVertex;
                }
            }
            else
            {
                current = node.NegChild;
                if (current == -1)
                {
                    // At a leaf node.
                    negativeDirection = node.NegVertex;
                }
            }
        }
    }

    template <typename Real>
    int ExtremalQuery3BSP<Real>::GetNumNodes() const noexcept
    {
        return mNumNodes;
    }

    template <typename Real>
    int ExtremalQuery3BSP<Real>::GetTreeDepth() const noexcept
    {
        return mTreeDepth;
    }

    template <typename Real>
    void ExtremalQuery3BSP<Real>::SortVertexAdjacents(const BasicMesh& mesh)
    {
        // The typecast is to allow modifying the vertices.  As long as the
        // sorting algorithm is correct, this is a safe thing to do.
        const int numVertices = mesh.GetNumVertices();
        auto vertices = mesh.GetVertices();

        const auto triangles = mesh.GetTriangles();
        for (int i = 0; i < numVertices; ++i)
        {
            // This copy circumvents the constness of the mesh vertices, which
            // allows the sorting of the mesh triangles shared by a mesh vertex.
            BasicMesh::Vertex& vertex = vertices[i];

            // This is a consequence of the mesh being a polyhedron.
            PHYSICS_ASSERTION_0(vertex.numVertices == vertex.numTriangles, "Unexpected condition\n");

            // Once we have the first vertex to sort and an initial triangle
            // sharing it, we can walk around the vertex following triangle
            // adjacency links.  It is safe to overwrite the vertex data.
            int t = vertex.t[0];
            const BasicMesh::Triangle* tri = &triangles[t];

            for (int adj = 0; adj < vertex.numVertices; ++adj)
            {
                int prev = 0, curr = 0;
                for (prev = 2, curr = 0; curr < 3; prev = curr++)
                {
                    if (tri->v[curr] == i)
                    {
                        vertex.v[adj] = tri->v[prev];
                        vertex.e[adj] = tri->e[prev];
                        vertex.t[adj] = t;

                        // The next triangle to visit.
                        t = tri->t[prev];
                        tri = &triangles[t];
                        break;
                    }
                }
                PHYSICS_ASSERTION_0(curr < 3, "Unexpected condition\n");
            }
        }
    }

    template <typename Real>
    void ExtremalQuery3BSP<Real>::CreateSphericalArcs(const BasicMesh& mesh, std::multiset<SphericalArc>& arcs)
    {
        const int numEdges = mesh.GetNumEdges();
        const auto edges = mesh.GetEdges();
        const auto triangles = mesh.GetTriangles();

        const int prev[3] = { 2, 0, 1 };
        const int next[3] = { 1, 2, 0 };

        for (int i = 0; i < numEdges; ++i)
        {
            const BasicMesh::Edge& edge = edges[i];

            SphericalArc arc;
            arc.NIndex[0] = edge.t[0];
            arc.NIndex[1] = edge.t[1];
            arc.Separation = 1;

            arc.Normal = Mathematics::Vector3Tools<Real>::CrossProduct(mFaceNormals[arc.NIndex[0]], (mFaceNormals[arc.NIndex[1]]));

            const BasicMesh::Triangle& adj = triangles[edge.t[0]];
            int j;
            for (j = 0; j < 3; ++j)
            {
                if (adj.v[j] != edge.v[0] && adj.v[j] != edge.v[1])
                {
                    arc.PosVertex = adj.v[prev[j]];
                    arc.NegVertex = adj.v[next[j]];
                    break;
                }
            }
            PHYSICS_ASSERTION_0(j < 3, "Unexpected condition\n");

            arcs.insert(arc);
        }

        CreateSphericalBisectors(mesh, arcs);
    }

    template <typename Real>
    void ExtremalQuery3BSP<Real>::CreateSphericalBisectors(const BasicMesh& mesh, std::multiset<SphericalArc>& arcs)
    {
        // For each vertex, sort the normals into a counterclockwise spherical
        // polygon when viewed from outside the sphere.
        SortVertexAdjacents(mesh);

        const int numVertices = mesh.GetNumVertices();
        const auto vertices = mesh.GetVertices();
        std::queue<std::pair<int, int>> queue;
        for (int i = 0; i < numVertices; ++i)
        {
            const BasicMesh::Vertex& vertex = vertices[i];

            queue.push(std::make_pair(0, vertex.numTriangles));
            while (!queue.empty())
            {
                const std::pair<int, int> arc = queue.front();
                queue.pop();
                int i0 = arc.first, i1 = arc.second;
                const int separation = i1 - i0;
                if (separation > 1 && separation != vertex.numTriangles - 1)
                {
                    if (i1 < vertex.numTriangles)
                    {
                        SphericalArc sphericalArc;
                        sphericalArc.NIndex[0] = vertex.t[i0];
                        sphericalArc.NIndex[1] = vertex.t[i1];
                        sphericalArc.Separation = separation;

                        sphericalArc.Normal = Mathematics::Vector3Tools<Real>::CrossProduct(mFaceNormals[sphericalArc.NIndex[0]], (mFaceNormals[sphericalArc.NIndex[1]]));

                        sphericalArc.PosVertex = i;
                        sphericalArc.NegVertex = i;
                        arcs.insert(sphericalArc);
                    }
                    int iMid = (i0 + i1 + 1) / 2;
                    if (iMid != i1)
                    {
                        queue.push(std::make_pair(i0, iMid));
                        queue.push(std::make_pair(iMid, i1));
                    }
                }
            }
        }
    }

    template <typename Real>
    void ExtremalQuery3BSP<Real>::CreateBSPTree(std::multiset<SphericalArc>& arcs, std::vector<SphericalArc>& nodes)
    {
        // The tree has at least a root.
        mTreeDepth = 1;

        typename std::multiset<SphericalArc>::reverse_iterator iter;
        for (iter = arcs.rbegin(); iter != arcs.rend(); ++iter)
        {
            InsertArc(*iter, nodes);
        }

        // The leaf nodes are not counted in the traversal of InsertArc.  The
        // depth must be incremented to account for leaves.
        ++mTreeDepth;
    }

    template <typename Real>
    void ExtremalQuery3BSP<Real>::InsertArc(const SphericalArc& arc, std::vector<SphericalArc>& nodes)
    {
        // The incoming arc is stored at the end of the nodes array.
        if (nodes.size() > 0)
        {
            // Do a nonrecursive depth-first search of the current BSP tree to
            // place the incoming arc.  Index 0 is the root of the BSP tree.
            std::stack<int> candidates;
            candidates.push(0);
            while (!candidates.empty())
            {
                const int current = candidates.top();
                candidates.pop();
                SphericalArc* node = &nodes[current];

                int sign0 = 0;
                if (arc.NIndex[0] == node->NIndex[0] || arc.NIndex[0] == node->NIndex[1])
                {
                    sign0 = 0;
                }
                else
                {
                    sign0 = static_cast<int>(Mathematics::Math<Real>::Sign(Mathematics::Vector3Tools<Real>::DotProduct(mFaceNormals[arc.NIndex[0]], node->Normal)));
                }

                int sign1 = 0;
                if (arc.NIndex[1] == node->NIndex[0] || arc.NIndex[1] == node->NIndex[1])
                {
                    sign1 = 0;
                }
                else
                {
                    sign1 = static_cast<int>(Mathematics::Math<Real>::Sign(Mathematics::Vector3Tools<Real>::DotProduct(mFaceNormals[arc.NIndex[1]], node->Normal)));
                }

                int doTest = 0;
                if (sign0 * sign1 < 0)
                {
                    // The new arc straddles the current arc, so propagate it
                    // to both child nodes.
                    doTest = 3;
                }
                else if (sign0 > 0 || sign1 > 0)
                {
                    // The new arc is on the positive side of the current arc.
                    doTest = 1;
                }
                else if (sign0 < 0 || sign1 < 0)
                {
                    // The new arc is on the negative side of the current arc.
                    doTest = 2;
                }
                // else: sign0 = sign1 = 0, in which case no propagation is
                // needed since the current BSP node will handle the correct
                // partitioning of the arcs during extremal queries.

                int depth = 0;

                if (doTest & 1)
                {
                    if (node->PosChild != -1)
                    {
                        candidates.push(node->PosChild);
                        depth = static_cast<int>(candidates.size());
                        if (depth > mTreeDepth)
                        {
                            mTreeDepth = depth;
                        }
                    }
                    else
                    {
                        node->PosChild = static_cast<int>(nodes.size());
                        nodes.push_back(arc);

                        // The push_back can cause a reallocation, so the current
                        // pointer must be refreshed.
                        node = &nodes[current];
                    }
                }

                if (doTest & 2)
                {
                    if (node->NegChild != -1)
                    {
                        candidates.push(node->NegChild);
                        depth = static_cast<int>(candidates.size());
                        if (depth > mTreeDepth)
                        {
                            mTreeDepth = depth;
                        }
                    }
                    else
                    {
                        node->NegChild = static_cast<int>(nodes.size());
                        nodes.push_back(arc);
                    }
                }
            }
        }
        else
        {
            // root node
            nodes.push_back(arc);
        }
    }

    // ExtremalQueryBSP::SphericalArc

    template <typename Real>
    ExtremalQuery3BSP<Real>::SphericalArc::SphericalArc() noexcept
        : PosChild(-1), NegChild(-1)
    {
    }

    template <typename Real>
    bool ExtremalQuery3BSP<Real>::SphericalArc::operator<(const SphericalArc& arc) const noexcept
    {
        return Separation < arc.Separation;
    }
}
    #include STSTEM_WARNING_POP
#endif  // !defined(PHYSICS_EXPORT_TEMPLATE) || defined(PHYSICS_INCLUDED_EXTREMAL_QUERY3BSP_DETAIL)

#endif  // PHYSICS_INTERSECTION_EXTREMAL_QUERY3BSP_DETAIL_H