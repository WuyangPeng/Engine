// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 11:02)

#include "Rendering/RenderingExport.h"

#include "CollapseRecordArray.h"
#include "Detail/CollapseRecordArrayImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
 
CORE_TOOLS_RTTI_DEFINE(Rendering, CollapseRecordArray);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CollapseRecordArray);
CORE_TOOLS_FACTORY_DEFINE(Rendering, CollapseRecordArray); 
CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, CollapseRecordArray);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, CollapseRecordArray);

Rendering::CollapseRecordArray
	::CollapseRecordArray(const std::vector<CollapseRecord>& collapseRecord)
	:ParentType{ "CollapseRecordArray" }, m_Impl{ make_shared<ImplType>(collapseRecord) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::CollapseRecordArray
	::~CollapseRecordArray()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, CollapseRecordArray)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecordArray,GetNumRecords,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecordArray,GetRecord,int,const Rendering::CollapseRecord )
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecordArray,GetRecords,const std::vector<Rendering::CollapseRecord>)