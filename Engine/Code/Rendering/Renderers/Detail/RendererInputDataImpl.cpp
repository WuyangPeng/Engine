// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:02)

#include "Rendering/RenderingExport.h"

#include "RendererInputDataImpl.h"
#include "Rendering/Renderers/RendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::RendererInputDataImpl ::RendererInputDataImpl(MAYBE_UNUSED int count)
    : m_RendererInput{ make_shared<RendererInput>(Rendering::RendererTypes::Default) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RendererInputDataImpl
	::IsValid() const noexcept
{
    if(m_RendererInput != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::RendererInputDataImpl
    ::Rebuild(RendererTypes type)
{
	RENDERING_CLASS_IS_VALID_1;

	m_RendererInput = make_shared<RendererInput>(type);
}

#include STSTEM_WARNING_POP