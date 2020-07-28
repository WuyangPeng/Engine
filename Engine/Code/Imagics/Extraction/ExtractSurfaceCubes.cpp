// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:36)

#include "Imagics/ImagicsExport.h"

#include "ExtractSurfaceCubes.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/ImagicsCustomAssertMacro.h"

#include <map>

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(6385)

typedef std::map<Mathematics::Vector3Df,int> VMap;
typedef VMap::iterator VMapIterator;
typedef std::map<Mathematics::TriangleKey,int> TMap;
typedef TMap::iterator TMapIterator;

Imagics::ExtractSurfaceCubes
	::ExtractSurfaceCubes(int xBound, int yBound,int zBound, int* data) noexcept
    : mXBound(xBound),
      mYBound(yBound),
	  mZBound(zBound),
	  mXYBound(xBound*yBound),
	  mData(data)
{
}

void Imagics::ExtractSurfaceCubes
	::ExtractContour (float level, std::vector<Mathematics::Vector3Df>& vertices, std::vector<Mathematics::TriangleKey>& triangles)
{
    vertices.clear();
    triangles.clear();

    for (int z = 0; z < mZBound-1; ++z)
    {
        for (int y = 0; y < mYBound-1; ++y)
        {
            for (int x = 0; x < mXBound-1; ++x)
            {
                // Get vertices on edges of box (if any).
                VETable table;
                const int type = GetVertices(level, x, y, z, table);
                if (type != 0)
                {
                    // Get edges on faces of box.
                    GetXMinEdges(x, y, z, type, table);
                    GetXMaxEdges(x, y, z, type, table);
                    GetYMinEdges(x, y, z, type, table);
                    GetYMaxEdges(x, y, z, type, table);
                    GetZMinEdges(x, y, z, type, table);
                    GetZMaxEdges(x, y, z, type, table);

                    // Ear-clip the wireframe mesh.
                    table.RemoveTriangles(vertices, triangles);
                }
            }
        }
    }
}

void Imagics::ExtractSurfaceCubes
	::MakeUnique (std::vector<Mathematics::Vector3Df>& vertices,std::vector<Mathematics::TriangleKey>& triangles)
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
        std::pair<VMapIterator,bool> result = vertexMap.insert(std::make_pair(vertices[v], nextVertex));

        if (result.second == true)
        {
            ++nextVertex;
        }
    }

    // Use a hash table to generate unique storage.
    TMap triangleMap;
    TMapIterator tIter;
    for (int t = 0, nextTriangle = 0; t < numTriangles; ++t)
    {
        // R.place old vertex indices by new ones
        Mathematics::TriangleKey& tri = triangles[t];
        vIter = vertexMap.find(vertices[tri.GetKey(0)]);
        IMAGICS_ASSERTION_0(vIter != vertexMap.end(), "Unexpected condition\n");
        tri.SetKey(0, vIter->second);
		vIter = vertexMap.find(vertices[tri.GetKey(1)]);
		IMAGICS_ASSERTION_0(vIter != vertexMap.end(), "Unexpected condition\n");
		tri.SetKey(1, vIter->second); 
		vIter = vertexMap.find(vertices[tri.GetKey(2)]);
		IMAGICS_ASSERTION_0(vIter != vertexMap.end(), "Unexpected condition\n");
		tri.SetKey(2, vIter->second); 

        // Keep only unique triangles.
        std::pair<TMapIterator,bool> result = triangleMap.insert(std::make_pair(tri, nextTriangle));

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

void Imagics::ExtractSurfaceCubes
	::OrientTriangles (std::vector<Mathematics::Vector3Df>& vertices,std::vector<Mathematics::TriangleKey>& triangles, bool sameDir)
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
        const float dot = Mathematics::Vector3DToolsf::DotProduct(gradAvr, normal);

        // Choose triangle orientation based on gradient direction.
        int save = 0;
        if (sameDir)
        {
            if (dot < 0.0f)
            {
                // Wrong orientation, reorder it.
				save = tri.GetKey(1);;
				tri.SetKey(1, tri.GetKey(2));
				tri.SetKey(2, save); 
            }
        }
        else
        {
            if (dot > 0.0f)
            {
                // Wrong orientation, reorder it.
				save = tri.GetKey(1);;
				tri.SetKey(1, tri.GetKey(2));
				tri.SetKey(2, save); 
            }
        }
    }
}

