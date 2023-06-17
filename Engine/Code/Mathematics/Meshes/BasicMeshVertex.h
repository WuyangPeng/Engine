///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:16)

#ifndef MATHEMATICS_MESHES_BASIC_BESH_VERTEX_H
#define MATHEMATICS_MESHES_BASIC_BESH_VERTEX_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

MATHEMATICS_NON_COPY_EXPORT_IMPL(BasicMeshVertexImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BasicMeshVertex
    {
    public:
        NON_COPY_TYPE_DECLARE(BasicMeshVertex);

    public:
        NODISCARD static BasicMeshVertex Create();

    private:
        explicit BasicMeshVertex(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetVertex(int index) const;
        NODISCARD int GetEdge(int index) const;
        NODISCARD int GetTriangle(int index) const;

        void InsertEdge(int vertex, int edge);
        void InsertTriangle(int triangle);

    private:
        PackageType impl;
    };
}

#endif  // MATHEMATICS_MESHES_BASIC_BESH_VERTEX_H
