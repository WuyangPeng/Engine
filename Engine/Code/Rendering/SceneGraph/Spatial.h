///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.6 (2022/04/03 15:20)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_H
#define RENDERING_SCENE_GRAPH_SPATIAL_H

#include "Rendering/RenderingDll.h"

#include "PickRecordContainer.h"
#include "Flags/CullingModeFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Controllers/ControlledObject.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/DataTypes/TransformDetail.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Spatial, SpatialData);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Spatial : public ControlledObject
    {
    public:
        using SpatialImpl = SpatialData;
        COPY_UNSHARED_TYPE_DECLARE(Spatial);
        using ParentType = ControlledObject;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using Math = Mathematics::Math<float>;
        using AVector = Mathematics::AVector<float>;
        using APoint = Mathematics::APoint<float>;
        using Matrix = Mathematics::Matrix<float>;

    public:
        explicit Spatial(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Spatial);

        // ���¼���״̬�Ϳ�������
        // ������������ת���ڱ������´��ݳ���ͼ�ͱ������ϴ�������߽硣
        bool Update(double applicationTime = -Mathematics::MathD::maxReal) override;

        // ���ʸ����󡣽ڵ��е���attach/detach���Ӷ���
        virtual void SetParent(Spatial* aParent) noexcept;

        NODISCARD bool Update(double applicationTime, bool initiator);

        // ���ʸ�����
        NODISCARD Spatial* GetParent() noexcept;
        NODISCARD const Spatial* GetParent() const noexcept;

        // ֧�ַּ��ü���
        void OnGetVisibleSet(Culler& culler, bool noCull);
        virtual void GetVisibleSet(Culler& culler, bool noCull) = 0;

        void SetLocalTransform(const TransformF& transform) noexcept;
        void SetWorldTransform(const TransformF& transform) noexcept;
        void SetWorldBound(const BoundF& bound) noexcept;
        void SetCullingMode(CullingMode culling) noexcept;

        NODISCARD TransformF GetLocalTransform() const noexcept;
        NODISCARD TransformF GetWorldTransform() const noexcept;
        NODISCARD BoundF GetWorldBound() const noexcept;
        NODISCARD CullingMode GetCullingMode() const noexcept;

        void SetLocalTransformTranslate(const APoint& translate) noexcept;
        void SetLocalTransformRotate(const Matrix& rotate) noexcept;

        NODISCARD virtual PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const;

        virtual ControllerInterfaceSharedPtr Clone() const = 0;

    protected:
        void InitWorldBound();
        void BoundGrowToContain(const BoundF& worldBound);

        // �Լ��θ��µ�֧�֡�
        virtual bool UpdateWorldData(double applicationTime);

        NODISCARD bool GetWorldBoundIsCurrent() const noexcept;
        void SetWorldTransformOnUpdate(const TransformF& transform) noexcept;

    private:
        // �Լ��θ��µ�֧�֡�
        virtual void UpdateWorldBound() = 0;
        void PropagateBoundToRoot();

    private:
        // ֧�ֲ�γ���ͼ��Spatial�ṩ��ָ�롣Node�ṩ����ָ�롣
        Spatial* parent;

        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Spatial);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Spatial);
}

#endif  // RENDERING_SCENE_GRAPH_SPATIAL_H
