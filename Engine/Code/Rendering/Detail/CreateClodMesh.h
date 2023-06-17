///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:51)

#ifndef RENDERING_DETAIL_CREATE_CLOD_MESH_H
#define RENDERING_DETAIL_CREATE_CLOD_MESH_H

#include "Rendering/RenderingDll.h"

#include "CollapseRecordArray.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(CreateClodMeshImpl);

// CreateClodMesh计算CollapseRecord的阵列，它表示在一个三角形网格边折叠。
// 一个边<V0,V1>折叠是由V0（以下简称“keep”顶点）更换V1（“throw”顶点）。
// 未引入任何新的顶点或表面属性。
// 此外，顶点和索引缓冲器被重新排列，使得顶点和三角形首先被移除，折叠发生在移除的数组的之后。
// 此支持发送顶点为静态几何硬件渲染器。
// 细节选择的等级只需要（1）改变活动顶点和三角形计数，
// 和（2）更新基于该CollapseRecord索引值的索引缓冲器。

// 当正常矢量中存在顶点缓冲器，可能会出现一些照明组件。
// 如果法线所使用的索引的三角拓扑每次缓冲目标记录的变化重新计算可以减少伪像。
// 在这种情况下，顶点缓冲区变成动态的，所以你要告诉渲染器来更新显存复制每一帧。

// 该CollapseRecord类可被修改以存储新的顶点和对增量更新属性。
// 例如，您可能想通过(V0+V1)/2，平均及其相应的属性以取代V0和V1，
// 在这种情况下，顶点缓冲区变成动态的，你要告诉渲染器来更新显存复制每一帧。

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CreateClodMesh
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CreateClodMesh);

    public:
        explicit CreateClodMesh(TrianglesMesh& mesh);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CollapseRecordArraySharedPtr GetCollapseRecordArray() const;

    private:
        PackageType impl;
    };

}

#endif  // RENDERING_DETAIL_CREATE_CLOD_MESH_H
