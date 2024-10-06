#include <GL/freeglut.h>  // GLUT�� OpenGL ��� ���� ����
#include <stdio.h>        // printf ����� ���� ��� ����

// ���� ��ǥ �迭 (8���� ����)
GLfloat MyVertices[8][3] = {
    {-0.25, -0.25,  0.25},
    {-0.25,  0.25,  0.25},
    { 0.25,  0.25,  0.25},
    { 0.25, -0.25,  0.25},
    {-0.25, -0.25, -0.25},
    {-0.25,  0.25, -0.25},
    { 0.25,  0.25, -0.25},
    { 0.25, -0.25, -0.25}
};

// ���� ���� �迭
GLfloat MyColors[8][3] = {
    {0.2, 0.2, 0.2},
    {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 1.0, 1.0},
    {0.0, 1.0, 1.0}
};

// ���÷��� �ݹ� �Լ�
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);  // ȭ�� �����

    // ���� 0, 3, 2, 1�� ������ ���� �׸��� (�ݽð� ����)
    glBegin(GL_POLYGON);
    glColor3fv(MyColors[0]); glVertex3fv(MyVertices[0]);  // ����� ���� ����
    glColor3fv(MyColors[3]); glVertex3fv(MyVertices[3]);
    glColor3fv(MyColors[2]); glVertex3fv(MyVertices[2]);
    glColor3fv(MyColors[1]); glVertex3fv(MyVertices[1]);
    glEnd();

    glFlush();  // �׸��� ��� ����
}

// ���� �Լ�
int main(int argc, char** argv) {
    // GLUT �ʱ�ȭ
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);  // ������ ũ�� ����
    glutCreateWindow("OpenGL Drawing Example");  // ������ ����

    // ȭ�� ���� �ݹ� �Լ� ���
    glutDisplayFunc(MyDisplay);

    // ���� �̺�Ʈ ���� ����
    glutMainLoop();

    return 0;
}
