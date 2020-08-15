// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/18 15:04)

#include "Rendering/RenderingExport.h"

#include "TransformMatrix.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const Rendering::TransformMatrix Rendering::TransformMatrix
	::sm_Identity;

Rendering::TransformMatrix
    ::TransformMatrix() noexcept
	:m_Matrix{ Mathematics::MatrixTypeFlags::Identity }, m_IsIdentity{ true }, m_IsRotationOrScaleMatrix{ true }, m_IsUniformScale{ true }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,TransformMatrix)

void Rendering::TransformMatrix ::MakeIdentity() noexcept
{
    RENDERING_CLASS_IS_VALID_9;    
 
    m_IsIdentity = true;
    m_IsRotationOrScaleMatrix = true;
    m_IsUniformScale = true;

    m_Matrix = Matrix::sm_Identity;
}

void Rendering::TransformMatrix
    ::MakeUnitScale (const Matrix& rotate)
{
    RENDERING_CLASS_IS_VALID_9;
    
    RENDERING_ASSERTION_1(m_IsRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");
 
    m_IsUniformScale = true;

    Modification(rotate);
}

// private
void Rendering::TransformMatrix
    ::Modification(const APoint& translate)
{
    m_Matrix(0,3) = translate[0];
	m_Matrix(1,3) = translate[1];
	m_Matrix(2,3) = translate[2];
}

// private
void Rendering::TransformMatrix
    ::Modification(const Matrix& matrix)
{
    m_Matrix(0,0) = matrix(0,0);
	m_Matrix(0,1) = matrix(0,1);
	m_Matrix(0,2) = matrix(0,2);
	m_Matrix(1,0) = matrix(1,0);
	m_Matrix(1,1) = matrix(1,1);
	m_Matrix(1,2) = matrix(1,2);
	m_Matrix(2,0) = matrix(2,0);
	m_Matrix(2,1) = matrix(2,1);
	m_Matrix(2,2) = matrix(2,2);
}

// private
void Rendering::TransformMatrix
    ::Modification(const Matrix& rotate,const APoint& scale)
{
    m_Matrix(0,0) = rotate(0,0) * scale[0];
	m_Matrix(0,1) = rotate(0,1) * scale[1];
	m_Matrix(0,2) = rotate(0,2) * scale[2];
	m_Matrix(1,0) = rotate(1,0) * scale[0];
	m_Matrix(1,1) = rotate(1,1) * scale[1];
	m_Matrix(1,2) = rotate(1,2) * scale[2];
	m_Matrix(2,0) = rotate(2,0) * scale[0];
	m_Matrix(2,1) = rotate(2,1) * scale[1];
	m_Matrix(2,2) = rotate(2,2) * scale[2];
}

bool Rendering::TransformMatrix ::IsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_IsIdentity;
}

bool Rendering::TransformMatrix ::IsRotationOrScaleMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_IsRotationOrScaleMatrix;
}

bool Rendering::TransformMatrix ::IsUniformScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_IsRotationOrScaleMatrix && m_IsUniformScale;
}

void Rendering::TransformMatrix
	::SetRotate (const Matrix& rotate,const APoint& scale)
{
    RENDERING_CLASS_IS_VALID_9;    
   
    m_IsIdentity = false;
    m_IsRotationOrScaleMatrix = true;
     
	Modification(rotate,scale);
}

void Rendering::TransformMatrix
    ::SetMatrix (const Matrix& matrix)
{
    RENDERING_CLASS_IS_VALID_9;
 
    m_IsIdentity = false;
    m_IsRotationOrScaleMatrix = false;
    m_IsUniformScale = false;
    
    Modification(matrix);
}

void Rendering::TransformMatrix
    ::SetTranslate (const APoint& translate)
{
    RENDERING_CLASS_IS_VALID_9;
  
    m_IsIdentity = false;
    
    Modification(translate);
}

void Rendering::TransformMatrix
    ::SetScale (const Matrix& rotate,const APoint& scale)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(m_IsRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");
   
    m_IsIdentity = false;
    m_IsUniformScale = false;
    
    Modification(rotate,scale);
}

void Rendering::TransformMatrix
    ::SetUniformScale (const Matrix& rotate,float scale)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(m_IsRotationOrScaleMatrix,"Matrix不是旋转矩阵。\n");
   
    m_IsIdentity = false;
    m_IsUniformScale = true;
    
	Modification(rotate, APoint{ scale, scale, scale });
}

const Rendering::TransformMatrix::Matrix Rendering::TransformMatrix ::GetMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Matrix;
}

int Rendering::TransformMatrix
    ::GetStreamingSize () const
{
    return MATHEMATICS_STREAM_SIZE(m_Matrix) + CORE_TOOLS_STREAM_SIZE(m_IsIdentity) * 3;
}

#include STSTEM_WARNING_POP