void Imagics::ExtractSurfaceCubes
	::ComputeNormals ( const std::vector<Mathematics::Vector3Df>& vertices,const std::vector<Mathematics::TriangleKey>& triangles, std::vector<Mathematics::Vector3Df>& normals)
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

int Imagics::
	ExtractSurfaceCubes::GetVertices (float level, int x, int y, int z, VETable& table)
{
    int type = 0;

    // get image values at corners of voxel
    const int i000 = x + mXBound*(y + mYBound*z);
    const int i100 = i000 + 1;
    const int i010 = i000 + mXBound;
    const int i110 = i010 + 1;
    const int i001 = i000 + mXYBound;
    const int i101 = i001 + 1;
    const int i011 = i001 + mXBound;
    const int i111 = i011 + 1;
    const  float f000 = (float)mData[i000];
    const float f100 = (float)mData[i100];
    const float f010 = (float)mData[i010];
    const float f110 = (float)mData[i110];
    const float f001 = (float)mData[i001];
    const float f101 = (float)mData[i101];
    const float f011 = (float)mData[i011];
    const float f111 = (float)mData[i111];

    const float x0 = (float)x;
    const float y0 = (float)y;
    const float z0 = (float)z;
    const  float x1 = x0 + 1.0f;
    const float y1 = y0 + 1.0f;
    const float z1 = z0 + 1.0f;

    // xmin-ymin edge
    float diff0 = level - f000;
    float diff1 = level - f001;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_XMIN_YMIN;
        table.Insert(EI_XMIN_YMIN,
            Mathematics::Vector3Df(x0, y0, z0 + diff0/(f001 - f000)));
    }

    // xmin-ymax edge
    diff0 = level - f010;
    diff1 = level - f011;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_XMIN_YMAX;
        table.Insert(EI_XMIN_YMAX,
            Mathematics::Vector3Df(x0, y1, z0 + diff0/(f011 - f010)));
    }

    // xmax-ymin edge
    diff0 = level - f100;
    diff1 = level - f101;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_XMAX_YMIN;
        table.Insert(EI_XMAX_YMIN, Mathematics::Vector3Df(x1, y0, z0 + diff0/(f101 - f100)));
    }

    // xmax-ymax edge
    diff0 = level - f110;
    diff1 = level - f111;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_XMAX_YMAX;
        table.Insert(EI_XMAX_YMAX, Mathematics::Vector3Df(x1, y1, z0 + diff0/(f111 - f110)));
    }

    // xmin-zmin edge
    diff0 = level - f000;
    diff1 = level - f010;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_XMIN_ZMIN;
        table.Insert(EI_XMIN_ZMIN,Mathematics::Vector3Df(x0, y0 + diff0/(f010 - f000), z0));
    }

    // xmin-zmax edge
    diff0 = level - f001;
    diff1 = level - f011;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_XMIN_ZMAX;
        table.Insert(EI_XMIN_ZMAX,Mathematics::Vector3Df(x0, y0 + diff0/(f011 - f001), z1));
    }

    // xmax-zmin edge
    diff0 = level - f100;
    diff1 = level - f110;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_XMAX_ZMIN;
        table.Insert(EI_XMAX_ZMIN,Mathematics::Vector3Df(x1, y0 + diff0/(f110 - f100), z0));
    }

    // xmax-zmax edge
    diff0 = level - f101;
    diff1 = level - f111;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_XMAX_ZMAX;
        table.Insert(EI_XMAX_ZMAX, Mathematics::Vector3Df(x1, y0 + diff0/(f111 - f101), z1));
    }

    // ymin-zmin edge
    diff0 = level - f000;
    diff1 = level - f100;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_YMIN_ZMIN;
        table.Insert(EI_YMIN_ZMIN,Mathematics::Vector3Df(x0 + diff0/(f100 - f000), y0, z0));
    }

    // ymin-zmax edge
    diff0 = level - f001;
    diff1 = level - f101;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_YMIN_ZMAX;
        table.Insert(EI_YMIN_ZMAX,Mathematics::Vector3Df(x0 + diff0/(f101 - f001), y0, z1));
    }

    // ymax-zmin edge
    diff0 = level - f010;
    diff1 = level - f110;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_YMAX_ZMIN;
        table.Insert(EI_YMAX_ZMIN,Mathematics::Vector3Df(x0 + diff0/(f110 - f010), y1, z0));
    }

    // ymax-zmax edge
    diff0 = level - f011;
    diff1 = level - f111;
    if (diff0*diff1 < 0.0f)
    {
        type |= EB_YMAX_ZMAX;
        table.Insert(EI_YMAX_ZMAX,Mathematics::Vector3Df(x0 + diff0/(f111 - f011), y1, z1));
    }

    return type;
}

