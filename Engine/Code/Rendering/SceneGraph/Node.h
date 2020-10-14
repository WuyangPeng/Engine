// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 11:24)

#ifndef RENDERING_SCENE_GRAPH_NODE_H
#define RENDERING_SCENE_GRAPH_NODE_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"
#include "Culler.h"

RENDERING_EXPORT_SHARED_PTR(NodeImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Node : public Spatial
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(Node, DESTRUCTOR_STATEMENT);
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
		IMPL_TYPE_DECLARE(Node);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(Node);
#include STSTEM_WARNING_POP

	CORE_TOOLS_SHARED_PTR_DECLARE( Node); 
}
#include STSTEM_WARNING_POP

#endif // RENDERING_SCENE_GRAPH_NODE_H
