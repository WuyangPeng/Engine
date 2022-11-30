@ingroup group_SystemWindowsTesting_Documentation

----------------------------
系統库Windows单元测试

----------------------------
1.	SystemOutputSuite
对系统输出模块进行测试：
（1）消息框选择使用标志：MessageBoxSelectionUseFlagsDataWindowsTesting。
（2）消息框选择使用语言ID：MessageBoxSelectionUseLanguageIDDataWindowsTesting。

----------------------------
2.	DynamicLinkSuite
对动态链接库模块进行测试：
（1）加载资源工具：FindResourceWindowsTesting、LoadResourceWindowsTesting、LoadStringWindowsTesting。
（2）枚举资源工具：EnumResourceToolsTesting、ResourceEnumTesting。

----------------------------
3.	OpenGLSuite 
对OpenGL模块进行测试：
（1） OpenGL Wgl 原型：OpenGLWglPrototypesTesting。

----------------------------
4.	WindowsSuite 
对Windows模块进行测试：
（1） Windows创建：WindowsCreateTesting。
（2） Windows进程：GetMessageTesting、
                   PeekMessageTesting、
                   PostQuitMessageTesting、
                   ValidateRectTesting、
                   DefWindowProcTesting、
                   MessageBoxTesting、
                   DestroyWindowTesting、
                   SendMessageTesting、
                   GetCommandLineTesting、
                   WindowPaintTesting。
（3） Windows注册：GetStockObjectTesting、
                   LoadCursorTesting、
                   LoadIconTesting、
                   RegisterClassTesting、
                   RegisterWindowMessageTesting。
（4） Windows字体信息：WindowsFontInformationTesting。
（5） Windows用户：WindowsUserTesting。

----------------------------
