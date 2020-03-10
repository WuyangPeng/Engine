// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 11:13)

#ifndef MATHEMATICS_MESHES_BASIC_BESH_VERTEX_H
#define MATHEMATICS_MESHES_BASIC_BESH_VERTEX_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

MATHEMATICS_EXPORT_SHARED_PTR(BasicMeshVertexImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BasicMeshVertex
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(BasicMeshVertex);
        
    public:
        BasicMeshVertex ();
        
        CLASS_INVARIANT_DECLARE;
        
        int GetVertex(int index) const;
        int GetEdge(int index) const;
        int GetTriangle(int index) const;
        
        void InsertEdge (int vertex, int edge);
        void InsertTriangle (int triangle);
        
    private:
		IMPL_TYPE_DECLARE(BasicMeshVertex);
    };	
}

#endif // MATHEMATICS_MESHES_BASIC_BESH_VERTEX_H

