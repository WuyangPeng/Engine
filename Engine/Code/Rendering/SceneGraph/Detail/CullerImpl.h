///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:06)

#ifndef RENDERING_SCENE_GRAPH_CULLER_IMPL_H
#define RENDERING_SCENE_GRAPH_CULLER_IMPL_H

#include "CameraFrustum.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/VisibleSet.h"
#include "Rendering/SceneGraph/Visual.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CullerImpl : private boost::noncopyable
    {
    public:
        using ClassType = CullerImpl;
        using Plane = Mathematics::Plane<float>;
        using APoint = Mathematics::APoint<float>;
        using Math = Mathematics::Math<float>;
        using AVector = Mathematics::AVector<float>;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

    public:
        // �ü���Ҫ���ģ�͡������Ҫ�޸������
        // ��Ӧ����ʹ��ComputeVisibleSet֮ǰ������SetCamera��
        explicit CullerImpl(const ConstCameraSharedPtr& camera);

        CLASS_INVARIANT_DECLARE;

        // ������������Ƶ�ƽ��ͷ���Ǳ�ڿɼ�����
        void SetCamera(const ConstCameraSharedPtr& aCamera) noexcept;
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        void SetFrustum(const float* aFrustum);
        NODISCARD const float* GetFrustum() const noexcept;

        // �������Ϊ�ǿɼ��Ķ��󸽼ӵ��ɼ���(�洢Ϊһ������)��
        void Insert(const VisualSharedPtr& visible);

        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        NODISCARD int GetPlaneQuantity() const noexcept;
        NODISCARD const Plane* GetPlanes() const noexcept;
        void SetPlaneState(int aPlaneState) noexcept;
        NODISCARD int GetPlaneState() const noexcept;
        void PushPlane(const Plane& aPlane) noexcept;
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
        NODISCARD NumericalValueSymbol WhichSide(const Plane& aPlane) const noexcept;

        // ������Ӧ��ʹ�õ���Ҫ������ʹ�õ��ڳ���ͼ�ü���
        // ��������ͼ,����Ǳ�ڿɼ������������ƽ�档
        void Clear() noexcept;

        NODISCARD VisualContainerIter begin() noexcept;
        NODISCARD VisualContainerIter end() noexcept;

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
        std::array<Plane, MaxPlaneQuantity> plane;
        int planeState;

        // ���ܿɼ����õ���GetVisibleSet��
        VisibleSet visibleSet;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CULLER_IMPL_H
