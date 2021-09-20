// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/22 11:20)

#ifndef RENDERING_SCENE_GRAPH_CULLER_H
#define RENDERING_SCENE_GRAPH_CULLER_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "Spatial.h"
#include "VisibleSet.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Plane.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

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
        virtual ~Culler() = default;
        Culler(const Culler&) = delete;
        Culler& operator=(const Culler&) = delete;
        Culler( Culler&&) = delete;
        Culler& operator=( Culler&&) = delete;

        CLASS_INVARIANT_DECLARE;

        // ������������Ƶ�ƽ��ͷ���Ǳ�ڿɼ�����
        void SetCamera(const ConstCameraSharedPtr& camera);
        ConstCameraSharedPtr GetCamera() const;
        void SetFrustum(const float* frustum);
        const float* GetFrustum() const;

        // �������Ϊ�ǿɼ��Ķ��󸽼ӵ��ɼ���(�洢Ϊһ������)��
        // ��������ܻḲ�Ǵ���Ϊ��
        // ����,��������������ܱ�����С����Ⱦ״̬�ı����
        // Ҳ������/ά����Ϊһ�����ص��Ż�ϵͳ�Ķ����б�
        virtual void Insert(const VisualSharedPtr& visible);

        int GetNumVisible() const;
        const ConstVisualSharedPtr GetVisible(int index) const;

        int GetPlaneQuantity() const;
        const Plane* GetPlanes() const;
        void SetPlaneState(unsigned int planeState);
        unsigned int GetPlaneState() const;
        void PushPlane(const Plane& plane);
        void PopPlane();

        // �Ƚ϶��������߽�����Ĳü�ƽ�档ֻ��Spatial�������������
        bool IsVisible(const FloatBound& bound);

        // ֧���� Portal::GetVisibleSet.
        bool IsVisible(int numVertices, const APoint* vertices, bool ignoreNearPlane) const;

        // ֧���� BspNode::GetVisibleSet.
        // ȷ����ͼƽ��ͷ���Ƿ���ȫ��ƽ���һ�ࡣ
        // ƽ��ġ����桱�ڰ�ռ䵽ƽ�淨�ߵĵ㡣�����桱������һ��ռ䡣
        // ��������+1�����ͼƽ��ͷ����ȫ��ƽ���������,
        // ��������-1�����ͼƽ��ͷ����ȫ��ƽ��ĸ����ϣ�
        // ����0�������ͼƽ��ͷ��λ��ƽ�档
        // ����ƽ������������ϵ�������������ϵ���ڲ��ԡ�
        NumericalValueSymbol WhichSide(const Plane& plane) const;

        // ������Ӧ��ʹ�õ���Ҫ������ʹ�õ��ڳ���ͼ�ü���
        // ��������ͼ,����Ǳ�ڿɼ������������ƽ�档
        void ComputeVisibleSet(SpatialSharedPtr scene);

        VisualContainerIter begin();
        VisualContainerIter end();

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CULLER_H
