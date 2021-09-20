// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.3.0.1 (2020/05/22 13:47)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "AndroidCallBack.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/AndroidFrame/AndroidCallBackDetail.h" 
#include "Framework/MiddleLayer/MiddleLayerInterface.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, AndroidCallBack)

namespace FrameworkToolset
{
	template
	class Framework::AndroidCallBack<Framework::MiddleLayerInterface>;
}
