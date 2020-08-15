// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:37)

#include "Imagics/ImagicsExport.h"

#include "ExtractSurfaceTetra.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/ImagicsCustomAssertMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26446)
typedef std::map<Mathematics::Vector3Df,int> VMap;
typedef VMap::iterator VMapIterator;
typedef std::map<Mathematics::TriangleKey,int> TMap;
typedef TMap::iterator TMapIterator;
 

Imagics::ExtractSurfaceTetra
	::ExtractSurfaceTetra (int xBound, int yBound,int zBound, int* data) noexcept
    :mXBound(xBound),
     mYBound(yBound),
	 mZBound(zBound),
	 mXYBound(xBound*yBound),
	 mXYZBound(mXYBound*zBound),
	 mData(data)
{
}

float Imagics::ExtractSurfaceTetra
	::GetFunction (const Mathematics::Vector3Df& P) const  
{
    const int x = (int)P.GetXCoordinate();
    if (x < 0 || x >= mXBound-1)
    {
        return 0.0f;
    }

    const int y = (int)P.GetYCoordinate();
    if (y < 0 || y >= mYBound-1)
    {
        return 0.0f;
    }

    const int z = (int)P.GetZCoordinate();
    if (z < 0 || z >= mZBound-1)
    {
        return 0.0f;
    }

    const float dx = P.GetXCoordinate() - x;
	const float	dy = P.GetYCoordinate() - y;
	const float dz = P.GetZCoordinate() - z;

    const int i000 = x + mXBound*(y + mYBound*z);
    const int i100 = i000 + 1;
    const int i010 = i000 + mXBound;
    const int i110 = i100 + mXBound;
    const int i001 = i000 + mXYBound;
    const int i101 = i100 + mXYBound;
    const int i011 = i010 + mXYBound;
    const int i111 = i110 + mXYBound;
    const float f000 = (float)mData[i000];
    const float f100 = (float)mData[i100];
    const float f010 = (float)mData[i010];
    const float f110 = (float)mData[i110];
    const float f001 = (float)mData[i001];
    const float f101 = (float)mData[i101];
    const float f011 = (float)mData[i011];
    const float f111 = (float)mData[i111];
    float c0 = 0.0f, c1 = 0.0f, c2 = 0.0f, interp = 0.0f;

    if ((x & 1) ^ (y & 1) ^ (z & 1))
    {
        if (dx - dy - dz >= 0.0f)
        {
            // 1205
            interp =
                (1.0f-(1.0f-dx)-dy-dz)*f100 +
                (1.0f-dx)*f000 +
                dy*f110 +
                dz*f101;
        }
        else if (dx - dy + dz <= 0.0f)
        {
            // 3027
            interp =
                (1.0f-dx-(1.0f-dy)-dz)*f010 +
                dx*f110 +
                (1.0f-dy)*f000 +
                dz*f011;
        }
        else if (dx + dy - dz <= 0.0f)
        {
            // 4750
            interp =
                (1.0f-dx-dy-(1-dz))*f001 +
                dx*f101 +
                dy*f011 +
                (1.0f-dz)*f000;
        }
        else if (dx + dy + dz >= 2.0f)
        {
            // 6572
            interp =
                (1.0f-(1.0f-dx)-(1.0f-dy)-(1.0f-dz))*f111 +
                (1.0f-dx)*f011 +
                (1.0f-dy)*f101 +
                (1.0f-dz)*f110;
        }
        else
        {
            // 0752
            c0 = 0.5f*(-dx+dy+dz);
            c1 = 0.5f*(dx-dy+dz);
            c2 = 0.5f*(dx+dy-dz);
            interp =
                (1.0f-c0-c1-c2)*f000 +
                c0*f011 +
                c1*f101 +
                c2*f110;
        }
    }
    else
    {
        if (dx + dy + dz <= 1.0f)
        {
            // 0134
            interp =
                (1.0f-dx-dy-dz)*f000 +
                dx*f100 +
                dy*f010 +
                dz*f001;
        }
        else if (dx + dy - dz >= 1.0f)
        {
            // 2316
            interp =
                (1.0f-(1.0f-dx)-(1.0f-dy)-dz)*f110 +
                (1.0f-dx)*f010 +
                (1.0f-dy)*f100 +
                dz*f111;
        }
        else if (dx - dy + dz >= 1.0f)
        {
            // 5461
            interp =
                (1.0f-(1.0f-dx)-dy-(1.0f-dz))*f101 +
                (1.0f-dx)*f001 +
                dy*f111 +
                (1.0f-dz)*f100;
        }
        else if (-dx + dy + dz >= 1.0f)
        {
            // 7643
            interp =
                (1.0f-dx-(1.0f-dy)-(1.0f-dz))*f011 +
                dx*f111 +
                (1.0f-dy)*f001 +
                (1.0f-dz)*f010;
        }
        else
        {
            // 6314
            c0 = 0.5f*((1.0f-dx)-(1.0f-dy)+(1.0f-dz));
            c1 = 0.5f*(-(1.0f-dx)+(1.0f-dy)+(1.0f-dz));
            c2 = 0.5f*((1.0f-dx)+(1.0f-dy)-(1.0f-dz));
            interp =
                (1.0f-c0-c1-c2)*f111 +
                c0*f010 +
                c1*f100 +
                c2*f001;
        }
    }

    return interp;
}

