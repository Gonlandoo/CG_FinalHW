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
//	//GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };//��Դλ��
//	//GLfloat white_light[] = { 0.5, 1.0, 1.0, 1.0 };
//	//GLfloat Light_Model_Ambient[] = { 0.2 , 0.2 , 0.2 , 1.0 }; //ȫ�ֻ�����,���ĸ�����Ϊ͸����
//	//glClearColor(0.0, 0.0, 0.0, 0.0);
//	//glShadeModel(GL_SMOOTH);
//	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);//������Դ
//	//glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);//�����
//	//glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);//�����
//	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient); //ȫ�ֻ�����
//	//glEnable(GL_LIGHTING);
//	//glEnable(GL_LIGHT0);
//	//glEnable(GL_DEPTH_TEST);
//
//	//����ָ���Ĳ���������һ��2D����
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
//		256, 256, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);//GL_DEPTH_COMPONENT:��������ʽ�����ڽ����ֵ��¼������ͼ��
//
//	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);//������Դ
//	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
//	//������Ӱͼ��ع��˷�ʽ
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	/*�����������*/
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);//�ȽϹ���
//	glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_LUMINANCE);//��Ӱͼ����
//	/*��Ϊ��ͨ�Ա�ģʽ��GL_NONE�������õ���ͼ�Ա�ģʽ��GL_COMPARE_REF_TO_TEXTURE��,����ʹ�õ����������ͼ�����Թ��˵ģ���ǰ����ֱ����䡣*/
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
//
//	//�Զ�������������
//	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//	//���ò���
//	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//
//	glCullFace(GL_BACK);//�޳�����
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_TEXTURE_2D);
//	glEnable(GL_TEXTURE_GEN_S);
//	glEnable(GL_TEXTURE_GEN_T);
//	glEnable(GL_TEXTURE_GEN_R);
//	glEnable(GL_TEXTURE_GEN_Q);
//	glEnable(GL_COLOR_MATERIAL);//������ɫ����ģʽ
//	glEnable(GL_CULL_FACE);//��������޳�
//}
//
//
///*���Ƴ����϶���*/
//void drawObjects(GLboolean shadowRender)
//{
//	GLboolean textureOn = glIsEnabled(GL_TEXTURE_2D);
//
//	if (shadowRender)
//		glDisable(GL_TEXTURE_2D);
//
//	//���ƾ���
//	if (!shadowRender) {
//		glNormal3f(0, 0, 1);
//		glColor3f(1, 1, 1);
//		glRectf(-20.0, -20.0, 20.0, 20.0);
//	}
//	//��ɫԲ��
//	glPushMatrix();
//	glTranslatef(11, 11, 11);
//	glRotatef(54.73, -5, 5, 0);
//	glRotatef(torusAngle, 1, 0, 0);
//	glColor3f(1, 0, 0);
//	glutSolidTorus(0.1, 0.4, 8, 36);
//	glPopMatrix();
//	//��ɫ������
//	glPushMatrix();
//	glTranslatef(2, 2, 2);
//	glColor3f(0, 0, 1);
//	glutSolidCube(0.4);
//	glPopMatrix();
//	//�߿�Բ���Դ
//	glPushMatrix();
//	glTranslatef(lightPos[0], lightPos[1], lightPos[2]);
//	glColor3f(1, 1, 1);
//	glutWireSphere(0.5, 6, 6);
//	glPopMatrix();
//
//	if (shadowRender && textureOn)
//		glEnable(GL_TEXTURE_2D);
//}
///*������Ӱͼ*/
//void generateShadowMap(void)
//{
//	GLint    viewport[4];
//	GLfloat  lightPos[4];
//
//	glGetLightfv(GL_LIGHT0, GL_POSITION, lightPos);//��ù�Դ��λ��
//	glGetIntegerv(GL_VIEWPORT, viewport);//����ӿ���Ϣ
//
//	glViewport(0, 0, 256, 256);//�����ӿ�����Ӱͼ��Сƥ��
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
//		up[0], up[1], up[2]);//��������ŵ���Դ��
//
//	drawObjects(GL_TRUE);//���Ƴ���
//
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//
//	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 0, 0, 256, 256, 0);//������Ƶ���Դ����Ⱦ����Ӱͼ
//
//	glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);//�ָ���ǰ�ӿ�
//
//	//������Ӱͼ
//	if (showShadow) {
//		GLfloat depthImage[256][256];
//		glReadPixels(0, 0, 256, 256, GL_DEPTH_COMPONENT, GL_FLOAT, depthImage);
//		glWindowPos2f(viewport[2] / 2, 0);//������Ӱͼ����λ��
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
//		//������ر�������ͼ
//	case 't': {
//		static GLboolean textureOn = GL_TRUE;
//		textureOn = !textureOn;
//		if (textureOn)
//			glEnable(GL_TEXTURE_2D);
//		else
//			glDisable(GL_TEXTURE_2D);
//	}
//			  break;
//			  //���������ͼ������ģʽ�Ա�
//	case 'm': {
//		static GLboolean compareMode = GL_TRUE;
//		compareMode = !compareMode;
//		//printf("Compare mode %s\n", compareMode ? "On" : "Off");
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE,
//			compareMode ? GL_COMPARE_R_TO_TEXTURE : GL_NONE);
//	}
//			  break;
//			  //�ȽϹ����л�
//	case 'f': {
//		static GLboolean funcMode = GL_TRUE;
//		funcMode = !funcMode;
//		//printf("Operator %s\n", funcMode ? "GL_LEQUAL" : "GL_GEQUAL");
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, funcMode ? GL_LEQUAL : GL_GEQUAL);//��ǰƬ��z����Ӱͼz�ȽϹ���(<=, >=)
//	}
//			  break;
//			  //�Ƿ���ʾ��Ӱͼ
//	case 's':
//		showShadow = !showShadow;
//		break;
//		//�˶���ֹͣ
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
////�Զ�������Ӱͼ����������
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
////��Ⱦ
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
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//�ӿڴ�С��w*h
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();//�ָ���ʼ����ϵ
//	if (w <= h)
//		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w,
//			1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
//	else
//		glOrtho(-1.5*(GLfloat)w / (GLfloat)h,
//			1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);//����һ������ƽ�е��Ӿ���
//	glMatrixMode(GL_MODELVIEW);
//	//GL_PROJECTION ͶӰ, GL_MODELVIEW ģ����ͼ, GL_TEXTURE ����.
//	glLoadIdentity();
//}
//int main(int argc, char** argv)
//
//{   
//	
//	//glWindowPos2f = (PFNGLWINDOWPOS2FARBPROC)glutGetProcAddress("glWindowPos2f");
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);//���ó�ʼ��ʾģʽ:������,RGB��ɫģʽ,����ʹ����Ȼ���
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

	glCullFace(GL_BACK);//�޳�����
	glFrontFace(GL_CCW);//ǰ�����εķ���Ĭ��ֵΪGL_CCW
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
	glMateriali(GL_FRONT, GL_SHININESS, 128);//�������Եľ��淴��ָ�� 
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
			glVertex3f(iStrip, y, iRun);//����
			glVertex3f(iStrip + fStep, y, iRun);

			iBounce++;
		}
		glEnd();
	}
	glShadeModel(GL_SMOOTH);
}

