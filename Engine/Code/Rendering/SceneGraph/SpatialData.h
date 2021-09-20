// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 14:05)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_DATA_H
#define RENDERING_SCENE_GRAPH_SPATIAL_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/CullingModeFlags.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/DataTypes/Transform.h"
#include "Mathematics/Algebra/APoint.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
	class   SpatialData
    {
    public:
        using ClassType = SpatialData;
        using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APoint<float>;
		using Matrix = Mathematics::Matrix<float>;
        using Bound =  Bound<float>;
        
    public:
        SpatialData ();
        
        CLASS_INVARIANT_DECLARE;
        
        void DirectSetWorldTransform(const FloatTransform& transform);
        void DirectSetWorldBound(const Bound& bound);
        
        void SetLocalTransform(const FloatTransform& transform);
        void SetCullingMode(CullingMode culling);

		void SetLocalTransformTranslate(const APoint& translate);
		void SetLocalTransformRotate(const Matrix& rotate);
        
        void SetLocalTransformToWorldTransform(const FloatTransform& worldTransform);
        void SetLocalTransformToWorldTransform();
        
        void InitWorldBound();
        void SetWorldBound(const Bound& worldBound);
        
        bool GetWorldTransformIsCurrent() const;
        bool GetWorldBoundIsCurrent() const;
        
        const FloatTransform GetLocalTransform() const;
        const FloatTransform GetWorldTransform() const;
        const Bound GetWorldBound() const;
        CullingMode GetCullingMode() const;
        
        void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;

		void SetWorldTransformOnUpdate(const FloatTransform& transform);

    private:
        // �ֲ�������任����ĳЩ�����,��������Ҫֱ����������任�ƹ�Spatial::Update()���ơ�
        // ���ֱ������m_WorldTransform,m_WorldTransformIsCurrentӦ������Ϊ��true����
        FloatTransform m_LocalTransform;
        FloatTransform m_WorldTransform;
        bool m_WorldTransformIsCurrent;

        // ����󶨷��ʡ���ĳЩ�����,��������Ҫֱ�����������,�ƹ�Spatial::Update()���ơ�
        // ���ֱ������m_WorldBound,m_WorldBoundIsCurrentӦ������Ϊ��true����
        Bound m_WorldBound;
        bool m_WorldBoundIsCurrent;
        
        CullingMode m_Culling;
    };
}

#endif // RENDERING_SCENE_GRAPH_SPATIAL_DATA_H
