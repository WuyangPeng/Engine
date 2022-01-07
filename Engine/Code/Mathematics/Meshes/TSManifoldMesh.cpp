// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:48)

#include "Mathematics/MathematicsExport.h"

#include "TSManifoldMesh.h"

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include <fstream>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26402)
Mathematics::TSManifoldMesh ::~TSManifoldMesh(){

    EXCEPTION_TRY{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
        TMapIterator telement;
for (telement = mTMap.begin(); telement != mTMap.end(); ++telement)
{
    //DELETE0(telement->second);
}

SMapIterator selement;
for (selement = mSMap.begin(); selement != mSMap.end(); ++selement)
{
    // DELETE0(selement->second);
}
#include STSTEM_WARNING_POP
}
EXCEPTION_ALL_CATCH(Mathematics)
}

Mathematics::TSManifoldMesh ::TSManifoldMesh(TCreator tCreator, SCreator sCreator) noexcept
{
    mTCreator = (tCreator ? tCreator : CreateTriangle);
    mSCreator = (sCreator ? sCreator : CreateTetrahedron);
}

const Mathematics::TSManifoldMesh::TMap& Mathematics::TSManifoldMesh ::GetTriangles() const noexcept
{
    return mTMap;
}

const Mathematics::TSManifoldMesh::SMap& Mathematics::TSManifoldMesh ::GetTetrahedra() const noexcept
{
    return mSMap;
}

Mathematics::TSManifoldMesh::Triangle* Mathematics::TSManifoldMesh ::CreateTriangle(int v0, int v1, int v2)
{
    v0;
    v1;
    v2;
    return nullptr;  //    NEW0 Triangle(v0, v1, v2);
}

Mathematics::TSManifoldMesh::Tetrahedron* Mathematics::TSManifoldMesh ::CreateTetrahedron(int v0, int v1, int v2, int v3)
{
    v0;
    v1;
    v2;
    v3;
    return nullptr;  //  NEW0 Tetrahedron(v0, v1, v2, v3);
}

Mathematics::TSManifoldMesh::Tetrahedron* Mathematics::TSManifoldMesh ::Insert(int v0, int v1, int v2, int v3)
{
    const TetrahedronKey skey(v0, v1, v2, v3);
    if (mSMap.find(skey) != mSMap.end())
    {
        // The tetrahedron already exists.  Return a null pointer as a signal
        // to the caller that the insertion failed.
        return 0;
    }

    // Add the new tetrahedron.
    Tetrahedron* tetra = mSCreator(v0, v1, v2, v3);
    mSMap[skey] = tetra;

    // Add the faces to the mesh if they do not already exist.
    for (int i = 0; i < 4; ++i)
    {
        if (tetra)
        {
            const int opposite[3]{ TetrahedronKey::oppositeFace[i][0], TetrahedronKey::oppositeFace[i][1], TetrahedronKey::oppositeFace[i][2] };
            const UnorderedTriangleKey tkey{ tetra->V[opposite[0]], tetra->V[opposite[1]], tetra->V[opposite[2]] };
            Triangle* face = nullptr;
            const TMapIterator titer = mTMap.find(tkey);
            if (titer == mTMap.end())
            {
                // This is the first time the face is encountered.
                face = mTCreator(tetra->V[opposite[0]], tetra->V[opposite[1]], tetra->V[opposite[2]]);
                mTMap[tkey] = face;

                // Update the face and tetrahedron.
                face->T[0] = tetra;
                tetra->T[i] = face;
            }
            else
            {
                // This is the second time the face is encountered.
                face = titer->second;
                if (!face)
                {
                    MATHEMATICS_ASSERTION_0(false, "Unexpected condition.");
                    return 0;
                }

                // Update the face.
                if (face->T[1])
                {
                    MATHEMATICS_ASSERTION_0(false, "The mesh must be manifold.");
                    return 0;
                }
                face->T[1] = tetra;

                // Update the adjacent triangles.
                Tetrahedron* adjacent = face->T[0];
                if (!adjacent)
                {
                    MATHEMATICS_ASSERTION_0(false, "Unexpected condition.");
                    return 0;
                }
                for (int j = 0; j < 4; ++j)
                {
                    if (adjacent->T[j] == face)
                    {
                        adjacent->S[j] = tetra;
                        break;
                    }
                }

                // Update the tetrahedron.

                tetra->T[i] = face;
                tetra->S[i] = adjacent;
            }
        }
    }

    return tetra;
}

