// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/18 14:58)

#include "Rendering/RenderingExport.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "TransformImpl.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/ClassInvariant/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const Rendering::TransformImpl Rendering::TransformImpl
        ::sm_Identity;

Rendering::TransformImpl
    ::TransformImpl() noexcept
	:m_TransformMatrix{}, m_RotationOrGeneralMatrix{ Mathematics::MatrixTypeFlags::Identity },
	 m_Translate{ 0.0f, 0.0f, 0.0f }, m_Scale{ 1.0f, 1.0f, 1.0f },
	 m_InverseMatrix{ Mathematics::MatrixTypeFlags::Identity }, m_InverseNeedsUpdate{ false }
{	
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,TransformImpl)

void Rendering::TransformImpl
    ::MakeIdentity () noexcept
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_RotationOrGeneralMatrix = Matrix::sm_Identity;
	m_Translate = APoint{ 0.0f, 0.0f, 0.0f };
	m_Scale = APoint{ 1.0f, 1.0f, 1.0f };
    
    m_TransformMatrix.MakeIdentity();
  
    m_InverseNeedsUpdate = true;
}

void Rendering::TransformImpl
    ::MakeUnitScale ()
{
    RENDERING_CLASS_IS_VALID_9;
    
	m_Scale = APoint{ 1.0f, 1.0f, 1.0f };
    
    m_TransformMatrix.MakeUnitScale(m_RotationOrGeneralMatrix);
    
    m_InverseNeedsUpdate = true;
}

bool Rendering::TransformImpl ::IsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TransformMatrix.IsIdentity ();
}

bool Rendering::TransformImpl ::IsRotationOrScaleMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TransformMatrix.IsRotationOrScaleMatrix();
}

bool Rendering::TransformImpl ::IsUniformScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TransformMatrix.IsUniformScale();
}

void Rendering::TransformImpl
    ::SetRotate (const Matrix& rotate)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_RotationOrGeneralMatrix = rotate;
    
    m_TransformMatrix.SetRotate(m_RotationOrGeneralMatrix,m_Scale);
    
    m_InverseNeedsUpdate = true;
}

void Rendering::TransformImpl
    ::SetMatrix (const Matrix& matrix)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_RotationOrGeneralMatrix = matrix;
    
    m_TransformMatrix.SetMatrix(matrix);
    
    m_InverseNeedsUpdate = true;
}

void Rendering::TransformImpl
    ::SetTranslate (const APoint& translate)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_Translate = translate;
    
    m_TransformMatrix.SetTranslate(m_Translate);
    
    m_InverseNeedsUpdate = true;
}

void Rendering::TransformImpl
    ::SetScale (const APoint& scale)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_Scale = scale;
    
    m_TransformMatrix.SetScale(m_RotationOrGeneralMatrix,m_Scale);
    
    m_InverseNeedsUpdate = true;
}

void Rendering::TransformImpl
    ::SetUniformScale (float scale)
{
    RENDERING_CLASS_IS_VALID_9;
    
	m_Scale = APoint{ scale, scale, scale };
  
    m_TransformMatrix.SetUniformScale(m_RotationOrGeneralMatrix,m_Scale[0]);
    
    m_InverseNeedsUpdate = true;
}

const Rendering::TransformImpl::Matrix Rendering::TransformImpl
    ::GetRotate () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(m_TransformMatrix.IsRotationOrScaleMatrix(),"Matrix不是旋转矩阵\n");

    CoreTools::DoNothing();
    
    return m_RotationOrGeneralMatrix;
}

const Rendering::TransformImpl::Matrix Rendering::TransformImpl
    ::GetMatrix () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_RotationOrGeneralMatrix;
}

const Rendering::TransformImpl::APoint Rendering::TransformImpl ::GetTranslate() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Translate;
}

const Rendering::TransformImpl::APoint Rendering::TransformImpl
    ::GetScale () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(m_TransformMatrix.IsRotationOrScaleMatrix(),"Matrix不是旋转矩阵\n");
    CoreTools::DoNothing();
    return m_Scale;
}