Mathematics::Vector3Df Imagics::ExtractSurfaceTetra
	::GetGradient (const Mathematics::Vector3Df& P) const
{
    const int x = (int)P.GetXCoordinate();
    if (x < 0 || x >= mXBound-1)
    {
        return Mathematics::Vector3Df::sm_Zero;
    }

    const int y = (int)P.GetYCoordinate();
    if (y < 0 || y >= mYBound-1)
    {
        return Mathematics::Vector3Df::sm_Zero;
    }

    const int z = (int)P.GetZCoordinate();
    if (z < 0 || z >= mZBound-1)
    {
        return Mathematics::Vector3Df::sm_Zero;
    }

    const float dx = P.GetXCoordinate() - x;
    const auto dy = P.GetYCoordinate() - y;
    const auto dz = P.GetZCoordinate() - z;

    const int i000 = x + mXBound*(y + mYBound*z);
    const int i100 = i000 + 1;
    const int i010 = i000 + mXBound;
    const int i110 = i100 + mXBound;
    const int i001 = i000 + mXYBound;
    const int i101 = i100 + mXYBound;
    const int i011 = i010 + mXYBound;
    const int i111 = i110 + mXYBound;
    const float f000 = (float)mData[i000];
    const float f100 = (float)mData[i100];
    const float f010 = (float)mData[i010];
    const float f110 = (float)mData[i110];
    const float f001 = (float)mData[i001];
    const float f101 = (float)mData[i101];
    const float f011 = (float)mData[i011];
    const float f111 = (float)mData[i111];
    Mathematics::Vector3Df interp;

    if ((x & 1) ^ (y & 1) ^ (z & 1))
    {
        if (dx - dy - dz >= 0.0f)
        {
            // 1205
            interp.SetXCoordinate(+ f100 - f000);
            interp.SetYCoordinate(- f100 + f110);
            interp.SetZCoordinate(- f100 + f101); 
        }
        else if (dx - dy + dz <= 0.0f)
        {
            // 3027
            interp.SetXCoordinate(- f010 + f110);
            interp.SetYCoordinate(+ f010 - f000);
            interp.SetZCoordinate(- f010 + f011);
        }
        else if (dx + dy - dz <= 0.0f)
        {
            // 4750
            interp.SetXCoordinate(- f001 + f101);
            interp.SetYCoordinate(- f001 + f011);
            interp.SetZCoordinate(+ f001 - f000);
        }
        else if (dx + dy + dz >= 2.0f)
        {
            // 6572
            interp.SetXCoordinate(+ f111 - f011);
            interp.SetYCoordinate(+ f111 - f101);
            interp.SetZCoordinate(+ f111 - f110);
        }
        else
        {
            // 0752
            interp.SetXCoordinate(0.5f*(-f000-f011+f101+f110));
            interp.SetYCoordinate(0.5f*(-f000+f011-f101+f110));
            interp.SetZCoordinate(0.5f*(-f000+f011+f101-f110));
        }
    }
    else
    {
        if (dx + dy + dz <= 1.0f)
        {
            // 0134
            interp.SetXCoordinate(- f000 + f100);
            interp.SetYCoordinate(- f000 + f010);
            interp.SetZCoordinate(- f000 + f001);
        }
        else if (dx + dy - dz >= 1.0f)
        {
            // 2316
            interp.SetXCoordinate(+ f110 - f010);
            interp.SetYCoordinate(+ f110 - f100);
            interp.SetZCoordinate(- f110 + f111);
        }
        else if (dx - dy + dz >= 1.0f)
        {
            // 5461
            interp.SetXCoordinate(+ f101 - f001);
            interp.SetYCoordinate(- f101 + f111);
            interp.SetZCoordinate(+ f101 - f100);
        }
        else if (-dx + dy + dz >= 1.0f)
        {
            // 7643
            interp.SetXCoordinate(- f011 + f111);
            interp.SetYCoordinate(+ f011 - f001);
            interp.SetZCoordinate(+ f011 - f010);
        }
        else
        {
            // 6314
            interp.SetXCoordinate(0.5f*(f111-f010+f100-f001));
            interp.SetYCoordinate(0.5f*(f111+f010-f100-f001));
            interp.SetZCoordinate(0.5f*(f111-f010-f100+f001));
        }
    }

    return interp;
}

