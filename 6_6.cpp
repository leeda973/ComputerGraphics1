#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

static int Day = 0, Time = 0;
static int autoRotate = 0; // �ڵ� ȸ�� �÷���

// ���� ����
void SetLighting() {
    GLfloat light_position[] = { 0.0, 0.0, 1.5, 1.0 }; // �¾翡�� ������ ���� ��ġ
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glEnable(GL_LIGHTING);   
    glEnable(GL_LIGHT0);     
    glEnable(GL_DEPTH_TEST); 
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity();


    glRotatef(90.0, 1.0, 0.0, 0.0);

    // �¾� �׸��� (������ ����)
    GLfloat sun_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat sun_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sun_ambient); 
    glutSolidSphere(0.2, 20, 16); // ��ü ��ü�� �¾� �׸���

    // ���� ���� �� ����
    glPushMatrix();
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.7, 0.0, 0.0);           
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0); 

    // ���� �׸���
    GLfloat earth_ambient[] = { 0.0, 0.0, 1.0, 1.0 }; 
    GLfloat earth_diffuse[] = { 0.0, 0.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, earth_ambient); 
    glutSolidSphere(0.1, 10, 8);  

    // ���� ���� �� ����
    glPushMatrix();
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0); 
    glTranslatef(0.2, 0.0, 0.0);            

    // �� �׸���
    GLfloat moon_ambient[] = { 1.0, 1.0, 0.0, 1.0 }; 
    GLfloat moon_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, moon_ambient); 
    glutSolidSphere(0.04, 10, 8);            

    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void Timer(int value) {
    if (autoRotate) {
        Day = (Day + 1) % 360;  
        Time = (Time + 2) % 360; 
        glutPostRedisplay();    
        glutTimerFunc(30, Timer, 1);
    }
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        Day = (Day + 10) % 360;
        glutPostRedisplay();
        break;
    case 't':
        Time = (Time + 5) % 360;
        glutPostRedisplay();
        break;
    case 's':
        autoRotate = !autoRotate;
        if (autoRotate) {
            glutTimerFunc(30, Timer, 1);
        }
        break;
    default:
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Solar System (Top View)");

    glClearColor(0.0, 0.0, 0.0, 1.0); // ���

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    SetLighting(); // ���� ����

    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}