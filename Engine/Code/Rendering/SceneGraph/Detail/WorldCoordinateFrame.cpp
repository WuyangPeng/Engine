// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 17:04)

#include "Rendering/RenderingExport.h"

#include "WorldCoordinateFrame.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/AVectorOrthonormalizeDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26440)
Rendering::WorldCoordinateFrame ::WorldCoordinateFrame(float epsilon)  
    : m_Position{ Mathematics::Float::g_Origin }, m_DirectionVector{ -Mathematics::Float::g_UnitZ }, m_UpVector{ Mathematics::Float::g_UnitY },
	m_RightVector{ Mathematics::Float::g_UnitX }, m_ViewMatrix{ Mathematics::Float::g_ZeroMatrix }, m_Epsilon{ epsilon }
{
    OnFrameChange ();
    
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::WorldCoordinateFrame
    ::IsValid() const noexcept
{
    try
    {
        if (m_DirectionVector.IsNormalize(m_Epsilon) && m_UpVector.IsNormalize(m_Epsilon) && m_RightVector.IsNormalize(m_Epsilon) &&
            Math::FAbs(Dot(m_DirectionVector, m_UpVector)) <= m_Epsilon &&
            Math::FAbs(Dot(m_UpVector, m_RightVector)) <= m_Epsilon &&
            Math::FAbs(Dot(m_RightVector, m_DirectionVector)) <= m_Epsilon)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
    
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::WorldCoordinateFrame
    ::SetFrame (const APoint& position,const AVector& directionVector,const AVector& upVector,const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_Position = position;
    
    SetAxes(directionVector, upVector, rightVector);
}

void Rendering::WorldCoordinateFrame
    ::SetPosition (const APoint& position)
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_Position = position;
    
    OnFrameChange ();
}

void Rendering::WorldCoordinateFrame
    ::SetAxes (const AVector& directionVector,const AVector& upVector,const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_DirectionVector = directionVector;
    m_UpVector = upVector;
    m_RightVector = rightVector;
    
    auto det = Dot(m_DirectionVector,Cross(m_UpVector,m_RightVector));
    if (m_Epsilon < Mathematics::FloatMath::FAbs(1.0f - det))
    {
        // 输入向量并没有形成一个标准正交集合。这里重新正交化
        const auto orthonormalize = Orthonormalize(m_DirectionVector, m_UpVector, m_RightVector, m_Epsilon);
        
        m_DirectionVector = orthonormalize.GetUVector();
        m_UpVector = orthonormalize.GetVVector();
        m_RightVector = orthonormalize.GetWVector();
    }
    
    OnFrameChange ();
}

const Rendering::WorldCoordinateFrame::APoint Rendering::WorldCoordinateFrame
    ::GetPosition () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Position;
}

const Rendering::WorldCoordinateFrame::AVector Rendering::WorldCoordinateFrame
    ::GetDirectionVector () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_DirectionVector;
}

const Rendering::WorldCoordinateFrame::AVector Rendering::WorldCoordinateFrame
    ::GetUpVector () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_UpVector;
}

const Rendering::WorldCoordinateFrame::AVector Rendering::WorldCoordinateFrame
    ::GetRightVector () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_RightVector;
}

const Rendering::WorldCoordinateFrame::Matrix Rendering::WorldCoordinateFrame
    ::GetViewMatrix () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_ViewMatrix;
}

// private
void Rendering::WorldCoordinateFrame ::OnFrameChange()  
{
    m_ViewMatrix(0,0) = m_RightVector[0];
    m_ViewMatrix(0,1) = m_RightVector[1];
    m_ViewMatrix(0,2) = m_RightVector[2];
    m_ViewMatrix(0,3) = -Dot(m_Position,m_RightVector);
    m_ViewMatrix(1,0) = m_UpVector[0];
    m_ViewMatrix(1,1) = m_UpVector[1];
    m_ViewMatrix(1,2) = m_UpVector[2];
    m_ViewMatrix(1,3) = -Dot(m_Position,m_UpVector);
    m_ViewMatrix(2,0) = m_DirectionVector[0];
    m_ViewMatrix(2,1) = m_DirectionVector[1];
    m_ViewMatrix(2,2) = m_DirectionVector[2];
    m_ViewMatrix(2,3) = -Dot(m_Position,m_DirectionVector);
    m_ViewMatrix(3,0) = 0.0f;
    m_ViewMatrix(3,1) = 0.0f;
    m_ViewMatrix(3,2) = 0.0f;
    m_ViewMatrix(3,3) = 1.0f;
}

void Rendering::WorldCoordinateFrame
    ::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_1;
    
	source.ReadAggregate(m_Position);
    source.ReadAggregate(m_DirectionVector);
    source.ReadAggregate(m_UpVector);
    source.ReadAggregate(m_RightVector);
    source.Read(m_Epsilon);
    
    OnFrameChange ();
}

void Rendering::WorldCoordinateFrame
    ::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	target.WriteAggregate(m_Position);
    target.WriteAggregate(m_DirectionVector);
    target.WriteAggregate(m_UpVector);
    target.WriteAggregate(m_RightVector);
    target.Write(m_Epsilon);
}

int Rendering::WorldCoordinateFrame
    ::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = MATHEMATICS_STREAM_SIZE(m_Position);
    
    size += MATHEMATICS_STREAM_SIZE(m_DirectionVector);
    size += MATHEMATICS_STREAM_SIZE(m_UpVector);
    size += MATHEMATICS_STREAM_SIZE(m_RightVector);
    
    size += CORE_TOOLS_STREAM_SIZE(m_Epsilon);
    
    return size;
}
 #include STSTEM_WARNING_POP