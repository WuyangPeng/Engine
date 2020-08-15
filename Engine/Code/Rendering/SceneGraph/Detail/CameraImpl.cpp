// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 15:38)

#include "Rendering/RenderingExport.h"

#include "CameraImpl.h"
#include "CameraFrustum.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2DDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26489)
Rendering::CameraImpl
::CameraImpl (bool isPerspective, float epsilon)
	: m_CameraMatrix{ WorldCoordinateFrame{ epsilon },CameraFrustum{ isPerspective },epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CameraImpl ::CameraImpl(float epsilon)  
    : m_CameraMatrix{ epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,CameraImpl)

void Rendering::CameraImpl
    ::SetFrame (const APoint& position,const AVector& directionVector,const AVector& upVector,const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;

    m_CameraMatrix.SetFrame(position,directionVector,upVector,rightVector);
}

void Rendering::CameraImpl
    ::SetPosition (const APoint& position)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_CameraMatrix.SetPosition(position);
}

void Rendering::CameraImpl
    ::SetAxes (const AVector& directionVector,const AVector& upVector,const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_CameraMatrix.SetAxes(directionVector,upVector,rightVector);
}

const Rendering::CameraImpl::APoint Rendering::CameraImpl
    ::GetPosition () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetWorldCoordinateFrame().GetPosition();
}

const Rendering::CameraImpl::AVector Rendering::CameraImpl
    ::GetDirectionVector () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetWorldCoordinateFrame().GetDirectionVector();
}

const Rendering::CameraImpl::AVector Rendering::CameraImpl
    ::GetUpVector () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetWorldCoordinateFrame().GetUpVector();
}

const Rendering::CameraImpl::AVector Rendering::CameraImpl
    ::GetRightVector () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetWorldCoordinateFrame().GetRightVector();
}

const Rendering::CameraImpl::Matrix Rendering::CameraImpl
    ::GetViewMatrix () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetWorldCoordinateFrame().GetViewMatrix();
}

bool Rendering::CameraImpl ::IsPerspective() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetCameraFrustum().IsPerspective();
}

void Rendering::CameraImpl
    ::SetFrustum (float directionMin, float directionMax,float upMin, float upMax,float rightMin, float rightMax)
{
    RENDERING_CLASS_IS_VALID_9;
    
	CameraFrustum cameraFrustum{ IsPerspective() };
    
    cameraFrustum.SetFrustum(directionMin,directionMax,upMin,upMax,rightMin,rightMax);
    
    m_CameraMatrix.OnFrustumChange(cameraFrustum);
}


void Rendering::CameraImpl
    ::SetFrustum (const float* frustum)
{
    RENDERING_CLASS_IS_VALID_9;
    
    SetFrustum(frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)],
               frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMax)],
               frustum[System::EnumCastUnderlying(ViewFrustum::UpMin)],
               frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)],
               frustum[System::EnumCastUnderlying(ViewFrustum::RightMin)],
               frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)]);
}

void Rendering::CameraImpl
    ::SetFrustum (float upFieldOfViewDegrees, float aspectRatio,float directionMin,float directionMax)
{
    RENDERING_CLASS_IS_VALID_9;
    
	CameraFrustum cameraFrustum{ IsPerspective() };
    
    cameraFrustum.SetFrustum(upFieldOfViewDegrees,aspectRatio,directionMin,directionMax);
    
    m_CameraMatrix.OnFrustumChange(cameraFrustum);
}

const float* Rendering::CameraImpl ::GetFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetCameraFrustum().GetFrustum ();
}

const Rendering::CameraFrustumData Rendering::CameraImpl ::GetFrustumData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetCameraFrustum().GetFrustumData ();
}

float Rendering::CameraImpl ::GetDirectionMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetCameraFrustum().GetDirectionMin();
}

float Rendering::CameraImpl ::GetDirectionMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetCameraFrustum().GetDirectionMax();
}

float Rendering::CameraImpl ::GetUpMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetCameraFrustum().GetUpMin();
}

float Rendering::CameraImpl ::GetUpMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetCameraFrustum().GetUpMax();
}

float Rendering::CameraImpl ::GetRightMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetCameraFrustum().GetRightMin();
}

float Rendering::CameraImpl ::GetRightMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetCameraFrustum().GetRightMax();
}

const Rendering::CameraImpl::Matrix Rendering::CameraImpl ::GetProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetProjectionMatrix ();
}

