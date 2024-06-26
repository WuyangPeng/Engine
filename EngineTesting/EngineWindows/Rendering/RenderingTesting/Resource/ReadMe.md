@ingroup group_RenderingTesting_Documentation

----------------------------
渲染库单元测试

1.   HelperSuite 

对帮助模块的单元测试，包括： 
（1）用户宏：UserMacroTesting。★★★

----------------------------
2.  BaseSuite 

对基础模块的单元测试，包括： 
（1）图形对象基类：GraphicsObjectTesting。★★★
（2）渲染对象基类。

----------------------------
3.  DataTypesSuite 

对数据类型模块的单元测试，包括： 
（1）半浮点数。
（2）颜色管理。
（3）转换。
（4）范围。

----------------------------
4.	ResourcesSuite 

对资源模块的单元测试，包括： 
（1）资源基类：ResourceTesting、★★★
			   BufferTesting。★★★			   
（2）顶点缓冲区：StructuredBufferTesting、★★★
				 VertexBufferTesting。★★★
（3）索引缓冲区：IndexBufferTesting。★★★
（3）纹理对象。
（4）渲染目标。
（5）顶点格式：VertexFormatAttributeTesting、★★★
			   VertexFormatTesting。★★★

----------------------------
5.	SceneGraphSuite 

对场景图模块的单元测试，包括： 
（1）  视景体对象:：WorldCoordinateFrameTesting、★★★
					ProjectionMatrixTesting、★★★
					CameraFrustumTesting、★★★
					ViewVolumeTesting、★★★
（2）  相机对象:  CameraFrustumDataTesting、★★★
				  PickLineTesting、★★★
				  CameraTesting。★★★ 
（3）  节点对象。SpatialTesting、★★★
				 NodeTesting、★★★
				 VisualTesting。☆☆☆
（4）  光照对象。
（5）  材质对象。
（6）  点-粒子图元。
（7）  直线图元。
（8）  三角形图元。
（9）  转换操作。
（10） 层次结构剔除机制。
（11） 屏幕目标。
（12） 标准网格。

----------------------------
6.	ControllersSuite 

对控制器模块的单元测试，包括： 
（1）  控制器对象：ControlledTesting、★★★
			       ControlledObjectTesting。★★★
（2）  转换控制器。
（3）  皮肤控制器。
（4）  点控制器。
（5）  粒子控制器。
（6）  变形控制器。
（7）  关键帧控制器。
（8）  混合转换控制器。
（9）  反向运动控制器。

----------------------------
7.	ShaderFloatsSuite

对浮点着色器模块的单元测试，包括： 
（1） 摄像机浮点着色器。
（2） 光源浮点着色器。
（3） 材料浮点着色器。
（4） 矩阵浮点着色器。

----------------------------
8.	DetailSuite 

对细节模块的单元测试，包括： 
（1） 切换节点。
（2） 广告牌效果。
（3） 折叠记录。
（4） LOD网格。
（5） LOD节点。

----------------------------
9.	ShadersSuite 

对着色器模块的单元测试，包括： 
（1） 数据。
（2） 像素着色器。
（3） 顶点着色器。
（4） 状态。
（5） 视觉效果。 

----------------------------
10.	LocalEffectsSuite

对局部特效模块的单元测试，包括： 
（1） 光照局部特效。
（2） 材质局部特效。
（3） 纹理局部特效。
（3） 顶点着色局部特效。
 
----------------------------
11.	GlobalEffectsSuite

对全局特效模块的单元测试，包括： 
（1）全局特效。 

----------------------------
12.	CurvesSurfacesSuite

对曲线曲面模块的单元测试，包括： 
（1）  浮点数组。
（2）  表面细分计算。
（3）  盒子曲面。
（4）  B样条曲面。
（5）  曲线网格。
（6）  曲线线段。
（7）  曲线曲面。
（8）  正方形曲面。
（9）  管曲面。
（10） 反转曲面。 
 
----------------------------
13.	StateSuite

对状态模块的单元测试，包括： 
（1）状态。

---------------------------- 
14.	IlluminationSuite 

对光照模块的单元测试，包括： 
（1）光照。

----------------------------
15.	ImageProcessingSuite

对图像处理模块的单元测试，包括： 
（1）图像处理。
 
----------------------------
16.	PictureSuite

对图像模块的单元测试，包括： 
（1）图像。

----------------------------
17.	SortingSuite

对排序模块的单元测试，包括： 
（1）排序。

----------------------------
18.	TerrainSuite

对地形处理模块的单元测试，包括： 
（1）地形处理。

----------------------------
19.	VertexSuite

对顶点模块的单元测试，包括： 
（1）顶点。

---------------------------- 
20.	TextFontsSuite

对文本及字体模块的单元测试，包括： 
（1）文本及字体。

----------------------------
21.	ConsoleGraphSuite

对控制台图形模块的单元测试，包括： 
（1）控制台图形。

----------------------------
22.	OpenGLAPISuite

对OpenGLAPI模块的单元测试，包括： 
（1）OpenGLAPI。

----------------------------
23.	DirectAPISuite 

对DirectAPI模块的单元测试，包括： 
（1）DirectAPI。

----------------------------
24.	RendererEngineSuite

对渲染器模块的单元测试，包括： 
（1） 渲染基础：ViewportTesting、
				DepthRangeTesting、
				EnvironmentParameterTesting、
				RenderingEnvironmentTesting。
（2） 渲染参数：RendererBasisTesting、
			    WindowsParameterTesting、
				RendererParameterTesting。
（3） 顶点格式对象。
（4） 索引缓冲区。
（5） 顶点缓冲区。
（6） 纹理对象。
（7） 缓冲管理。
（8） 渲染目标。

----------------------------
25.	OpenGLRendererSuite

对OpenGL渲染器模块的单元测试，包括： 
（1）OpenGL渲染器。

----------------------------
26.	Dx9RendererSuite 

对Dx9渲染器模块的单元测试，包括： 
（1）Dx9渲染器。

----------------------------
27.	AglRendererSuite 

对Agl渲染器模块的单元测试，包括： 
（1）Agl渲染器。

----------------------------
28.	GlutRendererSuite

对Glut渲染器模块的单元测试，包括： 
（1）Glut渲染器。

----------------------------
29.	GlxRendererSuite

对Glx渲染器模块的单元测试，包括： 
（1）Glx渲染器。

----------------------------
30.	WglRendererSuite

对Wgl渲染器模块的单元测试，包括： 
（1）Wgl渲染器。

----------------------------
