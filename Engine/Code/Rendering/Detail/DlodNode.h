///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:51)

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

        // ��������(LOD)ϸ�ڵȼ���
        NODISCARD APoint GetModelCenter() const noexcept;
        NODISCARD APoint GetWorldCenter() const noexcept;

        void SetModelCenter(const APoint& modelCenter) noexcept;

        // ����ӽڵ�ľ�������
        NODISCARD int GetNumLevelsOfDetail() const noexcept;
        NODISCARD float GetModelMinDistance(int index) const;
        NODISCARD float GetModelMaxDistance(int index) const;
        NODISCARD float GetWorldMinDistance(int index) const;
        NODISCARD float GetWorldMaxDistance(int index) const;
        void SetModelDistance(int index, float minDistance, float maxDistance);

    protected:
        // ֧�ַּ��ü���
        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) override;

    private:
        // ���ػ�����������LOD���ģ�������ͷ����ѡ���ӽڵ㡣
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
