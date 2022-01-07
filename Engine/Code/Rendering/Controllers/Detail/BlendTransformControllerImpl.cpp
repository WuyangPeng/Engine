// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 10:42)

#include "Rendering/RenderingExport.h"

#include "BlendTransformControllerImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Contract/Noexcept.h"

using std::string;
using std::vector;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::BlendTransformControllerImpl
	::BlendTransformControllerImpl() noexcept
	:m_FirstController{}, m_SecondController{}, m_Weight{ 0.0f }, m_RotationScaleMatrices{ false }, m_GeometricRotation{ false }, m_GeometricScale{ false }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::BlendTransformControllerImpl
	::BlendTransformControllerImpl(const TransformControllerSharedPtr& firstController,const TransformControllerSharedPtr& secondController, 
								   bool rotationScaleMatrices, bool geometricRotation,bool geometricScale) noexcept
	:m_FirstController{ firstController },m_SecondController{ secondController },m_Weight{ 0.0f },
	 m_RotationScaleMatrices{ rotationScaleMatrices },m_GeometricRotation{ geometricRotation },m_GeometricScale{ geometricScale }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::BlendTransformControllerImpl
	::IsValid() const noexcept
{
	if (0.0f <= m_Weight && m_Weight <= 1.0f)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::BlendTransformControllerImpl
	::GetStreamingSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_FirstController);
	size += CORE_TOOLS_STREAM_SIZE(m_SecondController);
	size += CORE_TOOLS_STREAM_SIZE(m_Weight);
	size += CORE_TOOLS_STREAM_SIZE(m_RotationScaleMatrices);
	size += CORE_TOOLS_STREAM_SIZE(m_GeometricRotation);
	size += CORE_TOOLS_STREAM_SIZE(m_GeometricScale);

	return size;
}

void Rendering::BlendTransformControllerImpl
	::Save(CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	//target.WriteSharedPtr(m_FirstController);
	//target.WriteSharedPtr(m_SecondController);
	target.Write(m_Weight);
	target.Write(m_RotationScaleMatrices);
	target.Write(m_GeometricRotation);
	target.Write(m_GeometricScale);
}

void Rendering::BlendTransformControllerImpl
	::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;	 

//	source.ReadSharedPtr(m_FirstController);
//	source.ReadSharedPtr(m_SecondController);
        source.Read(m_Weight);
        m_RotationScaleMatrices = source.ReadBool();
        m_GeometricRotation = source.ReadBool();
        m_GeometricScale = source.ReadBool();
}

bool Rendering::BlendTransformControllerImpl ::IsGeometricRotation() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_GeometricRotation;
}

bool Rendering::BlendTransformControllerImpl ::IsGeometricScale() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_GeometricScale;
}

void Rendering::BlendTransformControllerImpl
	::Link(CoreTools::ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_1;
    CoreTools::DisableNoexcept();
    source;
    //	source.ResolveObjectSharedPtrLink(m_FirstController);
	//source.ResolveObjectSharedPtrLink(m_SecondController);
}

void Rendering::BlendTransformControllerImpl
	::Register(CoreTools::ObjectRegister& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    target;
        CoreTools::DisableNoexcept();
	//target.RegisterSharedPtr(m_FirstController);
	//target.RegisterSharedPtr(m_SecondController);
}

const CoreTools::ObjectSharedPtr Rendering::BlendTransformControllerImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	auto found = m_FirstController->GetObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}
	else
	{
		found = m_SecondController->GetObjectByName(name);

		if (found != nullptr)
		{
			return found;
		}
	}

	return CoreTools::ObjectSharedPtr();
}

const vector<CoreTools::ObjectSharedPtr> Rendering::BlendTransformControllerImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	auto firstObjects = m_FirstController->GetAllObjectsByName(name);
	auto secondObjects = m_FirstController->GetAllObjectsByName(name);

	firstObjects.insert(firstObjects.end(), secondObjects.begin(), secondObjects.end());

	return firstObjects;
}

const CoreTools::ConstObjectSharedPtr Rendering::BlendTransformControllerImpl
	::GetConstObjectByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto found = m_FirstController->GetConstObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}
	else
	{
		found = m_SecondController->GetConstObjectByName(name);

		if (found != nullptr)
		{
			return found;
		}
	}

	return CoreTools::ConstObjectSharedPtr();
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::BlendTransformControllerImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_1;

	auto firstObjects = m_FirstController->GetAllConstObjectsByName(name);
	auto secondObjects = m_FirstController->GetAllConstObjectsByName(name);

	firstObjects.insert(firstObjects.end(), secondObjects.begin(), secondObjects.end());

	return firstObjects;
}

const Rendering::ConstTransformControllerSharedPtr Rendering::BlendTransformControllerImpl ::GetFirstController() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_FirstController;
}

