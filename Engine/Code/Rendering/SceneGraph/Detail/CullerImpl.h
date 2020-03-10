// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:16)

#ifndef RENDERING_SCENE_GRAPH_CULLER_IMPL_H
#define RENDERING_SCENE_GRAPH_CULLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CameraFrustum.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/SceneGraph/VisibleSet.h"
#include "Mathematics/Algebra/Plane.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CullerImpl: private boost::noncopyable
    {
    public:
        using ClassType = CullerImpl;
        using Plane = Mathematics::Plane<float>;
        using APoint = Mathematics::APoint<float>;
        using Math = Mathematics::Math<float>;
		using AVector = Mathematics::AVector<float>;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        
    public:
        // �ü���Ҫ���ģ�͡������Ҫ�޸������
        // ��Ӧ����ʹ��ComputeVisibleSet֮ǰ������SetCamera��
		explicit CullerImpl(const ConstCameraSmartPointer& camera);
        ~CullerImpl ();

		CLASS_INVARIANT_DECLARE;

        // ������������Ƶ�ƽ��ͷ���Ǳ�ڿɼ�����
		void SetCamera(const ConstCameraSmartPointer& camera);
		ConstCameraSmartPointer GetCamera() const;
        void SetFrustum (const float* frustum);
        const float* GetFrustum () const;

        // �������Ϊ�ǿɼ��Ķ��󸽼ӵ��ɼ���(�洢Ϊһ������)��
		void Insert(const ConstSpatialSmartPointer& visible);

        int GetNumVisible () const;
		const ConstSpatialSmartPointer& GetVisible(int index) const;
        
        int GetPlaneQuantity () const;
        const Plane* GetPlanes () const;
        void SetPlaneState (unsigned int planeState);
        unsigned int GetPlaneState () const;
        void PushPlane (const Plane& plane);
        void PopPlane ();

        // �Ƚ϶��������߽�����Ĳü�ƽ�档ֻ��Spatial�������������
        bool IsVisible (const Bound& bound);

        // ֧���� Portal::GetVisibleSet.
        bool IsVisible (int numVertices, const APoint* vertices,bool ignoreNearPlane) const;

        // ֧���� BspNode::GetVisibleSet.
        // ȷ����ͼƽ��ͷ���Ƿ���ȫ��ƽ���һ�ࡣ
        // ƽ��ġ����桱�ڰ�ռ䵽ƽ�淨�ߵĵ㡣�����桱������һ��ռ䡣
        // ��������+1�����ͼƽ��ͷ����ȫ��ƽ���������,
        // ��������-1�����ͼƽ��ͷ����ȫ��ƽ��ĸ����ϣ�
        // ����0�������ͼƽ��ͷ��λ��ƽ�档
        // ����ƽ������������ϵ�������������ϵ���ڲ��ԡ�
        NumericalValueSymbol WhichSide (const Plane& plane) const;

        // ������Ӧ��ʹ�õ���Ҫ������ʹ�õ��ڳ���ͼ�ü���
        // ��������ͼ,����Ǳ�ڿɼ������������ƽ�档
        void Clear ();

    private:
        // ���������Ϣ,������Ҫ�ü�������
		ConstCameraSmartPointer m_Camera;

        // ������ͼƽ��ͷ�����������������������ϵͳ�ı��ڲü���ƽ��ͷ�����(����,�Ż�ϵͳ)����Ӱ�����,
        // ��Ⱦ���ĳ�ʼ״̬�Ǳ�Ҫ�ġ�
        CameraFrustum m_Frustum;

        // ����ü�ƽ���Ӧ��ͼƽ��ͷ����κζ�����û�����Ĳü�ƽ�档
        // ��Աm_PlaneState����λ��־�ڲü�ϵͳ�洢ƽ���Ƿ��Ծ��
        // 1��ζ��ƽ���ǻ�Ծ��,����ƽ���ǲ���Ծ�ġ�
        // һ����Ծ��ƽ�����,����߽��,������һ�������ƽ�档��֧����һ����Ч�Ĳü��Ĳ�νṹ��
        // ����,���һ���ڵ�ı߽�����ڵ���ƽ����ͼƽ��ͷ��,
        // ��������ƽ��ڵ�Ĳ���Ծ��,��Ϊ�ӽڵ㶼�Զ����뿪ƽ�档
        int m_PlaneQuantity;
        Plane m_Plane[MaxPlaneQuantity];
        unsigned int m_PlaneState;
 
        // ���ܿɼ����õ���GetVisibleSet��
        VisibleSet m_VisibleSet;
    };
}

#endif // RENDERING_SCENE_GRAPH_CULLER_IMPL_H
