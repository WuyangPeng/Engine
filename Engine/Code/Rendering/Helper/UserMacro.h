///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:46)

#ifndef RENDERING_HELPER_USER_MACRO_H
#define RENDERING_HELPER_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"
#include "Mathematics/Helper/UserMacro.h"

#define RENDERING_ClOSE_BEGIN (0x01)

#define CLOSE_USE_RENDERING_TEMPLATE_TEST (RENDERING_ClOSE_BEGIN)  // 默认关闭
#define CLOSE_USE_VALIDATE_CAMERA_FRAME_ONCE (RENDERING_ClOSE_BEGIN << 1)
#define CLOSE_USE_ASSERT_ON_CHANGED_MAX_PROFILES (RENDERING_ClOSE_BEGIN << 2)
#define CLOSE_USE_RESET_STATE_AFTER_DRAW (RENDERING_ClOSE_BEGIN << 3)  // 默认关闭
#define CLOSE_USE_QUERY_PIXEL_COUNT (RENDERING_ClOSE_BEGIN << 4)  // 默认关闭
#define CLOSE_USE_TEXT_DISPLAY_LIST (RENDERING_ClOSE_BEGIN << 5)
#define CLOSE_USE_ENABLES_CHECKING_DATA_DX9_RENDERER (RENDERING_ClOSE_BEGIN << 6)
#define CLOSE_USE_RENDERING_EXPORT_TEMPLATE (RENDERING_ClOSE_BEGIN << 7)
#define CLOSE_USE_RENDERING_NAMED_OBJECTS (RENDERING_ClOSE_BEGIN << 8)

#define RENDERING_ClOSE_END CLOSE_USE_RENDERING_NAMED_OBJECTS

#define CLOSE_RENDERING_MAX (((RENDERING_ClOSE_END) << 1) - 1)

// 编译测试（默认为0x19，最大值为0x1FF）
#define COMPILE_RENDERING_CLOSE 0x18

static_assert(0 <= COMPILE_RENDERING_CLOSE, "COMPILE_RENDERING_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_RENDERING_CLOSE <= CLOSE_RENDERING_MAX, "COMPILE_RENDERING_CLOSE Must be less than or equal CLOSE_RENDERING_MAX.");

#ifdef _DEBUG

    #if !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_VALIDATE_CAMERA_FRAME_ONCE) != CLOSE_USE_VALIDATE_CAMERA_FRAME_ONCE

        // 启用此宏可验证相机轴方向是否形成右手正交法线集。
        // 该测试仅进行一次，因为帧随着时间旋转期间的数值舍入误差可能需要对帧进行重新正则化。
        // 使用在Camera类的SetAxes函数中。
        #define RENDERING_VALIDATE_CAMERA_FRAME_ONCE static_cast<void>(0)

    #endif  // !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_VALIDATE_CAMERA_FRAME_ONCE) != CLOSE_USE_VALIDATE_CAMERA_FRAME_ONCE

    #if !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_ASSERT_ON_CHANGED_MAX_PROFILES) != CLOSE_USE_ASSERT_ON_CHANGED_MAX_PROFILES

        // 启用此宏以测试ShaderFlags::Profiles::MaxProfiles是否已更改并影响流文件。
        // 使用在Shader类的Load函数中。
        #define RENDERING_ASSERT_ON_CHANGED_MAX_PROFILES static_cast<void>(0)

    #endif  // !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_ASSERT_ON_CHANGED_MAX_PROFILES) != CLOSE_USE_ASSERT_ON_CHANGED_MAX_PROFILES

    #if !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_RENDERING_NAMED_OBJECTS) != CLOSE_USE_RENDERING_NAMED_OBJECTS

        // 启用此宏以允许将名称分配给特定于图形API的对象以进行调试。
        #define RENDERING_USE_NAMED_OBJECTS static_cast<void>(0)

    #endif  // !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_RENDERING_NAMED_OBJECTS) != CLOSE_USE_RENDERING_NAMED_OBJECTS

    #ifdef SYSTEM_USE_DIRECTX_9

        #if !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_ENABLES_CHECKING_DATA_DX9_RENDERER) != CLOSE_USE_ENABLES_CHECKING_DATA_DX9_RENDERER

            // 启用此宏则启用DX9渲染器中各种数据的检查。
            #define RENDERING_ENABLES_CHECKING_DATA_DX9_RENDERER static_cast<void>(0)

        #endif  // !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_ENABLES_CHECKING_DATA_DX9_RENDERER) != CLOSE_USE_ENABLES_CHECKING_DATA_DX9_RENDERER

    #endif  // SYSTEM_USE_DIRECTX_9

#endif  // _DEBUG

#if !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_RENDERING_TEMPLATE_TEST) != CLOSE_USE_RENDERING_TEMPLATE_TEST

    #define RENDERING_TEMPLATE_TEST static_cast<void>(0)

#endif  // !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_RENDERING_TEMPLATE_TEST) != CLOSE_USE_RENDERING_TEMPLATE_TEST

#if !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_RESET_STATE_AFTER_DRAW) != CLOSE_USE_RESET_STATE_AFTER_DRAW

    // 启用此宏以允许在Renderer::Draw调用中重置渲染和其他状态。
    #define RENDERING_RESET_STATE_AFTER_DRAW static_cast<void>(0)

#endif  // !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_RESET_STATE_AFTER_DRAW) != CLOSE_USE_RESET_STATE_AFTER_DRAW

#if !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_QUERY_PIXEL_COUNT) != CLOSE_USE_QUERY_PIXEL_COUNT

    // 启用此宏以允许在Renderer::DrawPrimitive中计算绘制的像素数。
    #define RENDERING_QUERY_PIXEL_COUNT static_cast<void>(0)

#endif  // !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_QUERY_PIXEL_COUNT) != CLOSE_USE_QUERY_PIXEL_COUNT

#if !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_RENDERING_EXPORT_TEMPLATE) != CLOSE_USE_RENDERING_EXPORT_TEMPLATE

    #define RENDERING_EXPORT_TEMPLATE static_cast<void>(0)

#endif  // !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_RENDERING_EXPORT_TEMPLATE) != CLOSE_USE_RENDERING_EXPORT_TEMPLATE

#ifdef SYSTEM_PLATFORM_WIN32

    #if !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_TEXT_DISPLAY_LIST) != CLOSE_USE_TEXT_DISPLAY_LIST

        // 启用此宏以使用OpenGL中的显示列表绘制文本。否则，将使用位图字体手动绘制文本。
        #define RENDERING_USE_TEXT_DISPLAY_LIST static_cast<void>(0)

    #endif  // !defined(COMPILE_RENDERING_CLOSE) || (COMPILE_RENDERING_CLOSE & CLOSE_USE_TEXT_DISPLAY_LIST) != CLOSE_USE_TEXT_DISPLAY_LIST

#endif  // SYSTEM_PLATFORM_WIN32

#ifdef RENDERING_EXPORT_TEMPLATE

    #define RENDERING_TEMPLATE_DEFAULT_DECLARE RENDERING_DEFAULT_DECLARE

#else  // !RENDERING_EXPORT_TEMPLATE

    #define RENDERING_TEMPLATE_DEFAULT_DECLARE

#endif  // RENDERING_EXPORT_TEMPLATE

#ifdef BUILDING_STATIC

    #define BUILDING_RENDERING_STATIC static_cast<void>(0)

#endif  // BUILDING_STATIC

#endif  // RENDERING_HELPER_USER_MACRO_H
