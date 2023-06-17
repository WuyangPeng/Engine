///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:09)

#ifndef RENDERING_SCENE_GRAPH_CULLER_H
#define RENDERING_SCENE_GRAPH_CULLER_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "Spatial.h"
#include "VisibleSet.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Plane.h"

RENDERING_NON_COPY_EXPORT_IMPL(CullerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Culler
    {
    public:
        NON_COPY_TYPE_DECLARE(Culler);
        using Plane = Mathematics::Plane<float>;
        using APoint = Mathematics::APoint<float>;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

    public:
        // �ü���Ҫ���ģ�͡������Ҫ�޸������
        // ��Ӧ����ʹ��ComputeVisibleSet֮ǰ������SetCamera��
        explicit Culler(const ConstCameraSharedPtr& camera);
        virtual ~Culler() noexcept = default;
        Culler(const Culler& rhs) = default;
        Culler& operator=(const Culler& rhs) = default;
        Culler(Culler&& rhs) noexcept = default;
        Culler& operator=(Culler&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ������������Ƶ�ƽ��ͷ���Ǳ�ڿɼ�����
        void SetCamera(const ConstCameraSharedPtr& camera) noexcept;
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        void SetFrustum(const float* frustum);
        NODISCARD const float* GetFrustum() const noexcept;

        // �������Ϊ�ǿɼ��Ķ��󸽼ӵ��ɼ���(�洢Ϊһ������)��
        // ��������ܻḲ�Ǵ���Ϊ��
        // ����,��������������ܱ�����С����Ⱦ״̬�ı����
        // Ҳ������/ά����Ϊһ�����ص��Ż�ϵͳ�Ķ����б�
        virtual void Insert(const VisualSharedPtr& visible);

        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        NODISCARD int GetPlaneQuantity() const noexcept;
        NODISCARD const Plane* GetPlanes() const noexcept;
        void SetPlaneState(unsigned int planeState) noexcept;
        NODISCARD int GetPlaneState() const noexcept;
        void PushPlane(const Plane& plane) noexcept;
        void PopPlane() noexcept;

        // �Ƚ϶��������߽�����Ĳü�ƽ�档ֻ��Spatial�������������
        NODISCARD bool IsVisible(const BoundF& bound) noexcept;

        // ֧���� Portal::GetVisibleSet.
        NODISCARD bool IsVisible(int numVertices, const APoint* vertices, bool ignoreNearPlane) const noexcept;

        // ֧���� BspNode::GetVisibleSet.
        // ȷ����ͼƽ��ͷ���Ƿ���ȫ��ƽ���һ�ࡣ
        // ƽ��ġ����桱�ڰ�ռ䵽ƽ�淨�ߵĵ㡣�����桱������һ��ռ䡣
        // ��������+1�����ͼƽ��ͷ����ȫ��ƽ���������,
        // ��������-1�����ͼƽ��ͷ����ȫ��ƽ��ĸ����ϣ�
        // ����0�������ͼƽ��ͷ��λ��ƽ�档
        // ����ƽ������������ϵ�������������ϵ���ڲ��ԡ�
        NODISCARD NumericalValueSymbol WhichSide(const Plane& plane) const noexcept;

        // ������Ӧ��ʹ�õ���Ҫ������ʹ�õ��ڳ���ͼ�ü���
        // ��������ͼ,����Ǳ�ڿɼ������������ƽ�档
        void ComputeVisibleSet(SpatialSharedPtr scene);

        NODISCARD VisualContainerIter begin() noexcept;
        NODISCARD VisualContainerIter end() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CULLER_H