void Rendering::CameraImpl
    ::SetProjectionMatrix (const Matrix& projectionMatrix)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_CameraMatrix.SetProjectionMatrix(projectionMatrix);
}

void Rendering::CameraImpl
    ::SetProjectionMatrix (const APoint& p00, const APoint& p10,const APoint& p11, const APoint& p01,float nearExtrude, float farExtrude)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_CameraMatrix.SetProjectionMatrix(p00,p10,p11,p01,nearExtrude,farExtrude);
}

Rendering::DepthType Rendering::CameraImpl ::GetDepthType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetDepthType ();
}

const Rendering::CameraImpl::Matrix Rendering::CameraImpl ::GetProjectionViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetProjectionViewMatrix ();
}

void Rendering::CameraImpl
    ::SetPreViewMatrix (const Matrix& preViewMatrix)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_CameraMatrix.SetPreViewMatrix (preViewMatrix);
}

const Rendering::CameraImpl::Matrix Rendering::CameraImpl ::GetPreViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetPreViewMatrix ();
}

bool Rendering::CameraImpl ::PreViewIsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.PreViewIsIdentity ();
}

void Rendering::CameraImpl
    ::SetPostProjectionMatrix (const Matrix& postProjMatrix)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_CameraMatrix.SetPostProjectionMatrix (postProjMatrix);
}

const Rendering::CameraImpl::Matrix Rendering::CameraImpl ::GetPostProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.GetPostProjectionMatrix ();
}

bool Rendering::CameraImpl ::PostProjectionIsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_CameraMatrix.PostProjectionIsIdentity ();
}

const Rendering::CameraImpl::AxesAlignBoundingBox2D Rendering::CameraImpl
      ::ComputeBoundingAABB (int numVertices,const char* vertices,int stride,const Matrix& worldMatrix) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    // 计算当前世界投影视图矩阵。
    auto viewProjectionMatrix = GetProjectionMatrix() * GetViewMatrix();
    if (!PostProjectionIsIdentity())
    {
        viewProjectionMatrix = GetPostProjectionMatrix() * viewProjectionMatrix;
    }
const	auto worldViewProjectionMatrix = viewProjectionMatrix * worldMatrix;

    // 计算正则化的包围盒矩形显示坐标。
	auto xmin = Mathematics::Mathf::sm_MaxReal;
	auto xmax = -Mathematics::Mathf::sm_MaxReal;
	auto ymin = Mathematics::Mathf::sm_MaxReal;
	auto ymax = -Mathematics::Mathf::sm_MaxReal;
    for (auto i = 0; i < numVertices; ++i)
    {
		auto vertex = reinterpret_cast<const float*>(vertices);
		HomogeneousPoint position{ vertex[0], vertex[1], vertex[2], 1.0f };
		auto homogeneousPosition = worldViewProjectionMatrix * position;
                const auto invW = 1.0f / homogeneousPosition[3];
		auto xNormalizeDeviceCoordinate  = homogeneousPosition[0] * invW;
		auto yNormalizeDeviceCoordinate = homogeneousPosition[1] * invW;
        if (xNormalizeDeviceCoordinate < xmin)
        {
            xmin = xNormalizeDeviceCoordinate;
        }
        if (xmax < xNormalizeDeviceCoordinate)
        {
            xmax = xNormalizeDeviceCoordinate;
        }
        if (yNormalizeDeviceCoordinate < ymin)
        {
            ymin = yNormalizeDeviceCoordinate;
        }
        if (ymax < yNormalizeDeviceCoordinate)
        {
            ymax = yNormalizeDeviceCoordinate;
        }
        
        vertices += stride;
    }
    
	return AxesAlignBoundingBox2D{ xmin,xmax,ymin,ymax };
}

void Rendering::CameraImpl
    ::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;
    
    m_CameraMatrix.Load(source);
}

void Rendering::CameraImpl
    ::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

    m_CameraMatrix.Save(target);
}

int Rendering::CameraImpl
    ::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    
const	auto size = m_CameraMatrix.GetStreamingSize();
    
    return size;
}

float Rendering::CameraImpl ::GetEpsilon() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_CameraMatrix.GetEpsilon();
}

void Rendering::CameraImpl
	::SetDepthType(DepthType depthType)
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_CameraMatrix.SetDepthType(depthType);
}

#include STSTEM_WARNING_POP