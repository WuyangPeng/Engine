///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/04 15:46)

#include "Rendering/RenderingExport.h"

#include "BlendTransformControllerImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

using std::string;
using std::vector;

Rendering::BlendTransformControllerImpl::BlendTransformControllerImpl() noexcept
    : firstController{}, secondController{}, weight{ 0.0f }, rotationScaleMatrices{ false }, geometricRotation{ false }, geometricScale{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::BlendTransformControllerImpl::BlendTransformControllerImpl(const TransformControllerSharedPtr& firstController,
                                                                       const TransformControllerSharedPtr& secondController,
                                                                       bool rotationScaleMatrices,
                                                                       bool geometricRotation,
                                                                       bool geometricScale) noexcept
    : firstController{ firstController },
      secondController{ secondController },
      weight{ 0.0f },
      rotationScaleMatrices{ rotationScaleMatrices },
      geometricRotation{ geometricRotation },
      geometricScale{ geometricScale }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::BlendTransformControllerImpl::IsValid() const noexcept
{
    if (0.0f <= weight && weight <= 1.0f)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::BlendTransformControllerImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(firstController);
    size += CORE_TOOLS_STREAM_SIZE(secondController);
    size += CORE_TOOLS_STREAM_SIZE(weight);
    size += CORE_TOOLS_STREAM_SIZE(rotationScaleMatrices);
    size += CORE_TOOLS_STREAM_SIZE(geometricRotation);
    size += CORE_TOOLS_STREAM_SIZE(geometricScale);

    return size;
}

void Rendering::BlendTransformControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteObjectAssociated(firstController);
    target.WriteObjectAssociated(secondController);
    target.Write(weight);
    target.Write(rotationScaleMatrices);
    target.Write(geometricRotation);
    target.Write(geometricScale);
}

void Rendering::BlendTransformControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadObjectAssociated(firstController);
    source.ReadObjectAssociated(secondController);
    source.Read(weight);
    rotationScaleMatrices = source.ReadBool();
    geometricRotation = source.ReadBool();
    geometricScale = source.ReadBool();
}

bool Rendering::BlendTransformControllerImpl::IsGeometricRotation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return geometricRotation;
}

bool Rendering::BlendTransformControllerImpl::IsGeometricScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return geometricScale;
}

void Rendering::BlendTransformControllerImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ResolveLink(firstController);
    source.ResolveLink(secondController);
}

void Rendering::BlendTransformControllerImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Register(firstController);
    target.Register(secondController);
}

CoreTools::ObjectSharedPtr Rendering::BlendTransformControllerImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = firstController.object->GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }
    else
    {
        found = secondController.object->GetObjectByName(name);

        if (found != nullptr)
        {
            return found;
        }
    }

    return nullptr;
}

vector<CoreTools::ObjectSharedPtr> Rendering::BlendTransformControllerImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto firstObjects = firstController.object->GetAllObjectsByName(name);
    auto secondObjects = firstController.object->GetAllObjectsByName(name);

    firstObjects.insert(firstObjects.end(), secondObjects.begin(), secondObjects.end());

    return firstObjects;
}

CoreTools::ConstObjectSharedPtr Rendering::BlendTransformControllerImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto found = firstController.object->GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }
    else
    {
        found = secondController.object->GetConstObjectByName(name);

        if (found != nullptr)
        {
            return found;
        }
    }

    return nullptr;
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::BlendTransformControllerImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    auto firstObjects = firstController.object->GetAllConstObjectsByName(name);
    auto secondObjects = firstController.object->GetAllConstObjectsByName(name);

    firstObjects.insert(firstObjects.end(), secondObjects.begin(), secondObjects.end());

    return firstObjects;
}

Rendering::ConstTransformControllerSharedPtr Rendering::BlendTransformControllerImpl::GetFirstController() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return firstController.object;
}

bool Rendering::BlendTransformControllerImpl::IsRotationScaleMatrices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rotationScaleMatrices;
}

