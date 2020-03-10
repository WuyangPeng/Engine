// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 12:00)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformationHelper.h"
#include "Detail/TestingInformationHelperImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;

CoreTools::TestingInformationHelper
	::TestingInformationHelper()
	:m_Impl{ make_shared<ImplType>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, TestingInformationHelper)

int CoreTools::TestingInformationHelper
	::GetLoopCount(const string& suiteName, const string& testingName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetLoopCount(suiteName, testingName);
}

bool CoreTools::TestingInformationHelper
	::IsPrintRun() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsPrintRun();
}

int CoreTools::TestingInformationHelper
	::GetRandomSeed() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetRandomSeed();
}

