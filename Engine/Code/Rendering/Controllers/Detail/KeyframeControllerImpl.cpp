///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ°æ±¾£º0.8.0.6 (2022/04/06 15:37)

#include "Rendering/RenderingExport.h"

#include "KeyframeControllerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::KeyframeControllerImpl::KeyframeControllerImpl() noexcept
    : numCommonTimes{ 0 },
      commonTimes{},
      numTranslations{ 0 },
      translationTimes{},
      translations{},
      numRotations{ 0 },
      rotationTimes{},
      rotations{},
      numScales{ 0 },
      scaleTimes{},
      scales{},
      translationLastIndex{ 0 },
      rotationLastIndex{ 0 },
      scaleLastIndex{ 0 },
      commonLastIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::KeyframeControllerImpl::KeyframeControllerImpl(int numCommonTimes, int numTranslations, int numRotations, int numScales)
    : numCommonTimes{ numCommonTimes },
      commonTimes{},
      numTranslations{ numTranslations },
      translationTimes{},
      translations{},
      numRotations{ numRotations },
      rotationTimes{},
      rotations{},
      numScales{ numScales },
      scaleTimes{},
      scales{},
      translationLastIndex{ 0 },
      rotationLastIndex{ 0 },
      scaleLastIndex{ 0 },
      commonLastIndex{ 0 }
{
    ResetArraySize();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::KeyframeControllerImpl::ResetArraySize()
{
    if (0 < numCommonTimes)
    {
        commonTimes.resize(numCommonTimes);
    }

    if (0 < numTranslations)
    {
        translations.resize(numTranslations);

        if (numCommonTimes <= 0)
        {
            translationTimes.resize(numTranslations);
        }
    }

    if (0 < numRotations)
    {
        rotations.resize(numRotations);

        if (numCommonTimes <= 0)
        {
            rotations.resize(numTranslations);
        }
    }

    if (0 < numScales)
    {
        scales.resize(numScales);

        if (numCommonTimes <= 0)
        {
            scales.resize(numScales);
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::KeyframeControllerImpl::IsValid() const noexcept
{
    if (0 <= numCommonTimes && numCommonTimes <= numTranslations && numCommonTimes <= numRotations && numCommonTimes <= numScales)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::KeyframeControllerImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(numCommonTimes);

    if (0 < numCommonTimes)
    {
        size += numCommonTimes * CoreTools::GetStreamSize(commonTimes.at(0));
        size += CoreTools::GetStreamSize(numTranslations);
        size += numTranslations * MATHEMATICS_STREAM_SIZE(translations.at(0));
        size += CoreTools::GetStreamSize(numRotations);
        size += numRotations * MATHEMATICS_STREAM_SIZE(rotations.at(0));
        size += CoreTools::GetStreamSize(numScales);
        size += numScales * CoreTools::GetStreamSize(scales.at(0));
    }
    else
    {
        size += CoreTools::GetStreamSize(numTranslations);
        size += numTranslations * CoreTools::GetStreamSize(translationTimes.at(0));
        size += numTranslations * MATHEMATICS_STREAM_SIZE(translations.at(0));
        size += CoreTools::GetStreamSize(numRotations);
        size += numRotations * CoreTools::GetStreamSize(rotationTimes.at(0));
        size += numRotations * MATHEMATICS_STREAM_SIZE(rotations.at(0));
        size += CoreTools::GetStreamSize(numScales);
        size += numScales * CoreTools::GetStreamSize(scaleTimes.at(0));
        size += numScales * CoreTools::GetStreamSize(scales.at(0));
    }

    return size;
}

void Rendering::KeyframeControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numCommonTimes);

    if (0 < numCommonTimes)
    {
        target.WriteContainerWithoutNumber(commonTimes);

        if (0 < numTranslations)
            target.WriteAggregateContainerWithNumber(translations);
        else
            target.Write(numTranslations);

        if (0 < numRotations)
            target.WriteAggregateContainerWithNumber(rotations);
        else
            target.Write(numRotations);

        if (0 < numScales)
            target.WriteContainerWithNumber(scales);
        else
            target.Write(numScales);
    }
    else
    {
        if (0 < numTranslations)
        {
            target.WriteContainerWithNumber(translationTimes);
            target.WriteAggregateContainerWithoutNumber(translations);
        }
        else
        {
            target.Write(numTranslations);
        }

        if (0 < numRotations)
        {
            target.WriteContainerWithNumber(rotationTimes);
            target.WriteAggregateContainerWithoutNumber(rotations);
        }
        else
        {
            target.Write(numRotations);
        }

        if (0 < numScales)
        {
            target.WriteContainerWithNumber(scaleTimes);
            target.WriteContainerWithoutNumber(scales);
        }
        else
        {
            target.Write(numScales);
        }
    }
}

void Rendering::KeyframeControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numCommonTimes);

    if (0 < numCommonTimes)
    {
        commonTimes.resize(numCommonTimes);
        commonTimes = source.ReadContainerWithNumber<std::vector<float>>(numCommonTimes);

        source.Read(numTranslations);
        translations.resize(numTranslations);
        if (0 < numTranslations)
        {
            source.ReadAggregateContainer(numTranslations, translations);
        }

        source.Read(numRotations);
        rotations.resize(numRotations);
        if (0 < numRotations)
        {
            source.ReadAggregateContainer(numRotations, rotations);
        }

        source.Read(numScales);
        scales.resize(numScales);
        if (0 < numScales)
        {
            source.ReadContainer(numScales, scales);
        }
    }
    else
    {
        source.Read(numTranslations);
        translationTimes.resize(numTranslations);
        translations.resize(numTranslations);
        if (0 < numTranslations)
        {
            source.ReadContainer(numTranslations, translationTimes);
            source.ReadAggregateContainer(numTranslations, translations);
        }

        source.Read(numRotations);
        rotationTimes.resize(numRotations);
        rotations.resize(numRotations);
        if (0 < numRotations)
        {
            source.ReadContainer(numRotations, rotationTimes);
            source.ReadAggregateContainer(numRotations, rotations);
        }

        source.Read(numScales);
        scaleTimes.resize(numRotations);
        scales.resize(numScales);
        if (0 < numScales)
        {
            source.ReadContainer(numScales, scaleTimes);
            source.ReadContainer(numScales, scales);
        }
    }
}

