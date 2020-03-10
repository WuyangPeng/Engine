// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 15:43)

#include "Rendering/RenderingExport.h"

#include "CameraMatrix.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::CameraMatrix
    ::CameraMatrix (const WorldCoordinateFrame& worldCoordinateFrame,const CameraFrustum& cameraFrustum,float epsilon)
	:m_WorldCoordinateFrame{ worldCoordinateFrame }, m_CameraFrustum{ cameraFrustum }, m_PreViewMatrix{ Matrix::sm_Identity }, m_PreViewIsIdentity{ true },
	 m_PostProjectionMatrix{ Matrix::sm_Identity }, m_PostProjectionIsIdentity{ true }, m_DepthType{ CAMERA_MANAGE_SINGLETON.GetDepthType() }, m_Epsilon{ epsilon }
{
    OnFrustumChange();
    
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CameraMatrix
    ::CameraMatrix (float epsilon)
	:m_WorldCoordinateFrame{ epsilon }, m_CameraFrustum{ true },m_PreViewMatrix{ Matrix::sm_Identity },m_PreViewIsIdentity{ true },
	 m_PostProjectionMatrix{ Matrix::sm_Identity },m_PostProjectionIsIdentity{ true },m_DepthType{ CAMERA_MANAGE_SINGLETON.GetDepthType() },m_Epsilon{ epsilon }
{
    OnFrustumChange();
    
    RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::CameraMatrix
    ::OnFrustumChange ()
{
    auto directionMin = m_CameraFrustum.GetDirectionMin ();
	auto directionMax = m_CameraFrustum.GetDirectionMax ();
	auto upMin = m_CameraFrustum.GetUpMin ();
	auto upMax = m_CameraFrustum.GetUpMax ();
	auto rightMin = m_CameraFrustum.GetRightMin ();
	auto rightMax = m_CameraFrustum.GetRightMax ();
    
    // N (near), F (far), B (bottom), T (top),
    // L (left), 和 R (right)
    
    // 1 / (F - N)
	auto invDirectionDifference = 1.0f / (directionMax - directionMin);
    
    // 1 / (T - B)
	auto invUpDifference = 1.0f / (upMax - upMin);
    
    // 1 / (R - L)
	auto invRightDifference = 1.0f / (rightMax - rightMin);
    
    // (R + L) / ( R - L)
	auto rightSumDivideDifference = (rightMin + rightMax) * invRightDifference;
    
    // (T + B) / (T - B)
	auto upSumDivideDifference = (upMin + upMax) * invUpDifference;
    
    // (F + N) / (F - N)
	auto directionSumDivideDifference = (directionMin + directionMax) * invDirectionDifference;
    
    if (m_CameraFrustum.IsPerspective())
    {
        // 2 * N / (R - L)
		auto twoDirectionMinMultiplyInvRightDifference =  2.0f * directionMin * invRightDifference;
        
        // 2 * N / (T - B)
		auto twoDirectionMinMultiplyInvUpDifference =  2.0f * directionMin * invUpDifference;
        // F / (F - N)
		auto directionMaxMultiplyInvDirectionDifference = directionMax * invDirectionDifference;
        
        // N * F / (F - N)
		auto directionProductDivideDifference = directionMin * directionMaxMultiplyInvDirectionDifference;
        
        // 2 * N * F / (F - N)
		auto twoDirectionProductDivideDifference = 2.0f * directionProductDivideDifference;
        
        if (m_DepthType == DepthType::ZeroToOne)
        {
            // 映射 (x,y,z) 到 [-1,1]x[-1,1]x[0,1].
			auto& projection = m_ProjectionMatrix[System::EnumCastUnderlying(DepthType::ZeroToOne)];
            projection(0,0) = twoDirectionMinMultiplyInvRightDifference;
            projection(0,1) = 0.0f;
            projection(0,2) = -rightSumDivideDifference;
            projection(0,3) = 0.0f;
            projection(1,0) = 0.0f;
            projection(1,1) = twoDirectionMinMultiplyInvUpDifference;
            projection(1,2) = -upSumDivideDifference;
            projection(1,3) = 0.0f;
            projection(2,0) = 0.0f;
            projection(2,1) = 0.0f;
            projection(2,2) = directionMaxMultiplyInvDirectionDifference;
            projection(2,3) = -directionProductDivideDifference;
            projection(3,0) = 0.0f;
            projection(3,1) = 0.0f;
            projection(3,2) = 1.0f;
            projection(3,3) = 0.0f;
        }
        else
        {
            // 映射 (x,y,z) 到 [-1,1]x[-1,1]x[-1,1].
			auto& projection = m_ProjectionMatrix[System::EnumCastUnderlying(DepthType::MinusOneToOne)];
            projection(0,0) = twoDirectionMinMultiplyInvRightDifference;
            projection(0,1) = 0.0f;
            projection(0,2) = -rightSumDivideDifference;
            projection(0,3) = 0.0f;
            projection(1,0) = 0.0f;
            projection(1,1) = twoDirectionMinMultiplyInvUpDifference;
            projection(1,2) = -upSumDivideDifference;
            projection(1,3) = 0.0f;
            projection(2,0) = 0.0f;
            projection(2,1) = 0.0f;
            projection(2,2) = directionSumDivideDifference;
            projection(2,3) = -twoDirectionProductDivideDifference;
            projection(3,0) = 0.0f;
            projection(3,1) = 0.0f;
            projection(3,2) = 1.0f;
            projection(3,3) = 0.0f;
        }
    }
    else
    {
        // 2 / (R - L)
		auto twoInvRightDifference = 2.0f * invRightDifference;
        
        // 2 / (T - B)
		auto twoInvUpDifference = 2.0f * invUpDifference;
        
        // 2 / (F - N)
		auto twoInvDirectionDifference = 2.0f * invDirectionDifference;
        
        // N / (F - N)
		auto directionMinMultiplyInvDirectionDifference = directionMin * invDirectionDifference;
        
        if (m_DepthType == DepthType::ZeroToOne)
        {
            // 映射 (x,y,z) 到 [-1,1]x[-1,1]x[0,1].
			auto& projection = m_ProjectionMatrix[System::EnumCastUnderlying(DepthType::ZeroToOne)];
            projection(0,0) = twoInvRightDifference;
            projection(0,1) = 0.0f;
            projection(0,2) = 0.0f;
            projection(0,3) = -rightSumDivideDifference;
            projection(1,0) = 0.0f;
            projection(1,1) = twoInvUpDifference;
            projection(1,2) = 0.0f;
            projection(1,3) = -upSumDivideDifference;
            projection(2,0) = 0.0f;
            projection(2,1) = 0.0f;
            projection(2,2) = invDirectionDifference;
            projection(2,3) = -directionMinMultiplyInvDirectionDifference;
            projection(3,0) = 0.0f;
            projection(3,1) = 0.0f;
            projection(3,2) = 0.0f;
            projection(3,3) = 1.0f;
        }
        else
        {
            // 映射 (x,y,z) 到 [-1,1]x[-1,1]x[-1,1].
			auto& projection = m_ProjectionMatrix[System::EnumCastUnderlying(DepthType::MinusOneToOne)];
            projection(0,0) = twoInvRightDifference;
            projection(0,1) = 0.0f;
            projection(0,2) = 0.0f;
            projection(0,3) = -rightSumDivideDifference;
            projection(1,0) = 0.0f;
            projection(1,1) = twoInvUpDifference;
            projection(1,2) = 0.0f;
            projection(1,3) = -upSumDivideDifference;
            projection(2,0) = 0.0f;
            projection(2,1) = 0.0f;
            projection(2,2) = twoInvDirectionDifference;
            projection(2,3) = -directionSumDivideDifference;
            projection(3,0) = 0.0f;
            projection(3,1) = 0.0f;
            projection(3,2) = 0.0f;
            projection(3,3) = 1.0f;
        }
    }
    
    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix
    ::UpdateProjectionViewMatrix ()
{
	auto& projectionMatrix = m_ProjectionMatrix[System::EnumCastUnderlying(m_DepthType)];
	auto& projectionViewMatrix = m_ProjectionViewMatrix[System::EnumCastUnderlying(m_DepthType)];
    
    projectionViewMatrix = projectionMatrix * m_WorldCoordinateFrame.GetViewMatrix();
    if (!m_PostProjectionIsIdentity)
    {
        projectionViewMatrix = m_PostProjectionMatrix * projectionViewMatrix;
    }
    if (!m_PreViewIsIdentity)
    {
        projectionViewMatrix = projectionViewMatrix * m_PreViewMatrix;
    }
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,CameraMatrix)

const Rendering::CameraMatrix::Matrix Rendering::CameraMatrix
    ::GetProjectionMatrix () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_ProjectionMatrix[System::EnumCastUnderlying(m_DepthType)];
}

void Rendering::CameraMatrix
    ::SetProjectionMatrix (const Matrix& projectionMatrix)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_ProjectionMatrix[System::EnumCastUnderlying(m_DepthType)] = projectionMatrix;
    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix
    ::SetProjectionMatrix (const APoint& p00, const APoint& p10,const APoint& p11, const APoint& p01,float nearExtrude, float farExtrude)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(0.0f < nearExtrude, "nearExtrude必须大于0\n");
    RENDERING_ASSERTION_1(nearExtrude < farExtrude, "farExtrude必须大于nearExtrude\n");
    
    // 计算最近面的视图体积
	auto q000 = APoint::sm_Origin + nearExtrude * (p00 - APoint::sm_Origin);
	auto q100 = APoint::sm_Origin + nearExtrude * (p10 - APoint::sm_Origin);
	auto q110 = APoint::sm_Origin + nearExtrude * (p11 - APoint::sm_Origin);
	auto q010 = APoint::sm_Origin + nearExtrude * (p01 - APoint::sm_Origin);
    
    // 计算最远面的视图体积
	auto q001 = APoint::sm_Origin + farExtrude * (p00 - APoint::sm_Origin);
	auto q101 = APoint::sm_Origin + farExtrude * (p10 - APoint::sm_Origin);
	auto q111 = APoint::sm_Origin + farExtrude * (p11 - APoint::sm_Origin);
	auto q011 = APoint::sm_Origin + farExtrude * (p01 - APoint::sm_Origin);
    
    // 计算q111的表示
	auto u0 = q100 - q000;
	auto u1 = q010 - q000;
	auto u2 = q001 - q000;
 
	Matrix matrix{ u0, u1, u2, q000, Mathematics::MatrixMajorFlags::Column };
	auto inverseMatrix = matrix.Inverse(m_Epsilon);
	auto point = inverseMatrix * q111;
 
    // 计算分段线性变换的参数。
    //   y[i] = n[i] * x[i] / (d[0] * x[0] + d[1] * x[1] + d[2] * x[2] + d[3])
	auto twoPoint0 = 2.0f * point[0];
	auto twoPoint1 = 2.0f * point[1];
	auto twoPoint2 = 2.0f * point[2];
	auto d0 = +point[0] - point[1] - point[2] + 1.0f;
	auto d1 = -point[0] + point[1] - point[2] + 1.0f;
	auto d2 = -point[0] - point[1] + point[2] + 1.0f;
	auto d3 = +point[0] + point[1] + point[2] - 1.0f;
 
    // 计算透视投影从规范化长方体到规范化立方体[-1,1]^2 x [0,1]
	auto twoPoint2divide0 = twoPoint2 / twoPoint0;
	auto twoPoint2divide1 = twoPoint2 / twoPoint1;
    
    Matrix project;
    project(0,0) = twoPoint2divide0 * (2.0f * d3 + d0);
    project(0,1) = twoPoint2divide1 * d1;
    project(0,2) = d2;
    project(0,3) = -twoPoint2;
    project(1,0) = twoPoint2divide0 * d0;
    project(1,1)= twoPoint2divide1 * (2.0f * d3 + d1);
    project(1,2) = d2;
    project(1,3) = -twoPoint2;
    
    if (m_DepthType == DepthType::ZeroToOne)
    {
        project(2,0) = 0.0f;
        project(2,1) = 0.0f;
        project(2,2) = d3;
        project(2,3) = 0.0f;
    }
    else
    {
        project(2,0) = twoPoint2divide0 * d0;
        project(2,1) = twoPoint2divide1 * d1;
        project(2,2) = 2.0f * d3 + d2;
        project(2,3) = -twoPoint2;
    }
    
    project(3,0) = -twoPoint2divide0 * d0;
    project(3,1) = -twoPoint2divide1 * d1;
    project(3,2)  = -d2;
    project(3,3)  = twoPoint2;
    
    // 需要映射挤压四边形投影视图体积到规范的长方体，
    // 然后后面跟着透视投影到规范化立方体。
    SetProjectionMatrix(project * inverseMatrix);
}


Rendering::DepthType Rendering::CameraMatrix
    ::GetDepthType () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_DepthType;
}

