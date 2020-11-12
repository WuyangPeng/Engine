// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 13:49)

#include "Rendering/RenderingExport.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "IKJointImpl.h"

#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/DataTypes/TransformDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
using std::string;
using std::vector;

Rendering::IKJointImpl ::IKJointImpl() noexcept
    : m_Object{}, m_Goals{}
{
    Init(); 

	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::IKJointImpl
	::IKJointImpl( const SpatialSharedPtr& object,const IKGoalSharedPtrVector& goals )
	:m_Object{ object }, m_Goals{ goals }
{
	Init();

	RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::IKJointImpl
	::Init() noexcept
{
	for (auto i = 0; i < sm_NumAxis; ++i)
	{
		m_AllowTranslation[i] = false;
		m_MinTranslation[i] = -Mathematics::FloatMath::sm_MaxReal;
		m_MaxTranslation[i] = Mathematics::FloatMath::sm_MaxReal;
		m_AllowRotation[i] = false;
		m_MinRotation[i] = -Mathematics::FloatMath::GetPI();
		m_MaxRotation[i] = Mathematics::FloatMath::GetPI();
	}
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,IKJointImpl)

int Rendering::IKJointImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size =  sm_NumAxis * CORE_TOOLS_STREAM_SIZE(m_AllowTranslation[0]);
	size += sm_NumAxis * CORE_TOOLS_STREAM_SIZE(m_MinTranslation[0]);
	size += sm_NumAxis * CORE_TOOLS_STREAM_SIZE(m_MaxTranslation[0]);
	size += sm_NumAxis * CORE_TOOLS_STREAM_SIZE(m_AllowRotation[0]);
	size += sm_NumAxis * CORE_TOOLS_STREAM_SIZE(m_MinRotation[0]);
	size += sm_NumAxis * CORE_TOOLS_STREAM_SIZE(m_MaxRotation[0]);
	size += CORE_TOOLS_STREAM_SIZE(m_Object);
	size += CORE_TOOLS_STREAM_SIZE(boost::numeric_cast<int>(m_Goals.size()));

	if (!m_Goals.empty())
	{
		size += boost::numeric_cast<int>(m_Goals.size() * CORE_TOOLS_STREAM_SIZE(m_Goals[0]));
	}
		
	return size;
}

void Rendering::IKJointImpl
	::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    CoreTools::DisableNoexcept();
    target;
	//target.WriteBoolWithoutNumber(sm_NumAxis, m_AllowTranslation);
	//target.WriteWithoutNumber(sm_NumAxis, m_MinTranslation);
	//target.WriteWithoutNumber(sm_NumAxis, m_MaxTranslation);
	//target.WriteBoolWithoutNumber(sm_NumAxis, m_AllowRotation);
	//target.WriteWithoutNumber(sm_NumAxis, m_MinRotation);
	//target.WriteWithoutNumber(sm_NumAxis, m_MaxRotation);
//	target.WriteSharedPtr(m_Object);
	//target.WriteSharedPtrWithNumber(boost::numeric_cast<int>(m_Goals.size()), &m_Goals[0]);
}

void Rendering::IKJointImpl
	::Load( const CoreTools::BufferSourceSharedPtr& source )
{
	RENDERING_CLASS_IS_VALID_9;

//	source->ReadBool(sm_NumAxis, m_AllowTranslation);
       // source->Read(sm_NumAxis, m_MinTranslation);
       // source->Read(sm_NumAxis, m_MaxTranslation);
     //   source->ReadBool(sm_NumAxis, m_AllowRotation);
       // source->Read(sm_NumAxis, m_MinRotation);
       // source->Read(sm_NumAxis, m_MaxRotation);
        //	source.ReadSharedPtr(m_Object);

	int size{ 0 };
        source->Read(size);
	if(0 < size)
	{
		m_Goals.resize(size);
		//source.ReadSharedPtr(size, &m_Goals[0]);
	}	
}

void Rendering::IKJointImpl
	::Link(const  CoreTools::ObjectLinkSharedPtr& source )
{
	RENDERING_CLASS_IS_VALID_9;
    source;
        CoreTools::DisableNoexcept();
    // 	source.ResolveObjectSharedPtrLink(m_Object);
//	source.ResolveObjectSharedPtrLink(boost::numeric_cast<int>(m_Goals.size()), &m_Goals[0]);
}