void Imagics::ExtractSurfaceCubes
	::GetXMinEdges (int x, int y, int z, int type, VETable& table)
{
    int faceType = 0;
    if (type & EB_XMIN_YMIN)
    {
        faceType |= 0x01;
    }
    if (type & EB_XMIN_YMAX)
    {
        faceType |= 0x02;
    }
    if (type & EB_XMIN_ZMIN)
    {
        faceType |= 0x04;
    }
    if (type & EB_XMIN_ZMAX)
    {
        faceType |= 0x08;
    }

    switch (faceType)
    {
    case  0: return;
    case  3: table.Insert(EI_XMIN_YMIN, EI_XMIN_YMAX); break;
    case  5: table.Insert(EI_XMIN_YMIN, EI_XMIN_ZMIN); break;
    case  6: table.Insert(EI_XMIN_YMAX, EI_XMIN_ZMIN); break;
    case  9: table.Insert(EI_XMIN_YMIN, EI_XMIN_ZMAX); break;
    case 10: table.Insert(EI_XMIN_YMAX, EI_XMIN_ZMAX); break;
    case 12: table.Insert(EI_XMIN_ZMIN, EI_XMIN_ZMAX); break;
    case 15:
    {
        // Four vertices, one per edge, need to disambiguate.
        int i = x + mXBound*(y + mYBound*z);
        const int f00 = mData[i];  // F(x,y,z)
        i += mXBound;
        const int f10 = mData[i];  // F(x,y+1,z)
        i += mXYBound;
        const int f11 = mData[i];  // F(x,y+1,z+1)
        i -= mXBound;
        const int f01 = mData[i];  // F(x,y,z+1)
        const int det = f00*f11 - f01*f10;

        if (det > 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P2>, <P1,P3>.
            table.Insert(EI_XMIN_YMIN, EI_XMIN_ZMIN);
            table.Insert(EI_XMIN_YMAX, EI_XMIN_ZMAX);
        }
        else if (det < 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P3>, <P1,P2>.
            table.Insert(EI_XMIN_YMIN, EI_XMIN_ZMAX);
            table.Insert(EI_XMIN_YMAX, EI_XMIN_ZMIN);
        }
        else
        {
            // Plus-sign configuration, add branch point to tessellation.
            table.Insert(FI_XMIN, Mathematics::Vector3Df(table.GetX(EI_XMIN_ZMIN),
                table.GetY(EI_XMIN_ZMIN), table.GetZ(EI_XMIN_YMIN)));

            // Add edges sharing the branch point.
            table.Insert(EI_XMIN_YMIN, FI_XMIN);
            table.Insert(EI_XMIN_YMAX, FI_XMIN);
            table.Insert(EI_XMIN_ZMIN, FI_XMIN);
            table.Insert(EI_XMIN_ZMAX, FI_XMIN);
        }
        break;
    }
    default:
        IMAGICS_ASSERTION_3(false, "Unexpected condition\n");
        break;
    }
}