bool Mathematics::TSManifoldMesh ::Remove(int v0, int v1, int v2, int v3)
{
    const TetrahedronKey skey(v0, v1, v2, v3);
    const SMapIterator siter = mSMap.find(skey);
    if (siter == mSMap.end())
    {
        // The tetrahedron does not exist.
        return false;
    }

    // Get the tetrahedron.
    Tetrahedron* tetra = siter->second;

    // Remove the faces and update adjacent tetrahedra if necessary.
    for (int i = 0; i < 4; ++i)
    {
        // Inform the faces the tetrahedron is being deleted.
        Triangle* face = tetra->T[i];
        if (!face)
        {
            // The triangle edge should be nonnull.
            MATHEMATICS_ASSERTION_0(false, "Unexpected condition.");
            return false;
        }

        if (face->T[0] == tetra)
        {
            // One-tetrahedron faces always have pointer at index zero.
            face->T[0] = face->T[1];
            face->T[1] = 0;
        }
        else if (face->T[1] == tetra)
        {
            face->T[1] = 0;
        }
        else
        {
            MATHEMATICS_ASSERTION_0(false, "Unexpected condition.");
            return false;
        }

        // Remove the face if you have the last reference to it.
        if (!face->T[0] && !face->T[1])
        {
            const UnorderedTriangleKey tkey(face->V[0], face->V[1], face->V[2]);
            mTMap.erase(tkey);
            //  DELETE0(face);
        }

        // Inform adjacent tetrahedra the tetrahedron is being deleted.
        Tetrahedron* adjacent = tetra->S[i];
        if (adjacent)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (adjacent->S[j] == tetra)
                {
                    adjacent->S[j] = 0;
                    break;
                }
            }
        }
    }

    mSMap.erase(skey);
    // DELETE0(tetra);
    return true;
}

bool Mathematics::TSManifoldMesh ::IsClosed() const noexcept
{
    TMapCIterator element;
    for (element = mTMap.begin(); element != mTMap.end(); ++element)
    {
        Triangle const* tri = element->second;
        if (!tri->T[0] || !tri->T[1])
        {
            return false;
        }
    }
    return true;
}

bool Mathematics::TSManifoldMesh ::Print(const char* filename)
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        return false;
    }

    // Assign unique indices to the triangles.
    std::map<Triangle*, int> triIndex;
    triIndex[(Triangle*)0] = 0;
    int i = 1;
    TMapCIterator telement;
    for (telement = mTMap.begin(); telement != mTMap.end(); ++telement)
    {
        if (telement->second)
        {
            triIndex[telement->second] = i++;
        }
    }

    // Assign unique indices to the tetrahedra.
    std::map<Tetrahedron*, int> tetraIndex;
    tetraIndex[(Tetrahedron*)0] = 0;
    i = 1;
    SMapCIterator selement;
    for (selement = mSMap.begin(); selement != mSMap.end(); ++selement)
    {
        if (selement->second)
        {
            tetraIndex[selement->second] = i++;
        }
    }

    // Print the triangles.
    outFile << "triangle quantity = " << mTMap.size() << std::endl;
    for (telement = mTMap.begin(); telement != mTMap.end(); ++telement)
    {
        Triangle const& tri = *telement->second;
        outFile << 't' << triIndex[telement->second] << " <"
                << 'v' << tri.V[0] << ",v" << tri.V[1] << ",v"
                << tri.V[2] << "; ";
        for (int j = 0; j < 2; ++j)
        {
            if (tri.T[j])
            {
                outFile << 's' << tetraIndex[tri.T[j]];
            }
            else
            {
                outFile << '*';
            }
            outFile << (j == 0 ? '*' : '>');
        }
        outFile << std::endl;
    }
    outFile << std::endl;

    // Print the tetrahedra.
    outFile << "tetrahedron quantity = " << mSMap.size() << std::endl;
    for (selement = mSMap.begin(); selement != mSMap.end(); ++selement)
    {
        Tetrahedron const& tetra = *selement->second;
        outFile << 's' << tetraIndex[selement->second] << " <"
                << 'v' << tetra.V[0] << ",v" << tetra.V[1] << ",v"
                << tetra.V[2] << ",v" << tetra.V[3] << "; ";
        for (int j = 0; j < 4; ++j)
        {
            if (tetra.T[j])
            {
                outFile << 't' << triIndex[tetra.T[j]];
            }
            else
            {
                outFile << '*';
            }
            outFile << (j < 3 ? "," : "; ");
        }

        for (int j = 0; j < 4; ++j)
        {
            if (tetra.S[j])
            {
                outFile << 't' << tetraIndex[tetra.S[j]];
            }
            else
            {
                outFile << '*';
            }
            outFile << (j < 3 ? ',' : '>');
        }

        outFile << std::endl;
    }
    outFile << std::endl;
    return true;
}

Mathematics::TSManifoldMesh::Triangle ::~Triangle()
{
}

Mathematics::TSManifoldMesh::Triangle ::Triangle(int v0, int v1, int v2) noexcept
{
    V[0] = v0;
    V[1] = v1;
    V[2] = v2;
    T[0] = 0;
    T[1] = 0;
}

Mathematics::TSManifoldMesh::Tetrahedron ::~Tetrahedron()
{
}

Mathematics::TSManifoldMesh::Tetrahedron ::Tetrahedron(int v0, int v1, int v2, int v3) noexcept
    : V{}, T{}, S{}
{
    V[0] = v0;
    V[1] = v1;
    V[2] = v2;
    V[3] = v3;
    for (int i = 0; i < 4; ++i)
    {
        T[i] = 0;
        S[i] = 0;
    }
}

#include STSTEM_WARNING_POP