// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 13:49)

#include "Rendering/RenderingExport.h"

#include "IKJointImpl.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;
using std::vector;

Rendering::IKJointImpl
	::IKJointImpl()
	:m_Object{}, m_Goals{}
{
	Init();

	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::IKJointImpl
	::IKJointImpl( const SpatialSmartPointer& object,const IKGoalSmartPointerVector& goals )
	:m_Object{ object }, m_Goals{ goals }
{
	Init();

	RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::IKJointImpl
	::Init()
{
	for (auto i = 0; i < sm_NumAxis; ++i)
	{
		m_AllowTranslation[i] = false;
		m_MinTranslation[i] = -Mathematics::Mathf::sm_MaxReal;
		m_MaxTranslation[i] = Mathematics::Mathf::sm_MaxReal;
		m_AllowRotation[i] = false;
		m_MinRotation[i] = -Mathematics::Mathf::sm_PI;
		m_MaxRotation[i] = Mathematics::Mathf::sm_PI;
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
	::Save( CoreTools::BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteBoolWithoutNumber(sm_NumAxis, m_AllowTranslation);
	target.WriteWithoutNumber(sm_NumAxis, m_MinTranslation);
	target.WriteWithoutNumber(sm_NumAxis, m_MaxTranslation);
	target.WriteBoolWithoutNumber(sm_NumAxis, m_AllowRotation);
	target.WriteWithoutNumber(sm_NumAxis, m_MinRotation);
	target.WriteWithoutNumber(sm_NumAxis, m_MaxRotation);
	target.WriteSmartPointer(m_Object);
	target.WriteSmartPointerWithNumber(boost::numeric_cast<int>(m_Goals.size()), &m_Goals[0]);
}

void Rendering::IKJointImpl
	::Load( CoreTools::BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;

	source.ReadBool(sm_NumAxis, m_AllowTranslation);
	source.Read(sm_NumAxis, m_MinTranslation);
	source.Read(sm_NumAxis, m_MaxTranslation);
	source.ReadBool(sm_NumAxis, m_AllowRotation);
	source.Read(sm_NumAxis, m_MinRotation);
	source.Read(sm_NumAxis, m_MaxRotation);
	source.ReadSmartPointer(m_Object);

	int size{ 0 };
	source.Read(size);
	if(0 < size)
	{
		m_Goals.resize(size);
		source.ReadSmartPointer(size, &m_Goals[0]);
	}	
}

void Rendering::IKJointImpl
	::Link( CoreTools::ObjectLink& source )
{
	RENDERING_CLASS_IS_VALID_9;

	source.ResolveObjectSmartPointerLink(m_Object);
	source.ResolveObjectSmartPointerLink(boost::numeric_cast<int>(m_Goals.size()), &m_Goals[0]);
}

void Rendering::IKJointImpl
	::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.RegisterSmartPointer(m_Object);
	target.RegisterSmartPointer(boost::numeric_cast<int>(m_Goals.size()), &m_Goals[0]);
}

const CoreTools::ObjectSmartPointer Rendering::IKJointImpl
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

		return CoreTools::ObjectSmartPointer{};
	}		
}

const vector<CoreTools::ObjectSmartPointer> Rendering::IKJointImpl
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

const CoreTools::ConstObjectSmartPointer Rendering::IKJointImpl
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

		return CoreTools::ConstObjectSmartPointer{};
	}		
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::IKJointImpl
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

	auto parent = m_Object->GetParent();
	if (parent != nullptr)
	{
		return parent->GetWorldTransform().GetRotate().GetColumn((int)axisIndex);		 
	}
	else if (axisIndex == Mathematics::MatrixRotationAxis::X)
	{
		return AVector::sm_UnitX;
	}
	else if (axisIndex == Mathematics::MatrixRotationAxis::Y)
	{
		return AVector::sm_UnitY;
	}
	else  //  axisIndex == MatrixRotationAxis::Z
	{
		return AVector::sm_UnitZ;
	}
}

void Rendering::IKJointImpl
	::UpdateWorldTransform()
{
	RENDERING_CLASS_IS_VALID_9;

	auto parent = m_Object->GetParent();
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

	auto parent = m_Object->GetParent();
	if (parent != nullptr)
	{
		auto transform = m_Object->GetWorldTransform();

		auto rotate = parent->GetWorldTransform().GetRotate() * m_Object->GetLocalTransform().GetRotate();
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

	if (Mathematics::Mathf::FAbs(denom) <= Mathematics::Mathf::sm_ZeroTolerance)
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

	if (numer * numer + denom * denom <= Mathematics::Mathf::sm_ZeroTolerance)
	{
		// 未定义 atan2,不旋转。
		return false;
	}

    // 所需角度绕axis(i)旋转。
	auto theta = Mathematics::Mathf::ATan2(numer, denom);

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

	rotate = Mathematics::Matrixf{ rotateMatrix3 };
	m_Object->SetLocalTransformRotate(rotate);

	return true;
}

const Rendering::ConstSpatialSmartPointer Rendering::IKJointImpl
	::GetObjectSmartPointer() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Object.PolymorphicCastConstObjectSmartPointer<ConstSpatialSmartPointer>();
}

const Rendering::ConstIKGoalSmartPointer Rendering::IKJointImpl
	::GetGoalsSmartPointer(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Goals.size()), "索引错误！");

	return m_Goals[index].PolymorphicCastConstObjectSmartPointer<ConstIKGoalSmartPointer>();
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
