// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:08)

#include "Framework/FrameworkExport.h"

#include "ModelViewControllerMiddleLayer.h"
#include "Detail/ModelViewControllerMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::ModelViewControllerMiddleLayer
	::ModelViewControllerMiddleLayer()
	:m_Impl(new ImplType)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelViewControllerMiddleLayer
	::~ModelViewControllerMiddleLayer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework,ModelViewControllerMiddleLayer)
	 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework,ModelViewControllerMiddleLayer,SetModelMiddleLayer,MiddleLayerInterfaceSmartPointer,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework,ModelViewControllerMiddleLayer,SetViewMiddleLayer,MiddleLayerInterfaceSmartPointer,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework,ModelViewControllerMiddleLayer,SetControllerMiddleLayer,MiddleLayerInterfaceSmartPointer,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,ModelViewControllerMiddleLayer,GetModelMiddleLayer,const Framework::MiddleLayerInterfaceSmartPointer)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,ModelViewControllerMiddleLayer,GetViewMiddleLayer,const Framework::MiddleLayerInterfaceSmartPointer)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,ModelViewControllerMiddleLayer,GetControllerMiddleLayer,const Framework::MiddleLayerInterfaceSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,ModelViewControllerMiddleLayer,GetConstModelMiddleLayer,const Framework::ConstMiddleLayerInterfaceSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,ModelViewControllerMiddleLayer,GetConstViewMiddleLayer,const Framework::ConstMiddleLayerInterfaceSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,ModelViewControllerMiddleLayer,GetConstControllerMiddleLayer,const Framework::ConstMiddleLayerInterfaceSmartPointer)
 