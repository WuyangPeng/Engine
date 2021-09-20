// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.3.0.1 (2020/05/22 13:41)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "WindowRegisterHandle.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowRegister/WindowRegisterHandleDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, WindowRegisterHandle)

namespace FrameworkToolset
{
	template
	class Framework::WindowRegisterHandle<Framework::WindowProcessInterface>;
}