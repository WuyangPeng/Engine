// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:24)

#ifndef RENDERING_SCENE_GRAPH_NODE_H
#define RENDERING_SCENE_GRAPH_NODE_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"
#include "Culler.h"
EXPORT_SHARED_PTR(Rendering, NodeImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Node : public Spatial
    {
    public:
        void Swap(Node& rhs) noexcept;
        
            public:
                TYPE_DECLARE(Node);
                using ClassShareType = CoreTools::CopyUnsharedClasses;
                ~Node() noexcept;
                Node(const Node& rhs);
                Node& operator=(const Node& rhs);
                Node(Node&& rhs) noexcept;
                Node& operator=(Node&& rhs) noexcept;
        using ParentType = Spatial;
        
    public:
        Node (); 
        
		CLASS_INVARIANT_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Node);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
        
        int GetNumChildren () const;
        
		int AttachChild(SpatialSharedPtr  child);
        int DetachChild(SpatialSharedPtr child) noexcept;
		SpatialSharedPtr DetachChildAt(int index);
		SpatialSharedPtr GetChild(int index);
		ConstSpatialSharedPtr GetConstChild(int index) const;
        
          void GetVisibleSet(Culler& culler, bool noCull) override;
        
          ControllerInterfaceSharedPtr Clone() const override;

		  const PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const override;
          ObjectInterfaceSharedPtr CloneObject() const override;
    protected:
		  bool UpdateWorldData(double applicationTime) override;

		bool UpdateImplWorldData(double applicationTime);
        
    private:
                void UpdateWorldBound() override;

    private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(Node);
#include STSTEM_WARNING_POP

	CORE_TOOLS_SHARED_PTR_DECLARE( Node); 
}
#include STSTEM_WARNING_POP

#endif // RENDERING_SCENE_GRAPH_NODE_H