float Rendering::TransformImpl
    ::GetUniformScale () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(m_TransformMatrix.IsRotationOrScaleMatrix(),"Matrix不是旋转矩阵\n");
    RENDERING_ASSERTION_1(m_TransformMatrix.IsUniformScale(),"Matrix不是单位缩放\n");
    
    return m_Scale[0];
}

float Rendering::TransformImpl
    ::GetNorm () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    if (m_TransformMatrix.IsRotationOrScaleMatrix())
    {
        auto maxValue = Mathematics::Mathf::FAbs(m_Scale[0]);
        if (maxValue < Mathematics::Mathf::FAbs(m_Scale[1]))
        {
            maxValue = Mathematics::Mathf::FAbs(m_Scale[1]);
        }
        if (maxValue < Mathematics::Mathf::FAbs(m_Scale[2]))
        {
            maxValue = Mathematics::Mathf::FAbs(m_Scale[2]);
        }
        return maxValue;
    }
 
    // 一般的矩阵。使用max-row-sum矩阵规范。
    // 光谱规范(最大特征值的绝对值)小于或等于这个规范。
    // 因此,这个函数返回一个近似的最大缩放。
	auto maxRowSum = Mathematics::Mathf::FAbs(m_RotationOrGeneralMatrix(0,0)) +
					 Mathematics::Mathf::FAbs(m_RotationOrGeneralMatrix(0,1)) +
					 Mathematics::Mathf::FAbs(m_RotationOrGeneralMatrix(0,2));
    
	auto rowSum = Mathematics::Mathf::FAbs(m_RotationOrGeneralMatrix(1,0)) +
				  Mathematics::Mathf::FAbs(m_RotationOrGeneralMatrix(1,1)) +
				  Mathematics::Mathf::FAbs(m_RotationOrGeneralMatrix(1,2));
    
    if (maxRowSum < rowSum)
    {
        maxRowSum = rowSum;
    }
    
    rowSum = Mathematics::Mathf::FAbs(m_RotationOrGeneralMatrix(2,0)) +
			 Mathematics::Mathf::FAbs(m_RotationOrGeneralMatrix(2,1)) +
			 Mathematics::Mathf::FAbs(m_RotationOrGeneralMatrix(2,2));
    
    if (maxRowSum < rowSum)
    {
        maxRowSum = rowSum;
    }
    
    return maxRowSum;
}

Rendering::TransformImpl::APoint Rendering::TransformImpl
    ::operator* (const APoint& point) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TransformMatrix.GetMatrix() * point;
}

Rendering::TransformImpl::AVector Rendering::TransformImpl
    ::operator* (const AVector& vector) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TransformMatrix.GetMatrix() * vector;
}

Rendering::TransformImpl& Rendering::TransformImpl
    ::operator*= (const TransformImpl& transform)
{
    RENDERING_CLASS_IS_VALID_9;
    
    *this = *this * transform;
    
    return *this;
}

const Rendering::TransformImpl::Matrix Rendering::TransformImpl ::GetHomogeneousMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TransformMatrix.GetMatrix();
}