int Rendering::KeyframeControllerImpl::GetNumCommonTimes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numCommonTimes;
}

float Rendering::KeyframeControllerImpl::GetCommonTimes(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numCommonTimes, "Ë÷Òý´íÎó£¡");

    return commonTimes.at(index);
}

void Rendering::KeyframeControllerImpl::SetCommonTimes(int index, float aCommonTimes)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numCommonTimes, "Ë÷Òý´íÎó£¡");

    commonTimes.at(index) = aCommonTimes;
}

int Rendering::KeyframeControllerImpl::GetNumTranslations() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numTranslations;
}

float Rendering::KeyframeControllerImpl::GetTranslationTimes(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numTranslations && numCommonTimes == 0, "Ë÷Òý´íÎó£¡");

    return translationTimes.at(index);
}

Rendering::KeyframeControllerImpl::APoint Rendering::KeyframeControllerImpl::GetTranslations(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numTranslations, "Ë÷Òý´íÎó£¡");

    return translations.at(index);
}

void Rendering::KeyframeControllerImpl::SetTranslationTimes(int index, float translationTime)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numTranslations && numCommonTimes == 0, "Ë÷Òý´íÎó£¡");

    translationTimes.at(index) = translationTime;
}

void Rendering::KeyframeControllerImpl::SetTranslations(int index, const APoint& translation)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numTranslations, "Ë÷Òý´íÎó£¡");

    translations.at(index) = translation;
}

int Rendering::KeyframeControllerImpl::GetNumRotations() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numRotations;
}

float Rendering::KeyframeControllerImpl::GetRotationTimes(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numRotations && numCommonTimes == 0, "Ë÷Òý´íÎó£¡");

    return rotationTimes.at(index);
}

Rendering::KeyframeControllerImpl::AQuaternion Rendering::KeyframeControllerImpl::GetRotations(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numRotations, "Ë÷Òý´íÎó£¡");

    return rotations.at(index);
}

void Rendering::KeyframeControllerImpl::SetRotationTimes(int index, float rotationTime)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numRotations && numCommonTimes == 0, "Ë÷Òý´íÎó£¡");

    rotationTimes.at(index) = rotationTime;
}

