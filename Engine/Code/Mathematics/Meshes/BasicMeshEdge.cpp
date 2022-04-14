///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/22 16:16)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshEdge.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Mathematics::BasicMeshEdge::BasicMeshEdge() noexcept
    : triangle{ -1, -1 }, vertices{ -1, -1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, BasicMeshEdge)

int Mathematics::BasicMeshEdge::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices.at(index);
}

int Mathematics::BasicMeshEdge::GetTriangle(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangle.at(index);
}

void Mathematics::BasicMeshEdge::SetVertex(int index, int vertex)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    vertices.at(index) = vertex;
}

void Mathematics::BasicMeshEdge::SetTriangle(int index, int triangle0)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    triangle.at(index) = triangle0;
}
