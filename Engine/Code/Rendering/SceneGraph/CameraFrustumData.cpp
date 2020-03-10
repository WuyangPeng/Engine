// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 17:21)

#include "Rendering/RenderingExport.h"

#include "CameraFrustumData.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::CameraFrustumData
    ::CameraFrustumData ()
	:m_UpFieldOfViewDegrees{ 0.0f },m_AspectRatio{ 0.0f },m_DirectionMin{ 0.0f },m_DirectionMax{ 0.0f },m_Symmetric{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CameraFrustumData
    ::CameraFrustumData (float upFieldOfViewDegrees,float aspectRatio,float directionMin,float directionMax,bool symmetric)
	:m_UpFieldOfViewDegrees{ upFieldOfViewDegrees }, m_AspectRatio{ aspectRatio }, m_DirectionMin{ directionMin },
	 m_DirectionMax{ directionMax }, m_Symmetric{ symmetric }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,CameraFrustumData)

float Rendering::CameraFrustumData
    ::GetUpFieldOfViewDegrees() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(m_Symmetric,"参数是无效的。");
    
    return m_UpFieldOfViewDegrees;
}

float Rendering::CameraFrustumData
    ::GetAspectRatio() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(m_Symmetric,"参数是无效的。");
    
    return m_AspectRatio;
}

float Rendering::CameraFrustumData
    ::GetDirectionMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(m_Symmetric,"参数是无效的。");
    
    return m_DirectionMin;
}

float Rendering::CameraFrustumData
    ::GetDirectionMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(m_Symmetric,"参数是无效的。"); 
    
    return m_DirectionMax;
}

bool Rendering::CameraFrustumData
    ::IsSymmetric() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Symmetric;
}