void Rendering::IKJointImpl
	::Register( const CoreTools::ObjectRegisterSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
        CoreTools::DisableNoexcept();
    //	target.RegisterSharedPtr(m_Object);
//	target.RegisterSharedPtr(boost::numeric_cast<int>(m_Goals.size()), &m_Goals[0]);
}

const CoreTools::ObjectSharedPtr Rendering::IKJointImpl
	::GetObjectByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_9;

	auto object = m_Object->GetObjectByName(name);

	if (object != nullptr)
		return object;
	else 
	{
		for(auto& pointer:m_Goals)
		{
			object = pointer->GetObjectByName(name);
			
			if (object != nullptr)
			{
				return object;
			}				
		}

		return CoreTools::ObjectSharedPtr{};
	}		
}

const vector<CoreTools::ObjectSharedPtr> Rendering::IKJointImpl
	::GetAllObjectsByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_9;

	auto objects = m_Object->GetAllObjectsByName(name);
	 
	for (auto& pointer : m_Goals)
	{
		auto pointerObjects = pointer->GetAllObjectsByName(name);
		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());		
	}

	return objects;
}

const CoreTools::ConstObjectSharedPtr Rendering::IKJointImpl
	::GetConstObjectByName( const string& name ) const
{
	RENDERING_CLASS_IS_VALID_9;

	auto object = m_Object->GetConstObjectByName(name);

	if (object != nullptr)
	{
		return object;
	}	
	else 
	{
		for (auto& pointer : m_Goals)
		{
			object = pointer->GetConstObjectByName(name);
			if (object != nullptr)
			{
				return object;
			}				
		}

		return CoreTools::ConstObjectSharedPtr{};
	}		
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::IKJointImpl
	::GetAllConstObjectsByName( const string& name ) const
{
	RENDERING_CLASS_IS_VALID_9;

	auto objects = m_Object->GetAllConstObjectsByName(name);

	for (const auto& pointer:m_Goals)
	{
		auto pointerObjects = pointer->GetAllConstObjectsByName(name);
		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());		
	}

	return objects;
}

const Rendering::IKJointImpl::AVector Rendering::IKJointImpl
	::GetAxis( MatrixRotationAxis axisIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	const Rendering::Spatial* const parent = m_Object->GetParent();
	if (parent != nullptr)
	{
            return AVector{ parent->GetWorldTransform().GetRotate().GetColumn(System::EnumCastUnderlying(axisIndex)) };		 
	}
	else if (axisIndex == Mathematics::MatrixRotationAxis::X)
	{
		return Mathematics::FloatAVector::GetUnitX();
	}
	else if (axisIndex == Mathematics::MatrixRotationAxis::Y)
	{
            return Mathematics::FloatAVector::GetUnitY(); 
	}
	else  //  axisIndex == MatrixRotationAxis::Z
	{
            return Mathematics::FloatAVector::GetUnitZ();  
	}
}

void Rendering::IKJointImpl
	::UpdateWorldTransform()
{
	RENDERING_CLASS_IS_VALID_9;

	const Rendering::Spatial* const parent = m_Object->GetParent();
	if (parent != nullptr)
	{
		m_Object->SetWorldTransform(parent->GetWorldTransform() * m_Object->GetLocalTransform());		
	}
	else
	{
		m_Object->SetWorldTransform(m_Object->GetLocalTransform());
	}
}

void Rendering::IKJointImpl
	::UpdateWorldRotateAndTranslate()
{
	RENDERING_CLASS_IS_VALID_9;

	const Rendering::Spatial* const parent = m_Object->GetParent();
	if (parent != nullptr)
	{
		auto transform = m_Object->GetWorldTransform();

		const auto rotate = parent->GetWorldTransform().GetRotate() * m_Object->GetLocalTransform().GetRotate();
		transform.SetRotate(rotate);

		auto translate = parent->GetWorldTransform() * m_Object->GetLocalTransform().GetTranslate();

		transform.SetTranslate(translate);
		m_Object->SetWorldTransform(transform);
	}
	else
	{
		auto transform = m_Object->GetWorldTransform();

		transform.SetRotate(m_Object->GetLocalTransform().GetRotate());
		transform.SetTranslate(m_Object->GetLocalTransform().GetTranslate());
		m_Object->SetWorldTransform(transform);
	}
}