void Imagics::ExtractSurfaceTetra
	::ExtractContour (int level,std::vector<Mathematics::Vector3Df>& vertices, std::vector<Mathematics::TriangleKey>& triangles)
{
    // NOTE:  Isolated edges are computed, but not reported to the caller.
    // You can modify the code to return these if so desired.
    VtxMap vertexMap;
    ESet edgeSet;
    TriSet triangleSet;
    mNextIndex = 0;

    // Adjust image so level set is F(x,y,z) = 0.
    int i;
    for (i = 0; i < mXYZBound; ++i)
    {
        mData[i] = mData[i] - level;
    }

    const int xBoundM1 = mXBound - 1;
    const int yBoundM1 = mYBound - 1;
    const int zBoundM1 = mZBound - 1;
    for (int z = 0, zp = 1; z < zBoundM1; ++z, ++zp)
    {
        const int zParity = (z & 1);

        for (int y = 0, yp = 1; y < yBoundM1; ++y, ++yp)
        {
            const int yParity = (y & 1);

            for (int x = 0, xp = 1; x < xBoundM1; ++x, ++xp)
            {
               const int xParity = (x & 1);

               const int i000 = x + mXBound*(y + mYBound*z);
               const int i100 = i000 + 1;
               const int i010 = i000 + mXBound;
               const int i110 = i100 + mXBound;
               const int i001 = i000 + mXYBound;
               const int i101 = i100 + mXYBound;
               const int i011 = i010 + mXYBound;
               const int i111 = i110 + mXYBound;
               const int f000 = mData[i000];
               const int f100 = mData[i100];
              const  int f010 = mData[i010];
              const  int f110 = mData[i110];
               const int f001 = mData[i001];
               const int f101 = mData[i101];
               const int f011 = mData[i011];
               const int f111 = mData[i111];

                if (xParity ^ yParity ^ zParity)
                {
                    // 1205
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        xp, y, z, f100, xp, yp, z, f110, x, y, z, f000, xp, 
                        y, zp, f101);

                    // 3027
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        x, yp, z, f010, x, y, z, f000, xp, yp, z, f110, x, 
                        yp, zp, f011);

                    // 4750
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        x, y, zp, f001, x, yp, zp, f011, xp, y, zp, f101, x, 
                        y, z, f000);

                    // 6572
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        xp, yp, zp, f111, xp, y, zp, f101, x, yp, zp, f011, 
                        xp, yp, z, f110);

                    // 0752
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        x, y, z, f000, x, yp, zp, f011, xp, y, zp, f101, xp, 
                        yp, z, f110);
                }
                else
                {
                    // 0134
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        x, y, z, f000, xp, y, z, f100, x, yp, z, f010, x, y, 
                        zp, f001);

                    // 2316
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        xp, yp, z, f110, x, yp, z, f010, xp, y, z, f100, xp, 
                        yp, zp, f111);

                    // 5461
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        xp, y, zp, f101, x, y, zp, f001, xp, yp, zp, f111, 
                        xp, y, z, f100);

                    // 7643
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        x, yp, zp, f011, xp, yp, zp, f111, x, y, zp, f001, x, 
                        yp, z, f010);

                    // 6314
                    ProcessTetrahedron(vertexMap, edgeSet, triangleSet, 
                        xp, yp, zp, f111, x, yp, z, f010, xp, y, z, f100, x, 
                        y, zp, f001);
                }
            }
        }
    }

    // Readjust image so level set is F(x,y,z) = L.
    for (i = 0; i < mXYZBound; ++i)
    {
        mData[i] = mData[i] + level;
    }

    // Pack vertices into an array.
    vertices.resize(vertexMap.size());
    if (vertices.size() > 0)
    {
        VtxMapIterator vIter;
        for (vIter = vertexMap.begin(); vIter != vertexMap.end(); ++vIter)
        {
            const Vertex& vertex = vIter->first;
            vertex.GetTriple(vertices[vIter->second]);
        }
    }

    // Pack edges into an array (computed, but not reported to caller).
    std::vector<Mathematics::EdgeKey> edges;
    edges.resize(edgeSet.size());
    if (edges.size() > 0)
    {
        ESetIterator eIter = edgeSet.begin();
        for (i = 0; eIter != edgeSet.end(); ++eIter, ++i)
        {
            edges[i] = *eIter;
        }
    }

    // Pack triangles into an array.
    triangles.resize(triangleSet.size());
    if (triangles.size() > 0)
    {
        TSetIterator tIter = triangleSet.begin();
        for (i = 0; tIter != triangleSet.end(); ++tIter, ++i)
        {
            triangles[i] = *tIter;
        }
    }
}

void Imagics::ExtractSurfaceTetra
	::MakeUnique (std::vector<Mathematics::Vector3Df>& vertices, std::vector<Mathematics::TriangleKey>& triangles)
{
    const int numVertices = (int)vertices.size();
     const int numTriangles = (int)triangles.size();
    if (numVertices == 0 || numTriangles == 0)
    {
        return;
    }

    // Use a hash table to generate unique storage.
    VMap vertexMap;
    VMapIterator vIter;
    for (int v = 0, nextVertex = 0; v < numVertices; ++v)
    {
        // Keep only unique vertices.
        const std::pair<VMapIterator,bool> result = vertexMap.insert(
            std::make_pair(vertices[v], nextVertex));

        if (result.second == true)
        {
            ++nextVertex;
        }
    }

    // Use a hash table to generate unique storage.
    TMap triangleMap;
    TMapIterator tIter;
    for (int t = 0, nextTriangle = 0; t < numTriangles; t++)
    {
        // replace old vertex indices by new ones
        Mathematics::TriangleKey& tri = triangles[t];
        vIter = vertexMap.find(vertices[tri.GetKey(0)]);
        ASSERTION_0(vIter != vertexMap.end(), "Unexpected condition\n");
        tri.SetKey(0, vIter->second);
        vIter = vertexMap.find(vertices[tri.GetKey(1)]);
        ASSERTION_0(vIter != vertexMap.end(), "Unexpected condition\n");
        tri.SetKey(1, vIter->second);
        vIter = vertexMap.find(vertices[tri.GetKey(2)]);
        ASSERTION_0(vIter != vertexMap.end(), "Unexpected condition\n");
        tri.SetKey(2, vIter->second);

        // Keep only unique triangles.
        const std::pair<TMapIterator,bool> result = triangleMap.insert(
            std::make_pair(tri, nextTriangle));

        if (result.second == true)
        {
            ++nextTriangle;
        }
    }

    // Pack the vertices.
    vertices.resize(vertexMap.size());
    for (vIter = vertexMap.begin(); vIter != vertexMap.end(); ++vIter)
    {
        vertices[vIter->second] = vIter->first;
    }

    // Pack the triangles.
    triangles.resize(triangleMap.size());
    for (tIter = triangleMap.begin(); tIter != triangleMap.end(); ++tIter)
    {
        triangles[tIter->second] = tIter->first;
    }
}