const Rendering::TransformImpl::Matrix Rendering::TransformImpl
    ::GetInverseMatrix (float epsilon) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    if (m_InverseNeedsUpdate)
    {
        if (m_TransformMatrix.IsIdentity ())
        {
            m_InverseMatrix = Matrix::sm_Identity;
        }
        else
        {
            if (m_TransformMatrix.IsRotationOrScaleMatrix())
            {
                if (m_TransformMatrix.IsUniformScale())
                {
					auto invScale = 1.0f / m_Scale[0];
                    m_InverseMatrix(0,0) = invScale * m_RotationOrGeneralMatrix(0,0);
                    m_InverseMatrix(0,1) = invScale * m_RotationOrGeneralMatrix(1,0);
                    m_InverseMatrix(0,2) = invScale * m_RotationOrGeneralMatrix(2,0);
                    m_InverseMatrix(1,0) = invScale * m_RotationOrGeneralMatrix(0,1);
                    m_InverseMatrix(1,1) = invScale * m_RotationOrGeneralMatrix(1,1);
                    m_InverseMatrix(1,2) = invScale * m_RotationOrGeneralMatrix(2,1);
                    m_InverseMatrix(2,0) = invScale * m_RotationOrGeneralMatrix(0,2);
                    m_InverseMatrix(2,1) = invScale * m_RotationOrGeneralMatrix(1,2);
                    m_InverseMatrix(2,2) = invScale * m_RotationOrGeneralMatrix(2,2);
                }
                else
                {
					auto scale01 = m_Scale[0] * m_Scale[1];
					auto scale02 = m_Scale[0] * m_Scale[2];
					auto scale12 = m_Scale[1] * m_Scale[2];
					const auto inverseScale012 = 1.0f / (scale01 * m_Scale[2]);
					auto inverseScale0 = scale12 * inverseScale012;
					auto inverseScale1 = scale02 * inverseScale012;
					auto inverseScale2 = scale01 * inverseScale012;
                    
                    m_InverseMatrix(0,0) = inverseScale0 * m_RotationOrGeneralMatrix(0,0);
                    m_InverseMatrix(0,1) = inverseScale0 * m_RotationOrGeneralMatrix(1,0);
                    m_InverseMatrix(0,2) = inverseScale0 * m_RotationOrGeneralMatrix(2,0);
                    m_InverseMatrix(1,0) = inverseScale1 * m_RotationOrGeneralMatrix(0,1);
                    m_InverseMatrix(1,1) = inverseScale1 * m_RotationOrGeneralMatrix(1,1);
                    m_InverseMatrix(1,2) = inverseScale1 * m_RotationOrGeneralMatrix(2,1);
                    m_InverseMatrix(2,0) = inverseScale2 * m_RotationOrGeneralMatrix(0,2);
                    m_InverseMatrix(2,1) = inverseScale2 * m_RotationOrGeneralMatrix(1,2);
                    m_InverseMatrix(2,2) = inverseScale2 * m_RotationOrGeneralMatrix(2,2);
                }
            }
            else
            {
                m_InverseMatrix = m_RotationOrGeneralMatrix.Invert3x3(epsilon);
            }
            
            m_InverseMatrix(0,3) = -(m_InverseMatrix(0,0) * m_Translate[0] +
                                     m_InverseMatrix(0,1) * m_Translate[1] +
                                     m_InverseMatrix(0,2) * m_Translate[2]);
            
            m_InverseMatrix(1,3) = -(m_InverseMatrix(1,0) * m_Translate[0] +
                                     m_InverseMatrix(1,1) * m_Translate[1] +
                                     m_InverseMatrix(1,2) * m_Translate[2]);
            
            m_InverseMatrix(2,3) = -(m_InverseMatrix(2,0) * m_Translate[0] +
                                     m_InverseMatrix(2,1) * m_Translate[1] +
                                     m_InverseMatrix (2,2) * m_Translate[2]);
            
 
            // 对于一个仿射变换，m_Matrix的最后一行总是(0,0,0,1)。
            // 所以在构造函数中设置一次。没有必要在这里重置。
        }
        
        m_InverseNeedsUpdate = false;
    }
    
    return m_InverseMatrix;
}