bool Rendering::IKJointImpl
	::UpdateLocalTranslate( MatrixRotationAxis axisIndex )
{
	RENDERING_CLASS_IS_VALID_9;

	auto axis = GetAxis(axisIndex);
	 
	auto oldNorm = 0.0f;
	auto numer = 0.0f;
	auto denom = 0.0f;
	for(const auto& goal: m_Goals)
	{	 
		auto goalMinusEffector = goal->GetTargetPosition() - goal->GetEffectorPosition();
		oldNorm += goalMinusEffector.SquaredLength();
		numer += goal->GetWeight() * Dot(axis,goalMinusEffector);
		denom += goal->GetWeight();
	}

	if (Mathematics::FloatMath::FAbs(denom) <= Mathematics::FloatMath::GetZeroTolerance())
	{
		// 权重太小，没有转换。
		return false;
	}

	// 所需沿axis(i) 转换的距离。
	auto distance = numer / denom;

	// 截断到范围
	auto translate = m_Object->GetLocalTransform().GetTranslate();
	auto desired = translate[System::EnumCastUnderlying(axisIndex)] + distance;
	if (desired > m_MinTranslation[System::EnumCastUnderlying(axisIndex)])
	{
		if (desired < m_MaxTranslation[System::EnumCastUnderlying(axisIndex)])
		{
			translate[System::EnumCastUnderlying(axisIndex)] = desired;
		}
		else
		{
			distance = m_MaxTranslation[System::EnumCastUnderlying(axisIndex)] - translate[System::EnumCastUnderlying(axisIndex)];
			translate[System::EnumCastUnderlying(axisIndex)] = m_MaxTranslation[System::EnumCastUnderlying(axisIndex)];
		}
	}
	else
	{
		distance = m_MinTranslation[System::EnumCastUnderlying(axisIndex)] - translate[System::EnumCastUnderlying(axisIndex)];
		translate[System::EnumCastUnderlying(axisIndex)] = m_MinTranslation[System::EnumCastUnderlying(axisIndex)];
	}

	// 测试步骤是否应该采取。
	auto newNorm = 0.0f;
	auto step = distance * axis;
	for(const auto& goal: m_Goals)
	{
		auto newEffector = goal->GetEffectorPosition() + step;
		auto difference = goal->GetTargetPosition() - newEffector;
		newNorm += difference.SquaredLength();
	}
	if (oldNorm <= newNorm)
	{
		// 转换并没有得到更接近目标的效果。
		return false;
	}

	// 更新本地的转换。
	m_Object->SetLocalTransformTranslate(translate);

	return true;
}

