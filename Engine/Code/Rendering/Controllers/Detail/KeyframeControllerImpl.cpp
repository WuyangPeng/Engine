// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 13:57)

#include "Rendering/RenderingExport.h"

#include "KeyframeControllerImpl.h"

#include "Rendering/DataTypes/SpecializedIO.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::KeyframeControllerImpl
	::KeyframeControllerImpl()
	: m_NumCommonTimes{ 0 }, m_CommonTimes{},	  
	  m_NumTranslations{ 0 },m_TranslationTimes{},m_Translations{},	  
	  m_NumRotations{ 0 },m_RotationTimes{},m_Rotations{},	  
	  m_NumScales{ 0 },m_ScaleTimes{},m_Scales{},	  
	  m_TranslationLastIndex{ 0 },m_RotationLastIndex{ 0 },m_ScaleLastIndex{ 0 },m_CommonLastIndex{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::KeyframeControllerImpl
	::KeyframeControllerImpl(int numCommonTimes, int numTranslations, int numRotations, int numScales) 
	:m_NumCommonTimes{ numCommonTimes }, m_CommonTimes{},
	 m_NumTranslations{ numTranslations }, m_TranslationTimes{}, m_Translations{},
	 m_NumRotations{ numRotations }, m_RotationTimes{}, m_Rotations{},
	 m_NumScales{ numScales }, m_ScaleTimes{}, m_Scales{},
	 m_TranslationLastIndex{ 0 }, m_RotationLastIndex{ 0 }, m_ScaleLastIndex{ 0 }, m_CommonLastIndex{ 0 }
{
	ResetArraySize();

	RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::KeyframeControllerImpl
	::ResetArraySize() 
{
	if (0 < m_NumCommonTimes)
	{
		m_CommonTimes.resize(m_NumCommonTimes);
	}	 

	if (0 < m_NumTranslations)
	{
		m_Translations.resize(m_NumTranslations);

		if (m_NumCommonTimes <= 0)
		{
			m_TranslationTimes.resize(m_NumTranslations);
		}
	}


	if (0 < m_NumRotations)
	{
		m_Rotations.resize(m_NumRotations);

		if (m_NumCommonTimes <= 0)
		{
			m_Rotations.resize(m_NumTranslations);
		}
	}

	if (0 < m_NumScales)
	{
		m_Scales.resize(m_NumScales);

		if (m_NumCommonTimes <= 0)
		{
			m_Scales.resize(m_NumScales);
		}
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::KeyframeControllerImpl
	::IsValid() const noexcept
{
	if (0 <= m_NumCommonTimes && m_NumCommonTimes <= m_NumTranslations && m_NumCommonTimes <= m_NumRotations && m_NumCommonTimes <= m_NumScales)
	{
		return true;
	}		
	else
	{
		return false;
	}		
}
#endif // OPEN_CLASS_INVARIANT	

int Rendering::KeyframeControllerImpl
	::GetStreamingSize() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_NumCommonTimes);

	if (0 < m_NumCommonTimes)
	{
		size += m_NumCommonTimes * CORE_TOOLS_STREAM_SIZE(m_CommonTimes[0]);
		size += CORE_TOOLS_STREAM_SIZE(m_NumTranslations);
		size += m_NumTranslations * MATHEMATICS_STREAM_SIZE(m_Translations[0]);
		size += CORE_TOOLS_STREAM_SIZE(m_NumRotations);
		size += m_NumRotations * MATHEMATICS_STREAM_SIZE(m_Rotations[0]);
		size += CORE_TOOLS_STREAM_SIZE(m_NumScales);
		size += m_NumScales * CORE_TOOLS_STREAM_SIZE(m_Scales[0]);
	}
	else
	{
		size += CORE_TOOLS_STREAM_SIZE(m_NumTranslations);
		size += m_NumTranslations * CORE_TOOLS_STREAM_SIZE(m_TranslationTimes[0]);
		size += m_NumTranslations * MATHEMATICS_STREAM_SIZE(m_Translations[0]);
		size += CORE_TOOLS_STREAM_SIZE(m_NumRotations);
		size += m_NumRotations * CORE_TOOLS_STREAM_SIZE(m_RotationTimes[0]);
		size += m_NumRotations * MATHEMATICS_STREAM_SIZE(m_Rotations[0]);
		size += CORE_TOOLS_STREAM_SIZE(m_NumScales);
		size += m_NumScales * CORE_TOOLS_STREAM_SIZE(m_ScaleTimes[0]);
		size += m_NumScales * CORE_TOOLS_STREAM_SIZE(m_Scales[0]); 
	}

	return size;
}

void Rendering::KeyframeControllerImpl
	::Save(CoreTools::BufferTarget& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target.Write(m_NumCommonTimes);

	if (0 < m_NumCommonTimes)
	{
		target.WriteWithoutNumber(m_NumCommonTimes, &m_CommonTimes[0]);

		if (0 < m_NumTranslations)
			target.WriteAggregateWithNumber(m_NumTranslations, &m_Translations[0]);
		else
			target.Write(m_NumTranslations);

		if (0 < m_NumRotations)
			target.WriteAggregateWithNumber(m_NumRotations, &m_Rotations[0]);
		else
			target.Write(m_NumRotations);

		if (0 < m_NumScales)
			target.WriteWithNumber(m_NumScales, &m_Scales[0]);
		else
			target.Write(m_NumScales);
	}
	else
	{
		if (0 < m_NumTranslations)
		{
			target.WriteWithNumber(m_NumTranslations, &m_TranslationTimes[0]);
			target.WriteAggregateWithoutNumber(m_NumTranslations, &m_Translations[0]);
		}
		else
		{
			target.Write(m_NumTranslations);
		}

		if (0 < m_NumRotations)
		{
			target.WriteWithNumber(m_NumRotations, &m_RotationTimes[0]);
			target.WriteAggregateWithoutNumber(m_NumRotations, &m_Rotations[0]);
		}
		else
		{
			target.Write(m_NumRotations);
		}

		if (0 < m_NumScales)
		{
			target.WriteWithNumber(m_NumScales, &m_ScaleTimes[0]);
			target.WriteWithoutNumber(m_NumScales, &m_Scales[0]);
		}
		else
		{
			target.Write(m_NumScales);
		}		 
	}
}

void Rendering::KeyframeControllerImpl
	::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;

	source.Read(m_NumCommonTimes);

	if (0 < m_NumCommonTimes)
	{
		m_CommonTimes.resize(m_NumCommonTimes);
		source.Read(m_NumCommonTimes, &m_CommonTimes[0]);

		source.Read(m_NumTranslations);
		m_Translations.resize(m_NumTranslations);
		if (0 < m_NumTranslations)
		{
			source.ReadAggregate(m_NumTranslations, &m_Translations[0]);
		}

		source.Read(m_NumRotations);
		m_Rotations.resize(m_NumRotations);
		if (0 < m_NumRotations)
		{
			source.ReadAggregate(m_NumRotations, &m_Rotations[0]);
		}

		source.Read(m_NumScales);
		m_Scales.resize(m_NumScales);
		if (0 < m_NumScales)
		{
			source.Read(m_NumScales, &m_Scales[0]);
		}		  
	}
	else
	{
		source.Read(m_NumTranslations);
		m_TranslationTimes.resize(m_NumTranslations);
		m_Translations.resize(m_NumTranslations);
		if (0 < m_NumTranslations)
		{
			source.Read(m_NumTranslations, &m_TranslationTimes[0]);
			source.ReadAggregate(m_NumTranslations, &m_Translations[0]);
		}

		source.Read(m_NumRotations);
		m_RotationTimes.resize(m_NumRotations);
		m_Rotations.resize(m_NumRotations);
		if (0 < m_NumRotations)
		{
			source.Read(m_NumRotations, &m_RotationTimes[0]);
			source.ReadAggregate(m_NumRotations, &m_Rotations[0]);
		}

		source.Read(m_NumScales);
		m_ScaleTimes.resize(m_NumRotations);
		m_Scales.resize(m_NumScales);
		if (0 < m_NumScales)
		{
			source.Read(m_NumScales, &m_Scales[0]);
			source.Read(m_NumScales, &m_Scales[0]);
		}
 	}
}

int Rendering::KeyframeControllerImpl
	::GetNumCommonTimes() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumCommonTimes;
}

