// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:51)

#include "Mathematics/MathematicsExport.h"

#include "VEManifoldMesh.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <fstream>
#include "CoreTools/Helper/ExceptionMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26402)
#include SYSTEM_WARNING_DISABLE(26409)
Mathematics::VEManifoldMesh
	::VEManifoldMesh (VCreator vCreator, ECreator eCreator) noexcept
{
    mVCreator = (vCreator ? vCreator : CreateVertex);
    mECreator = (eCreator ? eCreator : CreateEdge);
}

Mathematics::VEManifoldMesh
	::~VEManifoldMesh ()
{
	EXCEPTION_TRY
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
 VMapIterator viter = mVMap.begin();
    const VMapIterator vend = mVMap.end();
    for (/**/; viter != vend; ++viter)
    {
        Vertex* vertex = viter->second;
        DELETE0(vertex);
    }

    EMapIterator eiter = mEMap.begin();
    const EMapIterator eend = mEMap.end();
    for (/**/; eiter != eend; ++eiter)
    {
        Edge* edge = eiter->second;
        DELETE0(edge);
    }
#include STSTEM_WARNING_POP
}
    EXCEPTION_ALL_CATCH(Mathematics)
    
}

Mathematics::VEManifoldMesh::VPtr Mathematics::VEManifoldMesh
	::CreateVertex (int v)
{
    return NEW0 Vertex(v);
}

Mathematics::VEManifoldMesh::EPtr Mathematics::VEManifoldMesh
	::CreateEdge (int v0, int v1) 
{
    return NEW0 Edge(v0, v1);
}

Mathematics::VEManifoldMesh::EPtr Mathematics::VEManifoldMesh
	::InsertEdge (int v0, int v1)
{
    const std::pair<int,int> ekey(v0, v1);
    const EMapIterator eiter = mEMap.find(ekey);
    if (eiter != mEMap.end())
    {
        // Edge already exists.
        return 0;
    }

    // Add new edge.
    EPtr edge = mECreator(v0,v1);
    mEMap[ekey] = edge;

    // Add vertices to mesh.
    for (int i = 0; i < 2; ++i)
    {
		if (edge)
		{
       const  int v = edge->V[i];
        VPtr vertex = nullptr;
        const VMapIterator viter = mVMap.find(v);
        if (viter == mVMap.end())
        {
            // First time vertex encountered.
            vertex = mVCreator(v);
            mVMap[v] = vertex;

            // Update vertex.
            vertex->E[0] = edge;
        }
        else
        {
            // Second time vertex encountered.
            vertex = viter->second;
    
			if (vertex == 0)
			{
				THROW_EXCEPTION(SYSTEM_TEXT("Unexpected condition\n"));
			}

            // Update vertex.
            if (vertex->E[1])
            {
                MATHEMATICS_ASSERTION_0(false, "Mesh must be manifold\n");
                return 0;
            }
            vertex->E[1] = edge;

            // Update adjacent edge.
            EPtr adjacent = vertex->E[0];
         
			if (adjacent == 0)
			{
				THROW_EXCEPTION(SYSTEM_TEXT("Unexpected condition\n"s));
			}
            for (int j = 0; j < 2; ++j)
            {
                if (adjacent->V[j] == v)
                {
                    adjacent->E[j] = edge;
                    break;
                }
            }

            // Update edge.
			
				edge->E[i] = adjacent;
			}
           
        }
    }

    return edge;
}