const Rendering::CameraMatrix::Matrix Rendering::CameraMatrix
    ::GetProjectionViewMatrix () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_ProjectionViewMatrix[System::EnumCastUnderlying(m_DepthType)];
}

void Rendering::CameraMatrix
    ::SetPreViewMatrix (const Matrix& preViewMatrix)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_PreViewMatrix = preViewMatrix;
    m_PreViewIsIdentity = Approximate(m_PreViewMatrix,Matrix::sm_Identity,m_Epsilon);
    
    UpdateProjectionViewMatrix();
}

const Rendering::CameraMatrix::Matrix Rendering::CameraMatrix
    ::GetPreViewMatrix () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_PreViewMatrix;
}

bool Rendering::CameraMatrix
    ::PreViewIsIdentity () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_PreViewIsIdentity;
}

void Rendering::CameraMatrix
    ::SetPostProjectionMatrix (const Matrix& postProjMatrix)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_PostProjectionMatrix = postProjMatrix;
    m_PostProjectionIsIdentity = Approximate(m_PostProjectionMatrix,Matrix::sm_Identity,m_Epsilon);
    
    UpdateProjectionViewMatrix();
}

const Rendering::CameraMatrix::Matrix Rendering::CameraMatrix
    ::GetPostProjectionMatrix () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_PostProjectionMatrix;
}

