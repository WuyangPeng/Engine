// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 17:00)

#include "Rendering/RenderingExport.h"

#include "VisibleSetImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointerDetail.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointerDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::vector;

Rendering::VisibleSetImpl ::VisibleSetImpl() noexcept
    : m_Visible{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}
 

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::VisibleSetImpl
    ::IsValid() const noexcept
{	
	return true; 
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::VisibleSetImpl
    ::GetNumVisible () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return boost::numeric_cast<int>(m_Visible.size());
}

void Rendering::VisibleSetImpl
	::Insert(const VisualSmartPointer& visible)
{
    RENDERING_CLASS_IS_VALID_9;
    
	m_Visible.push_back(visible);
}

const Rendering::ConstVisualSmartPointer Rendering::VisibleSetImpl
    ::GetVisible (int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumVisible(),"索引无效在GetVisible\n");
    
    return m_Visible.at(index);
}

void Rendering::VisibleSetImpl
    ::Clear () noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
	m_Visible.clear();
}

Rendering::VisibleSetImpl::VisualContainerIter Rendering::VisibleSetImpl ::begin() noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Visible.begin();
}

Rendering::VisibleSetImpl::VisualContainerIter Rendering::VisibleSetImpl ::end() noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Visible.end();
}
