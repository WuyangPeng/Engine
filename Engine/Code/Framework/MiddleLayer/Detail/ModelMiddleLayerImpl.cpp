// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:52)

#include "Framework/FrameworkExport.h"

#include "ModelMiddleLayerImpl.h" 
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;

Framework::ModelMiddleLayerImpl
	::ModelMiddleLayerImpl(int maxTimer)
	:m_PerformanceMeasurements{ maxTimer }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ModelMiddleLayerImpl)

double Framework::ModelMiddleLayerImpl
	::GetFrameRate() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_PerformanceMeasurements.GetFrameRate();
}

string Framework::ModelMiddleLayerImpl
	::GetFrameRateMessage() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_PerformanceMeasurements.GetFrameRateMessage();
}

void Framework::ModelMiddleLayerImpl
	::ResetTime()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_PerformanceMeasurements.ResetTime();
}

void Framework::ModelMiddleLayerImpl
	::MeasureTime()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_PerformanceMeasurements.MeasureTime();
}

void Framework::ModelMiddleLayerImpl
	::UpdateFrameCount()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_PerformanceMeasurements.UpdateFrameCount();
}

