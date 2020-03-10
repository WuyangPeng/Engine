// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:05)

#include "Framework/FrameworkExport.h"

#include "ModelMiddleLayerImpl.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;

Framework::ModelMiddleLayerImpl
	::ModelMiddleLayerImpl()
	:m_PerformanceMeasurements(30)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ModelMiddleLayerImpl)
 
void Framework::ModelMiddleLayerImpl
	::ResetTime()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_PerformanceMeasurements.ResetTime();
}

string Framework::ModelMiddleLayerImpl
	::GetFrameRateMessage() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_PerformanceMeasurements.GetFrameRateMessage();
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

double Framework::ModelMiddleLayerImpl
	::GetFrameRate() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_PerformanceMeasurements.GetFrameRate();
}
 

