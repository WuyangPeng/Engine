// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:13)

#ifndef MATHEMATICS_MESHES_BASIC_BESH_VERTEX_H
#define MATHEMATICS_MESHES_BASIC_BESH_VERTEX_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
MATHEMATICS_NON_COPY_EXPORT_IMPL(BasicMeshVertexImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BasicMeshVertex
    {
    public:
        NON_COPY_TYPE_DECLARE(BasicMeshVertex);
        
    public:
        BasicMeshVertex ();
        
        CLASS_INVARIANT_DECLARE;
        
        int GetVertex(int index) const;
        int GetEdge(int index) const;
        int GetTriangle(int index) const;
        
        void InsertEdge (int vertex, int edge);
        void InsertTriangle (int triangle);
        
    private:
        PackageType impl;
    };	
}

#endif // MATHEMATICS_MESHES_BASIC_BESH_VERTEX_H