bool Rendering::CameraMatrix
    ::PostProjectionIsIdentity () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_PostProjectionIsIdentity;
}

void Rendering::CameraMatrix
    ::OnFrustumChange (const CameraFrustum& cameraFrustum)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_CameraFrustum = cameraFrustum;
    
    OnFrustumChange();
}

const Rendering::CameraFrustum& Rendering::CameraMatrix
    ::GetCameraFrustum() const
{
    RENDERING_CLASS_IS_VALID_9;
    
    return m_CameraFrustum;   
}

const Rendering::WorldCoordinateFrame& Rendering::CameraMatrix
    ::GetWorldCoordinateFrame() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_WorldCoordinateFrame;
}

void Rendering::CameraMatrix
    ::SetFrame (const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_WorldCoordinateFrame.SetFrame(position,directionVector,upVector,rightVector);
    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix
    ::SetPosition (const APoint& position)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_WorldCoordinateFrame.SetPosition(position);
    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix
    ::SetAxes (const AVector& directionVector,const AVector& upVector,const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_WorldCoordinateFrame.SetAxes(directionVector,upVector,rightVector);
    UpdateProjectionViewMatrix();
}

void Rendering::CameraMatrix
    ::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;
    
    m_WorldCoordinateFrame.Load(source);
    m_CameraFrustum.Load(source);
 
    source.ReadAggregate(m_PreViewMatrix);
    m_PreViewIsIdentity = source.ReadBool();
    source.ReadAggregate(m_PostProjectionMatrix);
    m_PostProjectionIsIdentity = source.ReadBool();
    source.Read(m_Epsilon);
    
    // 计算m_ProjectionMatrix[].
    OnFrustumChange();
}

