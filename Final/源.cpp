//#include <glew.h>
////#include<glut.h>
//#include<freeglut.h>
////#include<GLFW/glfw3.h>
//#include<stdlib.h>
//#include<math.h>
//#define FREEGLUT_STATIC
//#ifdef GL_ARB_shadow
//#define GL_TEXTURE_COMPARE_MODE      GL_TEXTURE_COMPARE_MODE_ARB
//#define GL_TEXTURE_COMPARE_FUNC      GL_TEXTURE_COMPARE_FUNC_ARB
//#define GL_DEPTH_TEXTURE_MODE        GL_DEPTH_TEXTURE_MODE_ARB
//#define GL_COMPARE_R_TO_TEXTURE      GL_COMPARE_R_TO_TEXTURE_ARB
//#endif
//#pragma comment(lib,"glew32.lib")
//#pragma comment(lib,"freeglut.lib")
//
//#define PI       3.14159265359
//GLdouble innerRadius = 0.05;
//GLdouble outerRadius = 0.2;
//GLint nsides = 15;
//GLint rings = 30;
//
//
//GLdouble    fovy = 60.0;
//GLdouble    nearPlane = 10.0;
//GLdouble    farPlane = 100.0;
//
//GLfloat     angle = 0.0;
//GLfloat     torusAngle = 0.0;
//GLfloat  white[] = { 1.0, 1.0, 1.0, 1.0 };
//GLfloat     lightPos[] = { 1.0, 1.0, 1.0, 1.0 };
//GLfloat     lookat[] = { 1.0, 1.0, 1.0 };
//GLfloat     up[] = { 0.0, 0.0, 1.0 };
//GLboolean showShadow = GL_FALSE;
//void init(void)
//
//{
//	//GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	//GLfloat mat_shininess[] = { 50.0 };
//	//GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };//光源位置
//	//GLfloat white_light[] = { 0.5, 1.0, 1.0, 1.0 };
//	//GLfloat Light_Model_Ambient[] = { 0.2 , 0.2 , 0.2 , 1.0 }; //全局环境光,第四个参数为透明度
//	//glClearColor(0.0, 0.0, 0.0, 0.0);
//	//glShadeModel(GL_SMOOTH);
//	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);//创建光源
//	//glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);//漫射光
//	//glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);//镜面光
//	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient); //全局环境光
//	//glEnable(GL_LIGHTING);
//	//glEnable(GL_LIGHT0);
//	//glEnable(GL_DEPTH_TEST);
//
//	//根据指定的参数，生成一个2D纹理
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
//		256, 256, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);//GL_DEPTH_COMPONENT:深度纹理格式，用于将深度值记录到这张图中
//
//	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);//创建光源
//	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
//	//设置阴影图相关过滤方式
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	/*深度纹理特有*/
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);//比较规则
//	glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_LUMINANCE);//阴影图亮度
//	/*分为普通对比模式（GL_NONE）和引用到贴图对比模式（GL_COMPARE_REF_TO_TEXTURE）,后者使用的深度纹理贴图是线性过滤的，而前者是直接填充。*/
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
//
//	//自动生成纹理坐标
//	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//	//设置材质
//	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//
//	glCullFace(GL_BACK);//剔除背面
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_TEXTURE_2D);
//	glEnable(GL_TEXTURE_GEN_S);
//	glEnable(GL_TEXTURE_GEN_T);
//	glEnable(GL_TEXTURE_GEN_R);
//	glEnable(GL_TEXTURE_GEN_Q);
//	glEnable(GL_COLOR_MATERIAL);//激活颜色材料模式
//	glEnable(GL_CULL_FACE);//激活表面剔除
//}
//
//
///*绘制场景上对象*/
//void drawObjects(GLboolean shadowRender)
//{
//	GLboolean textureOn = glIsEnabled(GL_TEXTURE_2D);
//
//	if (shadowRender)
//		glDisable(GL_TEXTURE_2D);
//
//	//绘制矩形
//	if (!shadowRender) {
//		glNormal3f(0, 0, 1);
//		glColor3f(1, 1, 1);
//		glRectf(-20.0, -20.0, 20.0, 20.0);
//	}
//	//红色圆环
//	glPushMatrix();
//	glTranslatef(11, 11, 11);
//	glRotatef(54.73, -5, 5, 0);
//	glRotatef(torusAngle, 1, 0, 0);
//	glColor3f(1, 0, 0);
//	glutSolidTorus(0.1, 0.4, 8, 36);
//	glPopMatrix();
//	//蓝色立方体
//	glPushMatrix();
//	glTranslatef(2, 2, 2);
//	glColor3f(0, 0, 1);
//	glutSolidCube(0.4);
//	glPopMatrix();
//	//线框圆表光源
//	glPushMatrix();
//	glTranslatef(lightPos[0], lightPos[1], lightPos[2]);
//	glColor3f(1, 1, 1);
//	glutWireSphere(0.5, 6, 6);
//	glPopMatrix();
//
//	if (shadowRender && textureOn)
//		glEnable(GL_TEXTURE_2D);
//}
///*生成阴影图*/
//void generateShadowMap(void)
//{
//	GLint    viewport[4];
//	GLfloat  lightPos[4];
//
//	glGetLightfv(GL_LIGHT0, GL_POSITION, lightPos);//获得光源的位置
//	glGetIntegerv(GL_VIEWPORT, viewport);//获得视口信息
//
//	glViewport(0, 0, 256, 256);//设置视口与阴影图大小匹配
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	gluPerspective(80.0, 1.0, 10.0, 1000.0);
//	glMatrixMode(GL_MODELVIEW);
//
//	glPushMatrix();
//	glLoadIdentity();
//	gluLookAt(lightPos[0], lightPos[1], lightPos[2],
//		lookat[0], lookat[1], lookat[2],
//		up[0], up[1], up[2]);//把摄像机放到光源处
//
//	drawObjects(GL_TRUE);//绘制场景
//
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//
//	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 0, 0, 256, 256, 0);//摄像机移到光源处渲染的阴影图
//
//	glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);//恢复当前视口
//
//	//绘制阴影图
//	if (showShadow) {
//		GLfloat depthImage[256][256];
//		glReadPixels(0, 0, 256, 256, GL_DEPTH_COMPONENT, GL_FLOAT, depthImage);
//		glWindowPos2f(viewport[2] / 2, 0);//设置阴影图绘制位置
//		glDrawPixels(256, 256, GL_LUMINANCE,
//			GL_FLOAT, depthImage);
//		glutSwapBuffers();
//	}
//}
//void idle(void)
//{
//	angle += PI / 10000;
//	torusAngle += .1;
//	glutPostRedisplay();
//}
//
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 27:  /* Escape */
//		exit(0);
//		break;
//		//开启与关闭纹理贴图
//	case 't': {
//		static GLboolean textureOn = GL_TRUE;
//		textureOn = !textureOn;
//		if (textureOn)
//			glEnable(GL_TEXTURE_2D);
//		else
//			glDisable(GL_TEXTURE_2D);
//	}
//			  break;
//			  //深度纹理贴图的两种模式对比
//	case 'm': {
//		static GLboolean compareMode = GL_TRUE;
//		compareMode = !compareMode;
//		//printf("Compare mode %s\n", compareMode ? "On" : "Off");
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE,
//			compareMode ? GL_COMPARE_R_TO_TEXTURE : GL_NONE);
//	}
//			  break;
//			  //比较规则切换
//	case 'f': {
//		static GLboolean funcMode = GL_TRUE;
//		funcMode = !funcMode;
//		//printf("Operator %s\n", funcMode ? "GL_LEQUAL" : "GL_GEQUAL");
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, funcMode ? GL_LEQUAL : GL_GEQUAL);//当前片段z与阴影图z比较规则(<=, >=)
//	}
//			  break;
//			  //是否显示阴影图
//	case 's':
//		showShadow = !showShadow;
//		break;
//		//运动与停止
//	case 'p': {
//		static GLboolean  animate = GL_TRUE;
//		animate = !animate;
//		glutIdleFunc(animate ? idle : NULL);
//	}
//			  break;
//	}
//
//	glutPostRedisplay();
//}
//
//void transposeMatrix(GLfloat m[16])
//{
//	GLfloat  tmp;
//#define Swap( a, b )    tmp = a; a = b; b = tmp
//	Swap(m[1], m[4]);
//	Swap(m[2], m[8]);
//	Swap(m[3], m[12]);
//	Swap(m[6], m[9]);
//	Swap(m[7], m[13]);
//	Swap(m[11], m[14]);
//#undef Swap
//}
////自动生成阴影图的纹理坐标
//void generateTextureMatrix(void)
//{
//	GLfloat  tmpMatrix[16];
//
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(0.5, 0.5, 0.0);
//	glScalef(0.5, 0.5, 1.0);
//	gluPerspective(60.0, 1.0, 1.0, 1000.0);
//	gluLookAt(lightPos[0], lightPos[1], lightPos[2],
//		lookat[0], lookat[1], lookat[2],
//		up[0], up[1], up[2]);
//	glGetFloatv(GL_MODELVIEW_MATRIX, tmpMatrix);
//	glPopMatrix();
//
//	transposeMatrix(tmpMatrix);
//
//	glTexGenfv(GL_S, GL_OBJECT_PLANE, &tmpMatrix[0]);
//	glTexGenfv(GL_T, GL_OBJECT_PLANE, &tmpMatrix[4]);
//	glTexGenfv(GL_R, GL_OBJECT_PLANE, &tmpMatrix[8]);
//	glTexGenfv(GL_Q, GL_OBJECT_PLANE, &tmpMatrix[12]);
//}
////渲染
//void display(void)
//{
//	GLfloat  radius = 30;
//
//	generateShadowMap();
//	generateTextureMatrix();
//
//	if (showShadow)
//		return;
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glPushMatrix();
//	gluLookAt(radius*cos(angle), radius*sin(angle), 30,
//		lookat[0], lookat[1], lookat[2],
//		up[0], up[1], up[2]);
//	drawObjects(GL_FALSE);
//	glPopMatrix();
//
//	glutSwapBuffers();
//
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glutSolidSphere (1.0, 20, 16);
//	glutSolidTeapot(0.2);
//	glutSolidTorus(innerRadius, outerRadius, nsides, rings);
//	glFlush();
//}
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//视口大小：w*h
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();//恢复初始坐标系
//	if (w <= h)
//		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w,
//			1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
//	else
//		glOrtho(-1.5*(GLfloat)w / (GLfloat)h,
//			1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);//创建一个正交平行的视景体
//	glMatrixMode(GL_MODELVIEW);
//	//GL_PROJECTION 投影, GL_MODELVIEW 模型视图, GL_TEXTURE 纹理.
//	glLoadIdentity();
//}
//int main(int argc, char** argv)
//
//{   
//	
//	//glWindowPos2f = (PFNGLWINDOWPOS2FARBPROC)glutGetProcAddress("glWindowPos2f");
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);//设置初始显示模式:单缓存,RGB颜色模式,窗口使用深度缓存
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glWindowPos2f = (PFNGLWINDOWPOS2FARBPROC)glutGetProcAddress("glWindowPos2f");
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//
//	glutKeyboardFunc(keyboard);
//	glutIdleFunc(idle);
//	glutMainLoop();
//
//	return 0;
//
//
//}

