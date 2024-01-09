/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 16:09)

#ifndef RENDERING_VISIBILITY_CULLER_H
#define RENDERING_VISIBILITY_CULLER_H

#include "Rendering/RenderingDll.h"

#include "VisibleSet.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"
#include "Rendering/SceneGraph/Visual.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(Culler, CullerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Culler
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(Culler);

        using Plane = Mathematics::PlaneF;
        using APoint = Mathematics::APointF;
        using BoundingSphere = Mathematics::BoundingSphereF;

        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

        static constexpr auto quantity = System::EnumCastUnderlying(ViewFrustum::Quantity);

        using Container = std::array<float, quantity>;

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
        void SetCamera(const ConstCameraSharedPtr& camera);
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        void SetFrustum(const Container& frustum);
        NODISCARD Container GetFrustum() const noexcept;

        // �������Ϊ�ǿɼ��Ķ��󸽼ӵ��ɼ���(�洢Ϊһ������)��
        // ��������ܻḲ�Ǵ���Ϊ��
        // ����,��������������ܱ�����С����Ⱦ״̬�ı����
        // Ҳ������/ά����Ϊһ�����ص��Ż�ϵͳ�Ķ����б�
        virtual void Insert(const VisualSharedPtr& visible);

        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        NODISCARD int GetPlaneQuantity() const noexcept;
        NODISCARD Plane GetPlane(int index) const;
        void SetPlaneState(uint32_t planeState);
        NODISCARD uint32_t GetPlaneState() const noexcept;
        void PushPlane(const Plane& plane);
        void PopPlane();

        // �Ƚ϶��������߽�����Ĳü�ƽ�档ֻ��Spatial�������������
        NODISCARD bool IsVisible(const BoundingSphere& bound);

        /// ֧���� BspNode::GetVisibleSet.
        /// ȷ����ͼƽ��ͷ���Ƿ���ȫ��ƽ���һ�ࡣ
        /// ƽ��ġ����桱�ڰ�ռ䵽ƽ�淨�ߵĵ㡣�����桱������һ��ռ䡣
        /// ��������+1�����ͼƽ��ͷ����ȫ��ƽ���������,
        /// ��������-1�����ͼƽ��ͷ����ȫ��ƽ��ĸ����ϣ�
        /// ����0�������ͼƽ��ͷ��λ��ƽ�档
        /// ����ƽ������������ϵ�������������ϵ���ڲ��ԡ�
        NODISCARD NumericalValueSymbol WhichSide(const Plane& plane) const;

        /// ������Ӧ��ʹ�õ���Ҫ������ʹ�õ��ڳ���ͼ�ü���
        /// ��������ͼ,����Ǳ�ڿɼ������������ƽ�档
        void ComputeVisibleSet(const CameraSharedPtr& camera, const SpatialSharedPtr& scene);

        NODISCARD VisualContainerIter begin();
        NODISCARD VisualContainerIter end();

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_VISIBILITY_CULLER_H