void Rendering::CameraMatrix
    ::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    
    m_WorldCoordinateFrame.Save(target);
    m_CameraFrustum.Save(target);
 
    target.WriteAggregate(m_PreViewMatrix);
    target.WriteBool(m_PreViewIsIdentity);
    target.WriteAggregate(m_PostProjectionMatrix);
    target.WriteBool(m_PostProjectionIsIdentity);
    
    target.Write(m_Epsilon);
    
    // 这里不保存m_ProjectionMatrix[]和m_ProjectionViewMatrix[]。
}

int Rendering::CameraMatrix
    ::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    
	auto size = m_WorldCoordinateFrame.GetStreamingSize();
    
    size += m_CameraFrustum.GetStreamingSize();
 
    size += MATHEMATICS_STREAM_SIZE(m_PreViewMatrix);
    size += CORE_TOOLS_STREAM_SIZE(m_PreViewIsIdentity);
    size += MATHEMATICS_STREAM_SIZE(m_PostProjectionMatrix);
    size += CORE_TOOLS_STREAM_SIZE(m_PostProjectionIsIdentity);
    
    size += CORE_TOOLS_STREAM_SIZE(m_Epsilon);
    
    return size;
}

float Rendering::CameraMatrix
	::GetEpsilon() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Epsilon;
}

void Rendering::CameraMatrix
	::SetDepthType(DepthType depthType)
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_DepthType = depthType;

	// 设置m_DepthType并更新投影矩阵,投影矩阵取决于深度类型。
	// 因为我们已经改变了深度类型,我们需要再次更新投影矩阵。
	OnFrustumChange();
}