#include<glut.h>
GLfloat fLightPos[4] = { -100.0f, 100.0f, 50.0f, 1.0f };
GLfloat fLightPosMirror[4] = { -100.0f, -100.0f, 50.0f, 1.0f };
GLfloat fNoLight[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
GLfloat fLowLight[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat fBrightLight[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

static GLfloat yRot = 20.0f;

void SetupRC()
{
	glClearColor(fLowLight[0], fLowLight[1], fLowLight[2], fLowLight[3]);

	glCullFace(GL_BACK);//剔除背面
	glFrontFace(GL_CCW);//前面多边形的方向，默认值为GL_CCW
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, fNoLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, fNoLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, fLowLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, fBrightLight);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMateriali(GL_FRONT, GL_SHININESS, 128);//材质属性的镜面反射指数 
}

void DrawGround()
{
	GLfloat fExtent = 10.0f;
	GLfloat fStep = 0.8f;
	GLfloat y = 0.0f;
	GLfloat fColor;
	GLfloat iStrip, iRun;
	GLint iBounce = 0;
	glShadeModel(GL_SMOOTH);
	//glShadeModel(GL_FLAT);
	for (iStrip = -fExtent; iStrip <= fExtent; iStrip += fStep)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (iRun = fExtent; iRun >= -fExtent; iRun -= fStep)
		{
			if ((iBounce % 2) == 0)
				fColor = 1.0f;
			else
				fColor = 0.0f;

			glColor4f(fColor, fColor, fColor, 0.5f);
			glVertex3f(iStrip, y, iRun);//连续
			glVertex3f(iStrip + fStep, y, iRun);

			iBounce++;
		}
		glEnd();
	}
	glShadeModel(GL_SMOOTH);
}

void DrawSphere()
{
	//gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//摄像机位置(1,1,1)
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0.0f, 0.5f, -4.5f);//此时坐标系是颠倒的
	glPushMatrix();
	glRotatef(-yRot * 2.0f, 0.0f, 1.0f, 0.0f);
	glutSolidCube(0.4);
	//glutSolidSphere(0.12f, 32, 9);
	glPopMatrix();

	//glRotatef(yRot, 0.0f, 0.0f, 1.0f);

	glPopMatrix();
}