void Imagics::ExtractSurfaceTetra
	::OrientTriangles (std::vector<Mathematics::Vector3Df>& vertices,
                       std::vector<Mathematics::TriangleKey>& triangles, bool sameDir)
{
    const int numTriangles = (int)triangles.size();
    for (int i = 0; i < numTriangles; ++i)
    {
        Mathematics::TriangleKey& tri = triangles[i];

        // Get triangle vertices.
        const Mathematics::Vector3Df v0 = vertices[tri.GetKey(0)];
        const Mathematics::Vector3Df v1 = vertices[tri.GetKey(1)];
        const Mathematics::Vector3Df v2 = vertices[tri.GetKey(2)];
        
        // Construct triangle normal based on current orientation.
        const Mathematics::Vector3Df edge1 = v1 - v0;
        const Mathematics::Vector3Df edge2 = v2 - v0;
        const Mathematics::Vector3Df normal = Mathematics::Vector3DToolsf::CrossProduct(edge1,edge2);

        // Get the image gradient at the vertices.
        const Mathematics::Vector3Df grad0 = GetGradient(v0);
        const Mathematics::Vector3Df grad1 = GetGradient(v1);
        const Mathematics::Vector3Df grad2 = GetGradient(v2);

        // Compute the average gradient.
        const Mathematics::Vector3Df gradAvr = (grad0 + grad1 + grad2)/3.0f;
        
        // Compute the dot product of normal and average gradient.
        const float dot = Mathematics::Vector3DToolsf::DotProduct(gradAvr,normal);

        // Choose triangle orientation based on gradient direction.
        int save = 0;
        if (sameDir)
        {
            if (dot < 0.0f)
            {
                // Wrong orientation, reorder it.
                save = tri.GetKey(1);
                tri.SetKey(1,tri.GetKey(2));
				tri.SetKey(2,save);
            }
        }
        else
        {
            if (dot > 0.0f)
            {
                // Wrong orientation, reorder it.
				save = tri.GetKey(1);
				tri.SetKey(1,tri.GetKey(2));
				tri.SetKey(2,save);
            }
        }
    }
}

void Imagics::ExtractSurfaceTetra
	::ComputeNormals (const std::vector<Mathematics::Vector3Df>& vertices,const std::vector<Mathematics::TriangleKey>& triangles,  std::vector<Mathematics::Vector3Df>& normals)
{
    // Maintain a running sum of triangle normals at each vertex.
   const int numVertices = (int)vertices.size();
   const int numTriangles = (int)triangles.size();
    normals.resize(numVertices);
    int i;
    for (i = 0; i < numVertices; ++i)
    {
        normals[i] = Mathematics::Vector3Df::sm_Zero;
    }

    for (i = 0; i < numTriangles; ++i)
    {
        const Mathematics::TriangleKey& key = triangles[i];
       const Mathematics::Vector3Df v0 = vertices[key.GetKey(0)];
       const Mathematics::Vector3Df v1 = vertices[key.GetKey(1)];
       const Mathematics::Vector3Df v2 = vertices[key.GetKey(2)];

        // Construct triangle normal.
       const Mathematics::Vector3Df edge1 = v1 - v0;
       const Mathematics::Vector3Df edge2 = v2 - v0;
       const Mathematics::Vector3Df normal = Mathematics::Vector3DToolsf::CrossProduct(edge1,edge2);

        // Maintain the sum of normals at each vertex.
        normals[key.GetKey(0)] += normal;
        normals[key.GetKey(1)] += normal;
        normals[key.GetKey(2)] += normal;
    }

    // The normal vector storage was used to accumulate the sum of triangle
    // normals.  Now these vectors must be rescaled to be unit length.
    for (i = 0; i < numVertices; ++i)
    {
        normals[i].Normalize();
    }
}

int Imagics::ExtractSurfaceTetra
	::AddVertex (VtxMap& vertexMap, int xNumer, int xDenom,
                 int yNumer, int yDenom, int zNumer, int zDenom)
{
    Vertex vertex(xNumer, xDenom, yNumer, yDenom, zNumer, zDenom);
   const VtxMapIterator vIter = vertexMap.find(vertex);
    if (vIter != vertexMap.end())
    {
        // Vertex already in map, just return its unique index.
        return vIter->second;
    }
    else
    {
        // Vertex not in map, insert it and assign it a unique index.
        int i = mNextIndex++;
        vertexMap.insert(std::make_pair(vertex, i));
        return i;
    }
}

void Imagics::ExtractSurfaceTetra
	::AddEdge (VtxMap& vertexMap, ESet& edgeSet,
               int xNumer0, int xDenom0, int yNumer0, int yDenom0, int zNumer0,
			   int zDenom0, int xNumer1, int xDenom1, int yNumer1, int yDenom1,
			   int zNumer1, int zDenom1)
{
    const int v0 = AddVertex(vertexMap, xNumer0, xDenom0, yNumer0, yDenom0,
        zNumer0, zDenom0);

   const int v1 = AddVertex(vertexMap, xNumer1, xDenom1, yNumer1, yDenom1,
        zNumer1, zDenom1);

    edgeSet.insert( Mathematics::EdgeKey(v0, v1));
}