void Imagics::ExtractSurfaceCubes
	::GetXMaxEdges (int x, int y, int z, int type, VETable& table)
{
    int faceType = 0;
    if (type & EB_XMAX_YMIN)
    {
        faceType |= 0x01;
    }
    if (type & EB_XMAX_YMAX)
    {
        faceType |= 0x02;
    }
    if (type & EB_XMAX_ZMIN)
    {
        faceType |= 0x04;
    }
    if (type & EB_XMAX_ZMAX)
    {
        faceType |= 0x08;
    }

    switch (faceType)
    {
    case  0: return;
    case  3: table.Insert(EI_XMAX_YMIN, EI_XMAX_YMAX); break;
    case  5: table.Insert(EI_XMAX_YMIN, EI_XMAX_ZMIN); break;
    case  6: table.Insert(EI_XMAX_YMAX, EI_XMAX_ZMIN); break;
    case  9: table.Insert(EI_XMAX_YMIN, EI_XMAX_ZMAX); break;
    case 10: table.Insert(EI_XMAX_YMAX, EI_XMAX_ZMAX); break;
    case 12: table.Insert(EI_XMAX_ZMIN, EI_XMAX_ZMAX); break;
    case 15:
    {
        // Four vertices, one per edge, need to disambiguate.
        int i = (x+1) + mXBound*(y + mYBound*z);
        const int f00 = mData[i];  // F(x,y,z)
        i += mXBound;
        const int f10 = mData[i];  // F(x,y+1,z)
        i += mXYBound;
        const int f11 = mData[i];  // F(x,y+1,z+1)
        i -= mXBound;
        const int f01 = mData[i];  // F(x,y,z+1)
        const int det = f00*f11 - f01*f10;

        if (det > 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P2>, <P1,P3>.
            table.Insert(EI_XMAX_YMIN, EI_XMAX_ZMIN);
            table.Insert(EI_XMAX_YMAX, EI_XMAX_ZMAX);
        }
        else if (det < 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P3>, <P1,P2>.
            table.Insert(EI_XMAX_YMIN, EI_XMAX_ZMAX);
            table.Insert(EI_XMAX_YMAX, EI_XMAX_ZMIN);
        }
        else
        {
            // Plus-sign configuration, add branch point to tessellation.
            table.Insert(FI_XMAX,Mathematics::Vector3Df(table.GetX(EI_XMAX_ZMIN),
                table.GetY(EI_XMAX_ZMIN), table.GetZ(EI_XMAX_YMIN)));

            // Add edges sharing the branch point.
            table.Insert(EI_XMAX_YMIN, FI_XMAX);
            table.Insert(EI_XMAX_YMAX, FI_XMAX);
            table.Insert(EI_XMAX_ZMIN, FI_XMAX);
            table.Insert(EI_XMAX_ZMAX, FI_XMAX);
        }
        break;
    }
    default:
        IMAGICS_ASSERTION_3(false, "Unexpected condition\n");
        break;
    }
}

void Imagics::ExtractSurfaceCubes
	::GetYMinEdges (int x, int y, int z, int type,  VETable& table)
{
    int faceType = 0;
    if (type & EB_XMIN_YMIN)
    {
        faceType |= 0x01;
    }
    if (type & EB_XMAX_YMIN)
    {
        faceType |= 0x02;
    }
    if (type & EB_YMIN_ZMIN)
    {
        faceType |= 0x04;
    }
    if (type & EB_YMIN_ZMAX)
    {
        faceType |= 0x08;
    }

    switch (faceType)
    {
    case  0: return;
    case  3: table.Insert(EI_XMIN_YMIN, EI_XMAX_YMIN); break;
    case  5: table.Insert(EI_XMIN_YMIN, EI_YMIN_ZMIN); break;
    case  6: table.Insert(EI_XMAX_YMIN, EI_YMIN_ZMIN); break;
    case  9: table.Insert(EI_XMIN_YMIN, EI_YMIN_ZMAX); break;
    case 10: table.Insert(EI_XMAX_YMIN, EI_YMIN_ZMAX); break;
    case 12: table.Insert(EI_YMIN_ZMIN, EI_YMIN_ZMAX); break;
    case 15:
    {
        // Four vertices, one per edge, need to disambiguate.
        int i = x + mXBound*(y + mYBound*z);
        const int f00 = mData[i];  // F(x,y,z)
        i++;
        const int f10 = mData[i];  // F(x+1,y,z)
        i += mXYBound;
        const int f11 = mData[i];  // F(x+1,y,z+1)
        i--;
        const int f01 = mData[i];  // F(x,y,z+1)
        const int det = f00*f11 - f01*f10;

        if (det > 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P2>, <P1,P3>.
            table.Insert(EI_XMIN_YMIN, EI_YMIN_ZMIN);
            table.Insert(EI_XMAX_YMIN, EI_YMIN_ZMAX);
        }
        else if (det < 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P3>, <P1,P2>.
            table.Insert(EI_XMIN_YMIN, EI_YMIN_ZMAX);
            table.Insert(EI_XMAX_YMIN, EI_YMIN_ZMIN);
        }
        else
        {
            // Plus-sign configuration, add branch point to tessellation.
            table.Insert(FI_YMIN,Mathematics::Vector3Df(table.GetX(EI_YMIN_ZMIN),
                table.GetY(EI_XMIN_YMIN), table.GetZ(EI_XMIN_YMIN)));

            // Add edges sharing the branch point.
            table.Insert(EI_XMIN_YMIN, FI_YMIN);
            table.Insert(EI_XMAX_YMIN, FI_YMIN);
            table.Insert(EI_YMIN_ZMIN, FI_YMIN);
            table.Insert(EI_YMIN_ZMAX, FI_YMIN);
        }
        break;
    }
    default:
        IMAGICS_ASSERTION_3(false, "Unexpected condition\n");
        break;
    }
}