const Rendering::TransformImpl Rendering::TransformImpl
    ::GetInverseTransform (float epsilon) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    if (m_TransformMatrix.IsIdentity ())
    {
        return sm_Identity;
    }
    
    TransformImpl inverse;
    APoint inverseTransform;
    if (m_TransformMatrix.IsRotationOrScaleMatrix())
    {
        const auto inverseRotation = m_RotationOrGeneralMatrix.Transpose();
        inverse.SetRotate(inverseRotation);
        if (m_TransformMatrix.IsUniformScale())
        {
            const auto inverseScale = 1.0f / m_Scale[0];
            inverse.SetUniformScale(inverseScale);
            inverseTransform = -inverseScale * (inverseRotation * m_Translate);
        }
        else
        {
			// Transform 是 Y = M * X + T，M = R * S
			// 逆方向是X = S^{-1} * R^t * (Y - T)，
			// 无法表示为X = (R * S) * Y + T，
			// 只能表示为X = (S * R) * Y + T

			const auto matrix = m_RotationOrGeneralMatrix * Matrix(m_Scale[0], m_Scale[1], m_Scale[2]);
                        const auto inverseMatrix = matrix.Invert3x3(epsilon);

			inverse.SetMatrix(inverseMatrix);		

 			inverseTransform = -(inverseMatrix * m_Translate);
        }
    }
    else
    {
        const auto inverseMatrix = m_RotationOrGeneralMatrix.Invert3x3(epsilon);
        
        inverse.SetMatrix(inverseMatrix);
        inverseTransform = -(inverseMatrix * m_Translate);
    }
    
    inverse.SetTranslate(inverseTransform);
    
    return inverse;
}

int Rendering::TransformImpl
    ::GetStreamingSize () const
{
    const auto isIdentity = m_TransformMatrix.IsIdentity();
    const auto isRotationOrScaleMatrix = m_TransformMatrix.IsRotationOrScaleMatrix();
    const auto isUniformScale = m_TransformMatrix.IsUniformScale();
	
	auto size = CORE_TOOLS_STREAM_SIZE(isIdentity) * 3;

	if(isIdentity)
	{
		return size;
	}
	else if(isRotationOrScaleMatrix)
	{
		if(isUniformScale)
		{
			size += MATHEMATICS_STREAM_SIZE(m_RotationOrGeneralMatrix);
			size += CORE_TOOLS_STREAM_SIZE(m_Scale[0]);
			size += MATHEMATICS_STREAM_SIZE(m_Translate);
			
			return size;
		}
		else
		{
			size += MATHEMATICS_STREAM_SIZE(m_RotationOrGeneralMatrix);
			size += MATHEMATICS_STREAM_SIZE(m_Scale);
			size += MATHEMATICS_STREAM_SIZE(m_Translate);

			return size;			
		}
	}
	else
	{
		size += MATHEMATICS_STREAM_SIZE(m_RotationOrGeneralMatrix);
		size += MATHEMATICS_STREAM_SIZE(m_Translate);

		return size;			
	}
}

const Rendering::TransformImpl  Rendering
    ::operator* (const TransformImpl& lhs,const TransformImpl& rhs)
{
    if (lhs.IsIdentity())
    {
        return rhs;
    }

    if (rhs.IsIdentity())
    {
        return lhs;
    }

    TransformImpl product;
	
    if (lhs.IsRotationOrScaleMatrix() && rhs.IsRotationOrScaleMatrix())
    {
        if (lhs.IsUniformScale())
        {
            product.SetRotate(lhs.GetMatrix() * rhs.GetMatrix());

            product.SetTranslate(lhs.GetUniformScale() * (lhs.GetMatrix() * rhs.GetTranslate ()) + lhs.GetTranslate ());

            if (rhs.IsUniformScale())
            {
                product.SetUniformScale(lhs.GetUniformScale() * rhs.GetUniformScale());
            }
            else
            {
                product.SetScale(lhs.GetUniformScale() * rhs.GetScale());
            }

            return product;
        }
    }


    // 在所有剩余的情况下,不能写成矩阵R * S * X+T。
    const auto matrixA = (lhs.IsRotationOrScaleMatrix() ? lhs.GetMatrix().TimesDiagonal(lhs.GetScale()) : lhs.GetMatrix());
    const auto matrixB = (rhs.IsRotationOrScaleMatrix() ? rhs.GetMatrix().TimesDiagonal(rhs.GetScale()) : rhs.GetMatrix());

    product.SetMatrix(matrixA * matrixB);
    product.SetTranslate(matrixA * rhs.GetTranslate () + lhs.GetTranslate ());
    
    return product;
}

#include STSTEM_WARNING_POP