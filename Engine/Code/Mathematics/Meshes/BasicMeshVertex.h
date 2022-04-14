///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/22 16:29)

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