void Imagics::ExtractSurfaceTetra
	::AddTriangle (VtxMap& vertexMap, ESet& edgeSet,
                   TriSet& triangleSet, int xNumer0, int xDenom0, int yNumer0, int yDenom0,
				   int zNumer0, int zDenom0, int xNumer1, int xDenom1, int yNumer1,
				   int yDenom1, int zNumer1, int zDenom1, int xNumer2, int xDenom2,
				   int yNumer2, int yDenom2, int zNumer2, int zDenom2)
{
   const int v0 = AddVertex(vertexMap, xNumer0, xDenom0, yNumer0, yDenom0,
        zNumer0, zDenom0);

  const  int v1 = AddVertex(vertexMap, xNumer1, xDenom1, yNumer1, yDenom1,
        zNumer1, zDenom1);

   const int v2 = AddVertex(vertexMap, xNumer2, xDenom2, yNumer2, yDenom2,
        zNumer2, zDenom2);

    // Nothing to do if triangle already exists.
    Mathematics::TriangleKey key(v0, v1, v2);
    if (triangleSet.find(key) != triangleSet.end())
    {
        return;
    }

    // Prevent double-sided triangles.
	key.Swap(1,2);
    if (triangleSet.find(key) != triangleSet.end())
    {
        return;
    }

    edgeSet.insert(Mathematics::EdgeKey(v0, v1));
    edgeSet.insert(Mathematics::EdgeKey(v1, v2));
    edgeSet.insert(Mathematics::EdgeKey(v2, v0));

    // Compute triangle normal assuming counterclockwise ordering.
   const Mathematics::Vector3Df pos0(
        xNumer0/(float)xDenom0,
        yNumer0/(float)yDenom0,
        zNumer0/(float)zDenom0);

   const Mathematics::Vector3Df pos1(
        xNumer1/(float)xDenom1,
        yNumer1/(float)yDenom1,
        zNumer1/(float)zDenom1);

   const Mathematics::Vector3Df pos2(
        xNumer2/(float)xDenom2,
        yNumer2/(float)yDenom2,
        zNumer2/(float)zDenom2);

   const Mathematics::Vector3Df edge0 = pos1 - pos0;
   const Mathematics::Vector3Df edge1 = pos2 - pos0;
   const Mathematics::Vector3Df normal = Mathematics::Vector3DToolsf::CrossProduct(edge0,edge1);

    // Choose triangle orientation based on gradient direction.
   const Mathematics::Vector3Df centroid = (pos0 + pos1 + pos2)/3.0f;
   const Mathematics::Vector3Df grad = GetGradient(centroid);
    if (Mathematics::Vector3DToolsf::DotProduct(grad,normal) <= 0.0f)
    {
        triangleSet.insert(Mathematics::TriangleKey(v0, v1, v2));
    }
    else
    {
        triangleSet.insert(Mathematics::TriangleKey(v0, v2, v1));
    }
}