bool Rendering::IKJointImpl
	::UpdateLocalRotate( MatrixRotationAxis axisIndex )
{
	RENDERING_CLASS_IS_VALID_9;

	auto axis = GetAxis(axisIndex);

	auto numer = 0.0f;
	auto denom = 0.0f;
	auto oldNorm = 0.0f;

	for(const auto& goal: m_Goals)
	{
		auto effectorMinusPoint = goal->GetEffectorPosition() - m_Object->GetWorldTransform().GetTranslate();
		auto goalMinusPoint = goal->GetTargetPosition() - m_Object->GetWorldTransform().GetTranslate();
		auto goalMinusEffector = goal->GetTargetPosition() - goal->GetEffectorPosition();
		oldNorm += goalMinusEffector.SquaredLength();
		auto axisCrossEffectorMinusPoint = Cross(axis,effectorMinusPoint);
		auto axisCrossAxisCrossEffectorMinusPoint = Cross(axis,axisCrossEffectorMinusPoint);
		numer += goal->GetWeight() * Dot(goalMinusPoint,axisCrossEffectorMinusPoint);
		denom -= goal->GetWeight() * Dot(goalMinusPoint,axisCrossAxisCrossEffectorMinusPoint);
	}

	if (numer * numer + denom * denom <= Mathematics::FloatMath::GetZeroTolerance())
	{
		// 未定义 atan2,不旋转。
		return false;
	}

    // 所需角度绕axis(i)旋转。
	auto theta = Mathematics::FloatMath::ATan2(numer, denom);

	// 局部因子旋转欧拉角。
	auto rotate = m_Object->GetLocalTransform().GetRotate();
	auto rotateMatrix3 = rotate.GetMatrix3();
	auto euler = rotateMatrix3.ExtractEulerZYX();
	 
	// 截断到范围
	auto desired = euler.GetAngle(axisIndex) + theta;
	if (desired > m_MinRotation[System::EnumCastUnderlying(axisIndex)])
	{
		if (desired < m_MaxRotation[System::EnumCastUnderlying(axisIndex)])
		{
			euler.SetAngle(axisIndex, desired);
		}
		else
		{
			theta = m_MaxRotation[System::EnumCastUnderlying(axisIndex)] - euler.GetAngle(axisIndex);
			euler.SetAngle(axisIndex, m_MaxRotation[System::EnumCastUnderlying(axisIndex)]);
		}
	}
	else
	{
		theta = m_MinRotation[System::EnumCastUnderlying(axisIndex)] - euler.GetAngle(axisIndex);
		euler.SetAngle(axisIndex, m_MinRotation[System::EnumCastUnderlying(axisIndex)]);
	}

	// 测试步骤是否应该采取。
	auto newNorm = 0.0f;
	rotate.MakeRotation(axis, theta);
	for(const auto& goal: m_Goals)
	{	 
		auto effectorMinusPoint = goal->GetEffectorPosition() - m_Object->GetWorldTransform().GetTranslate();
		auto newEffector = m_Object->GetWorldTransform().GetTranslate() + rotate * effectorMinusPoint;
		auto goalMinusEffector = goal->GetTargetPosition() - newEffector;
		newNorm += goalMinusEffector.SquaredLength();
	}

	if (oldNorm <= newNorm)
	{
		// 旋转并没有得到更接近目标的效果。
		return false;
	}

	// 更新局部旋转
	rotateMatrix3.MakeEulerZYX(euler.GetZ0Angle(), euler.GetY0Angle(), euler.GetX0Angle());

	rotate = Mathematics::FloatMatrix{ rotateMatrix3 };
	m_Object->SetLocalTransformRotate(rotate);

	return true;
}

const Rendering::ConstSpatialSharedPtr Rendering::IKJointImpl
	::GetObjectSharedPtr() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Object;
}

const Rendering::ConstIKGoalSharedPtr Rendering::IKJointImpl
	::GetGoalsSharedPtr(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Goals.size()), "索引错误！");

	return m_Goals[index];
}

int Rendering::IKJointImpl
	::GetGoalsNum() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Goals.size());
}

void Rendering::IKJointImpl
	::SetAllowTranslation(MatrixRotationAxis axisIndex, bool allowTranslation) 
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= System::EnumCastUnderlying(axisIndex) && System::EnumCastUnderlying(axisIndex) < sm_NumAxis, "索引错误！");

	m_AllowTranslation[System::EnumCastUnderlying(axisIndex)] = allowTranslation;
}

void Rendering::IKJointImpl 
	::SetAllowRotation(MatrixRotationAxis axisIndex, bool allowRotation) 
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= System::EnumCastUnderlying(axisIndex) && System::EnumCastUnderlying(axisIndex) < sm_NumAxis, "索引错误！");

	m_AllowRotation[System::EnumCastUnderlying(axisIndex)] = allowRotation;
}

bool Rendering::IKJointImpl
	::IsAllowTranslation(MatrixRotationAxis axisIndex) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= System::EnumCastUnderlying(axisIndex) && System::EnumCastUnderlying(axisIndex) < sm_NumAxis, "索引错误！");

	return m_AllowTranslation[System::EnumCastUnderlying(axisIndex)];
}

bool Rendering::IKJointImpl
	::IsAllowRotation(MatrixRotationAxis axisIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= System::EnumCastUnderlying(axisIndex) && System::EnumCastUnderlying(axisIndex) < sm_NumAxis, "索引错误！");

	return m_AllowRotation[System::EnumCastUnderlying(axisIndex)];
}
#include STSTEM_WARNING_POP