void Rendering::KeyframeControllerImpl::SetRotations(int index, const AQuaternion& rotation)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numRotations, "Ë÷Òý´íÎó£¡");

    rotations.at(index) = rotation;
}

int Rendering::KeyframeControllerImpl::GetNumScales() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numScales;
}

float Rendering::KeyframeControllerImpl::GetScaleTimes(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numScales && numCommonTimes == 0, "Ë÷Òý´íÎó£¡");

    return scaleTimes.at(index);
}

float Rendering::KeyframeControllerImpl::GetScales(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numScales, "Ë÷Òý´íÎó£¡");

    return scales.at(index);
}

void Rendering::KeyframeControllerImpl::SetScaleTimes(int index, float scaleTime)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numScales && numCommonTimes == 0, "Ë÷Òý´íÎó£¡");

    scaleTimes.at(index) = scaleTime;
}

void Rendering::KeyframeControllerImpl::SetScales(int index, float scale)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numScales, "Ë÷Òý´íÎó£¡");

    scales.at(index) = scale;
}

// static
Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl::GetKeyInfo(float ctrlTime, const std::vector<float>& times, int& lastIndex)
{
    if (ctrlTime <= times.at(0))
    {
        lastIndex = 0;

        return ControllerKeyInfo{};
    }

    const auto index = times.size() - 1;
    if (times.at(index) <= ctrlTime)
    {
        lastIndex = boost::numeric_cast<int>(times.size() - 1);

        return ControllerKeyInfo{ 0.0f, lastIndex, lastIndex };
    }

    if (times.at(lastIndex) < ctrlTime)
    {
        auto nextIndex = lastIndex + 1;
        while (times.at(nextIndex) <= ctrlTime)
        {
            lastIndex = nextIndex;
            ++nextIndex;
        }

        const auto normTime = (ctrlTime - times.at(lastIndex)) / (times.at(nextIndex) - times.at(lastIndex));

        return ControllerKeyInfo{ normTime, lastIndex, nextIndex };
    }
    else if (ctrlTime < times.at(lastIndex))
    {
        auto nextIndex = lastIndex - 1;
        while (ctrlTime <= times.at(nextIndex))
        {
            lastIndex = nextIndex;
            --nextIndex;
        }

        const auto normTime = (ctrlTime - times.at(nextIndex)) / (times.at(lastIndex) - times.at(nextIndex));

        return ControllerKeyInfo{ normTime, nextIndex, lastIndex };
    }
    else
    {
        return ControllerKeyInfo{ 0.0f, lastIndex, lastIndex };
    }
}

Rendering::KeyframeControllerImpl::APoint Rendering::KeyframeControllerImpl::GetTranslate(const ControllerKeyInfo& keyInfo) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto translation = translations.at(keyInfo.GetFirstIndex()) + keyInfo.GetNormTime() * (translations.at(keyInfo.GetSecondIndex()) - translations.at(keyInfo.GetFirstIndex()));
    return translation;
}

Rendering::KeyframeControllerImpl::Matrix Rendering::KeyframeControllerImpl::GetRotate(const ControllerKeyInfo& keyInfo) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    AQuaternion quaternion;
    quaternion.Slerp(keyInfo.GetNormTime(), rotations.at(keyInfo.GetFirstIndex()), rotations.at(keyInfo.GetSecondIndex()));

    return quaternion.ToRotationMatrix();
}

float Rendering::KeyframeControllerImpl::GetScale(const ControllerKeyInfo& keyInfo) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return scales.at(keyInfo.GetFirstIndex()) + keyInfo.GetNormTime() * (scales.at(keyInfo.GetSecondIndex()) - scales.at(keyInfo.GetFirstIndex()));
}

Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl::GetTranslateKeyInfo(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    return GetKeyInfo(ctrlTime, translationTimes, translationLastIndex);
}

Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl::GetRotateKeyInfo(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    return GetKeyInfo(ctrlTime, rotationTimes, rotationLastIndex);
}

Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl::GetScaleKeyInfo(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    return GetKeyInfo(ctrlTime, scaleTimes, scaleLastIndex);
}

Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl::GetCommonKeyInfo(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    return GetKeyInfo(ctrlTime, commonTimes, commonLastIndex);
}
