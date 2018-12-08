////#include<iostream>
////#include <stdlib.h>
////#include <stdio.h>
////#include <glut.h>
////#include <cstdio>
////using namespace std;
////static int axis = 2;
////float theta[3] = { 0.0, 0.0, 0.0 };
////GLubyte image[64][64][3];
////int aa[1333][777][4], width = 512, height = 512;
////GLfloat ap[512][512][3];
////
////int PI = 3.1415926;
////int www = 666, hhh = 666;
////double r = 5;
////GLfloat speed = 1, rx, ry, rz, dx = 8, dy = 1, dz = 1;
////
////void show() {//绘制物体
////	//非正交投影
////
////	glColor3f(1.0, 1.0, 1.0);
////	double i, j, ii, jj, k, x, y, z, dt = 1, dr = 10;
////	i = -r, j = r, ii = -r, jj = r;
////	//绘制正方体
////
////	for (double q = i;q < j;q += dt)//左
////		for (double w = ii;w < jj;w += dt) {
////			glBegin(GL_POLYGON);
////
////			glTexCoord2f((q + r) / r / 4, (w + r) / r / 4);
////			glVertex3f(q, w, r);
////			glTexCoord2f((q + r) / r / 4, (w + r + dt) / r / 4);
////			glVertex3f(q, w + dt, r);
////			glTexCoord2f((q + r + dt) / r / 4, (w + r + dt) / r / 4);
////			glVertex3f(q + dt, w + dt, r);
////			glTexCoord2f((q + r + dt) / r / 4, (w + r) / r / 4);
////			glVertex3f(q + dt, w, r);
////			glEnd();
////		}
////	for (double q = i;q < j;q += dt)//右
////		for (double w = ii;w < jj;w += dt) {
////			glBegin(GL_POLYGON);
////
////
////			glTexCoord2f((q + r) / r / 4, (w + r) / r / 4);
////			glVertex3f(q, w, -r);
////			glTexCoord2f((q + r) / r / 4, (w + r + dt) / r / 4);
////			glVertex3f(q, w + dt, -r);
////			glTexCoord2f((q + r + dt) / r / 4, (w + r + dt) / r / 4);
////			glVertex3f(q + dt, w + dt, -r);
////			glTexCoord2f((q + r + dt) / r / 4, (w + r) / r / 4);
////			glVertex3f(q + dt, w, -r);
////			glEnd();
////		}
////
////
////	for (double q = i;q < j;q += dt)//前
////		for (double w = ii;w < jj;w += dt) {
////			glBegin(GL_POLYGON);
////
////			glTexCoord2f((w + r) / r / 4, (q + r) / r / 4);
////			glVertex3f(-r, q, w);
////			glTexCoord2f((w + r + dt) / r / 4, (q + r) / r / 4);
////			glVertex3f(-r, q, w + dt);
////			glTexCoord2f((w + r + dt) / r / 4, (q + r + dt) / r / 4);
////			glVertex3f(-r, q + dt, w + dt);
////			glTexCoord2f((w + r) / r / 4, (q + r + dt) / r / 4);
////			glVertex3f(-r, q + dt, w);
////			glEnd();
////		}
////	//上
////	//glColor3f(1.0,0.0,0.4);    
////	for (double q = i;q < j;q += dt)
////		for (double w = ii;w < jj;w += dt) {
////
////			glBegin(GL_POLYGON);//上
////			glTexCoord2f((q + r) / r / 4 + 0.5, (w + r) / r / 4 + 0.5);
////			glVertex3f(q, r, w);
////			glTexCoord2f((q + r) / r / 4 + 0.5, (w + r + dt) / r / 4 + 0.5);
////			glVertex3f(q, r, w + dt);
////			glTexCoord2f((q + r + dt) / r / 4 + 0.5, (w + r + dt) / r / 4 + 0.5);
////			glVertex3f(q + dt, r, w + dt);
////			glTexCoord2f((q + r + dt) / r / 4 + 0.5, (w + r) / r / 4 + 0.5);
////			glVertex3f(q + dt, r, w);
////			glEnd();
////		}
////	for (double q = i;q < j;q += dt)//下
////		for (double w = ii;w < jj;w += dt) {
////			glBegin(GL_POLYGON);
////			glTexCoord2f((q + r) / r / 4, (w + r) / r / 4 + 0.5);
////			glVertex3f(q, -r, w);
////			glTexCoord2f((q + r) / r / 4, (w + r + dt) / r / 4 + 0.5);
////			glVertex3f(q, -r, w + dt);
////			glTexCoord2f((q + r + dt) / r / 4, (w + r + dt) / r / 4 + 0.5);
////			glVertex3f(q + dt, -r, w + dt);
////			glTexCoord2f((q + r + dt) / r / 4, (w + r) / r / 4 + 0.5);
////			glVertex3f(q + dt, -r, w);
////			glEnd();
////		}
////	//绘制球
////	glTranslatef(-2, -3, -3);
////	glColor3f(0.1, 0.2, 0.7);
////	glutSolidSphere(1.4, 40, 40);
////	//绘制圆锥
////	glRotatef(-90, 1, 0, 0);
////	glTranslatef(1, -3, -2);
////	glColor3f(0.4, 0.7, 0.8);
////	glutSolidCone(1, 3, 10, 10);
////
////
////}
////
////void display()
////{
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//必须要做，清理缓存
////
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	gluPerspective(60.0, (GLfloat)www / (GLfloat)hhh, 1.0, 20.0);
////
////
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////	glMatrixMode(GL_MODELVIEW);
////	glEnable(GL_DEPTH_TEST);
////	glLoadIdentity();
////
////	gluLookAt(dx, dy, dz, 0, 0, 0, 0, 1, 0);
////
////	show();
////
////	glutSwapBuffers();
////
////}
////void reshape(GLsizei w, GLsizei h)
////{
////	float aspectRatio;
////	//设置视口
////	glViewport(0, 0, w, h);
////
////	//设置投影（取景）变换方式
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	aspectRatio = (GLfloat)w / (GLfloat)h;
////	gluPerspective(60, aspectRatio, 1, 30);
////
////	//设置模型变换和视图变换方式
////	glMatrixMode(GL_MODELVIEW);
////	glLoadIdentity();
////	gluLookAt(0.0, 0.0, 5.0,
////		0.0, 0.0, 0.0,
////		0.0, 1.0, 0.0);
////}
////void keyboard(unsigned char key, int x, int y)//定义键盘操作
////{
////	switch (key)
////	{
////		//控制位移的键
////	case 'u': case 'U':
////		dx += speed;
////		break;
////	case 'j': case 'J':
////		dx -= speed;
////		break;
////	case 'i': case 'I':
////		dy -= speed;
////		break;
////	case 'k': case 'K':
////		dy += speed;
////		break;
////	case 'o': case 'O':
////		dz += speed;
////		break;
////	case 'l': case 'L':
////		dz -= speed;
////		break;
////
////	}
////	glutPostRedisplay();
////}
////void SetupLights()
////{
////	GLfloat ambientLight[] = { 0.2f,  0.2f,  0.2f,  1.0f };//环境光  
////	GLfloat diffuseLight[] = { 0.9f,  0.9f,  0.9f,  1.0f };//漫反射  
////	GLfloat specularLight[] = { 1.0f,  1.0f,  1.0f,  1.0f };//镜面光  
////	GLfloat lightPos[] = { -4.0f, -4.0f, 4.0f, 1.0f };//光源位置  
////
////	glEnable(GL_LIGHTING);          //启用光照  
////	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);    //设置环境光源  
////	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);    //设置漫反射光源  
////	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);   //设置镜面光源  
////	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);        //设置灯光位置  
////	glEnable(GL_LIGHT0);            //打开第一个灯光  
////
////	glEnable(GL_COLOR_MATERIAL);    //启用材质的颜色跟踪  
////	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);  //指定材料着色的面  
////	glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight); //指定材料对镜面光的反应  
////	glMateriali(GL_FRONT, GL_SHININESS, 100);           //指定反射系数  
////}
////void init()
////{
////
////	glEnable(GL_DEPTH_TEST);
////	glEnable(GL_TEXTURE_2D);
////
////	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_FLOAT, ap);//设置纹理参数
////
////	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
////	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
////	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
////	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
////}
////int main(int argc, char* argv[])
////{
////
////	glutInit(&argc, argv);
////
////	//读入纹理
////	//freopen_s(&stream, "d:\\in.txt", "r", stdin);
////	freopen("F.txt", "r", stdin);
////	for (int q = 1;q <= 512;q++)
////		for (int e = 1;e <= 3;e++)
////			for (int w = 1;w <= 512;w++)
////			{
////				cin>>aa[height - q + 1][w][e];
////				if (q <= height && w <= width)
////					ap[height - q][w - 1][e - 1] = aa[height - q + 1][w][e] * 1.0 / 255;
////				if (e != 3 || w != width) scanf_s(",");
////
////			}
////	int co = 0;
////	printf("%d %d %d", aa[1][1][1], aa[1280][720][2], aa[131][123][3]);
////
////
////	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
////	glutInitWindowSize(500, 500);
////	glutInitWindowPosition(0, 0);
////	glutCreateWindow("room");
////	glutKeyboardFunc(keyboard);//键盘改变视点
////	SetupLights();//灯光
////	glutDisplayFunc(display);
////	glutReshapeFunc(reshape);
////
////	init();
////
////	glutMainLoop();
////
////
////	return 0;
////}
//#include<glut.h>
//#include<vector>
//
//
//GLuint tex_shadow; // 纹理名字
//GLfloat     torusAngle = 0.0;
//GLfloat     lightPos[] = { 1.0, 1.0, 0.0, 1.0 }; // 光源在世界坐标中的位置
// // 光源视角的投影矩阵
// // 光源视角的视图矩阵
///* 初始化材料属性、光源属性、光照模型，打开深度缓冲区等 */
//void init(void)
//{
//	//初始化光源
//	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat Light_Model_Ambient[] = { 0.2 , 0.2 , 0.2 , 1.0 };//全局环境光
//	GLfloat mat_shininess[] = { 50.0 };
//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
//
//	glClearColor(0, 0, 0, 0.0); //设置背景色为白色
//	//glColor3f(0, 0 ,0 );
//	glShadeModel(GL_SMOOTH);
//	//glShadeModel(GL_FLAT);//设置颜色插值为平面模式
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);//创建光源
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);//漫射光
//	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);//镜面光
//
//	//生成一个纹理
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,256, 256, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
//	//GL_DEPTH_COMPONENT:深度纹理格式，用于将深度值记录到这张图中
//	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);//创建光源
//	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
//	//初始化纹理（阴影图）
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
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
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//
//
//
//}

