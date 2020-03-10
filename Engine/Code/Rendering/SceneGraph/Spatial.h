// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:45)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_H
#define RENDERING_SCENE_GRAPH_SPATIAL_H

#include "Rendering/RenderingDll.h"

#include "SpatialData.h"
#include "PickRecordContainer.h"
#include "Flags/CullingModeFlags.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/Controllers/ControlledObject.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointer.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointer.h"

RENDERING_EXPORT_SHARED_PTR(SpatialData);

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
	class Culler;  

    class RENDERING_DEFAULT_DECLARE Spatial : public ControlledObject
    {
    public:
        using ClassType = Spatial;
        using ParentType = ControlledObject;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using Math = Mathematics::Math<float>;
		using AVector = Mathematics::AVector<float>;
		using APoint = Mathematics::APoint<float>;
		using Matrix = Mathematics::Matrix<float>;
        
    public:
        Spatial();
        virtual ~Spatial();
        
        Spatial(const Spatial& rhs);
        Spatial& operator= (const Spatial& rhs);
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Spatial);
        
        // ���¼���״̬�Ϳ�������
        // ������������ת���ڱ������´��ݳ���ͼ�ͱ������ϴ�������߽硣
		virtual bool Update(double applicationTime = -Mathematics::Mathd::sm_MaxReal) override;
        
        // ���ʸ����󡣽ڵ��е���attach/detach���Ӷ���
		virtual void SetParent(Spatial* parent);
        
        bool Update (double applicationTime,bool initiator);
        
        // ���ʸ�����
        Spatial* GetParent ();	
		const Spatial* GetParent () const;	
 
        // ֧�ַּ��ü���
        void OnGetVisibleSet (Culler& culler, bool noCull);
        virtual void GetVisibleSet (Culler& culler, bool noCull) = 0;
	    
        void SetLocalTransform(const Transform& transform);
        void SetWorldTransform(const Transform& transform);
        void SetWorldBound(const Bound& bound);
        void SetCullingMode(CullingMode culling);
        
        const Transform GetLocalTransform() const;
        const Transform GetWorldTransform() const;
        const Bound GetWorldBound() const;
        CullingMode GetCullingMode() const; 

		void SetLocalTransformTranslate(const APoint& translate);
		void SetLocalTransformRotate(const Matrix& rotate);

		virtual const PickRecordContainer ExecuteRecursive(const APoint& origin,const AVector& direction,float tMin, float tMax) const;
        
     protected:
        void InitWorldBound();
        void BoundGrowToContain(const Bound& worldBound);
        
        // �Լ��θ��µ�֧�֡�
        virtual bool UpdateWorldData (double applicationTime);

        bool GetWorldBoundIsCurrent() const;
		void SetWorldTransformOnUpdate(const Transform& transform);
        
    private:
        using SpatialDataPtr = std::shared_ptr<SpatialData>;
        
    private:
        // �Լ��θ��µ�֧�֡�
        virtual void UpdateWorldBound () = 0;
        void PropagateBoundToRoot ();

    private:
        // ֧�ֲ�γ���ͼ��Spatial�ṩ��ָ�롣Node�ṩ����ָ�롣
        Spatial* m_Parent;
        
        SpatialDataPtr m_SpatialDataPtr;
    };
    
    CORE_TOOLS_STREAM_REGISTER(Spatial);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, Spatial); 
}

#endif // RENDERING_SCENE_GRAPH_SPATIAL_H