void Imagics::ExtractSurfaceTetra
	::ProcessTetrahedron (VtxMap& vertexMap,
                          ESet& edgeSet, TriSet& triangleSet, int x0, int y0, int z0, int f0,
                          int x1, int y1, int z1, int f1, int x2, int y2, int z2, int f2, int x3,
                          int y3, int z3, int f3)
{
    int xn0 = 0, yn0= 0, zn0= 0, d0= 0;
    int xn1= 0, yn1= 0, zn1= 0, d1= 0;
    int xn2= 0, yn2= 0, zn2= 0, d2= 0;
    int xn3= 0, yn3= 0, zn3= 0, d3= 0;

    if (f0 != 0)
    {
        // convert to case +***
        if (f0 < 0)
        {
            f0 = -f0;
            f1 = -f1;
            f2 = -f2;
            f3 = -f3;
        }

        if (f1 > 0)
        {
            if (f2 > 0)
            {
                if (f3 > 0)
                {
                    // ++++
                    return;
                }
                else if (f3 < 0)
                {
                    // +++-
                    d0 = f0 - f3;
                    xn0 = f0*x3 - f3*x0;
                    yn0 = f0*y3 - f3*y0;
                    zn0 = f0*z3 - f3*z0;
                    d1 = f1 - f3;
                    xn1 = f1*x3 - f3*x1;
                    yn1 = f1*y3 - f3*y1;
                    zn1 = f1*z3 - f3*z1;
                    d2 = f2 - f3;
                    xn2 = f2*x3 - f3*x2;
                    yn2 = f2*y3 - f3*y2;
                    zn2 = f2*z3 - f3*z2;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn2, d2, yn2, d2, zn2, d2);
                }
                else
                {
                    // +++0
                    AddVertex(vertexMap, x3, 1, y3, 1, z3, 1);
                }
            }
            else if (f2 < 0)
            {
                d0 = f0 - f2;
                xn0 = f0*x2 - f2*x0;
                yn0 = f0*y2 - f2*y0;
                zn0 = f0*z2 - f2*z0;
                d1 = f1 - f2;
                xn1 = f1*x2 - f2*x1;
                yn1 = f1*y2 - f2*y1;
                zn1 = f1*z2 - f2*z1;

                if (f3 > 0)
                {
                    // ++-+
                    d2 = f3 - f2;
                    xn2 = f3*x2 - f2*x3;
                    yn2 = f3*y2 - f2*y3;
                    zn2 = f3*z2 - f2*z3;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn2, d2, yn2, d2, zn2, d2);
                }
                else if (f3 < 0)
                {
                    // ++--
                    d2 = f0 - f3;
                    xn2 = f0*x3 - f3*x0;
                    yn2 = f0*y3 - f3*y0;
                    zn2 = f0*z3 - f3*z0;
                    d3 = f1 - f3;
                    xn3 = f1*x3 - f3*x1;
                    yn3 = f1*y3 - f3*y1;
                    zn3 = f1*z3 - f3*z1;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn2, d2, yn2, d2, zn2, d2);
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn3, d3, yn3, d3, zn3, d3, 
                        xn2, d2, yn2, d2, zn2, d2);
                }
                else
                {
                    // ++-0
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        x3, 1, y3, 1, z3, 1);
                }
            }
            else
            {
                if (f3 > 0)
                {
                    // ++0+
                    AddVertex(vertexMap, x2, 1, y2, 1, z2, 1);
                }
                else if (f3 < 0)
                {
                    // ++0-
                    d0 = f0 - f3;
                    xn0 = f0*x3 - f3*x0;
                    yn0 = f0*y3 - f3*y0;
                    zn0 = f0*z3 - f3*z0;
                    d1 = f1 - f3;
                    xn1 = f1*x3 - f3*x1;
                    yn1 = f1*y3 - f3*y1;
                    zn1 = f1*z3 - f3*z1;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        x2, 1, y2, 1, z2, 1);
                }
                else
                {
                    // ++00
                    AddEdge(vertexMap, edgeSet, x2, 1, y2, 1, z2, 1, x3, 1,
                        y3, 1, z3, 1);
                }
            }
        }
        else if (f1 < 0)
        {
            if (f2 > 0)
            {
                d0 = f0 - f1;
                xn0 = f0*x1 - f1*x0;
                yn0 = f0*y1 - f1*y0;
                zn0 = f0*z1 - f1*z0;
                d1 = f2 - f1;
                xn1 = f2*x1 - f1*x2;
                yn1 = f2*y1 - f1*y2;
                zn1 = f2*z1 - f1*z2;

                if (f3 > 0)
                {
                    // +-++
                    d2 = f3 - f1;
                    xn2 = f3*x1 - f1*x3;
                    yn2 = f3*y1 - f1*y3;
                    zn2 = f3*z1 - f1*z3;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn2, d2, yn2, d2, zn2, d2);
                }
                else if (f3 < 0)
                {
                    // +-+-
                    d2 = f0 - f3;
                    xn2 = f0*x3 - f3*x0;
                    yn2 = f0*y3 - f3*y0;
                    zn2 = f0*z3 - f3*z0;
                    d3 = f2 - f3;
                    xn3 = f2*x3 - f3*x2;
                    yn3 = f2*y3 - f3*y2;
                    zn3 = f2*z3 - f3*z2;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn2, d2, yn2, d2, zn2, d2);
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn3, d3, yn3, d3, zn3, d3, 
                        xn2, d2, yn2, d2, zn2, d2);
                }
                else
                {
                    // +-+0
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        x3, 1, y3, 1, z3, 1);
                }
            }
            else if (f2 < 0)
            {
                d0 = f1 - f0;
                xn0 = f1*x0 - f0*x1;
                yn0 = f1*y0 - f0*y1;
                zn0 = f1*z0 - f0*z1;
                d1 = f2 - f0;
                xn1 = f2*x0 - f0*x2;
                yn1 = f2*y0 - f0*y2;
                zn1 = f2*z0 - f0*z2;

                if (f3 > 0)
                {
                    // +--+
                    d2 = f1 - f3;
                    xn2 = f1*x3 - f3*x1;
                    yn2 = f1*y3 - f3*y1;
                    zn2 = f1*z3 - f3*z1;
                    d3 = f2 - f3;
                    xn3 = f2*x3 - f3*x2;
                    yn3 = f2*y3 - f3*y2;
                    zn3 = f2*z3 - f3*z2;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn2, d2, yn2, d2, zn2, d2);
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn3, d3, yn3, d3, zn3, d3, 
                        xn2, d2, yn2, d2, zn2, d2);
                }
                else if (f3 < 0)
                {
                    // +---
                    d2 = f3 - f0;
                    xn2 = f3*x0 - f0*x3;
                    yn2 = f3*y0 - f0*y3;
                    zn2 = f3*z0 - f0*z3;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        xn2, d2, yn2, d2, zn2, d2);
                }
                else
                {
                    // +--0
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        x3, 1, y3, 1, z3, 1);
                }
            }
            else
            {
                d0 = f1 - f0;
                xn0 = f1*x0 - f0*x1;
                yn0 = f1*y0 - f0*y1;
                zn0 = f1*z0 - f0*z1;

                if (f3 > 0)
                {
                    // +-0+
                    d1 = f1 - f3;
                    xn1 = f1*x3 - f3*x1;
                    yn1 = f1*y3 - f3*y1;
                    zn1 = f1*z3 - f3*z1;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        x2, 1, y2, 1, z2, 1);
                }
                else if (f3 < 0)
                {
                    // +-0-
                    d1 = f3 - f0;
                    xn1 = f3*x0 - f0*x3;
                    yn1 = f3*y0 - f0*y3;
                    zn1 = f3*z0 - f0*z3;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        x2, 1, y2, 1, z2, 1);
                }
                else
                {
                    // +-00
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        x2, 1, y2, 1, z2, 1, 
                        x3, 1, y3, 1, z3, 1);
                }
            }
        }
        else
        {
            if (f2 > 0)
            {
                if (f3 > 0)
                {
                    // +0++
                    AddVertex(vertexMap, x1, 1, y1, 1, z1, 1);
                }
                else if (f3 < 0)
                {
                    // +0+-
                    d0 = f0 - f3;
                    xn0 = f0*x3 - f3*x0;
                    yn0 = f0*y3 - f3*y0;
                    zn0 = f0*z3 - f3*z0;
                    d1 = f2 - f3;
                    xn1 = f2*x3 - f3*x2;
                    yn1 = f2*y3 - f3*y2;
                    zn1 = f2*z3 - f3*z2;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        x1, 1, y1, 1, z1, 1);
                }
                else
                {
                    // +0+0
                    AddEdge(vertexMap, edgeSet, x1, 1, y1, 1, z1, 1, x3, 1,
                        y3, 1, z3, 1);
                }
            }
            else if (f2 < 0)
            {
                d0 = f2 - f0;
                xn0 = f2*x0 - f0*x2;
                yn0 = f2*y0 - f0*y2;
                zn0 = f2*z0 - f0*z2;

                if (f3 > 0)
                {
                    // +0-+
                    d1 = f2 - f3;
                    xn1 = f2*x3 - f3*x2;
                    yn1 = f2*y3 - f3*y2;
                    zn1 = f2*z3 - f3*z2;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        x1, 1, y1, 1, z1, 1);
                }
                else if (f3 < 0)
                {
                    // +0--
                    d1 = f0 - f3;
                    xn1 = f0*x3 - f3*x0;
                    yn1 = f0*y3 - f3*y0;
                    zn1 = f0*z3 - f3*z0;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        xn1, d1, yn1, d1, zn1, d1, 
                        x1, 1, y1, 1, z1, 1);
                }
                else
                {
                    // +0-0
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        x1, 1, y1, 1, z1, 1, 
                        x3, 1, y3, 1, z3, 1);
                }
            }
            else
            {
                if (f3 > 0)
                {
                    // +00+
                    AddEdge(vertexMap, edgeSet, x1, 1, y1, 1, z1, 1, x2, 1,
                        y2, 1, z2, 1);
                }
                else if (f3 < 0)
                {
                    // +00-
                    d0 = f0 - f3;
                    xn0 = f0*x3 - f3*x0;
                    yn0 = f0*y3 - f3*y0;
                    zn0 = f0*z3 - f3*z0;
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        xn0, d0, yn0, d0, zn0, d0, 
                        x1, 1, y1, 1, z1, 1, 
                        x2, 1, y2, 1, z2, 1);
                }
                else
                {
                    // +000
                    AddTriangle(vertexMap, edgeSet, triangleSet, 
                        x1, 1, y1, 1, z1, 1, 
                        x2, 1, y2, 1, z2, 1, 
                        x3, 1, y3, 1, z3, 1);
                }
            }
        }
    }
    else if (f1 != 0)
    {
        // convert to case 0+**
        if (f1 < 0)
        {
            f1 = -f1;
            f2 = -f2;
            f3 = -f3;
        }

        if (f2 > 0)
        {
            if (f3 > 0)
            {
                // 0+++
                AddVertex(vertexMap, x0, 1, y0, 1, z0, 1);
            }
            else if (f3 < 0)
            {
                // 0++-
                d0 = f2 - f3;
                xn0 = f2*x3 - f3*x2;
                yn0 = f2*y3 - f3*y2;
                zn0 = f2*z3 - f3*z2;
                d1 = f1 - f3;
                xn1 = f1*x3 - f3*x1;
                yn1 = f1*y3 - f3*y1;
                zn1 = f1*z3 - f3*z1;
                AddTriangle(vertexMap, edgeSet, triangleSet, 
                    xn0, d0, yn0, d0, zn0, d0, 
                    xn1, d1, yn1, d1, zn1, d1, 
                    x0, 1, y0, 1, z0, 1);
            }
            else
            {
                // 0++0
                AddEdge(vertexMap, edgeSet, x0, 1, y0, 1, z0, 1, x3, 1,
                    y3, 1, z3, 1);
            }
        }
        else if (f2 < 0)
        {
            d0 = f2 - f1;
            xn0 = f2*x1 - f1*x2;
            yn0 = f2*y1 - f1*y2;
            zn0 = f2*z1 - f1*z2;

            if (f3 > 0)
            {
                // 0+-+
                d1 = f2 - f3;
                xn1 = f2*x3 - f3*x2;
                yn1 = f2*y3 - f3*y2;
                zn1 = f2*z3 - f3*z2;
                AddTriangle(vertexMap, edgeSet, triangleSet, 
                    xn0, d0, yn0, d0, zn0, d0, 
                    xn1, d1, yn1, d1, zn1, d1, 
                    x0, 1, y0, 1, z0, 1);
            }
            else if (f3 < 0)
            {
                // 0+--
                d1 = f1 - f3;
                xn1 = f1*x3 - f3*x1;
                yn1 = f1*y3 - f3*y1;
                zn1 = f1*z3 - f3*z1;
                AddTriangle(vertexMap, edgeSet, triangleSet, 
                    xn0, d0, yn0, d0, zn0, d0, 
                    xn1, d1, yn1, d1, zn1, d1, 
                    x0, 1, y0, 1, z0, 1);
            }
            else
            {
                // 0+-0
                AddTriangle(vertexMap, edgeSet, triangleSet, 
                    xn0, d0, yn0, d0, zn0, d0, 
                    x0, 1, y0, 1, z0, 1, 
                    x3, 1, y3, 1, z3, 1);
            }
        }
        else
        {
            if (f3 > 0)
            {
                // 0+0+
                AddEdge(vertexMap, edgeSet, x0, 1, y0, 1, z0, 1, x2, 1,
                    y2, 1, z2, 1);
            }
            else if (f3 < 0)
            {
                // 0+0-
                d0 = f1 - f3;
                xn0 = f1*x3 - f3*x1;
                yn0 = f1*y3 - f3*y1;
                zn0 = f1*z3 - f3*z1;
                AddTriangle(vertexMap, edgeSet, triangleSet, 
                    xn0, d0, yn0, d0, zn0, d0, 
                    x0, 1, y0, 1, z0, 1, 
                    x2, 1, y2, 1, z2, 1);
            }
            else
            {
                // 0+00
                AddTriangle(vertexMap, edgeSet, triangleSet, 
                    x0, 1, y0, 1, z0, 1, 
                    x2, 1, y2, 1, z2, 1, 
                    x3, 1, y3, 1, z3, 1);
            }
        }
    }
    else if (f2 != 0)
    {
        // convert to case 00+*
        if (f2 < 0)
        {
            f2 = -f2;
            f3 = -f3;
        }

        if (f3 > 0)
        {
            // 00++
            AddEdge(vertexMap, edgeSet, x0, 1, y0, 1, z0, 1, x1, 1, y1, 1,
                z1, 1);
        }
        else if (f3 < 0)
        {
            // 00+-
            d0 = f2 - f3;
            xn0 = f2*x3 - f3*x2;
            yn0 = f2*y3 - f3*y2;
            zn0 = f2*z3 - f3*z2;
            AddTriangle(vertexMap, edgeSet, triangleSet, 
                xn0, d0, yn0, d0, zn0, d0, 
                x0, 1, y0, 1, z0, 1, 
                x1, 1, y1, 1, z1, 1);
        }
        else
        {
            // 00+0
            AddTriangle(vertexMap, edgeSet, triangleSet, 
                x0, 1, y0, 1, z0, 1, 
                x1, 1, y1, 1, z1, 1, 
                x3, 1, y3, 1, z3, 1);
        }
    }
    else if (f3 != 0)
    {
        // cases 000+ or 000-
        AddTriangle(vertexMap, edgeSet, triangleSet, 
            x0, 1, y0, 1, z0, 1, 
            x1, 1, y1, 1, z1, 1, 
            x2, 1, y2, 1, z2, 1);
    }
    else
    {
        // case 0000
        AddTriangle(vertexMap, edgeSet, triangleSet, 
            x0, 1, y0, 1, z0, 1, 
            x1, 1, y1, 1, z1, 1, 
            x2, 1, y2, 1, z2, 1);
        AddTriangle(vertexMap, edgeSet, triangleSet, 
            x0, 1, y0, 1, z0, 1, 
            x1, 1, y1, 1, z1, 1, 
            x3, 1, y3, 1, z3, 1);
        AddTriangle(vertexMap, edgeSet, triangleSet, 
            x0, 1, y0, 1, z0, 1, 
            x2, 1, y2, 1, z2, 1, 
            x3, 1, y3, 1, z3, 1);
        AddTriangle(vertexMap, edgeSet, triangleSet, 
            x1, 1, y1, 1, z1, 1, 
            x2, 1, y2, 1, z2, 1, 
            x3, 1, y3, 1, z3, 1);
    }
}

