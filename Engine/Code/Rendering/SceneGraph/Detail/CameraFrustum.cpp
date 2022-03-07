// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 15:33)

#include "Rendering/RenderingExport.h"

#include "CameraFrustum.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::CameraFrustum ::CameraFrustum(bool isPerspective) noexcept
    : m_IsPerspective{ isPerspective }
{
    SetFrustum(90.0f, 1.0f, 1.0f, 10000.0f);
    
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,CameraFrustum)

bool Rendering::CameraFrustum ::IsPerspective() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_IsPerspective;
}

void Rendering::CameraFrustum ::SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)] = directionMin;
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMax)] = directionMax;
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMin)] = upMin;
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)] = upMax;
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMin)] = rightMin;
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)] = rightMax;
}

void Rendering::CameraFrustum ::SetFrustum(const float* frustum) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
    
    SetFrustum(frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)],
               frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMax)],
               frustum[System::EnumCastUnderlying(ViewFrustum::UpMin)],
               frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)],
               frustum[System::EnumCastUnderlying(ViewFrustum::RightMin)],
               frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)]);
}

void Rendering::CameraFrustum
    ::SetFrustum (float upFieldOfViewDegrees, float aspectRatio,float directionMin,float directionMax) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
    
  const  auto halfAngleRadians = 0.5f * upFieldOfViewDegrees * Mathematics::MathF::GetDegreeToRadian();
    
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)] = directionMin * Mathematics::MathF::Tan(halfAngleRadians);
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)] = aspectRatio * m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)];
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMin)] = -m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)];
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMin)] = -m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)];
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)] = directionMin;
    m_Frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMax)] = directionMax;
}

const float* Rendering::CameraFrustum ::GetFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Frustum;
}

const Rendering::CameraFrustumData Rendering::CameraFrustum ::GetFrustumData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    if (m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMin)] == -m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)] &&
        m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMin)] == -m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)])
    {
    const    auto ratio = m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)] / m_Frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)];
        const auto upFieldOfViewDegrees = 2.0f * Mathematics::MathF::ATan(ratio) * Mathematics::MathF::GetRadianToDegree();
    const auto aspectRatio = m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)] / m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)];
        const auto directionMin = m_Frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)];
    const auto directionMax = m_Frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMax)];
        
		return CameraFrustumData{ upFieldOfViewDegrees,aspectRatio, directionMin,directionMax };
    }
    
	return CameraFrustumData{};
}

float Rendering::CameraFrustum
    ::GetDirectionMin () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)];
}

float Rendering::CameraFrustum ::GetDirectionMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMax)];
}

float Rendering::CameraFrustum ::GetUpMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMin)];
}

float Rendering::CameraFrustum ::GetUpMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)];
}

float Rendering::CameraFrustum ::GetRightMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMin)];
}

float Rendering::CameraFrustum ::GetRightMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)];
}

void Rendering::CameraFrustum ::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;
 
   // source.Read(System::EnumCastUnderlying(ViewFrustum::Quantity), m_Frustum);
    m_IsPerspective = source.ReadBool();
}

void Rendering::CameraFrustum
    ::Save( CoreTools::BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    
   // target.WriteWithoutNumber(System::EnumCastUnderlying(ViewFrustum::Quantity), m_Frustum);
    target.Write(m_IsPerspective);
}

int Rendering::CameraFrustum ::GetStreamingSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    
	auto size = System::EnumCastUnderlying(ViewFrustum::Quantity) * CORE_TOOLS_STREAM_SIZE(m_Frustum[0]);
 
    size += CORE_TOOLS_STREAM_SIZE(m_IsPerspective);
    
    return size;
}
 #include STSTEM_WARNING_POP