// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/18 15:43)

#include "Rendering/RenderingExport.h"

#include "Transform.h"
#include "Detail/TransformImpl.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

const Rendering::Transform Rendering::Transform
	::sm_Identity;

Rendering::Transform
    ::Transform()
	:m_Impl{ make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,Transform)

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering,Transform)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, MakeIdentity,void);

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, MakeUnitScale,void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, IsIdentity,bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, IsRotationOrScaleMatrix,bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, IsUniformScale,bool);

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Transform, SetRotate,Matrix,void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Transform, SetMatrix,Matrix,void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Transform,  SetTranslate,APoint,void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Transform, SetScale,APoint,void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Transform,  SetUniformScale,float,void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, GetRotate,  const Rendering::Transform::Matrix);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, GetMatrix,  const Rendering::Transform::Matrix);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, GetTranslate, const Rendering::Transform::APoint);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, GetScale, const Rendering::Transform::APoint);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, GetUniformScale,float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform, GetNorm,float);

Rendering::Transform::APoint Rendering::Transform
    ::operator* (const APoint& point) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return (*m_Impl) * point;
}

Rendering::Transform::AVector Rendering::Transform
    ::operator* (const AVector& vector) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return (*m_Impl) * vector;
}

Rendering::Transform& Rendering::Transform
    ::operator*= (const Transform& transform)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;
    
    *m_Impl *= *transform.m_Impl;
    
    return *this;
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Transform,GetHomogeneousMatrix,const Rendering::Transform::Matrix);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Transform,GetInverseMatrix,float, const Rendering::Transform::Matrix);

const Rendering::Transform Rendering::Transform
    ::GetInverseTransform (float epsilon) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    Transform transform;
    
    *transform.m_Impl = m_Impl->GetInverseTransform(epsilon);

	return transform;
}

int Rendering::Transform
    ::GetStreamingSize () const
{
    return m_Impl->GetStreamingSize ();
}

const Rendering::Transform Rendering
    ::operator* (const Transform& lhs, const Transform& rhs)
{
	Transform result{ lhs };
    
    result *= rhs;
    
    return result;
}

bool Rendering
    ::Approximate(const Transform& lhs, const Transform& rhs, const float epsilon)
{
	auto lhsIsIdentity = lhs.IsIdentity ();  
	auto lhsIsRotationOrScaleMatrix = lhs.IsRotationOrScaleMatrix ();
	auto lhsIsUniformScale = lhs.IsUniformScale ();

	auto rhsIsIdentity = rhs.IsIdentity ();
	auto rhsIsRotationOrScaleMatrix = rhs.IsRotationOrScaleMatrix ();
	auto rhsIsUniformScale = rhs.IsUniformScale ();

	if(lhsIsIdentity != rhsIsIdentity || lhsIsRotationOrScaleMatrix != rhsIsRotationOrScaleMatrix || lhsIsUniformScale != rhsIsUniformScale)
    {
        return false;
    }
    else if(lhsIsIdentity && rhsIsIdentity)
    {
        return true;
    }
    else if(lhsIsRotationOrScaleMatrix && rhsIsRotationOrScaleMatrix)
    {
	    if(lhsIsUniformScale && rhsIsUniformScale)
	    {
			if (Approximate(lhs.GetRotate(), rhs.GetRotate(), epsilon) && Mathematics::Mathf::Approximate(lhs.GetUniformScale(), rhs.GetUniformScale(), epsilon) &&
				Approximate(lhs.GetTranslate(), rhs.GetTranslate(), epsilon))
			{
				return true;
			}               
			else
			{
				return false;
			}
                
	    }
	    else
	    {
	       if(Approximate(lhs.GetRotate (),rhs.GetRotate (),epsilon) && Approximate(lhs.GetScale (),rhs.GetScale (),epsilon) && Approximate(lhs.GetTranslate (),rhs.GetTranslate (),epsilon))
                return true;
           else
                return false;  
	    }
    }
	else
	{
        if(Approximate(lhs.GetMatrix (),rhs.GetMatrix (),epsilon) && Approximate(lhs.GetTranslate (),rhs.GetTranslate (),epsilon) )
            return true;
        else
            return false;   
	} 
	}

std::ostream& Rendering
	::operator<<(std::ostream& outFile, const Transform& transform) 
{
	if(transform.IsRotationOrScaleMatrix())
	{
		outFile << "Rotate:" << transform.GetRotate() << "°°";
		outFile << "Translate:" << transform.GetTranslate() << "°°";
		outFile << "Scale:" << transform.GetScale() << "°°";
	}
	else
	{
		outFile << "Rotate:" << transform.GetMatrix() << "°°";
		outFile << "Translate:" << transform.GetTranslate() << "°°";	
	}		

	return outFile;
}