void RenderScene()
{
	// 清空颜色缓冲区和深度缓冲区
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// 首先绘制地板下方的球体
	// 保存矩阵状态
	glPushMatrix();
	// 将光源0的位置摆放到地板下方
	glLightfv(GL_LIGHT0, GL_POSITION, fLightPosMirror);
	// 保存矩阵状态
	glPushMatrix();
	// 设置顺时针环绕的一面为多边形的正面，对多边形进行镜像
	glFrontFace(GL_CW);
	// 在Y轴使用-1的缩放因子来反转Y轴
	glScalef(1.0f, -1.0f, 1.0f);

	// 绘制地板下方的球体
	DrawSphere();
	// 设置逆时针环绕的一面为多边形的正面
	glFrontFace(GL_CCW);
	// 恢复矩阵状态
	glPopMatrix();

	// 对地板设置透明的颜色混合效果，来实现反射的幻觉 
	// 关闭光照计算
	glDisable(GL_LIGHTING);
	// 打开颜色混合
	glEnable(GL_BLEND);
	// 设置混合因子
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// 绘制地板
	DrawGround();
	// 关闭颜色混合
	glDisable(GL_BLEND);
	// 打开光照计算
	glEnable(GL_LIGHTING);

	// 最后绘制地板上方的球体 
	// 将光源0的位置摆放到地板上面
	glLightfv(GL_LIGHT0, GL_POSITION, fLightPos);

	// 绘制地板上方的球体
	DrawSphere();
	// 恢复矩阵状态
	glPopMatrix();

	// 执行缓冲区的交换
	glutSwapBuffers();
}

void TimerFunction(int value)
{
	yRot += 1.0f;
	glutPostRedisplay();
	glutTimerFunc(1, TimerFunction, 1);
}

void ChangeSize(int w, int h)
{
	GLfloat fAspect;

	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);
	fAspect = (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);//把物体投影到一个平面上，对投影矩阵进行操作
	glLoadIdentity();

   //透视，生成的矩阵与当前的矩阵相乘，生成透视效果
	gluPerspective(35.0f, fAspect, 1.0f, 50.0f);
	//para：眼睛上下睁开的幅度，裁剪面的宽高比（影响到视野的截面有多大），近/远裁剪面到眼睛的距离

	glMatrixMode(GL_MODELVIEW);//对模型视景进行操作
	glLoadIdentity();
	glTranslatef(0.0f, -0.4f, 0.0f);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Final");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	//glutTimerFunc(10, TimerFunction, 1);
	SetupRC();
	glutMainLoop();

	return 0;
}