void Imagics::ExtractSurfaceCubes
	::GetYMaxEdges (int x, int y, int z, int type,  VETable& table)
{
    int faceType = 0;
    if (type & EB_XMIN_YMAX)
    {
        faceType |= 0x01;
    }
    if (type & EB_XMAX_YMAX)
    {
        faceType |= 0x02;
    }
    if (type & EB_YMAX_ZMIN)
    {
        faceType |= 0x04;
    }
    if (type & EB_YMAX_ZMAX)
    {
        faceType |= 0x08;
    }

    switch (faceType)
    {
    case  0: return;
    case  3: table.Insert(EI_XMIN_YMAX, EI_XMAX_YMAX); break;
    case  5: table.Insert(EI_XMIN_YMAX, EI_YMAX_ZMIN); break;
    case  6: table.Insert(EI_XMAX_YMAX, EI_YMAX_ZMIN); break;
    case  9: table.Insert(EI_XMIN_YMAX, EI_YMAX_ZMAX); break;
    case 10: table.Insert(EI_XMAX_YMAX, EI_YMAX_ZMAX); break;
    case 12: table.Insert(EI_YMAX_ZMIN, EI_YMAX_ZMAX); break;
    case 15:
    {
        // Four vertices, one per edge, need to disambiguate.
        int i = x + mXBound*((y+1) + mYBound*z);
        const int f00 = mData[i];  // F(x,y,z)
        i++;
        const int f10 = mData[i];  // F(x+1,y,z)
        i += mXYBound;
        const int f11 = mData[i];  // F(x+1,y,z+1)
        i--;
        const int f01 = mData[i];  // F(x,y,z+1)
        const int det = f00*f11 - f01*f10;

        if (det > 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P2>, <P1,P3>.
            table.Insert(EI_XMIN_YMAX, EI_YMAX_ZMIN);
            table.Insert(EI_XMAX_YMAX, EI_YMAX_ZMAX);
        }
        else if (det < 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P3>, <P1,P2>.
            table.Insert(EI_XMIN_YMAX, EI_YMAX_ZMAX);
            table.Insert(EI_XMAX_YMAX, EI_YMAX_ZMIN);
        }
        else
        {
            // Plus-sign configuration, add branch point to tessellation.
            table.Insert(FI_YMAX,Mathematics::Vector3Df(table.GetX(EI_YMAX_ZMIN),table.GetY(EI_XMIN_YMAX), table.GetZ(EI_XMIN_YMAX)));

            // Add edges sharing the branch point.
            table.Insert(EI_XMIN_YMAX, FI_YMAX);
            table.Insert(EI_XMAX_YMAX, FI_YMAX);
            table.Insert(EI_YMAX_ZMIN, FI_YMAX);
            table.Insert(EI_YMAX_ZMAX, FI_YMAX);
        }
        break;
    }
    default:
        IMAGICS_ASSERTION_3(false, "Unexpected condition\n");
        break;
    }
}

