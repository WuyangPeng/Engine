// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:27)

#ifndef RENDERING_GLOBAL_EFFECTS_GLOBAL_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_GLOBAL_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
 

namespace Rendering
{
	class VisibleSet;
	class Renderer;
	
	class RENDERING_DEFAULT_DECLARE GlobalEffect : public CoreTools::Object		
	{
	public:
		using ClassType = GlobalEffect;
		using ParentType = Object;

	private:		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(GlobalEffect);		
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 
		
	protected:
		// Abstract base class.  Construction and destruction.
		GlobalEffect ();
	public:
 
		
		// This function is called in Renderer::Draw(visibleSet,globalEffect)
		// when the globalEffect is nonnull.
		virtual void Draw (std::shared_ptr<Renderer> renderer, VisibleSet& visibleSet) = 0;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(GlobalEffect);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( GlobalEffect);
}

#endif // RENDERING_GLOBAL_EFFECTS_GLOBAL_EFFECT_H