bool Mathematics::VEManifoldMesh
	::RemoveEdge (int v0, int v1)
{
    const std::pair<int,int> ekey(v0, v1);
    const EMapIterator eiter = mEMap.find(ekey);
    if (eiter == mEMap.end())
    {
        // Edge does not exist.
        return false;
    }

    EPtr edge = eiter->second;
    for (int i = 0; i < 2; ++i)
    {
        // Inform vertices you are going away.
        const VMapIterator viter = mVMap.find(edge->V[i]);
        MATHEMATICS_ASSERTION_0(viter != mVMap.end(), "Unexpected condition\n");
        Vertex* vertex = viter->second;
		if (vertex == 0)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("Unexpected condition\n"s));
		}
        if (vertex->E[0] == edge)
        {
            // One-edge vertices always have pointer in slot zero.
            vertex->E[0] = vertex->E[1];
            vertex->E[1] = 0;
        }
        else if (vertex->E[1] == edge)
        {
            vertex->E[1] = 0;
        }
        else
        {
            MATHEMATICS_ASSERTION_0(false, "Unexpected condition\n");
            return false;
        }

        // Remove vertex if you had the last reference to it.
        if (!vertex->E[0] && !vertex->E[1])
        {
            mVMap.erase(vertex->V);
            DELETE0(vertex);
        }

        // Inform adjacent edges you are going away.
        EPtr adjacent = edge->E[i];
        if (adjacent)
        {
            for (int j = 0; j < 2; ++j)
            {
                if (adjacent->E[j] == edge)
                {
                    adjacent->E[j] = 0;
                    break;
                }
            }
        }
    }

    mEMap.erase(ekey);
    DELETE0(edge);
    return true;
}

bool Mathematics::VEManifoldMesh
	::IsClosed () const
{
    VMapCIterator viter = mVMap.begin();
    const VMapCIterator vend = mVMap.end();
    for (/**/; viter != vend; ++viter)
    {
        const Vertex* vertex = viter->second;
        if (!vertex->E[0] || !vertex->E[1])
        {
            return false;
        }
    }
    return true;
}

void Mathematics::VEManifoldMesh
	::Print (const char* filename)
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        return;
    }

    // Assign unique indices to the edges.
    std::map<EPtr,int> edgeIndex;
    edgeIndex[EPtr{}] = 0;
    EMapIterator eiter = mEMap.begin();
    const EMapIterator eend = mEMap.end();
    for (int i = 1; eiter != eend; ++eiter)
    {
        if (eiter->second)
        {
            edgeIndex[eiter->second] = i;
            ++i;
        }
    }

    // Print vertices.
    outFile << "vertex quantity = " <<  mVMap.size() << std::endl;
    VMapIterator viter = mVMap.begin();
    const VMapIterator vend = mVMap.end();
    for (/**/; viter != vend; ++viter)
    {
        const Vertex& vertex = *viter->second;
        outFile << 'v' << vertex.V << " <";
        if (vertex.E[0])
        {
            outFile << 'e' << edgeIndex[vertex.E[0]];
        }
        else
        {
            outFile << '*';
        }
        outFile << ',';
        if (vertex.E[1])
        {
            outFile << 'e'  << edgeIndex[vertex.E[1]];
        }
        else
        {
            outFile << '*';
        }
        outFile << '>' << std::endl;
    }

    // Print edges.
    outFile << "edge quantity = " <<  mEMap.size()  << std::endl;
    for (eiter = mEMap.begin(); eiter != eend; ++eiter)
    {
        const Edge& edge = *eiter->second;
        outFile << 'e' << edgeIndex[eiter->second] << " <"
              << 'v' << edge.V[0] << ",v" << edge.V[1] << "; ";
        if (edge.E[0])
        {
            outFile << 'e' << edgeIndex[edge.E[0]];
        }
        else
        {
            outFile << '*';
        }
        outFile << ',';
        if (edge.E[1])
        {
            outFile << 'e' << edgeIndex[edge.E[1]];
        }
        else
        {
            outFile << '*';
        }
        outFile << '>' << std::endl;
    }
    outFile << std::endl;
}



// VEManifoldMesh::Vertex

Mathematics::VEManifoldMesh::Vertex
	::Vertex (int v) noexcept
{
    V = v;
    E[0] = 0;
    E[1] = 0;
}

Mathematics::VEManifoldMesh::Vertex
	::~Vertex ()
{
}



// VEManifoldMesh::Edge

Mathematics::VEManifoldMesh::Edge
	::Edge (int v0, int v1) noexcept
{
    V[0] = v0;
    V[1] = v1;
    E[0] = 0;
    E[1] = 0;
}

Mathematics::VEManifoldMesh::Edge
	::~Edge ()
{
}


const Mathematics::VEManifoldMesh::VMap& Mathematics::VEManifoldMesh
	::GetVertices () const noexcept
{
	return mVMap;
}

const Mathematics::VEManifoldMesh::EMap& Mathematics::VEManifoldMesh
	::GetEdges () const noexcept
{
	return mEMap;
}
#include STSTEM_WARNING_POP