float Rendering::KeyframeControllerImpl
	::GetCommonTimes(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumCommonTimes, "À˜“˝¥ÌŒÛ£°");

	return m_CommonTimes[index];
}

void Rendering::KeyframeControllerImpl
	::SetCommonTimes(int index, float commonTimes)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumCommonTimes, "À˜“˝¥ÌŒÛ£°");

	m_CommonTimes[index] = commonTimes;
}

int Rendering::KeyframeControllerImpl
	::GetNumTranslations() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumTranslations;
}

float Rendering::KeyframeControllerImpl
	::GetTranslationTimes(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumTranslations && m_NumCommonTimes == 0, "À˜“˝¥ÌŒÛ£°");

	return m_TranslationTimes[index];
}

const Rendering::KeyframeControllerImpl::APoint Rendering::KeyframeControllerImpl
	::GetTranslations(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumTranslations, "À˜“˝¥ÌŒÛ£°");

	return m_Translations[index];
}

void Rendering::KeyframeControllerImpl
	::SetTranslationTimes(int index, float translationTimes)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumTranslations && m_NumCommonTimes == 0, "À˜“˝¥ÌŒÛ£°");

	m_TranslationTimes[index] = translationTimes;
}

void Rendering::KeyframeControllerImpl
	::SetTranslations(int index, const APoint& translations) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumTranslations, "À˜“˝¥ÌŒÛ£°");

	m_Translations[index] = translations;
}

int Rendering::KeyframeControllerImpl
	::GetNumRotations() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumRotations;
}

float Rendering::KeyframeControllerImpl
	::GetRotationTimes(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumRotations && m_NumCommonTimes == 0, "À˜“˝¥ÌŒÛ£°");

	return m_RotationTimes[index];
}

const Rendering::KeyframeControllerImpl::AQuaternion Rendering::KeyframeControllerImpl
	::GetRotations(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumRotations, "À˜“˝¥ÌŒÛ£°");

	return m_Rotations[index];
}

