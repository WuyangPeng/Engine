// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:11)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
#define RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H

#include "Rendering/RenderingDll.h"

#include "System/EnumOperator/EnumCastDetail.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraFrustum
    {
    public:
		using ClassType = CameraFrustum;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
        
    public:
        explicit CameraFrustum (bool isPerspective);
        
		CLASS_INVARIANT_DECLARE;
  
        // Ĭ����ͼƽ��ͷ����һ��90�ȵ���Ұ,
        // ��߱�Ϊ1����ֵΪ1��ԶֵΪ10000��
        bool IsPerspective () const;
 
        // ������ͼƽ��ͷ�塣����[rmin,rmax] �������ҷ���R��
        // ��Щ������ƽ��ͷ��ġ�left���͡�right��ֵ��
        // ����[umin,umax] �������Ϸ���U��
        // ��Щ�ǡ�bottom���͡�top��ֵ��
        // ����[dmin,dmax] ������ͼ����D��
        // ��Щ�ǡ�near���͡�far��ֵ��
        void SetFrustum (float directionMin, float directionMax,float upMin, float upMax,float rightMin, float rightMax);

        // ͬʱ������ͼƽ��ͷ�����е�ֵ��
        // ����������밴dmin, dmax, umin, umax, rmin, rmax��˳��
        void SetFrustum (const float* frustum);
 
        // ����һ���ԳƵ���ͼƽ��ͷ��(umin = -umax, rmin = -rmax)
        // ʹ��һ����ͼ�ֶ���up�����һ����߱ȡ�
        // ��������൱��OpenGL��gluPerspective��
        // ��ˣ������������ָ����ͼ�Ķ�����������(0,180)
        void SetFrustum (float upFieldOfViewDegrees, float aspectRatio,float directionMin,float directionMax);

        // ͬʱ���������ͼƽ��ͷ���ֵ��
        const float* GetFrustum () const;
 
        // �õ�һ���Գ���ͼƽ��ͷ��Ĳ�����
        // ����ֵ��true���ҽ���ƽ��ͷ���ǶԳƵģ�
        // ֻ������������£��������������Ч�ġ�
        const CameraFrustumData GetFrustumData () const;
 
        // ��õ�һ��ͼƽ��ͷ���ֵ��
        float GetDirectionMin () const;
        float GetDirectionMax () const;
        float GetUpMin () const;
        float GetUpMax () const;
        float GetRightMin () const;
        float GetRightMax () const;
        
        void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
        
    private:
        // ��ͼƽ��ͷ��,�洢��˳��Ϊmin (near), dmax (far),
        // umin (bottom), umax (top), rmin (left), �� rmax (right).
        float m_Frustum[System::EnumCastUnderlying(ViewFrustum::Quantity)];
 
        // �����Ա�ǡ�true������͸��������ǡ�false���������������
        bool m_IsPerspective;
    };
}

#endif // RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
