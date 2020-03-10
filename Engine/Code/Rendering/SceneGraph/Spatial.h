// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:45)

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
        
        // 更新几何状态和控制器。
        // 函数计算世界转换在遍历向下传递场景图和遍历向上传递世界边界。
		virtual bool Update(double applicationTime = -Mathematics::Mathd::sm_MaxReal) override;
        
        // 访问父对象。节点中调用attach/detach在子对象。
		virtual void SetParent(Spatial* parent);
        
        bool Update (double applicationTime,bool initiator);
        
        // 访问父对象。
        Spatial* GetParent ();	
		const Spatial* GetParent () const;	
 
        // 支持分级裁剪。
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
        
        // 对几何更新的支持。
        virtual bool UpdateWorldData (double applicationTime);

        bool GetWorldBoundIsCurrent() const;
		void SetWorldTransformOnUpdate(const Transform& transform);
        
    private:
        using SpatialDataPtr = std::shared_ptr<SpatialData>;
        
    private:
        // 对几何更新的支持。
        virtual void UpdateWorldBound () = 0;
        void PropagateBoundToRoot ();

    private:
        // 支持层次场景图。Spatial提供父指针。Node提供了子指针。
        Spatial* m_Parent;
        
        SpatialDataPtr m_SpatialDataPtr;
    };
    
    CORE_TOOLS_STREAM_REGISTER(Spatial);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, Spatial); 
}

#endif // RENDERING_SCENE_GRAPH_SPATIAL_H
