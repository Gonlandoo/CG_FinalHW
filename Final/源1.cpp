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
////void show() {//��������
////	//������ͶӰ
////
////	glColor3f(1.0, 1.0, 1.0);
////	double i, j, ii, jj, k, x, y, z, dt = 1, dr = 10;
////	i = -r, j = r, ii = -r, jj = r;
////	//����������
////
////	for (double q = i;q < j;q += dt)//��
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
////	for (double q = i;q < j;q += dt)//��
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
////	for (double q = i;q < j;q += dt)//ǰ
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
////	//��
////	//glColor3f(1.0,0.0,0.4);    
////	for (double q = i;q < j;q += dt)
////		for (double w = ii;w < jj;w += dt) {
////
////			glBegin(GL_POLYGON);//��
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
////	for (double q = i;q < j;q += dt)//��
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
////	//������
////	glTranslatef(-2, -3, -3);
////	glColor3f(0.1, 0.2, 0.7);
////	glutSolidSphere(1.4, 40, 40);
////	//����Բ׶
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
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//����Ҫ����������
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
////	//�����ӿ�
////	glViewport(0, 0, w, h);
////
////	//����ͶӰ��ȡ�����任��ʽ
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	aspectRatio = (GLfloat)w / (GLfloat)h;
////	gluPerspective(60, aspectRatio, 1, 30);
////
////	//����ģ�ͱ任����ͼ�任��ʽ
////	glMatrixMode(GL_MODELVIEW);
////	glLoadIdentity();
////	gluLookAt(0.0, 0.0, 5.0,
////		0.0, 0.0, 0.0,
////		0.0, 1.0, 0.0);
////}
////void keyboard(unsigned char key, int x, int y)//������̲���
////{
////	switch (key)
////	{
////		//����λ�Ƶļ�
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
////	GLfloat ambientLight[] = { 0.2f,  0.2f,  0.2f,  1.0f };//������  
////	GLfloat diffuseLight[] = { 0.9f,  0.9f,  0.9f,  1.0f };//������  
////	GLfloat specularLight[] = { 1.0f,  1.0f,  1.0f,  1.0f };//�����  
////	GLfloat lightPos[] = { -4.0f, -4.0f, 4.0f, 1.0f };//��Դλ��  
////
////	glEnable(GL_LIGHTING);          //���ù���  
////	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);    //���û�����Դ  
////	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);    //�����������Դ  
////	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);   //���þ����Դ  
////	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);        //���õƹ�λ��  
////	glEnable(GL_LIGHT0);            //�򿪵�һ���ƹ�  
////
////	glEnable(GL_COLOR_MATERIAL);    //���ò��ʵ���ɫ����  
////	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);  //ָ��������ɫ����  
////	glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight); //ָ�����϶Ծ����ķ�Ӧ  
////	glMateriali(GL_FRONT, GL_SHININESS, 100);           //ָ������ϵ��  
////}
////void init()
////{
////
////	glEnable(GL_DEPTH_TEST);
////	glEnable(GL_TEXTURE_2D);
////
////	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_FLOAT, ap);//�����������
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
////	//��������
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
////	glutKeyboardFunc(keyboard);//���̸ı��ӵ�
////	SetupLights();//�ƹ�
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
//GLuint tex_shadow; // ��������
//GLfloat     torusAngle = 0.0;
//GLfloat     lightPos[] = { 1.0, 1.0, 0.0, 1.0 }; // ��Դ�����������е�λ��
// // ��Դ�ӽǵ�ͶӰ����
// // ��Դ�ӽǵ���ͼ����
///* ��ʼ���������ԡ���Դ���ԡ�����ģ�ͣ�����Ȼ������� */
//void init(void)
//{
//	//��ʼ����Դ
//	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat Light_Model_Ambient[] = { 0.2 , 0.2 , 0.2 , 1.0 };//ȫ�ֻ�����
//	GLfloat mat_shininess[] = { 50.0 };
//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
//
//	glClearColor(0, 0, 0, 0.0); //���ñ���ɫΪ��ɫ
//	//glColor3f(0, 0 ,0 );
//	glShadeModel(GL_SMOOTH);
//	//glShadeModel(GL_FLAT);//������ɫ��ֵΪƽ��ģʽ
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);//������Դ
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);//�����
//	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);//�����
//
//	//����һ������
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,256, 256, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
//	//GL_DEPTH_COMPONENT:��������ʽ�����ڽ����ֵ��¼������ͼ��
//	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);//������Դ
//	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
//	//��ʼ��������Ӱͼ��
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
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
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//
//
//
//}

///*���� GLUT ����,����һ����*/
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//�����λ��(1,1,1)
//
//	glColor3f(1.0, 0.0, 0.0);
//	glTranslatef(0.5, 0.11, 0.11);//ƽ��
//	glRotatef(100.73, -0.5, 0.5, 0);//��ת
//	//glRotatef(torusAngle, 1, 0, 0);
//	glutSolidTorus(0.05,0.2,8,32);//Բ��
//	DrawGround();
//	
//	//glutSolidSphere(0.5, 40, 50);    //�뾶Ϊ 1,40 ��γ��,50 �����ߵ���
//	glFlush();
//}
///* ���� GLUT �� reshape ������w��h �ֱ������ͼ�εĴ��ڵĿ�͸�*/
//void reshape(int w, int h)//��ȡͼ����ʾ
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
//			1.5* (GLfloat)h / (GLfloat)w, -10.0, 10.0); //����ƽ���Ӿ���
//	else
//		glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)
//			w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);     // GLUT ������ʼ��
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // ��ʾģʽ��ʼ��
//	glutInitWindowSize(500, 500);       // ���崰�ڴ�С
//	glutInitWindowPosition(100, 100);   // ���崰��λ��  
//	glutCreateWindow(argv[0]);   // ��ʾ����,���ڱ���Ϊִ�к�����
//	init();
//	glutDisplayFunc(display); 	// ע�� OpenGL ��ͼ����(һ������ĵ��÷�ʽ,��ͬ) 
//	glutReshapeFunc(reshape);   // ע�ᴰ�ڴ�С�ı�ʱ����Ӧ����
//	glutMainLoop();      // ���� GLUT ��Ϣѭ������ʼִ�г���
//	return 0;
//}