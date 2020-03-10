// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2019/12/30 10:16)

#include "ThreadingCoreRenderEngineExport.h"

#include "ThreadingCoreRenderEngine.h"
#include "ThreadingCoreRenderEngineLib.h"

// 线程核心渲染引擎（Threading Core Render Engine）包含十七个模块，七个层级：
// 第一层：系统（System）。
// 第二层：核心工具（CoreTools）。
// 第三层：网络（Network）、数据库（Database）、脚本（Script）、数学（Mathematics）、音效（SoundEffect）、输入输出（InputOutput）。
// 第四层：资源管理（ResourceManager）、渲染（Rendering）、物理（Physics）、图像分析（Imagics）。
// 第五层：动画（Animation）、人工智能（ArtificialIntellegence）、界面（UserInterface）。
// 第六层：辅助工具（AssistTools）。
// 第七层：框架（Framework）。

// 关联的外部库：
// 直接关联：boost、stlsoft、Visual Leak Detector（Debug）、zlib、freeType，
// 通过宏控制是否关联：ACE、openssl、mysql connector c++、freealut、wxWidgets、opencv、openal、lua。

// 包含四个相关模块：工具箱（Toolset）、编辑器（Editor）、例子（Example）、库例子（LibExample）。

// 四个相关模块的单元测试：引擎单元测试（EngineTesting）、编辑器单元测试（EditorTesting）、例子单元测试（ExampleTesting）、库例子单元测试（LibExampleTesting）。