void Imagics::ExtractSurfaceCubes
	::GetZMinEdges (int x, int y, int z, int type, VETable& table)
{
    int faceType = 0;
    if (type & EB_XMIN_ZMIN)
    {
        faceType |= 0x01;
    }
    if (type & EB_XMAX_ZMIN)
    {
        faceType |= 0x02;
    }
    if (type & EB_YMIN_ZMIN)
    {
        faceType |= 0x04;
    }
    if (type & EB_YMAX_ZMIN)
    {
        faceType |= 0x08;
    }

    switch (faceType)
    {
    case  0: return;
    case  3: table.Insert(EI_XMIN_ZMIN, EI_XMAX_ZMIN); break;
    case  5: table.Insert(EI_XMIN_ZMIN, EI_YMIN_ZMIN); break;
    case  6: table.Insert(EI_XMAX_ZMIN, EI_YMIN_ZMIN); break;
    case  9: table.Insert(EI_XMIN_ZMIN, EI_YMAX_ZMIN); break;
    case 10: table.Insert(EI_XMAX_ZMIN, EI_YMAX_ZMIN); break;
    case 12: table.Insert(EI_YMIN_ZMIN, EI_YMAX_ZMIN); break;
    case 15:
    {
        // Four vertices, one per edge, need to disambiguate.
        int i = x + mXBound*(y + mYBound*z);
        const int f00 = mData[i];  // F(x,y,z)
        i++;
        const int f10 = mData[i];  // F(x+1,y,z)
        i += mXBound;
        const int f11 = mData[i];  // F(x+1,y+1,z)
        i--;
        const int f01 = mData[i];  // F(x,y+1,z)
        const int det = f00*f11 - f01*f10;

        if (det > 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P2>, <P1,P3>.
            table.Insert(EI_XMIN_ZMIN, EI_YMIN_ZMIN);
            table.Insert(EI_XMAX_ZMIN, EI_YMAX_ZMIN);
        }
        else if (det < 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P3>, <P1,P2>.
            table.Insert(EI_XMIN_ZMIN, EI_YMAX_ZMIN);
            table.Insert(EI_XMAX_ZMIN, EI_YMIN_ZMIN);
        }
        else
        {
            // Plus-sign configuration, add branch point to tessellation.
            table.Insert(FI_ZMIN,Mathematics::Vector3Df(table.GetX(EI_YMIN_ZMIN),
                table.GetY(EI_XMIN_ZMIN), table.GetZ(EI_XMIN_ZMIN)));

            // Add edges sharing the branch point.
            table.Insert(EI_XMIN_ZMIN, FI_ZMIN);
            table.Insert(EI_XMAX_ZMIN, FI_ZMIN);
            table.Insert(EI_YMIN_ZMIN, FI_ZMIN);
            table.Insert(EI_YMAX_ZMIN, FI_ZMIN);
        }
        break;
    }
    default:
        IMAGICS_ASSERTION_3(false, "Unexpected condition\n");
        break;
    }
}

void Imagics::ExtractSurfaceCubes
	::GetZMaxEdges (int x, int y, int z, int type,    VETable& table)
{
    int faceType = 0;
    if (type & EB_XMIN_ZMAX)
    {
        faceType |= 0x01;
    }
    if (type & EB_XMAX_ZMAX)
    {
        faceType |= 0x02;
    }
    if (type & EB_YMIN_ZMAX)
    {
        faceType |= 0x04;
    }
    if (type & EB_YMAX_ZMAX)
    {
        faceType |= 0x08;
    }

    switch (faceType)
    {
    case  0: return;
    case  3: table.Insert(EI_XMIN_ZMAX, EI_XMAX_ZMAX); break;
    case  5: table.Insert(EI_XMIN_ZMAX, EI_YMIN_ZMAX); break;
    case  6: table.Insert(EI_XMAX_ZMAX, EI_YMIN_ZMAX); break;
    case  9: table.Insert(EI_XMIN_ZMAX, EI_YMAX_ZMAX); break;
    case 10: table.Insert(EI_XMAX_ZMAX, EI_YMAX_ZMAX); break;
    case 12: table.Insert(EI_YMIN_ZMAX, EI_YMAX_ZMAX); break;
    case 15:
    {
        // Four vertices, one per edge, need to disambiguate.
        int i = x + mXBound*(y + mYBound*(z+1));
        const int f00 = mData[i];  // F(x,y,z)
        i++;
        const int f10 = mData[i];  // F(x+1,y,z)
        i += mXBound;
        const int f11 = mData[i];  // F(x+1,y+1,z)
        i--;
        const int f01 = mData[i];  // F(x,y+1,z)
        const int det = f00*f11 - f01*f10;

        if (det > 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P2>, <P1,P3>.
            table.Insert(EI_XMIN_ZMAX, EI_YMIN_ZMAX);
            table.Insert(EI_XMAX_ZMAX, EI_YMAX_ZMAX);
        }
        else if (det < 0)
        {
            // Disjoint hyperbolic segments, pair <P0,P3>, <P1,P2>.
            table.Insert(EI_XMIN_ZMAX, EI_YMAX_ZMAX);
            table.Insert(EI_XMAX_ZMAX, EI_YMIN_ZMAX);
        }
        else
        {
            // Plus-sign configuration, add branch point to tessellation.
            table.Insert(FI_ZMAX,Mathematics::Vector3Df(table.GetX(EI_YMIN_ZMAX),
                table.GetY(EI_XMIN_ZMAX), table.GetZ(EI_XMIN_ZMAX)));

            // Add edges sharing the branch point.
            table.Insert(EI_XMIN_ZMAX, FI_ZMAX);
            table.Insert(EI_XMAX_ZMAX, FI_ZMAX);
            table.Insert(EI_YMIN_ZMAX, FI_ZMAX);
            table.Insert(EI_YMAX_ZMAX, FI_ZMAX);
        }
        break;
    }
    default:
        IMAGICS_ASSERTION_3(false, "Unexpected condition\n");
        break;
    }
}