void Rendering::KeyframeControllerImpl
	::SetRotationTimes(int index, float rotationTimes)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumRotations && m_NumCommonTimes == 0, "À˜“˝¥ÌŒÛ£°");

	m_RotationTimes[index] = rotationTimes;
}

void Rendering::KeyframeControllerImpl
	::SetRotations(int index, const AQuaternion& rotations)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumRotations, "À˜“˝¥ÌŒÛ£°");

	m_Rotations[index] = rotations;
}

int Rendering::KeyframeControllerImpl
	::GetNumScales() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumScales;
}

float Rendering::KeyframeControllerImpl
	::GetScaleTimes(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumScales && m_NumCommonTimes == 0, "À˜“˝¥ÌŒÛ£°");

	return m_ScaleTimes[index];
}

float Rendering::KeyframeControllerImpl
	::GetScales(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumScales, "À˜“˝¥ÌŒÛ£°");

	return m_Scales[index];
}

void Rendering::KeyframeControllerImpl
	::SetScaleTimes(int index, float scaleTimes)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumScales && m_NumCommonTimes == 0, "À˜“˝¥ÌŒÛ£°");

	m_ScaleTimes[index] = scaleTimes;
}

void Rendering::KeyframeControllerImpl
	::SetScales(int index, float scales) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumScales, "À˜“˝¥ÌŒÛ£°");

	m_Scales[index] = scales;
}

// static
const Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl
	::GetKeyInfo(float ctrlTime, const std::vector<float>& times, int& lastIndex) 
{
	if (ctrlTime <= times[0])
	{
		lastIndex = 0;
	
		return ControllerKeyInfo();
	}

	if (times[times.size() - 1] <= ctrlTime)
	{	
		lastIndex = boost::numeric_cast<int>(times.size() - 1);
	
		return ControllerKeyInfo{ 0.0f, lastIndex, lastIndex };
	}

 
	if (times[lastIndex] < ctrlTime)
	{
		auto nextIndex = lastIndex + 1;
		while (times[nextIndex] <= ctrlTime)
		{
			lastIndex = nextIndex;
			++nextIndex;
		}

		auto normTime = (ctrlTime - times[lastIndex]) / (times[nextIndex] - times[lastIndex]);

		return ControllerKeyInfo{ normTime, lastIndex, nextIndex };
	}
	else if (ctrlTime < times[lastIndex])
	{
		auto nextIndex = lastIndex - 1;
		while (ctrlTime <= times[nextIndex])
		{
			lastIndex = nextIndex;
			--nextIndex;
		}

		auto normTime = (ctrlTime - times[nextIndex]) / (times[lastIndex] - times[nextIndex]);

		return ControllerKeyInfo{ normTime, nextIndex, lastIndex };
	}
	else
	{
		return ControllerKeyInfo{ 0.0f, lastIndex, lastIndex };
	}
}

const Rendering::KeyframeControllerImpl::APoint Rendering::KeyframeControllerImpl
	::GetTranslate(const ControllerKeyInfo& keyInfo) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto translation = m_Translations[keyInfo.GetFirstIndex()] + keyInfo.GetNormTime() *  (m_Translations[keyInfo.GetSecondIndex()] -  m_Translations[keyInfo.GetFirstIndex()]);
	return translation;
}

const Rendering::KeyframeControllerImpl::Matrix Rendering::KeyframeControllerImpl
	::GetRotate(const ControllerKeyInfo& keyInfo) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	
	AQuaternion quaternion;
	quaternion.Slerp(keyInfo.GetNormTime(), m_Rotations[keyInfo.GetFirstIndex()], m_Rotations[keyInfo.GetSecondIndex()]);
	
	return quaternion.ToRotationMatrix();
}

float Rendering::KeyframeControllerImpl
	::GetScale(const ControllerKeyInfo& keyInfo) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Scales[keyInfo.GetFirstIndex()] + keyInfo.GetNormTime() * (m_Scales[keyInfo.GetSecondIndex()] - m_Scales[keyInfo.GetFirstIndex()]);
}

const Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl
	::GetTranslateKeyInfo( float ctrlTime )
{
	RENDERING_CLASS_IS_VALID_1;

	return GetKeyInfo(ctrlTime,m_TranslationTimes,m_TranslationLastIndex);
}

const Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl
	::GetRotateKeyInfo( float ctrlTime )
{
	RENDERING_CLASS_IS_VALID_1;

	return GetKeyInfo(ctrlTime,m_RotationTimes,m_RotationLastIndex);
}

const Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl
	::GetScaleKeyInfo( float ctrlTime )
{
	RENDERING_CLASS_IS_VALID_1;

	return GetKeyInfo(ctrlTime,m_ScaleTimes,m_ScaleLastIndex);
}

const Rendering::ControllerKeyInfo Rendering::KeyframeControllerImpl
	::GetCommonKeyInfo( float ctrlTime )
{
	RENDERING_CLASS_IS_VALID_1;

	return GetKeyInfo(ctrlTime,m_CommonTimes,m_CommonLastIndex);
}