Rendering::ConstTransformControllerSharedPtr Rendering::BlendTransformControllerImpl::GetSecondController() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return secondController.object;
}

void Rendering::BlendTransformControllerImpl::SetWeight(float aWeight) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    weight = aWeight;
}

float Rendering::BlendTransformControllerImpl::GetWeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return weight;
}

void Rendering::BlendTransformControllerImpl::SetObject(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;

    firstController.object->SetObject(object);
    secondController.object->SetObject(object);
}

bool Rendering::BlendTransformControllerImpl::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    firstController.object->Update(applicationTime);
    secondController.object->Update(applicationTime);

    return true;
}

Rendering::BlendTransformControllerImpl::APoint Rendering::BlendTransformControllerImpl::GetBlendTranslate() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto firstTransform = firstController.object->GetTransform();
    const auto secondTransform = secondController.object->GetTransform();
    const auto oneMinusWeight = 1.0f - weight;

    // 算术混合转换。
    const auto firstTranslate = firstTransform.GetTranslate();
    const auto secondTranslate = secondTransform.GetTranslate();
    auto blendTranslate = oneMinusWeight * firstTranslate + weight * secondTranslate;

    return blendTranslate;
}

Rendering::BlendTransformControllerImpl::Matrix Rendering::BlendTransformControllerImpl::GetBlendQuaternion() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto firstTransform = firstController.object->GetTransform();
    const auto secondTransform = secondController.object->GetTransform();

    const auto firstRotate = firstTransform.GetRotate();
    const auto secondRotate = secondTransform.GetRotate();

    const Mathematics::AQuaternionF firstQuaternion{ firstRotate };
    Mathematics::AQuaternionF secondQuaternion{ secondRotate };
    if (Dot(firstQuaternion, secondQuaternion) < 0.0f)
    {
        secondQuaternion = -secondQuaternion;
    }

    Mathematics::AQuaternionF blendQuaternion;

    if (geometricRotation)
    {
        blendQuaternion.Slerp(weight, firstQuaternion, secondQuaternion);
    }
    else
    {
        const auto oneMinusWeight = 1.0f - weight;
        blendQuaternion = oneMinusWeight * firstQuaternion + weight * secondQuaternion;
        blendQuaternion.Normalize();
    }

    return blendQuaternion.ToRotationMatrix();
}

Rendering::BlendTransformControllerImpl::APoint Rendering::BlendTransformControllerImpl::GetBlendScale() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto firstTransform = firstController.object->GetTransform();
    const auto secondTransform = secondController.object->GetTransform();

    auto firstScale = firstTransform.GetScale();
    auto secondScale = secondTransform.GetScale();

    APoint blendScale{};

    const auto oneMinusWeight = 1.0f - weight;

    if (geometricScale)
    {
        for (auto i = 0; i < 3; ++i)
        {
            auto s0 = firstScale[i];
            auto s1 = secondScale[i];
            auto absS0 = Mathematics::MathF::FAbs(s0);
            auto absS1 = Mathematics::MathF::FAbs(s1);

            if (Mathematics::MathF::GetZeroTolerance() < absS0 && Mathematics::MathF::GetZeroTolerance() < absS1)
            {
                const auto sign0 = Mathematics::MathF::Sign(s0);
                const auto sign1 = Mathematics::MathF::Sign(s1);

                auto pow0 = Mathematics::MathF::Pow(absS0, oneMinusWeight);
                auto pow1 = Mathematics::MathF::Pow(absS1, weight);

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
        blendScale = oneMinusWeight * firstScale + weight * secondScale;
    }

    return blendScale;
}

Rendering::BlendTransformControllerImpl::Matrix Rendering::BlendTransformControllerImpl::GetMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto firstTransform = firstController.object->GetTransform();
    const auto secondTransform = secondController.object->GetTransform();

    const auto& firstMatrix = firstTransform.GetMatrix();
    const auto& secondMatrix = secondTransform.GetMatrix();

    const auto oneMinusWeight = 1.0f - weight;

    return oneMinusWeight * firstMatrix + weight * secondMatrix;
}