Mathematics::Vector3Df Imagics::ExtractSurfaceCubes
	::GetGradient (Mathematics::Vector3Df P)
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

    // Get image values at corners of voxel.
    const int i000 = x + mXBound*(y + mYBound*z);
    const int i100 = i000 + 1;
    const int i010 = i000 + mXBound;
    const int i110 = i010 + 1;
    const int i001 = i000 + mXYBound;
    const int i101 = i001 + 1;
    const int i011 = i001 + mXBound;
    const  int i111 = i011 + 1;
    const float f000 = (float)mData[i000];
    const float f100 = (float)mData[i100];
    const  float f010 = (float)mData[i010];
    const float f110 = (float)mData[i110];
    const  float f001 = (float)mData[i001];
    const float f101 = (float)mData[i101];
    const float f011 = (float)mData[i011];
    const float f111 = (float)mData[i111];

	P.SetXCoordinate(P.GetXCoordinate() - x); 
	P.SetYCoordinate(P.GetYCoordinate() - y);
	P.SetZCoordinate(P.GetZCoordinate() - z); 
    const float oneMX = 1.0f - P.GetXCoordinate();
    const float oneMY = 1.0f - P.GetYCoordinate();
    const float oneMZ = 1.0f - P.GetZCoordinate();

    Mathematics::Vector3Df grad;

    float tmp0 = oneMY*(f100 - f000) + P.GetYCoordinate()*(f110 - f010);
	float tmp1 = oneMY*(f101 - f001) + P.GetYCoordinate()*(f111 - f011);
    grad.SetXCoordinate(oneMZ*tmp0 + P.GetZCoordinate()*tmp1);
    
    tmp0 = oneMX*(f010 - f000) + P.GetXCoordinate()*(f110 - f100);
	tmp1 = oneMX*(f011 - f001) + P.GetXCoordinate()*(f111 - f101);
	grad.SetYCoordinate(oneMZ*tmp0 + P.GetZCoordinate()*tmp1);
    
	tmp0 = oneMX*(f001 - f000) + P.GetXCoordinate()*(f101 - f100);
	tmp1 = oneMX*(f011 - f010) + P.GetXCoordinate()*(f111 - f110);
	grad.SetZCoordinate(oneMY*tmp0 + P.GetYCoordinate()*tmp1);

    return grad;
}



// ExtractSurfaceCubes::VETable

Imagics::ExtractSurfaceCubes::VETable
	::VETable () noexcept
{
}

bool Imagics::ExtractSurfaceCubes::VETable
	::IsValidVertex (int i) const
{
    IMAGICS_ASSERTION_0(0 <= i && i < 18, "Invalid index\n");
    return mVertex[i].Valid;
}

float Imagics::ExtractSurfaceCubes::VETable
	::GetX (int i) const
{
    IMAGICS_ASSERTION_0(0 <= i && i < 18, "Invalid index\n");
    return mVertex[i].P.GetXCoordinate();
}

float Imagics::ExtractSurfaceCubes::VETable
	::GetY (int i) const
{
    IMAGICS_ASSERTION_0(0 <= i && i < 18, "Invalid index\n");
	return mVertex[i].P.GetYCoordinate();
}

float Imagics::ExtractSurfaceCubes::VETable
	::GetZ (int i) const
{
    IMAGICS_ASSERTION_0(0 <= i && i < 18, "Invalid index\n");
    return mVertex[i].P.GetZCoordinate();
}

