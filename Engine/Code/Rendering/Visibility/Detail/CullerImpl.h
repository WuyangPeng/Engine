/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 15:40)

#ifndef RENDERING_VISIBILITY_CULLER_IMPL_H
#define RENDERING_VISIBILITY_CULLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Detail/CameraFrustum.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/Visibility/VisibleSet.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CullerImpl
    {
    public:
        using ClassType = CullerImpl;

        using Plane = Mathematics::PlaneF;
        using APoint = Mathematics::APointF;
        using Math = Mathematics::MathF;
        using AVector = Mathematics::AVectorF;
        using BoundingSphere = Mathematics::BoundingSphereF;

        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

        static constexpr auto quantity = System::EnumCastUnderlying(ViewFrustum::Quantity);

        using Container = std::array<float, quantity>;

    public:
        // �ü���Ҫ���ģ�͡������Ҫ�޸������
        // ��Ӧ����ʹ��ComputeVisibleSet֮ǰ������SetCamera��
        explicit CullerImpl(ConstCameraSharedPtr camera);
        ~CullerImpl() noexcept = default;
        CullerImpl(const CullerImpl& rhs);
        CullerImpl& operator=(const CullerImpl& rhs);
        CullerImpl(CullerImpl&& rhs) noexcept;
        CullerImpl& operator=(CullerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ������������Ƶ�ƽ��ͷ���Ǳ�ڿɼ�����
        void SetCamera(const ConstCameraSharedPtr& aCamera) noexcept;
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        void SetFrustum(const Container& aFrustum);
        NODISCARD Container GetFrustum() const noexcept;

        // �������Ϊ�ǿɼ��Ķ��󸽼ӵ��ɼ���(�洢Ϊһ������)��
        void Insert(const VisualSharedPtr& visible);

        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        NODISCARD int GetPlaneQuantity() const noexcept;
        NODISCARD Plane GetPlane(int index) const;
        void SetPlaneState(uint32_t aPlaneState) noexcept;
        NODISCARD uint32_t GetPlaneState() const noexcept;
        void PushPlane(const Plane& aPlane) noexcept;
        void PopPlane() noexcept;

        // �Ƚ϶��������߽�����Ĳü�ƽ�档ֻ��Spatial�������������
        NODISCARD bool IsVisible(const BoundingSphere& bound) noexcept;

        /// ֧���� BspNode::GetVisibleSet.
        /// ȷ����ͼƽ��ͷ���Ƿ���ȫ��ƽ���һ�ࡣ
        /// ƽ��ġ����桱�ڰ�ռ䵽ƽ�淨�ߵĵ㡣�����桱������һ��ռ䡣
        /// ��������+1�����ͼƽ��ͷ����ȫ��ƽ���������,
        /// ��������-1�����ͼƽ��ͷ����ȫ��ƽ��ĸ����ϣ�
        /// ����0�������ͼƽ��ͷ��λ��ƽ�档
        /// ����ƽ������������ϵ�������������ϵ���ڲ��ԡ�
        NODISCARD NumericalValueSymbol WhichSide(const Plane& aPlane) const;

        // ������Ӧ��ʹ�õ���Ҫ������ʹ�õ��ڳ���ͼ�ü���
        // ��������ͼ,����Ǳ�ڿɼ������������ƽ�档
        void Clear();

        NODISCARD VisualContainerIter begin();
        NODISCARD VisualContainerIter end();

        void PushViewFrustumPlanes(const Camera& aCamera);

    private:
        using PlaneContainer = std::array<Plane, quantity>;

    private:
        // ���������Ϣ,������Ҫ�ü�������
        ConstCameraSharedPtr camera;

        // ������ͼƽ��ͷ�����������������������ϵͳ�ı��ڲü���ƽ��ͷ�����(����,�Ż�ϵͳ)����Ӱ�����,
        // ��Ⱦ���ĳ�ʼ״̬�Ǳ�Ҫ�ġ�
        CameraFrustum frustum;

        // ����ü�ƽ���Ӧ��ͼƽ��ͷ����κζ�����û�����Ĳü�ƽ�档
        // ��Աm_PlaneState����λ��־�ڲü�ϵͳ�洢ƽ���Ƿ��Ծ��
        // 1��ζ��ƽ���ǻ�Ծ��,����ƽ���ǲ���Ծ�ġ�
        // һ����Ծ��ƽ�����,����߽��,������һ�������ƽ�档��֧����һ����Ч�Ĳü��Ĳ�νṹ��
        // ����,���һ���ڵ�ı߽�����ڵ���ƽ����ͼƽ��ͷ��,
        // ��������ƽ��ڵ�Ĳ���Ծ��,��Ϊ�ӽڵ㶼�Զ����뿪ƽ�档
        int planeQuantity;
        PlaneContainer plane;
        uint32_t planeState;

        // ���ܿɼ����õ���GetVisibleSet��
        VisibleSet visibleSet;
    };
}

#endif  // RENDERING_VISIBILITY_CULLER_IMPL_H