///*调用 GLUT 函数,绘制一个球*/
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//摄像机位置(1,1,1)
//
//	glColor3f(1.0, 0.0, 0.0);
//	glTranslatef(0.5, 0.11, 0.11);//平移
//	glRotatef(100.73, -0.5, 0.5, 0);//旋转
//	//glRotatef(torusAngle, 1, 0, 0);
//	glutSolidTorus(0.05,0.2,8,32);//圆环
//	DrawGround();
//	
//	//glutSolidSphere(0.5, 40, 50);    //半径为 1,40 条纬线,50 条经线的球
//	glFlush();
//}
///* 定义 GLUT 的 reshape 函数，w、h 分别是输出图形的窗口的宽和高*/
//void reshape(int w, int h)//截取图像显示
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
//			1.5* (GLfloat)h / (GLfloat)w, -10.0, 10.0); //创建平行视景体
//	else
//		glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)
//			w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);     // GLUT 环境初始化
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // 显示模式初始化
//	glutInitWindowSize(500, 500);       // 定义窗口大小
//	glutInitWindowPosition(100, 100);   // 定义窗口位置  
//	glutCreateWindow(argv[0]);   // 显示窗口,窗口标题为执行函数名
//	init();
//	glutDisplayFunc(display); 	// 注册 OpenGL 绘图函数(一种特殊的调用方式,下同) 
//	glutReshapeFunc(reshape);   // 注册窗口大小改变时的响应函数
//	glutMainLoop();      // 进入 GLUT 消息循环，开始执行程序
//	return 0;
//}