void Imagics::ExtractSurfaceCubes::VETable
	::Insert (int i, const Mathematics::Vector3Df& P)
{
    IMAGICS_ASSERTION_0(0 <= i && i < 18, "Invalid index\n");
    Vertex& vertex = mVertex[i];
    vertex.P = P;
    vertex.Valid = true;
}

void Imagics::ExtractSurfaceCubes::VETable
	::Insert (int i0, int i1)
{
    IMAGICS_ASSERTION_0(0 <= i0 && i0 < 18 && 0 <= i1 && i1 < 18, "Invalid index\n");
    Vertex& vertex0 = mVertex[i0];
    Vertex& vertex1 = mVertex[i1];

    IMAGICS_ASSERTION_0(vertex0.NumAdjacents < 4 && vertex1.NumAdjacents < 4,
        "Invalid adjacent quantity\n");
    vertex0.Adj[vertex0.NumAdjacents++] = i1;
    vertex1.Adj[vertex1.NumAdjacents++] = i0;
}

void Imagics::ExtractSurfaceCubes::VETable
	::RemoveTriangles ( std::vector<Mathematics::Vector3Df>& vertices, std::vector<Mathematics::TriangleKey>& triangles)
{
    // ear-clip the wireframe to get the triangles
    Mathematics::TriangleKey tri(0,0,0);
    while (Remove(tri))
    {
        const int v0 = (int)vertices.size();
        const auto v1 = v0 + 1;
        const auto v2 = v1 + 1;
        triangles.push_back(Mathematics::TriangleKey(v0, v1, v2));
        vertices.push_back(mVertex[tri.GetKey(0)].P);
        vertices.push_back(mVertex[tri.GetKey(1)].P);
        vertices.push_back(mVertex[tri.GetKey(2)].P);
    }
}

void Imagics::ExtractSurfaceCubes::VETable
	::RemoveVertex (int i)
{
    IMAGICS_ASSERTION_0(0 <= i && i < 18, "Invalid index\n");
    Vertex& vertex0 = mVertex[i];

    IMAGICS_ASSERTION_0(vertex0.NumAdjacents == 2, "Invalid number of adjacents.\n");

    int a0 = vertex0.Adj[0], a1 = vertex0.Adj[1];
    Vertex& adjVertex0 = mVertex[a0];
    Vertex& adjVertex1 = mVertex[a1];

    int j;
    for (j = 0; j < adjVertex0.NumAdjacents; j++)
    {
        if (adjVertex0.Adj[j] == i)
        {
            adjVertex0.Adj[j] = a1;
            break;
        }
    }
    IMAGICS_ASSERTION_0(j != adjVertex0.NumAdjacents, "Unexpected condition\n");

    for (j = 0; j < adjVertex1.NumAdjacents; j++)
    {
        if (adjVertex1.Adj[j] == i)
        {
            adjVertex1.Adj[j] = a0;
            break;
        }
    }
    IMAGICS_ASSERTION_0(j != adjVertex1.NumAdjacents, "Unexpected condition\n");

    vertex0.Valid = false;

    if (adjVertex0.NumAdjacents == 2)
    {
        if (adjVertex0.Adj[0] == adjVertex0.Adj[1])
        {
            adjVertex0.Valid = false;
        }
    }

    if (adjVertex1.NumAdjacents == 2)
    {
        if (adjVertex1.Adj[0] == adjVertex1.Adj[1])
        {
            adjVertex1.Valid = false;
        }
    }
}

bool Imagics::ExtractSurfaceCubes::VETable
	::Remove (Mathematics::TriangleKey& tri)
{
    for (int i = 0; i < 18; ++i)
    {
        const Vertex& vertex = mVertex[i];
        if (vertex.Valid && vertex.NumAdjacents == 2)
        {
            tri.SetKey(0,i);
			tri.SetKey(1, vertex.Adj[0]);
			tri.SetKey(2, vertex.Adj[1]); 
            RemoveVertex(i);
            return true;
        }
    }

    return false;
}



// ExtractSurfaceCubes::VETable::Vertex

Imagics::ExtractSurfaceCubes::VETable::Vertex
	::Vertex () noexcept
    :NumAdjacents(0),Valid(false)
{
}

#include STSTEM_WARNING_POP