// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:43)

#include "Mathematics/MathematicsExport.h"

#include "OrderedEdgeKey.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
Mathematics::OrderedEdgeKey
	::OrderedEdgeKey (int first, int second) noexcept
{
    m_Vertex[0] = first;
    m_Vertex[1] = second;
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}


Mathematics::OrderedEdgeKey
	::OrderedEdgeKey(const OrderedEdgeKey& rhs) noexcept
{ 
    m_Vertex[0] = rhs.m_Vertex[0];
    m_Vertex[1] = rhs.m_Vertex[1];
    
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::OrderedEdgeKey& Mathematics::OrderedEdgeKey
	::operator = (const OrderedEdgeKey& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Vertex[0] = rhs.m_Vertex[0];
    m_Vertex[1] = rhs.m_Vertex[1];

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, OrderedEdgeKey)

int Mathematics::OrderedEdgeKey
	::GetKey(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9; 
    
	if (0 <= index && index < 2)
	{
		return m_Vertex[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("À˜“˝¥ÌŒÛ£°"s));
	}
    
}

bool Mathematics
	::operator< (const OrderedEdgeKey& lhs, const OrderedEdgeKey& rhs)
{
    
    if (lhs.GetKey(1) < rhs.GetKey(1))
    {
        return true;
    }
    
    if (rhs.GetKey(1) < lhs.GetKey(1))
    {
        return false;
    }
    
    return lhs.GetKey(0) < rhs.GetKey(0);
}

#include STSTEM_WARNING_POP