void DrawSphere()
{
	//gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//�����λ��(1,1,1)
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0.0f, 0.5f, -4.5f);//��ʱ����ϵ�ǵߵ���
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
	// �����ɫ����������Ȼ�����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// ���Ȼ��Ƶذ��·�������
	// �������״̬
	glPushMatrix();
	// ����Դ0��λ�ðڷŵ��ذ��·�
	glLightfv(GL_LIGHT0, GL_POSITION, fLightPosMirror);
	// �������״̬
	glPushMatrix();
	// ����˳ʱ�뻷�Ƶ�һ��Ϊ����ε����棬�Զ���ν��о���
	glFrontFace(GL_CW);
	// ��Y��ʹ��-1��������������תY��
	glScalef(1.0f, -1.0f, 1.0f);

	// ���Ƶذ��·�������
	DrawSphere();
	// ������ʱ�뻷�Ƶ�һ��Ϊ����ε�����
	glFrontFace(GL_CCW);
	// �ָ�����״̬
	glPopMatrix();

	// �Եذ�����͸������ɫ���Ч������ʵ�ַ���Ļþ� 
	// �رչ��ռ���
	glDisable(GL_LIGHTING);
	// ����ɫ���
	glEnable(GL_BLEND);
	// ���û������
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ���Ƶذ�
	DrawGround();
	// �ر���ɫ���
	glDisable(GL_BLEND);
	// �򿪹��ռ���
	glEnable(GL_LIGHTING);

	// �����Ƶذ��Ϸ������� 
	// ����Դ0��λ�ðڷŵ��ذ�����
	glLightfv(GL_LIGHT0, GL_POSITION, fLightPos);

	// ���Ƶذ��Ϸ�������
	DrawSphere();
	// �ָ�����״̬
	glPopMatrix();

	// ִ�л������Ľ���
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

	glMatrixMode(GL_PROJECTION);//������ͶӰ��һ��ƽ���ϣ���ͶӰ������в���
	glLoadIdentity();

   //͸�ӣ����ɵľ����뵱ǰ�ľ�����ˣ�����͸��Ч��
	gluPerspective(35.0f, fAspect, 1.0f, 50.0f);
	//para���۾����������ķ��ȣ��ü���Ŀ�߱ȣ�Ӱ�쵽��Ұ�Ľ����ж�󣩣���/Զ�ü��浽�۾��ľ���

	glMatrixMode(GL_MODELVIEW);//��ģ���Ӿ����в���
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