bool Rendering::BlendTransformControllerImpl ::IsRotationScaleMatrices() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_RotationScaleMatrices;
}

const Rendering::ConstTransformControllerSharedPtr Rendering::BlendTransformControllerImpl ::GetSecondController() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	
	return m_SecondController;
}

void Rendering::BlendTransformControllerImpl ::SetWeight(float weight) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_Weight = weight;
}

float Rendering::BlendTransformControllerImpl ::GetWeight() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Weight;
}

void Rendering::BlendTransformControllerImpl
	::SetObject(ControllerInterface* object)
{
	RENDERING_CLASS_IS_VALID_1;

	m_FirstController->SetObject(object);
	m_SecondController->SetObject(object);
}

bool Rendering::BlendTransformControllerImpl
	::Update(double applicationTime)
{
	RENDERING_CLASS_IS_VALID_1;

	m_FirstController->Update(applicationTime);
	m_SecondController->Update(applicationTime);

	return true;
}

const Rendering::BlendTransformControllerImpl::APoint Rendering::BlendTransformControllerImpl
	::GetBlendTranslate() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	const auto firstTransform = m_FirstController->GetTransform();
	const auto secondTransform = m_SecondController->GetTransform();
        const auto oneMinusWeight = 1.0f - m_Weight;

	// À„ ıªÏ∫œ◊™ªª°£
	const auto firstTranslate = firstTransform.GetTranslate();
	const auto secondTranslate = secondTransform.GetTranslate();
	auto blendTranslate = oneMinusWeight * firstTranslate + m_Weight * secondTranslate;

	return blendTranslate;
}

const Rendering::BlendTransformControllerImpl::Matrix Rendering::BlendTransformControllerImpl
	::GetBlendQuaternion() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	const auto firstTransform = m_FirstController->GetTransform();
	const auto secondTransform = m_SecondController->GetTransform();

	const auto firstRotate = firstTransform.GetRotate();
	const auto secondRotate = secondTransform.GetRotate();

	const Mathematics::FloatAQuaternion firstQuaternion{ firstRotate };
        const Mathematics::FloatAQuaternion secondQuaternion{ secondRotate };
	if (Dot(firstQuaternion,secondQuaternion) < 0.0f)
	{
		//secondQuaternion = -secondQuaternion;
	}

	Mathematics::FloatAQuaternion blendQuaternion;

	if (m_GeometricRotation)
	{
		blendQuaternion.Slerp(m_Weight, firstQuaternion, secondQuaternion);
	}
	else
	{
		const auto oneMinusWeight = 1.0f - m_Weight;
		blendQuaternion = oneMinusWeight * firstQuaternion + m_Weight * secondQuaternion;
		blendQuaternion.Normalize();
	}

	return blendQuaternion.ToRotationMatrix();
}

const Rendering::BlendTransformControllerImpl::APoint Rendering::BlendTransformControllerImpl
	::GetBlendScale() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	const auto firstTransform = m_FirstController->GetTransform();
	const auto secondTransform = m_SecondController->GetTransform();

	auto firstScale = firstTransform.GetScale();
	auto secondScale = secondTransform.GetScale();
 
	APoint blendScale;

	const auto oneMinusWeight = 1.0f - m_Weight;

	if (m_GeometricScale)
	{
		for (auto i = 0; i < 3; ++i)
		{
			auto s0 = firstScale[i];
			auto s1 = secondScale[i];
			auto absS0 = Mathematics::FloatMath::FAbs(s0);
			auto absS1 = Mathematics::FloatMath::FAbs(s1);

			if (Mathematics::FloatMath::GetZeroTolerance() < absS0 && Mathematics::FloatMath::GetZeroTolerance() < absS1)
			{
                            const auto sign0 = Mathematics::FloatMath::Sign(s0);
                            const auto sign1 = Mathematics::FloatMath::Sign(s1);
			 
				auto pow0 = Mathematics::FloatMath::Pow(absS0, oneMinusWeight);
				auto pow1 = Mathematics::FloatMath::Pow(absS1, m_Weight);

				blendScale[i] = sign0 * (sign1 * pow0) * pow1;
			}
			else
			{
				blendScale[i] = 0.0f;
			}
		}
	}
	else
	{
		blendScale = oneMinusWeight * firstScale + m_Weight * secondScale;
	}

	return blendScale;
}

const Rendering::BlendTransformControllerImpl::Matrix Rendering::BlendTransformControllerImpl
	::GetMatrix() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	const auto firstTransform = m_FirstController->GetTransform();
	const auto secondTransform = m_SecondController->GetTransform();

	const auto& firstMatrix = firstTransform.GetMatrix();
	const auto& secondMatrix = secondTransform.GetMatrix();

	 const auto oneMinusWeight = 1.0f - m_Weight;

	return oneMinusWeight * firstMatrix + m_Weight * secondMatrix;
}

#include STSTEM_WARNING_POP