///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 23:43)

#include "System/SystemExport.h"

#include "OpenGLPolygon.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL10Extensions.h"
#include "Detail/GL11Extensions.h"
#include "System/Helper/EnumCast.h"

void System::SetGLPolygonMode(RasterizerStateCullFace face, RasterizerStateFillMode mode) noexcept
{
    GLPolygonMode(EnumCastUnderlying(face), EnumCastUnderlying(mode));
}

void System::SetGLPolygonOffset(OpenGLFloat factor, OpenGLFloat units) noexcept
{
    GLPolygonOffset(factor, units);
}
