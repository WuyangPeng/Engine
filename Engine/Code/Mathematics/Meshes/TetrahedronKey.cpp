// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.2 (2019/07/16 11:48)

#include "Mathematics/MathematicsExport.h"

#include "TetrahedronKey.h" 

const int Mathematics::TetrahedronKey
	::oppositeFace[4][3] = { { 1, 2, 3 }, { 0, 3, 2 }, { 0, 1, 3 }, { 0, 2, 1 } };

Mathematics::TetrahedronKey
	::TetrahedronKey(int v0, int v1, int v2, int v3) noexcept
{
    int imin = 0;
    V[0] = v0;
    if (v1 < V[0])
    {
        V[0] = v1;
        imin = 1;
    }
    if (v2 < V[0])
    {
        V[0] = v2;
        imin = 2;
    }
    if (v3 < V[0])
    {
        V[0] = v3;
        imin = 3;
    }

    if (imin == 0)
    {
        Permute(v1, v2, v3);
    }
    else if (imin == 1)
    {
        Permute(v0, v3, v2);
    }
    else if (imin == 2)
    {
        Permute(v0, v1, v3);
    }
    else  // imin == 3
    {
        Permute(v0, v2, v1);
    }
}

bool Mathematics::TetrahedronKey
	::operator< (const TetrahedronKey& key) const noexcept
{
    if (V[3] < key.V[3])
    {
        return true;
    }

    if (V[3] > key.V[3])
    {
        return false;
    }

    if (V[2] < key.V[2])
    {
        return true;
    }

    if (V[2] > key.V[2])
    {
        return false;
    }

    if (V[1] < key.V[1])
    {
        return true;
    }

    if (V[1] > key.V[1])
    {
        return false;
    }

    return V[0] < key.V[0];
}

void Mathematics::TetrahedronKey 
	::Permute(int u0, int u1, int u2) noexcept
{
    // Once V[0] is determined, create a permutation (V[1],V[2],V[3]) so
    // that (V[0],V[1],V[2],V[3]) is a positive permutation of (v0,v1,v2,v3).
    if (u0 < u1)
    {
        if (u0 < u2)
        {
            // u0 is minimum
            V[1] = u0;
            V[2] = u1;
            V[3] = u2;
        }
        else
        {
            // u2 is minimum
            V[1] = u2;
            V[2] = u0;
            V[3] = u1;
        }
    }
    else
    {
        if (u1 < u2)
        {
            // u1 is minimum
            V[1] = u1;
            V[2] = u2;
            V[3] = u0;
        }
        else
        {
            // u2 is minimum
            V[1] = u2;
            V[2] = u0;
            V[3] = u1;
        }
    }
}

