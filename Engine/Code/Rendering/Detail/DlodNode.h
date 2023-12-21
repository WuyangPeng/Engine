///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:51)

#ifndef RENDERING_DETAIL_DLOD_NODE_H
#define RENDERING_DETAIL_DLOD_NODE_H

#include "Rendering/RenderingDll.h"

#include "SwitchNode.h"
#include "CoreTools/Helper/ExportMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(DlodNode, DlodNodeImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DlodNode : public SwitchNode
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(DlodNode);
        using ParentType = SwitchNode;

    public:
        explicit DlodNode(int numLevelsOfDetail);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DlodNode);

        // 访问中心(LOD)细节等级。
        NODISCARD APoint GetModelCenter() const noexcept;
        NODISCARD APoint GetWorldCenter() const noexcept;

        void SetModelCenter(const APoint& modelCenter) noexcept;

        // 获得子节点的距离间隔。
        NODISCARD int GetNumLevelsOfDetail() const noexcept;
        NODISCARD float GetModelMinDistance(int index) const;
        NODISCARD float GetModelMaxDistance(int index) const;
        NODISCARD float GetWorldMinDistance(int index) const;
        NODISCARD float GetWorldMaxDistance(int index) const;
        void SetModelDistance(int index, float minDistance, float maxDistance);

    protected:
        // 支持分级裁剪。
        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) override;

    private:
        // 开关基于来自世界LOD中心，以摄像头距离选择子节点。
        void SelectLevelOfDetail(const Camera& camera);

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(DlodNode);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DlodNode);
}

#endif  // RENDERING_DETAIL_DLOD_NODE_H
