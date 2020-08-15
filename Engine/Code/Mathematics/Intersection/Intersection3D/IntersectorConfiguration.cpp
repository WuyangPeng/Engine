// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 15:00)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_INTERSECTOR_CONFIGURATION_DETAIL
	#define MATHEMATICS_INCLUDED_INTERSECTOR_CONFIGURATION_DETAIL
#endif // MATHEMATICS_INCLUDED_INTERSECTOR_CONFIGURATION_DETAIL

#include "IntersectorConfigurationDetail.h"
    #include "System/Helper/PragmaWarning.h"
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)
namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class IntersectorConfiguration<float>;	
	
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class IntersectorConfiguration<double>; 
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_EXPORT_TEMPLATE