Imagics::ExtractSurfaceTetra::Vertex
	::Vertex (int xNumer, int xDenom, int yNumer,
    int yDenom, int zNumer, int zDenom) noexcept
{
    if (xDenom > 0)
    {
        XNumer = xNumer;
        XDenom = xDenom;
    }
    else
    {
        XNumer = -xNumer;
        XDenom = -xDenom;
    }

    if (yDenom > 0)
    {
        YNumer = yNumer;
        YDenom = yDenom;
    }
    else
    {
        YNumer = -yNumer;
        YDenom = -yDenom;
    }

    if (zDenom > 0)
    {
        ZNumer = zNumer;
        ZDenom = zDenom;
    }
    else
    {
        ZNumer = -zNumer;
        ZDenom = -zDenom;
    }
}

bool Imagics::ExtractSurfaceTetra::Vertex
	::operator< (const Vertex& vertex) const noexcept
{
    const unsigned int value0[6] =
    {
        *(unsigned int*)&XNumer,
        *(unsigned int*)&XDenom,
        *(unsigned int*)&YNumer,
        *(unsigned int*)&YDenom,
        *(unsigned int*)&ZNumer,
        *(unsigned int*)&ZDenom
    };

    const unsigned int value1[6] =
    {
        *(unsigned int*)&vertex.XNumer,
        *(unsigned int*)&vertex.XDenom,
        *(unsigned int*)&vertex.YNumer,
        *(unsigned int*)&vertex.YDenom,
        *(unsigned int*)&vertex.ZNumer,
        *(unsigned int*)&vertex.ZDenom
    };

    for (int i = 0; i < 6; ++i)
    {
        if (value0[i] < value1[i])
        {
            return true;
        }
        if (value0[i] > value1[i])
        {
            return false;
        }
    }

    return false;
}

void Imagics::ExtractSurfaceTetra::Vertex
	::GetTriple (Mathematics::Vector3Df& meshVertex) const
{
    meshVertex.SetXCoordinate(float(XNumer)/float(XDenom));
    meshVertex.SetYCoordinate(float(YNumer)/float(YDenom));
    meshVertex.SetZCoordinate(float(ZNumer)/float(ZDenom));
}

#include STSTEM_WARNING_POP