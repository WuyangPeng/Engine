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

#include <boost/numeric/conversion/cast.hpp>

using std::vector;

Rendering::VisibleSetImpl
    ::VisibleSetImpl ()
	: m_NumVisible{ 0 }, m_Visible{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisibleSetImpl
     ::~VisibleSetImpl ()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::VisibleSetImpl
    ::IsValid() const noexcept
{
    if(m_NumVisible <= static_cast<int>(m_Visible.size()))
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::VisibleSetImpl
    ::GetNumVisible () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_NumVisible;
}

void Rendering::VisibleSetImpl
	::Insert(const ConstSpatialSmartPointer& visible)
{
    RENDERING_CLASS_IS_VALID_1;
    
    auto size = boost::numeric_cast<int>(m_Visible.size());
    if (m_NumVisible < size)
    {
        m_Visible[m_NumVisible] = visible;
    }
    else
    {
        m_Visible.push_back(visible);
    }
    
    ++m_NumVisible;
}

const Rendering::ConstSpatialSmartPointer& Rendering::VisibleSetImpl
    ::GetVisible (int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_1(0 <= index && index < m_NumVisible,"索引无效在GetVisible\n");
    
    return m_Visible[index];
}

void Rendering::VisibleSetImpl
    ::Clear ()
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_NumVisible = 0;
}